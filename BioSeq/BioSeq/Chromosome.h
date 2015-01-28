#ifndef CHROMOSOME_H_
#define CHROMOSOME_H_

#include "DNA.h"

class Chromosome
{
public:
	Chromosome();
	Chromosome(DNA dna);
	Chromosome(string str);
	void addDNA(const DNA & dna);
	void setDNA(string str);
	DNA getDNAObj() const;
	string getDNAStr() const;
	void printChrom() const;
	bool haveDis(const string disName);
	void findDis(const string name, const string patt);


private:
	list<DNA> strands;
	string entireDNA;
	list<string> diseases;
};

bool findDisHelper(const string patt, const string dna, int *line_number);

#endif