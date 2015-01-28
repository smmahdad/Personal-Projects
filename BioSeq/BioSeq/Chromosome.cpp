#include "Chromosome.h"

static int COL_SIZE = 20;

Chromosome::Chromosome()
{
	entireDNA = "";
}

Chromosome::Chromosome(DNA dna)
{
	entireDNA = dna.getDNA();
	strands.push_back(dna);
}

Chromosome::Chromosome(string str)
{
	entireDNA += str;
	DNA temp(str);
	strands.push_back(temp);
}

void Chromosome::addDNA(const DNA & dna)
{
	strands.push_back(dna);
	entireDNA += dna.getDNA();
}

void Chromosome::setDNA(string str)
{
	strands.clear();
	DNA temp(str);
	strands.push_back(temp);
	entireDNA = str;
}

DNA Chromosome::getDNAObj() const
{
	DNA ret;
	list<DNA>::const_iterator iter = strands.cbegin();
	while (iter != strands.cend())
	{
		ret.setDNAInParts(iter->getDNA());
		iter++;
	}
	return ret;
}

string Chromosome::getDNAStr() const
{
	return entireDNA;
}

void Chromosome::findDis(const string name, const string patt)
{
	int index_num = 0;
	if (!haveDis(name))
	{
		if (findDisHelper(patt, entireDNA, &index_num))
			diseases.push_back(name + " at line " + to_string((index_num / COL_SIZE) + 1) + " element " + to_string(index_num % COL_SIZE));
	}
}

bool Chromosome::haveDis(const string disName)
{
	list<string>::iterator disIter = diseases.begin();
	for (; disIter != diseases.end(); disIter++)
	{
		if (*disIter == disName)
			return true;
	}
	return false;
}

bool findDisHelper(const string patt, const string dna, int *line_number)
{
	int sizePatt = patt.size();
	int sizeDNA = dna.size();
	*line_number = *line_number + 1;

	if (sizePatt == 0)
	{
		return true;
	}
	else if (sizeDNA == 0 || sizePatt > sizeDNA)
	{
		return false;
		*line_number = -1;
	}
	else
	{
		bool samePatt = true;
		for (int i = 0; i < sizePatt && samePatt; i++)
		{
			if (patt[i] != dna[i])
			{
				samePatt = false;
			}
		}

		if (!samePatt)
		{
			return findDisHelper(patt, dna.substr(1, sizeDNA - 1), line_number);
		}
		return true;
	}
}

void Chromosome::printChrom() const
{
	list<DNA>::const_iterator iter = strands.cbegin();
	int line_number = 1;
	while (iter != strands.end())
	{
		iter->printDNA(&line_number);
		iter++;
		line_number++;
	}
	cout << endl << endl;
	list<string>::const_iterator disIter = diseases.cbegin();
	if (disIter != diseases.cend())
	{
		cout << "[" << *disIter;
		disIter++;
		while (disIter != diseases.cend())
		{
			cout << ", " << *disIter;
			disIter++;
		}
		cout << "]" << endl << endl;
	}
	cout << endl;
}