#include "Human.h"

static int NUM_OF_CRHOM_PAIRS = 23;

Human::Human()
{
	firstName = "Senor";
	lastName = "Nobody";
	age = 128;
	entireDNA = "";
	chromInData = 0;
	
}
Human::Human(string first, string last, int ageOld)
{
	firstName = first;
	lastName = last;
	age = ageOld;
	entireDNA = "";
	chromInData = 0;
}

void Human::setInfo(string first, string last, int ageOld)
{
	firstName = first;
	lastName = last;
	age = ageOld;
	entireDNA = "";
	chromInData = 0;
	chromList.clear();
}

void Human::addChrom(const Chromosome &chrom)
{
	chromList.push_back(chrom);
	chromInData++;
}

void Human::printHuman() const
{
	cout << lastName << ", " << firstName << "\nAge: " << age << endl << endl;
	int i = 1;
	list<Chromosome>::const_iterator iter = chromList.begin();
	while (iter != chromList.cend())
	{
		cout << "Chromosome " << i << ":\n";
		iter->printChrom();
		iter++;
		i++;
	}
	cout << endl;
}

void Human::checkDis(string name, string patt, int chromNum)
{
	if (chromNum > NUM_OF_CRHOM_PAIRS * 2 || chromNum < 0)
	{
		cerr << "Error: Humans only have 23 Chromosomes!" << endl;
	}
	else if (chromNum > chromInData)
	{
		cerr << "Haven't fully uploaded all your information!" << endl;
	}
	else if (chromNum == 0)
	{
		list<Chromosome>::iterator iter = chromList.begin();
		int i = 1;
		while (i <= chromInData)
		{
			iter->findDis(name, patt);
			i++;
			iter++;
		}
	}
	else
	{
		list<Chromosome>::iterator iter = chromList.begin();
		int i = 1;
		while (i < chromNum)
		{
			i++;
			iter++;
		}

		iter->findDis(name, patt);

	}
}

