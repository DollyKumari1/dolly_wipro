#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    int bookID;
    std::string bookName;
    std::string author;
    double price;
    int quantityOnHand;

public:
    Book(int id, const std::string& name, const std::string& author, double price, int qoh);

    int getBookID() const;
    std::string getBookName() const;
    std::string getAuthor() const;
    double getPrice() const;
    int getQuantityOnHand() const;

    void setBookID(int id);
    void setBookName(const std::string& name);
    void setAuthor(const std::string& author);
    void setPrice(double price);
    void setQuantityOnHand(int qoh);

    
    void buy(int qty);
    void sell(int qty);
    void display() const;
};

#endif 
