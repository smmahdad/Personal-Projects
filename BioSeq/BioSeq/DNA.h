#ifndef DNA_H_
#define DNA_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <map>
using namespace std;

class DNA
{
public:
	DNA();
	DNA(string dna);

	void printDNA(int *line_number) const;
	void DNA::setDNA(string dna);
	void DNA::setDNAInParts(string dna);
	void setDNAInParts(const DNA &dna);
	string DNA::getDNA() const;

private:
	string dnaSeq;
	list<string> diseases;

};

bool findDisHelper(const string patt, const string dna);

#endif