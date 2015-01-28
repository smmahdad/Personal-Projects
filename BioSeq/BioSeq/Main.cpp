#include "Human.h"
#include "InputHandler.h"
#include "RandomOutput.h"

void outputDetails();

int main()
{
	/*Chromosome chr("naflgknqreogihzfljbngwerohzfdlnbvsfgjhsofvnzkjdbfgwaihbzoivhbaoihbadflkeafnzodginqeoinzldkverqwpoh");
	Chromosome chr1("aaaaaafaaaaaaaamaaaaaaaazaaaaa");
	Human sam("Sam", "Mahdad", 20);
	sam.addChrom(chr);
	sam.addChrom(chr1);
	sam.checkDis("Alz", "fnz", 1);
	sam.checkDis("Lou Disease", "odginqeo", 1);
	sam.checkDis("Aspergers", "bvzlk", 2);
	sam.checkDis("Timmy", "bdfaljfneoquwbgdzljbnglwenafln", 2);
	sam.printHuman();

	Human Erik("Erik", "Bender", 68);
	srand(time(NULL));
	
	for (int i = 0; i < 46; i++)
	{
		string ran = randomizer(20);
		Chromosome temp(ran);
		Erik.addChrom(temp);
	}

	Erik.checkDis("Rando Disease", "GC", 0);
	Erik.printHuman();*/

	string resp;
	cout << "Would you like to make a new person? ";
	cin >> resp;

	if (resp[0] == 'y' || resp[0] == 'Y')
		outputDetails();
	Human human;
	readData(human);
	cout << "\n\nChecking for disease Rando     GC TA" << endl;
	human.checkDis("Rando", "TAATATTAAT", 0);

	human.printHuman();

	cout << endl;
	system("pause");
	return 0;
}

void outputDetails()
{
	string fName, lName;
	int age, chromNum, pairs;
	cout << "What is your name? (FirstName LastName) ";
	cin >> fName >> lName;
	cout << "How old are you? ";
	cin >> age;
	cout << "How many chromosomes would you like? ";
	cin >> chromNum;
	cout << "How many pair bindings? ";
	cin >> pairs;
	outputGenerator(fName, lName, age, chromNum, pairs);
}