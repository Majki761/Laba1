#include "CardUtils.h"

std::string ToString(Color c)
{
    switch (c)
    {
    case Color::Hearts:   return "Hearts";
    case Color::Spades:   return "Spades";
    case Color::Diamonds: return "Diamonds";
    case Color::Clubs:    return "Clubs";
    default: return "?";
    }
}

std::string ToString(Value v)
{
    switch (v)
    {
    case Value::Two:   return "2";
    case Value::Three: return "3";
    case Value::Four:  return "4";
    case Value::Five:  return "5";
    case Value::Six:   return "6";
    case Value::Seven: return "7";
    case Value::Eight: return "8";
    case Value::Nine:  return "9";
    case Value::Ten:   return "10";
    case Value::Jack:  return "J";
    case Value::Queen: return "Q";
    case Value::King:  return "K";
    case Value::Ace:   return "A";
    default: return "?";
    }
}
