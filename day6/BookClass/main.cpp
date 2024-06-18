#include <iostream>
#include "Book.h"

int main() {
    Book book1(1, "Bookname 1", "Author 1", 10.00, 50);

    std::cout << "Initial book details:" << std::endl;
    book1.display();
    std::cout << std::endl;

    book1.buy(10);
    std::cout << std::endl;
    
    book1.sell(5);
    std::cout << std::endl;

    book1.sell(100); 
    std::cout << std::endl;

    std::cout << "Updated book details:" << std::endl;
    book1.display();

    return 0;
}
