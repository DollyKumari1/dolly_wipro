#include <iostream>
#include <thread>
#include <mutex>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

std::mutex mtx;
std::string username;

void receive_messages(int client_socket) {
    char buffer[256];
    int bytes_received;

    while (true) {
        bytes_received = recv(client_socket, buffer, 256, 0);
        if (bytes_received <= 0) {
            break;
        }

        std::string message(buffer, bytes_received);
        std::cout << message << std::endl;
    }
}

int main() {
    int client_socket;
    struct sockaddr_in server_addr;

    // Prompt for username
    std::cout << "Enter your name: ";
    std::cin >> username;

    // Create client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        std::cerr << "Error creating client socket" << std::endl;
        return 1;
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Connect to server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Error connecting to server" << std::endl;
        return 1;
    }

    // Send username to server
    send(client_socket, username.c_str(), username.size(), 0);

    std::cout << "Connected to chat server" << std::endl;

    // Start receiving messages in separate thread
    std::thread(receive_messages, client_socket).detach();

    while (true) {
        std::string message;
        std::getline(std::cin, message);

        // Send message to server
        send(client_socket, message.c_str(), message.size(), 0);
    }

    close(client_socket);
    return 0;
}
