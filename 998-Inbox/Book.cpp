#include <iostream>

using namespace std;

class Book
{
    private:
        string name;
        string author;
        double price;
    public:
        Book (string name, string author, double price) : name(name), author(author), price(price) {}
        string getName () {return name;}
        string getAuthor () {return author;}
        double getPrice () {return price;}
};
int main()
{
    Book a("Dont Panic", "John", 3.99);
    cout << a.getAuthor() << " " << a.getName() << " " << a.getPrice() <<endl;
}