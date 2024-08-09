#include <iostream>
#include <thread>
#include <mutex>
#include <map>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080

std::mutex mtx;
std::map<int, std::string> clients;
std::map<int, int> client_sockets;

void handle_client(int client_socket) {
    char buffer[256];
    int bytes_received;

    // Receive client name
    bytes_received = recv(client_socket, buffer, 256, 0);
    std::string client_name(buffer, bytes_received);
    std::cout << client_name << " connected" << std::endl;

    // Add client to map
    mtx.lock();
    clients[client_socket] = client_name;
    mtx.unlock();

    while (true) {
        bytes_received = recv(client_socket, buffer, 256, 0);
        if (bytes_received <= 0) {
            break;
        }

        std::string message(buffer, bytes_received);
        std::cout << client_name << ": " << message << std::endl;

        // Relay message to all other clients
        for (auto& client : clients) {
            if (client.first != client_socket) {
                send(client.first, (client_name + ": " + message).c_str(), (client_name + ": " + message).size(), 0);
            }
        }
    }

    // Remove client from map
    mtx.lock();
    clients.erase(client_socket);
    mtx.unlock();

    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        std::cerr << "Error creating server socket" << std::endl;
        return 1;
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind server socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Error binding server socket" << std::endl;
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        std::cerr << "Error listening for incoming connections" << std::endl;
        return 1;
    }

    std::cout << "Chat server started on port " << PORT << std::endl;

    while (true) {
        // Accept incoming connection
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
        if (client_socket < 0) {
            std::cerr << "Error accepting incoming connection" << std::endl;
            continue;
        }

        // Handle client in separate thread
        std::thread(handle_client, client_socket).detach();
    }

    return 0;
}
