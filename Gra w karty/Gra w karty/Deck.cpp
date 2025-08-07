#include "Deck.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>

Deck::Deck()
{
    Initialize();
}

void Deck::Initialize()
{
    int counter = 0;
    for (int i = 0; i < (int)Color::Size; ++i)
    {
        for (int j = 0; j < (int)Value::Size; ++j)
        {
            m_cards[counter].color = (Color)i;
            m_cards[counter].value = (Value)j;
            ++counter;
        }
    }
    m_currentCardIndex = 0;
}

void Deck::Shuffle()
{
    srand((unsigned)time(nullptr));
    const int size = 52;
    for (int i = 0; i < size; ++i)
    {
        int randIndex = rand() % size;
        std::swap(m_cards[i], m_cards[randIndex]);
    }
}

Card Deck::Deal()
{
    if (m_currentCardIndex < 52)
        return m_cards[m_currentCardIndex++];
    else
        return { Color::Hearts, Value::Two }; // fallback
}



