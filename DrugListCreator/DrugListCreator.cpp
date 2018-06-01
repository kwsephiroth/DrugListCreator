#include "DrugListCreator.h"



DrugListCreator::DrugListCreator()
{
}


DrugListCreator::~DrugListCreator()
{
}

void DrugListCreator::CreateList(const string& filePath, const set<DrugListColumnHeader>& headers)
{
	ifstream inputFile(filePath);

	string item;

	if (!inputFile.fail())
	{
		int columnNum = 1;
		int lineNumber = 1;
		bool multipleColumns = (headers.size() > 1);

		ofstream outputFile(filePath + ".output.txt");
		if (outputFile.fail())
		{
			cout << "ERROR: Failed to open file at path '" << filePath << "'" << endl;
			return;
		}
		cout << "Writing output to file....Please wait..." << endl;
		while (getline(inputFile, item))
		{
			char* tokens = strtok(const_cast<char*>(item.c_str()), "\t");
			columnNum = 1;
			while (tokens != NULL)
			{
				if (headers.find(static_cast<DrugListColumnHeader>(columnNum)) != headers.end())
				{
					if (multipleColumns)
					{
						outputFile << tokens << "\t";
						//cout << tokens << "\t";
					}
					else
					{
						outputFile << tokens;
						//cout << tokens;
					}
				}
				tokens = strtok(NULL, "\t");
				columnNum++;
			}
			//cout << endl;
			outputFile << endl;
		}
		cout << "Finished writing output to file '" << filePath + ".output.txt'." << endl;
		inputFile.close();
		outputFile.close();
	}
	else
	{
		cout << "ERROR: Failed to open file at path '" << filePath << "'" << endl;
	}
}