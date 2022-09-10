//
// Created by Grim Reaper on 28.08.2022.
//
#pragma once
#include <iostream>
#include <vector>
class Rotor
{
private:
    /*TO CHECK:
     * Be rotor nr. 1. Should notch activate when 17 is "visible", or
     * when paw hits position 17?*/
    constexpr static size_t notchPosition[6] =
            {
                0,
                17,
                5,
                13,
                10,
                0,
            };
    size_t position;
    size_t number;
public:
    Rotor(size_t num, size_t pos) noexcept(true);
    ~Rotor() = default;
    void goThrough(std::vector<std::string> &text) noexcept(true);
    void step() noexcept(true);
    size_t getPosition() noexcept(true);
    size_t getNotchPosition() noexcept(true);
    size_t getNumber() noexcept(true);
};