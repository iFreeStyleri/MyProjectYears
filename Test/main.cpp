
#include <iostream>
#include "Programs.h"

#define  color {system("color 02");}

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	color;
	Programs prog;
	int choice = 1;
	while (choice != 0) {
		prog.MatrixOut("###ProjectK###", true);
		prog.MatrixOut("0-Выход\n1-###BubbleSort###\n2-###CenterOfMass###\n3-###DynamicMassive###", true);
		cin >> choice;
		if(choice == 1) prog.BubbleSorting();
		if(choice == 2) prog.CenterOfMass();
		if(choice == 3) prog.DynamicCheck();
	}

}