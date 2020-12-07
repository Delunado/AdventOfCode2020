#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

enum class PASSPORT_FIELD_TYPE {
	BYR,
	IYR,
	EYR,
	HGT,
	HCL,
	ECL,
	PID,
	CID
};

struct PassportInfo
{
private:
	bool hasByr;
	bool hasIyr;
	bool hasEyr;
	bool hasHgt;
	bool hasHcl;
	bool hasEcl;
	bool hasPid;
	bool hasCid;

public:
	PassportInfo() : hasByr(false), hasIyr(false), hasEyr(false), hasHgt(false), hasHcl(false),
		hasEcl(false), hasPid(false), hasCid(false) {}

	void EnterField(PASSPORT_FIELD_TYPE fieldType) {
		switch (fieldType)
		{
		case PASSPORT_FIELD_TYPE::BYR:
			hasByr = true;
		case PASSPORT_FIELD_TYPE::IYR:
			hasIyr = true;
		case PASSPORT_FIELD_TYPE::EYR:
			hasEyr = true;
		case PASSPORT_FIELD_TYPE::HGT:
			hasHgt = true;
		case PASSPORT_FIELD_TYPE::HCL:
			hasHcl = true;
		case PASSPORT_FIELD_TYPE::ECL:
			hasEcl = true;
		case PASSPORT_FIELD_TYPE::PID:
			hasPid = true;
		case PASSPORT_FIELD_TYPE::CID:
			hasCid = true;
		default:
			break;
		}
	}

	bool IsValid() {
		return (hasByr && hasIyr && hasEyr && hasHgt && hasHcl && hasEcl && hasPid);
	}
};

class Day4
{
private:
	std::vector<PassportInfo> passportList;

	void LoadProblem(std::string filepath);

public:
	Day4(std::string problemPath);

	void Resolve();
};

