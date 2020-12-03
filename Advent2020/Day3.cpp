#include "Day3.h"

Day3::Day3(std::string problemPath)
{
	LoadProblem(problemPath);
}

void Day3::LoadProblem(std::string filepath)
{
	std::fstream file;
	file.open(filepath);

	if (file) {
		while (!file.eof()) {
			std::string row;
			file >> row;
			map.push_back(row);
		}
	}
}

int Day3::CountTreesSlope(int slopeX, int slopeY)
{
	int treeCount = 0;
	int actualX = 0;

	for (int i = slopeY; i < map.size(); i += slopeY) {
		actualX = (actualX + slopeX) % map[i].length();	

		treeCount += (map[i][actualX] == TREE_CHAR) ? 1 : 0;
	}

	return treeCount;
}


void Day3::Resolve()
{
	std::cout << "Day 3 - Problem 1: " << CountTreesSlope(3, 1) << std::endl;

	std::cout << "Day 3 - Problem 2: " << CountTreesSlope(3, 1) * 
										  CountTreesSlope(1, 1) * 
									      CountTreesSlope(5, 1) * 
		                                  CountTreesSlope(7, 1) * 
		                                  CountTreesSlope(1, 2) << std::endl;
}
