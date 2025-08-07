#pragma once
#include "Book.h"
#include "Reader.h"
#include <vector>
#include <map>
#include <fstream>

class Library {
    vector<Book> books;
    map<string, Reader> readers;
    int nextId = 1;

    Book* findBook(int id) {
        for (auto& b : books)
            if (b.getId() == id)
                return &b;
        return nullptr;
    }

public:
    void addBook(const string& title, const string& author) {
        books.emplace_back(nextId++, title, author);
        cout << "Book added.\n";
    }

    void removeBook(int id) {
        books.erase(remove_if(books.begin(), books.end(),
            [id](const Book& b) { return b.getId() == id; }), books.end());
        cout << "Book removed.\n";
    }

    void borrowBook(const string& imie, const string& nazwisko, int id) {
        Book* b = findBook(id);
        if (!b) {
            cout << "Book not found.\n";
            return;
        }
        if (b->isBorrowed()) {
            cout << "Book is already borrowed.\n";
            return;
        }

        string key = imie + "_" + nazwisko;
        if (readers.count(key) == 0)
            readers[key] = Reader(imie, nazwisko);

        readers[key].borrowBook(id);
        b->borrow();
        cout << "Book borrowed.\n";
    }

    void returnBook(const string& imie, const string& nazwisko, int id) {
        string key = imie + "_" + nazwisko;
        if (readers.count(key) == 0 || !readers[key].hasBook(id)) {
            cout << "This reader doesn't have this book.\n";
            return;
        }

        Book* b = findBook(id);
        if (b) b->giveBack();
        readers[key].returnBook(id);
        cout << "Book returned.\n";
    }

    void showState() const {
        cout << "\n--- Books ---\n";
        for (const auto& b : books)
            b.description();

        cout << "\n--- Readers ---\n";
        for (const auto& [_, r] : readers)
            r.listBooks();
    }

    void saveToFile(const string& filename) {
        ofstream fout(filename);
        for (const auto& b : books)
            fout << "B|" << b.serialize() << "\n";
        for (const auto& [_, r] : readers)
            fout << "R|" << r.serialize() << "\n";
        fout.close();
        cout << "Library saved.\n";
    }

    void loadFromFile(const string& filename) {
        ifstream fin(filename);
        if (!fin) {
            cout << "File not found.\n";
            return;
        }

        books.clear();
        readers.clear();
        string line;
        while (getline(fin, line)) {
            if (line.rfind("B|", 0) == 0) {
                books.push_back(Book::deserialize(line.substr(2)));
                nextId = max(nextId, books.back().getId() + 1);
            }
            else if (line.rfind("R|", 0) == 0) {
                Reader r = Reader::deserialize(line.substr(2));
                readers[r.getKey()] = r;
            }
        }
        fin.close();
        cout << "Library loaded.\n";
    }
};

