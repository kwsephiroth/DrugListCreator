#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "DrugListCreator.h"

using namespace std;

int main(int argc, char* argv[])
{
	string filePath;

	if (argc >= 2)
	{
		filePath = argv[1];
	}
	else
	{
		cout << "Please enter input file path: ";
		getline(cin, filePath);
	}

	set<DrugListColumnHeader> headers{DrugListColumnHeader::DrugName};
	DrugListCreator::CreateList(filePath, headers);

	system("pause");
	return 0;
}