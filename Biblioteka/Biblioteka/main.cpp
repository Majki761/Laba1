#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>

class Ksiazka {
public:
    int id;
    std::string tytul;
    std::string autor;
    bool wypozyczona = false;

    Ksiazka(int id, const std::string& tytul, const std::string& autor)
        : id(id), tytul(tytul), autor(autor) {
    }

    std::string opis() const {
        return "[" + std::to_string(id) + "] \"" + tytul + "\" - " + autor + (wypozyczona ? " (wypozyczona)" : " (dostepna)");
    }
};

class Osoba {
public:
    std::string imie;
    std::string nazwisko;

    Osoba(const std::string& imie, const std::string& nazwisko)
        : imie(imie), nazwisko(nazwisko) {
    }
};

class Czytelnik : public Osoba {
public:
    std::vector<int> wypozyczoneKsiazki;

    Czytelnik() : Osoba("", "") {}

    Czytelnik(const std::string& imie, const std::string& nazwisko)
        : Osoba(imie, nazwisko) {
    }
};

class Biblioteka {
private:
    std::vector<Ksiazka> ksiazki;
    std::map<std::string, Czytelnik> czytelnicy;
    int nextBookId = 1;

    static std::string kluczCzytelnika(const std::string& imie, const std::string& nazwisko) {
        return imie + "_" + nazwisko;
    }

public:
    void dodajKsiazke(const std::string& tytul, const std::string& autor) {
        ksiazki.emplace_back(nextBookId++, tytul, autor);
    }

    void usunKsiazke(int id) {
        auto it = std::find_if(ksiazki.begin(), ksiazki.end(), [id](const Ksiazka& k) { return k.id == id; });
        if (it != ksiazki.end()) {
            if (it->wypozyczona) {
                std::cout << "Nie mozna usunac ksiazki - jest wypozyczona.\n";
                return;
            }
            ksiazki.erase(it);
            std::cout << "Ksiazka usunieta.\n";
        }
        else {
            std::cout << "Nie znaleziono ksiazki o podanym ID.\n";
        }
    }

    void wypozyczKsiazke(const std::string& imie, const std::string& nazwisko, int id) {
        auto it = std::find_if(ksiazki.begin(), ksiazki.end(), [id](Ksiazka& k) { return k.id == id; });
        if (it == ksiazki.end()) {
            std::cout << "Nie znaleziono ksiazki o podanym ID.\n";
            return;
        }

        if (it->wypozyczona) {
            std::cout << "Ksiazka jest juz wypozyczona.\n";
            return;
        }

        std::string klucz = kluczCzytelnika(imie, nazwisko);
        Czytelnik& czytelnik = czytelnicy.try_emplace(klucz, imie, nazwisko).first->second;

        czytelnik.wypozyczoneKsiazki.push_back(id);
        it->wypozyczona = true;

        std::cout << "Wypozyczono ksiazke.\n";
    }

    void zwrocKsiazke(const std::string& imie, const std::string& nazwisko, int id) {
        std::string klucz = kluczCzytelnika(imie, nazwisko);
        auto it = czytelnicy.find(klucz);
        if (it == czytelnicy.end()) {
            std::cout << "Nie znaleziono czytelnika.\n";
            return;
        }

        auto& ksiazkiCzytelnika = it->second.wypozyczoneKsiazki;
        auto found = std::find(ksiazkiCzytelnika.begin(), ksiazkiCzytelnika.end(), id);

        if (found == ksiazkiCzytelnika.end()) {
            std::cout << "Czytelnik nie wypozyczyl tej ksiazki.\n";
            return;
        }

        ksiazkiCzytelnika.erase(found);

        auto ksIt = std::find_if(ksiazki.begin(), ksiazki.end(), [id](Ksiazka& k) { return k.id == id; });
        if (ksIt != ksiazki.end()) {
            ksIt->wypozyczona = false;
        }

        std::cout << "Zwrocono ksiazke.\n";
    }

    void wyswietlStan() {
        std::cout << "--- Ksiazki ---\n";
        for (const auto& k : ksiazki) {
            std::cout << k.opis() << "\n";
        }

        std::cout << "--- Czytelnicy ---\n";
        for (const auto& para : czytelnicy) {
            const auto& c = para.second;
            std::cout << c.imie << " " << c.nazwisko << " wypozyczyl(a): ";
            for (int id : c.wypozyczoneKsiazki) {
                std::cout << id << " ";
            }
            std::cout << "\n";
        }
    }

