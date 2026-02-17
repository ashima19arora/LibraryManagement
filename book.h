#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool available;

    void input();
    void display() const;

    void saveToFile() const;
    static void loadFromFile(vector<Book> &books);
    static void saveAll(const vector<Book> &books);
};

// -------- Function Implementations --------
void Book::input() {
    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Title: ";
    getline(cin, title);
    cout << "Enter Author: ";
    getline(cin, author);
    available = true;
}

void Book::display() const {
    cout << "ID: " << id
         << " | Title: " << title
         << " | Author: " << author
         << " | " << (available ? "Available" : "Issued")
         << endl;
}

void Book::saveToFile() const {
    ofstream fout("books.txt", ios::app);
    fout << id << '\n' << title << '\n' << author << '\n' << available << '\n';
    fout.close();
}

void Book::loadFromFile(vector<Book> &books) {
    ifstream fin("books.txt");
    if (!fin) return;

    while (!fin.eof()) {
        Book b;
        if (!(fin >> b.id)) break;
        fin.ignore();
        getline(fin, b.title);
        getline(fin, b.author);
        fin >> b.available;
        fin.ignore();
        books.push_back(b);
    }
    fin.close();
}

void Book::saveAll(const vector<Book> &books) {
    ofstream fout("books.txt");
    for (const auto &b : books) {
        fout << b.id << '\n' << b.title << '\n' << b.author << '\n' << b.available << '\n';
    }
    fout.close();
}

#endif
