
#include <iostream>
#include <thread>
#include <string>
#include "DynamicMassive.h"

#define SIZE 10
#define SIZEB 2000
#define cls {system("cls");}
#define Sleep {sleep_for(20ms);}

using namespace std;
using namespace this_thread;


class Programs
{
private:

	struct PointM {
		double x;
		double y;
		double m;
	};

	struct Point {
		double x;
		double y;
	};

	Point getFigure(PointM* pointsM, int num)
	{
		Point Temp[SIZE];
		Point GetFigure;

		for (int i = 0; i < num; ++i)
		{
			Temp[i].x = pointsM[i].x * pointsM[i].m;
			Temp[i].y = pointsM[i].y * pointsM[i].m;
		}

		for (int j = 1; j <= num; ++j)
		{
			Temp[j].x += Temp[j - 1].x;
			Temp[j].y += Temp[j - 1].y;
			pointsM[j].m += pointsM[j - 1].m;
			if (j == num)
			{
				GetFigure.x = Temp[j - 1].x / pointsM[j - 1].m;
				GetFigure.y = Temp[j - 1].y / pointsM[j - 1].m;
			}
		}

		return GetFigure;
	}

	PointM setFigure(PointM* pointsM, int num) {
		for (int i = 1; i <= num; ++i)
		{
			cout << "������� x , y � ����� (�� ������ 1) " << i << " �����:";
			cout << endl << "x:";
			cin >> pointsM[i - 1].x;
			cout << "y:";
			cin >> pointsM[i - 1].y;
			do {
				cout << "m:";
				cin >> pointsM[i - 1].m;
			} while (pointsM[i - 1].m <= 0);
		}
		return *pointsM;
	}

	double roundR(double number)
	{
		return floor(number * 100) / 100;
	}

	int* BubbleSort(int* numb, int max)
	{
		for (int i = 0; i < max; ++i) {
			bool flag = true;
			for (int j = 0; j < max - 1; ++j) 
			{
				if (numb[j] > numb[j + 1]) 
				{
					flag = false;
					swap(numb[j], numb[j + 1]);
				}
			}
			if (flag)
				break;
		}
		return numb;
	}
	

public:

	void MatrixOut(const char* stringC, bool endLine)
	{
		if (endLine == true)
		{
			for (int i = 0; i < strlen(stringC); ++i)
			{
				if (stringC[i] == '\n' || stringC[i] == '\t' || stringC[i] == ' ')
				{
					cout << stringC[i];
				}
				else
				{
					cout << stringC[i];
					Sleep;
				}
			}
			cout << endl;
		}
		if (endLine == false)
		{
			for (int i = 0; i < strlen(stringC); ++i)
			{
				if (stringC[i] == '\n' || stringC[i] == '\t' || stringC[i] == ' ')
				{
					cout << stringC[i];
				}
				else
				{
					cout << stringC[i];
					Sleep;
				}
			}
		}
	}

	void CenterOfMass()
	{
		PointM pointsM[SIZE];
		Point MassPoint;
		int numb;
		int choices = 1;
		while (choices != 0)
		{
			cls;
			MatrixOut("###The Center of Mass program###\n�������� ���������� ����� � ������: ", false);

			cin >> numb;
			if (numb < SIZE + 1 && numb > 0) {
				cls;
				MatrixOut("###The Center of Mass program###", true);
				setFigure(pointsM, numb);
				cls;

				MatrixOut("###The Center of Mass program###", true);
				for (int i = 0; i < numb; ++i)
				{
					cout << "� " << i + 1 << " ����� x = " << pointsM[i].x << ", y = " << pointsM[i].y << ", m = " << pointsM[i].m << endl;
					Sleep;
				}

				MassPoint = getFigure(pointsM, numb);
				cout << endl << "����� ����� � ������ ��������� ��:\nx = " << roundR(MassPoint.x) << "\ny = " << roundR(MassPoint.y) << endl;
				MatrixOut("�������� �������� (��� ������ 0): ", false);
				cin >> choices;
			}
			else
			{
				cout << "������ �������� ���������� ����� ���� 1 ��� ������ " << SIZE << "!!" << endl;
				MatrixOut("�������� �������� (��� ������ 0): ", false);
				cin >> choices;
			}
			cls;
		}

	}

	void BubbleSorting()
	{
		srand(time(NULL));
		int numbers[SIZEB], tempNum[SIZEB];
		int numb = 1;
		int value, choices;
		while (numb != 0) {
			cls;
			MatrixOut("###Bubble Sort###", true);
			MatrixOut("0 - �����", true);
			MatrixOut("1 - ������ ����", true);
			MatrixOut("2 - ������������", true);
			cin >> numb;
			switch (numb)
			{
			case 1:
				cls;
				MatrixOut("������� ���������� ����� ��� ����������(�� ������ 2000): ", false);
				cin >> value;
				if (!(value >= 2000) && value > 0) {
					cls;
					cout << "������� �����:" << endl;

					for (int j = 0; j < value; ++j) {
						if (j < 10) {
							cout << j + 1 << ")  ";
							cin >> numbers[j];
							tempNum[j] = numbers[j];
						}
						else {
							cout << j + 1 << ") ";
							cin >> numbers[j];
							tempNum[j] = numbers[j];
						}
					}
					cls;

					cout << "\t###Bubble Sort###" << endl;
					cout << "����\t\t\t�����" << endl;
					BubbleSort(numbers, value);

					for (int k = 0; k < value; ++k) {
						cout << tempNum[k] << "\t\t\t" << numbers[k] << endl;
						Sleep;
					}
					cout << endl << "����� ������� �������������!" << endl;
				}
				else
					MatrixOut("�� ����� �� ������� �������!", true);
				break;
			case 2:
				cls;
				MatrixOut("������� ���������� ����� ��� ����������(�� ������ 2000): ", false);
				cin >> value;
				if (!(value >= 2000) && value > 0) {
					for (int i = 0; i < value; ++i) {
						numbers[i] = rand() % 100000;
						tempNum[i] = numbers[i];
					}
					cls;
					cout << endl << "\t###Bubble Sort##" << endl;
					cout << "��������� ����\t\t�����" << endl;
					BubbleSort(numbers, value);
					for (int k = 0; k < value; ++k) {
						cout << tempNum[k] << "\t\t\t" << numbers[k] << endl;
						Sleep;
					}
					cout << endl << "����� ������� �������������!" << endl;
				}
				else
				{
					MatrixOut("�� ����� �� ������� �������!", true);
				}
				break;
			}
			cin >> choices;
			cls;
		}
	}

