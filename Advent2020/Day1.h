#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Day1
{
private:
    const int NUMBER_SEARCHED = 2020;

    std::vector<int> input;

    void LoadProblem(std::string filepath);

    int TwoNumbersSum();
    int ThreeNumbersSum();

public:
    Day1(std::string problemPath);

    void Resolve();
};

