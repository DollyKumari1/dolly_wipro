#include "Book.h"
#include <iostream>

using namespace std;

Book::Book(int id, const string& name, const string& author, double price, int qoh)
    : bookID(id), bookName(name), author(author), price(price), quantityOnHand(qoh) {}

int Book::getBookID() const {
    return bookID;
}

string Book::getBookName() const {
    return bookName;
}

string Book::getAuthor() const {
    return author;
}

double Book::getPrice() const {
    return price;
}

int Book::getQuantityOnHand() const {
    return quantityOnHand;
}

void Book::setBookID(int id) {
    bookID = id;
}

void Book::setBookName(const string& name) {
    bookName = name;
}

void Book::setAuthor(const string& author) {
    this->author = author;
}

void Book::setPrice(double price) {
    this->price = price;
}

void Book::setQuantityOnHand(int qoh) {
    quantityOnHand = qoh;
}

void Book::buy(int qty) {
    if (qty > 0) {
        quantityOnHand += qty;
        cout << qty << " copies bought. New quantity on hand: " << quantityOnHand << endl;
    } else {
        cout << "Invalid quantity. Please enter a positive number." << endl;
    }
}

void Book::sell(int qty) {
    if (qty > 0 && qty <= quantityOnHand) {
        quantityOnHand -= qty;
        cout << qty << " copies sold. New quantity on hand: " << quantityOnHand << endl;
    } else if (qty > quantityOnHand) {
        cout << "Not enough copies in stock. Available: " << quantityOnHand << endl;
    } else {
        std::cout << "Invalid quantity. Please enter a positive number." << std::endl;
    }
}

void Book::display() const {
    std::cout << "Book ID: " << bookID << std::endl;
    std::cout << "Book Name: " << bookName << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Price: $" << price << std::endl;
    std::cout << "Quantity on Hand: " << quantityOnHand << std::endl;
}
