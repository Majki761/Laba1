#pragma once
#include "Card.h"

class Deck
{
public:
    Deck();

    void Initialize();
    void Shuffle();
    Card Deal();

private:
    int m_currentCardIndex = 0;
    Card m_cards[52];
};