    void zapiszDoPliku(const std::string& nazwa) {
        std::ofstream plik(nazwa);
        for (const auto& k : ksiazki) {
            plik << k.id << "|" << k.tytul << "|" << k.autor << "|" << k.wypozyczona << "\n";
        }
        plik << "---\n";
        for (const auto& para : czytelnicy) {
            const auto& c = para.second;
            plik << c.imie << "|" << c.nazwisko << "|";
            for (size_t i = 0; i < c.wypozyczoneKsiazki.size(); ++i) {
                plik << c.wypozyczoneKsiazki[i];
                if (i + 1 < c.wypozyczoneKsiazki.size()) plik << ",";
            }
            plik << "\n";
        }
        std::cout << "Zapisano do pliku.\n";
    }

    void wczytajZPliku(const std::string& nazwa) {
        ksiazki.clear();
        czytelnicy.clear();

        std::ifstream plik(nazwa);
        std::string linia;

        while (std::getline(plik, linia) && linia != "---") {
            std::stringstream ss(linia);
            std::string idStr, tytul, autor, stan;

            std::getline(ss, idStr, '|');
            std::getline(ss, tytul, '|');
            std::getline(ss, autor, '|');
            std::getline(ss, stan);

            int id = std::stoi(idStr);
            bool wyp = (stan == "1");

            ksiazki.emplace_back(id, tytul, autor);
            ksiazki.back().wypozyczona = wyp;

            if (id >= nextBookId) nextBookId = id + 1;
        }

        while (std::getline(plik, linia)) {
            std::stringstream ss(linia);
            std::string imie, nazwisko, lista;

            std::getline(ss, imie, '|');
            std::getline(ss, nazwisko, '|');
            std::getline(ss, lista);

            Czytelnik c(imie, nazwisko);

            std::stringstream ls(lista);
            std::string idStr;
            while (std::getline(ls, idStr, ',')) {
                if (!idStr.empty())
                    c.wypozyczoneKsiazki.push_back(std::stoi(idStr));
            }

            czytelnicy[kluczCzytelnika(imie, nazwisko)] = c;
        }

        std::cout << "Wczytano z pliku.\n";
    }
};

int main() {
    Biblioteka biblioteka;

    while (true) {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Dodaj ksiazke\n";
        std::cout << "2. Usun ksiazke\n";
        std::cout << "3. Wypozycz ksiazke\n";
        std::cout << "4. Zwroc ksiazke\n";
        std::cout << "5. Wyswietl stan biblioteki\n";
        std::cout << "6. Zapisz do pliku\n";
        std::cout << "7. Wczytaj z pliku\n";
        std::cout << "0. Wyjdz\n";
        std::cout << "Wybor: ";

        int wybor;
        std::cin >> wybor;
        std::cin.ignore(); // czyscimy bufor

        if (wybor == 0) break;

        if (wybor == 1) {
            std::string tytul, autor;
            std::cout << "Podaj tytul ksiazki: ";
            std::getline(std::cin, tytul);
            std::cout << "Podaj autora ksiazki: ";
            std::getline(std::cin, autor);
            biblioteka.dodajKsiazke(tytul, autor);
        }
        else if (wybor == 2) {
            int id;
            std::cout << "Podaj ID ksiazki do usuniecia: ";
            std::cin >> id;
            biblioteka.usunKsiazke(id);
        }
        else if (wybor == 3) {
            std::string imie, nazwisko;
            int id;
            std::cout << "Podaj imie czytelnika: ";
            std::cin.ignore();
            std::getline(std::cin, imie);
            std::cout << "Podaj nazwisko czytelnika: ";
            std::getline(std::cin, nazwisko);
            std::cout << "Podaj ID ksiazki do wypozyczenia: ";
            std::cin >> id;
            biblioteka.wypozyczKsiazke(imie, nazwisko, id);
        }
        else if (wybor == 4) {
            std::string imie, nazwisko;
            int id;
            std::cout << "Podaj imie czytelnika: ";
            std::cin.ignore();
            std::getline(std::cin, imie);
            std::cout << "Podaj nazwisko czytelnika: ";
            std::getline(std::cin, nazwisko);
            std::cout << "Podaj ID ksiazki do zwrotu: ";
            std::cin >> id;
            biblioteka.zwrocKsiazke(imie, nazwisko, id);
        }
        else if (wybor == 5) {
            biblioteka.wyswietlStan();
        }
        else if (wybor == 6) {
            std::string nazwa;
            std::cout << "Podaj nazwe pliku do zapisu: ";
            std::cin.ignore();
            std::getline(std::cin, nazwa);
            biblioteka.zapiszDoPliku(nazwa);
        }
        else if (wybor == 7) {
            std::string nazwa;
            std::cout << "Podaj nazwe pliku do wczytania: ";
            std::cin.ignore();
            std::getline(std::cin, nazwa);
            biblioteka.wczytajZPliku(nazwa);
        }
        else {
            std::cout << "Nieznana opcja.\n";
        }
    }

    std::cout << "Koniec programu.\n";
    return 0;
}
