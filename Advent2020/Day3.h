#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Day3
{
private:
	const int TREE_CHAR = '#';

	std::vector<std::string> map;

	void LoadProblem(std::string filepath);

	int CountTreesSlope(int slopeX, int slopeY);

public:
	Day3(std::string problemPath);

	void Resolve();
};

