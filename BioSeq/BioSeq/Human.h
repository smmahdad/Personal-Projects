#ifndef HUMAN_H_
#define HUMAN_H_

#include "Chromosome.h"

class Human
{
public:
	Human();
	Human(string first, string last, int ageOld);
	void setInfo(string first, string last, int ageOld);
	void addChrom(const Chromosome &chrom);
	void printHuman() const;
	void checkDis(string name, string patt, int chromNum);


private:
	string firstName;
	string lastName;
	int age;
	list<Chromosome> chromList;
	string entireDNA;
	list<string> diseases;
	int chromInData;
	
};





#endif