#include "Day2.h"

void Day2::LoadProblem(std::string filepath)
{
	std::fstream file;
	file.open(filepath);

	if (file) {
		while (!file.eof()) {
			int min = 0;
			int max = 0;
			char charToCheck = ' ';
			std::string password = "";

			std::string token;

			std::getline(file, token, '-');
			min = std::stoi(token);

			std::getline(file, token, ' ');
			max = std::stoi(token);

			std::getline(file, token, ':');
			charToCheck = token[0];

			std::getline(file, token, ' ');
			std::getline(file, token);
			password = token;

			passwordList.push_back(PasswordInfo(min, max, charToCheck, password));
		}
	}
	else {
		std::cout << "can't open file!" << std::endl;
	}
}

int Day2::FindValidPasswords(POLICY_TYPE policyType)
{
	int validPasswords = 0;

	for (int i = 0; i < passwordList.size(); i++) {

		switch (policyType)
		{
		case POLICY_TYPE::OLD:
			validPasswords += (passwordList[i].IsValidOldPolicy()) ? 1 : 0;
			break;

		case POLICY_TYPE::NEW:
			validPasswords += (passwordList[i].IsValidNewPolicy()) ? 1 : 0;
			break;

		default:
			break;
		}
	}

	return validPasswords;
}

Day2::Day2(std::string problemPath)
{
	LoadProblem(problemPath);
}

void Day2::Resolve()
{
	std::cout << "Day 2 - Problem 1: " << FindValidPasswords(POLICY_TYPE::OLD) << std::endl;
	std::cout << "Day 2 - Problem 2: " << FindValidPasswords(POLICY_TYPE::NEW) << std::endl;
}
