#include <iostream>
#include <vector>
#include <string>
#include "Deck.h"
#include "Hand.h"
#include <map>

int GetHandRank(const std::string& handName)
{
    static std::map<std::string, int> rank = {
        {"High Card", 1},
        {"Para", 2},
        {"Dwie pary", 3},
        {"Trojka", 4},
        {"Strit", 5},
        {"Kolor", 6},
        {"Full", 7},
        {"Kareta", 8},
        {"Poker", 9}
    };
    auto it = rank.find(handName);
    return it != rank.end() ? it->second : 0;
}

int CompareHands(const Hand& h1, const Hand& h2)
{
    int rank1 = GetHandRank(h1.Evaluate());
    int rank2 = GetHandRank(h2.Evaluate());

    if (rank1 > rank2) return 1;
    if (rank1 < rank2) return -1;

    std::vector<int> v1 = h1.GetSortedValues();
    std::vector<int> v2 = h2.GetSortedValues();

    for (size_t i = 0; i < v1.size(); ++i)
    {
        if (v1[i] > v2[i]) return 1;
        if (v1[i] < v2[i]) return -1;
    }
    return 0;
}

void ReplaceCardsInteractive(Hand& hand, Deck& deck)
{
    std::cout << "Wprowadz indeksy kart do wymiany (0-4), oddzielone spacjami, lub ENTER jesli brak wymiany:\n";
    std::string line;
    std::getline(std::cin, line);
    if (line.empty()) return;

    std::vector<int> indices;
    size_t pos = 0;
    while (pos < line.size())
    {
        while (pos < line.size() && line[pos] == ' ') ++pos;
        if (pos >= line.size()) break;
        if (isdigit(line[pos]))
        {
            int idx = line[pos] - '0';
            if (idx >= 0 && idx < 5)
                indices.push_back(idx);
        }
        ++pos;
    }

    for (int idx : indices)
    {
        Card newCard = deck.Deal();
        hand.ReplaceCard(idx, newCard);
    }
}

int main()
{
    Deck deck;
    deck.Shuffle();

    Hand player1, player2;

    for (int i = 0; i < 5; ++i)
    {
        player1.AddCard(deck.Deal(), i);
        player2.AddCard(deck.Deal(), i);
    }

    std::cout << "Gracz 1 - Twoje karty:\n";
    player1.Print();
    ReplaceCardsInteractive(player1, deck);
    std::cout << "Twoja reka po wymianie:\n";
    player1.Print();

    std::cout << "\nGracz 2 - Twoje karty:\n";
    player2.Print();
    ReplaceCardsInteractive(player2, deck);
    std::cout << "Reka gracza 2 po wymianie:\n";
    player2.Print();

    std::string eval1 = player1.Evaluate();
    std::string eval2 = player2.Evaluate();

    std::cout << "\nGracz 1: " << eval1 << "\n";
    std::cout << "Gracz 2: " << eval2 << "\n";

    int result = CompareHands(player1, player2);
    if (result == 1) std::cout << "Gracz 1 wygrywa!\n";
    else if (result == -1) std::cout << "Gracz 2 wygrywa!\n";
    else std::cout << "Remis!\n";

    return 0;
}

