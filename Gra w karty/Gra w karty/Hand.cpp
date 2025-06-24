#include "Hand.h"
#include "CardUtils.h"
#include <iostream>
#include <map>
#include <algorithm>

static bool isStraight(const std::vector<int>& vals)
{
    for (int i = 1; i < 5; ++i)
    {
        if (vals[i] != vals[i - 1] - 1)
            break;
        if (i == 4)
            return true;
    }
    // Special case A-2-3-4-5
    if (vals == std::vector<int>{12, 3, 2, 1, 0})
        return true;
    return false;
}

void Hand::AddCard(const Card& card, int index)
{
    if (index >= 0 && index < 5)
        m_cards[index] = card;
}

void Hand::ReplaceCard(int index, const Card& newCard)
{
    if (index >= 0 && index < 5)
        m_cards[index] = newCard;
}

void Hand::Print() const
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << ToString(m_cards[i].value) << " " << ToString(m_cards[i].color) << "\n";
    }
}

std::vector<int> Hand::GetSortedValues() const
{
    std::vector<int> values;
    for (int i = 0; i < 5; ++i)
        values.push_back(static_cast<int>(m_cards[i].value));
    std::sort(values.begin(), values.end(), std::greater<int>());
    return values;
}

std::string Hand::Evaluate() const
{
    std::map<Value, int> valueCount;
    std::map<Color, int> colorCount;
    std::vector<int> values;

    for (int i = 0; i < 5; ++i)
    {
        valueCount[m_cards[i].value]++;
        colorCount[m_cards[i].color]++;
        values.push_back(static_cast<int>(m_cards[i].value));
    }

    std::sort(values.begin(), values.end(), std::greater<int>());

    bool flush = false;
    for (auto& c : colorCount)
        if (c.second == 5) flush = true;

    bool straight = isStraight(values);

    if (straight && flush) return "Poker";

    int pairs = 0, three = 0, four = 0;
    for (auto& vc : valueCount)
    {
        if (vc.second == 4) four++;
        else if (vc.second == 3) three++;
        else if (vc.second == 2) pairs++;
    }

    if (four == 1) return "Kareta";
    if (three == 1 && pairs == 1) return "Full";
    if (flush) return "Kolor";
    if (straight) return "Strit";
    if (three == 1) return "Trojka";
    if (pairs == 2) return "Dwie pary";
    if (pairs == 1) return "Para";

    return "High Card";
}
