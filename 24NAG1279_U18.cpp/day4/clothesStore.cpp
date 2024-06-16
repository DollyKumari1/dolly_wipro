#include <iostream>
#include <string>

struct Item_Rec {
    std::string itemName;
    std::string itemType;
    double price;
    int quantity;
};

int main() {
    Item_Rec item;

    item.itemName = "Blue Shirt";
    item.itemType = "Men's Clothing";
    item.price = 29.99;
    item.quantity = 50;

    std::cout << "Item Name: " << item.itemName << std::endl;
    std::cout << "Item Type: " << item.itemType << std::endl;
    std::cout << "Price: $" << item.price << std::endl;
    std::cout << "Quantity: " << item.quantity << std::endl;

    return 0;
}
