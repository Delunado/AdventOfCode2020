#include "Day5.h"
#include <bitset>
#include <algorithm>

Day5::Day5(std::string problemPath): seatCodes(std::vector<std::string>()), seatIDs(std::vector<long>())
{
	LoadProblem(problemPath);
}

void Day5::LoadProblem(std::string filepath)
{
	std::fstream file;
	file.open(filepath);

	if (file) {
		while (!file.eof()) {

			std::string line;
			file >> line;

			seatCodes.push_back(line);		
		}
	}
}

void Day5::DecodeSeatIDs()
{
	std::bitset<7> firstByte = std::bitset<7>();
	std::bitset<3> secondByte = std::bitset<3>();

	int secondByteOffset = 3;

	long actualID = 0;

	for (int j = 0; j < seatCodes.size(); j++) {

		std::string seatCode = seatCodes[j];

		for (int i = 0; i < seatCode.size() - secondByteOffset; i++) {
			firstByte[(seatCode.size() - secondByteOffset - 1) - i] = (seatCode[i] == 'B') ? 1 : 0;
		}

		for (int i = seatCode.size() - secondByteOffset; i < seatCode.size(); i++) {
			secondByte[((seatCode.size() - 1) - i)] = (seatCode[i] == 'R') ? 1 : 0;
		}

		actualID = (firstByte.to_ulong() * 8) + secondByte.to_ulong();

		seatIDs.push_back(actualID);
	}
}

long Day5::FindGreatestID()
{
	std::sort(seatIDs.begin(), seatIDs.end());

	return seatIDs[seatIDs.size() - 1];
}

long Day5::FindMySeatID()
{
	std::sort(seatIDs.begin(), seatIDs.end());

	for (int i = 1; i < seatIDs.size(); i++) {
		if (seatIDs[i] - seatIDs[i-1] > 1)
			return seatIDs[i] - 1;
	}

	return -1;
}


void Day5::Resolve()
{
	DecodeSeatIDs();

	std::cout << "Day 5 - Problem 1: " << FindGreatestID() << std::endl;
	std::cout << "Day 5 - Problem 2: " << FindMySeatID() << std::endl;
}
