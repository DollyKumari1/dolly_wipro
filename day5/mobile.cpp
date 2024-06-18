#include <iostream>
#include <string>

using namespace std;

class MobilePhone {
private:
    string brand;
    string model;
    double price;
    int batteryLife; 

public:
    MobilePhone() : brand(""), model(""), price(0.0), batteryLife(100) {}

    MobilePhone(string brand, string model, double price)
        : brand(brand), model(model), price(price), batteryLife(100) {}

    void makeCall(string number) {
        cout << "Calling " << number << "..." << endl;
        consumeBattery(5);
    }

    void hangUp() {
        cout << "Ending the call." << endl;
    }

    void sendMessage(string number, string message) {
        cout << "Sending message to " << number << ": " << message << endl;
        consumeBattery(2);
    }

    void readMessage() {
        cout << "Reading messages..." << endl;
    }

    void chargePhone() {
        cout << "Charging the phone..." << endl;
        batteryLife = 100; 
    }

    void displayInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Price: $" << price << endl;
        cout << "Battery Life: " << batteryLife << "%" << endl;
    }

private:
    void consumeBattery(int amount) {
        // Simulate battery consumption
        if (batteryLife > amount) {
            batteryLife -= amount;
        } else {
            batteryLife = 0;
            cout << "Battery low! Please charge your phone." << endl;
        }
    }
};

int main() {
    MobilePhone phone1("Apple", "iPhone 12", 799.99);
    MobilePhone phone2("Samsung", "Galaxy S21", 899.99);

    cout << "Phone 1 Details:" << endl;
    phone1.displayInfo();
    cout << endl;

    cout << "Phone 2 Details:" << endl;
    phone2.displayInfo();
    cout << endl;

    phone1.makeCall("123-456-7890");
    phone2.sendMessage("987-654-3210", "Hello! How are you?");

    cout << endl;
    cout << "Updated Battery Life:" << endl;
    phone1.displayInfo();
    phone2.displayInfo();

    phone1.chargePhone();
    cout << "After charging Phone 1:" << endl;
    phone1.displayInfo();

    return 0;
}
