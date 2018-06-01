#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <string.h>

using namespace std;

enum class DrugListColumnHeader
{
	ApplNo=1,
	ProductNo=2,
	Form=3,
	Strength=4,
	ReferenceDrug=5,
	DrugName=6,
	ActiveIngredient=7,
	ReferenceStandard=8
};

class DrugListCreator
{
public:
	DrugListCreator();
	~DrugListCreator();
	static void CreateList(const string& filePath, const set<DrugListColumnHeader>& headers);
};

