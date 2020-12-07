#include "Day4.h"

Day4::Day4(std::string problemPath) : passportList(std::vector<PassportInfo>())
{
	LoadProblem(problemPath);
}

void Day4::LoadProblem(std::string filepath)
{
	std::ifstream file;
	file.open(filepath);

	if (file) {
		PassportInfo passportInfo = PassportInfo();

		while (!file.eof())
		{
			std::string line;
			std::string token;

			file >> line;

			if (line.empty()) {
				passportInfo = PassportInfo();
				continue;
			}
			else {
				std::getline(file, token, ':');
			}

		
			//switch (switch_on)
			//{
			//default:
			//	break;
			//}
		}
	}
}

void Day4::Resolve()
{
}
