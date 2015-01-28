#include <string>
#include <fstream>
#include <iostream>
using namespace std;

const int HUMAN_CHROM = 46;
const char FILE_NAME[] = "dummy.txt";

string randomizer(int pairs)
{
	string ran = "";
	for (int i = 0; i < pairs; i++)
	{
		int n = rand() % 4;
		int m = 65;
		switch (n)
		{
		case 0:
			n = 65;
			m = 84;
			break;
		case 1:
			n = 67;
			m = 71;
			break;
		case 2:
			n = 71;
			m = 67;
			break;
		case 3:
			n = 84;
			m = 65;
			break;
		}
		ran += (char)n;
		ran += (char)m;
	}
	return ran;
}

void outputGenerator(string firstName, string lastName, int age, int chromNum, int pairs)
{
	ofstream outFile;

	outFile.open(FILE_NAME);

	if (outFile.fail())
	{
		cerr << "Failed to open output file.\n";
		system("pause");
		exit(1);
	}

	outFile << firstName << " " << lastName << " " << age << endl;
	for (int i = 0; i < chromNum && i < HUMAN_CHROM ; i++)
	{
		outFile << randomizer(pairs) << endl << endl;
	}
	outFile << "END";
	outFile.close();
}