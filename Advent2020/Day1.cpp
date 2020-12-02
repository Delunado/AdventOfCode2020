#include "Day1.h"

void Day1::LoadProblem(std::string filepath)
{
    std::fstream file;
    file.open(filepath);

    if (file) {
        while (!file.eof()) {
            int nextNumber;
            file >> nextNumber;

            input.push_back(nextNumber);
        }
    }
    else {
        std::cout << "Can't open file " << filepath << std::endl;
    }
}

int Day1::TwoNumbersSum()
{
    int solution = 0;

    for (int i = 0; i < input.size(); i++) {

        for (int j = i; j < input.size(); j++) {

            if (input[i] + input[j] == 2020) {
                solution = input[i] * input[j];
                break;
            }

        }
    }

    return solution;
}

int Day1::ThreeNumbersSum()
{
    int solution = 0;

    for (int i = 0; i < input.size(); i++) {
        int number1 = input[i];

        for (int j = i; j < input.size(); j++) {
            int number2 = number1 + input[j];

            if (number2 < 2020) {
                for (int k = j; k < input.size(); k++) {
                    int number3 = number2 + input[k];

                    if (number3 == 2020) {
                        solution = input[i] * input[j] * input[k];
                        break;
                    }
                }
            }
        }
    }

    return solution;
}

Day1::Day1(std::string problemPath): input(std::vector<int>())
{
    LoadProblem(problemPath);
}

void Day1::Resolve()
{
    std::cout << "Day 1 - Problem 1: " << TwoNumbersSum() << std::endl;
    std::cout << "Day 1 - Problem 2: " << ThreeNumbersSum() << std::endl;
}
