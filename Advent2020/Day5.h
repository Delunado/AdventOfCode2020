#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Day5
{
private:
	std::vector<std::string> seatCodes;
	std::vector<long> seatIDs;

	void LoadProblem(std::string filepath);
	void DecodeSeatIDs();
	long FindGreatestID();
	long FindMySeatID();

public:
	Day5(std::string problemPath);

	void Resolve();
};

