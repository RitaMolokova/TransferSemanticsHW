#include <iostream>
#include <string>
using namespace std;

class Book {
    char* author;
    char* text;
    int pages;
    int year;
public:
    Book() = default;
    Book(const char* authorc, const char* textc, int pagesc, int yearc){
        author = new char[strlen(authorc) + 1];
        strcpy_s(author, strlen(authorc) + 1, authorc);
        text = new char[strlen(textc) + 1];
        strcpy_s(text, strlen(textc) + 1, textc);
        pages = pagesc;
        year = yearc;
    }
    Book& operator=(const Book& obj) = delete;
    Book(Book& obj) = delete;
    Book& operator=(Book&& obj){
        author = obj.author;
        text = obj.text;
        pages = obj.pages;
        year = obj.year;
        obj.author = nullptr;
        obj.text = nullptr;
        obj.pages = 0;
        obj.year = 0;
        return*this;
    }   
    Book(Book&& obj){
        author = obj.author;
        text = obj.text;
        pages = obj.pages;
        year = obj.year;
        obj.author = nullptr;
        obj.text = nullptr;
        obj.pages = 0;
        obj.year = 0;
    }

    void Print() {
        cout << "Author: " << author << "\t Text: " << text << "\t Pages: " << pages << "\t Year: " << year;
    }
};


int main()
{
    Book book1("Artur Conan Doyle", "Sherlock Holms", 720, 1887);

    Book a = move(book1);
    a.Print();

}