#include "DNA.h"

static int COLUMN_SIZE = 20;

DNA::DNA()
{
	dnaSeq = "";
}

DNA::DNA(string dna)
{
	dnaSeq = dna;
}


void DNA::setDNA(string dna)
{
	dnaSeq = dna;
	diseases.clear();
}

void DNA::setDNAInParts(string dna)
{
	dnaSeq += dna;
}

void DNA::setDNAInParts(const DNA &dna)
{
	dnaSeq += dna.getDNA();
}


void DNA::printDNA(int *line_number) const
{
	int lenDNA = dnaSeq.size();
	int col = 1;
	int space = 1;
	for (int i = 0; i < lenDNA; i++)
	{
		if (col == 1)
		{
			cout << "Line #" << *line_number << ": ";
			*line_number = *line_number + 1;
		}
		space++;
		col++;
		cout << dnaSeq[i];

		if (col > COLUMN_SIZE)
		{
			cout << endl;
			col = 1;
			space = 1;
		}
		else if (space > 2)
		{
			cout << " ";
			space = 1;
		}

	}
}

string DNA::getDNA() const
{
	return dnaSeq;
}