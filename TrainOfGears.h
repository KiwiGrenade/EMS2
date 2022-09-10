//
// Created by mango on 05.09.22.
//
#pragma once
#include <iostream>
#include "Rotor.h"
#include <vector>
class TrainOfGears
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
    void step(std::vector<Rotor*> rotors) noexcept(false);
public:
    TrainOfGears() = default;
    ~TrainOfGears() = default;
    void runPlugboard(std::vector<std::string> &text, const std::string &plugboard) noexcept(false);
    void runRotors(std::vector<std::string> &text, std::vector<Rotor*> &rotors) noexcept(false);
};