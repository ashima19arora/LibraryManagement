#include "Book.h"
#include <vector>
using namespace std;

int main() {
    cout << "\n===== Welcome to Library Management System =====\n";
    vector<Book> books;
    Book::loadFromFile(books);

    int choice;

    while (true) {
        cout << "\n---- Library Menu ----\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Book b;
            b.input();
            books.push_back(b);
            Book::saveAll(books);
            cout << "Book added successfully!\n";
        }
        else if (choice == 2) {
            if (books.empty()) cout << "No books in library.\n";
            else {
                cout << "\n--- Book List ---\n";
                for (const auto &b : books) b.display();
                cout << "--- Total books: " << books.size() << " ---\n";

            }
        }
        else if (choice == 3) {
            int bid; cout << "Enter Book ID to issue: "; cin >> bid;
            bool found = false;
            for (auto &b : books) {
                if (b.id == bid) {
                    found = true;
                    if (b.available) {
                        b.available = false;
                        Book::saveAll(books);
                        cout << "Book issued successfully!\n";
                    } else cout << "Book already issued.\n";
                    break;
                }
            }
            if (!found) cout << "Book not found.\n";
        }
        else if (choice == 4) {
            int bid; cout << "Enter Book ID to return: "; cin >> bid;
            bool found = false;
            for (auto &b : books) {
                if (b.id == bid) {
                    found = true;
                    if (!b.available) {
                        b.available = true;
                        Book::saveAll(books);
                        cout << "Book returned successfully!\n";
                    } else cout << "Book was not issued.\n";
                    break;
                }
            }
            if (!found) cout << "Book not found.\n";
        }
        else if (choice == 5) {
            cout << "Exiting program. Goodbye!\n";
            break;
        }
        else cout << "Invalid choice. Try again.\n";
    }

    return 0;
}
