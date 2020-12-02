#include <iostream>

#include "Day1.h"
#include "Day2.h"

int main()
{
    Day1 day1Problem = Day1("problem1.txt");
    day1Problem.Resolve();

    std::cout << "- - - - - - - - - - - -" << std::endl;

    Day2 day2Problem = Day2("problem2.txt");
    day2Problem.Resolve();
}
