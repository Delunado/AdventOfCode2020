#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

class PasswordInfo 
{
private:
	int minCharReps;
	int maxCharReps;
	char checkedChar;
	std::string password;

public:
	PasswordInfo(int minCharReps, int maxCharReps, char checkedChar, std::string password) :
		minCharReps(minCharReps), maxCharReps(maxCharReps), checkedChar(checkedChar), password(password) {}

	bool IsValidOldPolicy() 
	{
		int charCount = 0;

		for (int i = 0; i < password.length(); i++) {

			if (password[i] == checkedChar) {
				charCount++;

				if (charCount > maxCharReps)
					break;
			}
		}

		return (charCount >= minCharReps && charCount <= maxCharReps);
	}

	bool IsValidNewPolicy()
	{
		bool firstDigitValid = password[minCharReps - 1] == checkedChar;
		bool secondDigitValid = password[maxCharReps - 1] == checkedChar;

		//My old friend, XOR!
		return firstDigitValid ^ secondDigitValid;
	}
};

enum class POLICY_TYPE {
	OLD,
	NEW
};

class Day2
{
private:
	std::vector<PasswordInfo> passwordList;

	void LoadProblem(std::string filepath);
	int FindValidPasswords(POLICY_TYPE policyType);

public:
	Day2(std::string problemPath);

	void Resolve();
};

