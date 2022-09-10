//
// Created by Grim Reaper on 28.08.2022.
//
#include <iostream>
#include <vector>
#include "Rotor.h"

Rotor::Rotor(size_t num, size_t pos) noexcept(true)
:   number(num),
    position(pos)
    {}

void Rotor::step() noexcept(true)
{
    position = (position + 1) % 26;
}
size_t Rotor::getPosition() noexcept(true)
{
    return position;
}
size_t Rotor::getNotchPosition() noexcept(true)
{
    return notchPosition[number];
}
size_t Rotor::getNumber() noexcept(true)
{
    return number;
}