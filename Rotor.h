//
// Created by Grim Reaper on 28.08.2022.
//
#pragma once
#include <iostream>
class Rotor
{
private:
    const std::string rotorList[6] =
            {
                    // normal alphabet
                    {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"},
                    // rotor I
                    {"EKMFLGDQVZNTOWYHXUSPAIBRCJ"},
                    // rotor II
                    {"AJDKSIRUXBLHWTMCQGZNPYFVOE"},
                    // rotor III
                    {"BDFHJLCPRTXVZNYEIWGAKMUSQO"},
                    // rotor IV
                    {"ESOVPZJAYQUIRHXLNFTGKDCMWB"},
                    // rotor V
                    {"VZBRGITYUPSDNHLXAWMJQOFECK"},
            };
    constexpr static  size_t turnoverNotchPosition[6] =
            {
                0,
                17,
                5,
                13,
                10,
                0,
            };
    static size_t position[6];
    size_t number;
public:
    Rotor(size_t number, size_t position) noexcept(true);
    void goThrough(std::vector<std::string> &text) noexcept(true);
};