	void DynamicCheck()
	{
		MyList<int> mass;
		int i = 1;
		while (i != 0) 
		{
			cls;
			MatrixOut("###MyMassive###", true);
			MatrixOut("0-�����", true);
			MatrixOut("1-������� ������", true);
			MatrixOut("2-�������� �������", true);
			MatrixOut("3-������� ������", true);
			MatrixOut("4-������� ������", true);

			cin >> i;

			if (i == 1)
			{
				cls;
				int n, s;
				MatrixOut("������� ���������� ���������: ", false);
				cin >> n;
				for (int j = 0; j < n; ++j)
				{
					cout <<"������� ������� "<< j << ": ";
					cin >> s;
					mass.pushBack(s);
					cout << endl;
				}
			}
			else if (i == 2)
			{
				int change = 1;
				while (change != 0)
				{
					cls;
					MatrixOut("�������� ������� ��� ��������?", true);
					MatrixOut("0-�����\n1-��������\n2-��������", true);
					cin >> change;
					if (change == 1)
					{
						int index = 1, in;
						MatrixOut("������� ������ �������� � �������: ", false);
						cin >> index;
						if (!(index < 0) && !(index >= mass.Capacity()))
						{
							MatrixOut("������� �������: ", false);
							cin >> in;
							mass.SetArray(in, index);
						}
						else
						{
							MatrixOut("����������� ����� ������", true);
							sleep_for(500ms);
						}
					}
					if (change == 2)
					{
						int choice = 0;
						MatrixOut("������ �������� �������� ������ ������� ��� � �����?\n0-�����\n1-������ �������\n2-� ����� �������", true);
						cin >> choice;
						if (choice == 1)
						{
							MatrixOut("������� ��������� ������ ��������?", true);
							int index = 1, dent = 0, numb;
							cin >> numb;
							if (numb > 0)
							{
								if (numb == 1)
								{
									int n;
									MatrixOut("������� ������ � ������� ������ �������� �������: ", false);
									cin >> index;
									if (!(index < 0 && index < mass.Capacity()))
									{
										MatrixOut("������� �������:", false);
										cin >> n;
										mass.pushBetween(n, index);
									}
									else
									{
										MatrixOut("�� ����� �� ������� �������!", false);
										sleep_for(500ms);
									}
								}
								else if (numb >= 1)
								{
									MatrixOut("������� ������ ����� �������� ����� ��������� ��������: ", false);
									cin >> index;
									if (!(index < 0 && index < mass.Capacity()))
									{
										int number = index;
										int* arr = (int*)malloc(numb * sizeof(int));
										MatrixOut("�������� ��������:", true);
										for (int j = 0; j < numb; ++j)
										{
											cout << ++number << ":";
											cin >> arr[j];

										}
										mass.pushBetween(arr, numb, index);
										free(arr);
									}
									else
									{
										MatrixOut("�� ����� �� ������� �������!", false);
										sleep_for(500ms);
									}
								}
								else
								{
									MatrixOut("�� ����� ���������� ��������� ������ ����", true);
									sleep_for(500ms);
								}
							}
							else
							{
								MatrixOut("�� ������� ���������� ��������� ������ ����", true);
								sleep_for(500ms);
							}
						}
						else if (choice == 2)
						{
							int elem = 0;
							MatrixOut("������� ��������� ������ �������� � ����� �������?", true);
							cin >> elem;
							if (elem == 1)
							{
								int n;
								cin >> n;
								mass.pushBack(n);
							}
							else if (elem >= 1)
							{
								MatrixOut("������� ��� ��������, ������� ������ ��������:", true);
								int* arr = (int*)malloc(elem * sizeof(int));
								for (int j = 0; j < elem; ++j)
								{
									cout << j << ":";
									cin >> arr[j];
								}
								free(arr);
								mass.pushBack(arr,elem);
							}
						}
					}
				}
			}
			else if (i == 3)
			{
				cls;
				if (mass.Capacity() != 0)
				{
					mass.deleteArray();
					MatrixOut("������ �����!", true);
					sleep_for(500ms);
				}
				else
				{
					MatrixOut("������ �� ������", true);
					sleep_for(500ms);
				}
			}
			else if (i == 4)
			{
				if (mass.Capacity() != 0)
				{
					cls;
					int stop;
					for (int j = 0; j < mass.Capacity(); ++j)
					{
						cout << j << ": " << mass.GetArray(j) << endl;
					}
					MatrixOut("������ �������!", true);
					cin >> stop;
				}
				else
				{
					MatrixOut("������ �� ������!", true);
					sleep_for(500ms);
				}
			}
		}
		cls;
	}
};
