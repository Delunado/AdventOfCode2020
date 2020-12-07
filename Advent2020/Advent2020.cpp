#include <iostream>

#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"
#include "Day5.h"

int main()
{
    Day1 day1Problem = Day1("problem1.txt");
    day1Problem.Resolve();

    std::cout << "- - - - - - - - - - - -" << std::endl;

    Day2 day2Problem = Day2("problem2.txt");
    day2Problem.Resolve();

    std::cout << "- - - - - - - - - - - -" << std::endl;

    Day3 day3Problem = Day3("problem3.txt");
    day3Problem.Resolve();

    //std::cout << "- - - - - - - - - - - -" << std::endl;

    //Day4 day4Problem = Day4("problem4.txt");
    //day4Problem.Resolve();

    std::cout << "- - - - - - - - - - - -" << std::endl;

    Day5 day5Problem = Day5("problem5.txt");
    day5Problem.Resolve();
}
