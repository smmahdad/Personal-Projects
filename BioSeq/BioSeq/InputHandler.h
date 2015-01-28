#include "Human.h"
#include "DNA.h"
#include "Chromosome.h"

#include <fstream>
#include <iomanip>
using namespace std;

const char INPUT_DATA[] = "dummy.txt";
const int MAX_CHROMOSOME = 46;


void makeHuman(ifstream& infile, Human &human);

void readData(Human &human)
{
	ifstream infile;

	infile.open(INPUT_DATA);

	if (!infile)
	{
		cerr << "The file " << INPUT_DATA << " cannot be found\n";
		system("pause");
		exit(1);
	}

	makeHuman(infile, human);
	infile.close();
}

void makeHuman(ifstream& infile, Human &human)
{
	string firstName, lastName, chromosomeSeq;
	int age, chromosomeCount = 0;

	Chromosome temp;

	infile >> firstName;
	infile >> lastName >> age;
	
	human.setInfo(firstName, lastName, age);

	infile >> chromosomeSeq;

	while (chromosomeSeq != "END" && chromosomeCount < MAX_CHROMOSOME)
	{
		chromosomeCount++;
		temp.setDNA(chromosomeSeq);
		human.addChrom(temp);
		infile >> chromosomeSeq;
	}
}