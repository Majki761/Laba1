#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Osoba {
protected:
    string imie;
    string nazwisko;

public:
    Osoba(string i = "Imie", string n = "Nazwisko") : imie(i), nazwisko(n) {}
    string getKey() const { return imie + "_" + nazwisko; }
    virtual ~Osoba() = default;
};

class Reader : public Osoba {
    vector<int> borrowedBooks;

public:
    Reader(string i = "Imie", string n = "Nazwisko") : Osoba(i, n) {}

    void borrowBook(int bookId) {
        borrowedBooks.push_back(bookId);
    }

    void returnBook(int bookId) {
        borrowedBooks.erase(remove(borrowedBooks.begin(), borrowedBooks.end(), bookId), borrowedBooks.end());
    }

    bool hasBook(int bookId) const {
        return find(borrowedBooks.begin(), borrowedBooks.end(), bookId) != borrowedBooks.end();
    }

    void listBooks() const {
        cout << imie << " " << nazwisko << " has books: ";
        for (int id : borrowedBooks) cout << id << " ";
        cout << endl;
    }

    string serialize() const {
        stringstream ss;
        ss << imie << "|" << nazwisko << "|";
        for (size_t i = 0; i < borrowedBooks.size(); ++i) {
            ss << borrowedBooks[i];
            if (i + 1 < borrowedBooks.size()) ss << ",";
        }
        return ss.str();
    }

    static Reader deserialize(const string& line) {
        stringstream ss(line);
        string imie, nazwisko, booksStr;
        getline(ss, imie, '|');
        getline(ss, nazwisko, '|');
        getline(ss, booksStr);

        Reader r(imie, nazwisko);
        stringstream bs(booksStr);
        string id;
        while (getline(bs, id, ',')) {
            if (!id.empty())
                r.borrowBook(stoi(id));
        }
        return r;
    }
};

