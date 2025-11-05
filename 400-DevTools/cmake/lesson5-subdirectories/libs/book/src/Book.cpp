#include "book/Book.h"
#include <iostream>
#include <iomanip>

Book::Book(int id, const std::string& title, 
           const std::string& author, double price)
    : id(id), title(title), author(author), price(price) {}

void Book::print() const {
    std::cout << std::left << std::setw(5) << id
              << std::setw(30) << title
              << std::setw(20) << author
              << std::fixed << std::setprecision(2) << price << std::endl;
}
