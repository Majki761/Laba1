#pragma once
#include <iostream>
#include <string>
using namespace std;

class Book {
    int id;
    string title;
    string author;
    bool is_borrowed;

public:
    Book(int i = 0, string t = "Untitled", string a = "Unknown", bool borrowed = false)
        : id(i), title(t), author(a), is_borrowed(borrowed) {
    }

    void description() const {
        cout << "[" << id << "] " << title << " by " << author
            << (is_borrowed ? " (borrowed)\n" : " (available)\n");
    }

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool isBorrowed() const { return is_borrowed; }

    void borrow() { is_borrowed = true; }
    void giveBack() { is_borrowed = false; }

    string serialize() const {
        return to_string(id) + "|" + title + "|" + author + "|" + (is_borrowed ? "1" : "0");
    }

    static Book deserialize(const string& line) {
        size_t p1 = line.find('|');
        size_t p2 = line.find('|', p1 + 1);
        size_t p3 = line.find('|', p2 + 1);
        int id = stoi(line.substr(0, p1));
        string title = line.substr(p1 + 1, p2 - p1 - 1);
        string author = line.substr(p2 + 1, p3 - p2 - 1);
        bool borrowed = line.substr(p3 + 1) == "1";
        return Book(id, title, author, borrowed);
    }
};


