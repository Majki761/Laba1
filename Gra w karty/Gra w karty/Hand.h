#pragma once
#include "Card.h"
#include <string>
#include <vector>

class Hand
{
public:
    void AddCard(const Card& card, int index);
    void ReplaceCard(int index, const Card& newCard);
    void Print() const;
    std::string Evaluate() const;
    std::vector<int> GetSortedValues() const;

private:
    Card m_cards[5];
};


