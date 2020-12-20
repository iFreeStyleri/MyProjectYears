
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
			cout << "Введите x , y и массу (не меньше 1) " << i << " точки:";
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
			MatrixOut("###The Center of Mass program###\nВыберите количество углов у фигуры: ", false);

			cin >> numb;
			if (numb < SIZE + 1 && numb > 0) {
				cls;
				MatrixOut("###The Center of Mass program###", true);
				setFigure(pointsM, numb);
				cls;

				MatrixOut("###The Center of Mass program###", true);
				for (int i = 0; i < numb; ++i)
				{
					cout << "У " << i + 1 << " точки x = " << pointsM[i].x << ", y = " << pointsM[i].y << ", m = " << pointsM[i].m << endl;
					Sleep;
				}

				MassPoint = getFigure(pointsM, numb);
				cout << endl << "Центр массы у фигуры находится на:\nx = " << roundR(MassPoint.x) << "\ny = " << roundR(MassPoint.y) << endl;
				MatrixOut("Выберите действие (для выхода 0): ", false);
				cin >> choices;
			}
			else
			{
				cout << "Нельзя выбирать количество углов ниже 1 или больше " << SIZE << "!!" << endl;
				MatrixOut("Выберите действие (для выхода 0): ", false);
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
			MatrixOut("0 - Выход", true);
			MatrixOut("1 - ручной ввод", true);
			MatrixOut("2 - рандомизатор", true);
			cin >> numb;
			switch (numb)
			{
			case 1:
				cls;
				MatrixOut("Введите количество чисел для сортировки(не больше 2000): ", false);
				cin >> value;
				if (!(value >= 2000) && value > 0) {
					cls;
					cout << "Введите числа:" << endl;

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
					cout << "Ввод\t\t\tВывод" << endl;
					BubbleSort(numbers, value);

					for (int k = 0; k < value; ++k) {
						cout << tempNum[k] << "\t\t\t" << numbers[k] << endl;
						Sleep;
					}
					cout << endl << "Числа успешно отсортированы!" << endl;
				}
				else
					MatrixOut("Вы вышли за границы массива!", true);
				break;
			case 2:
				cls;
				MatrixOut("Введите количество чисел для сортировки(не больше 2000): ", false);
				cin >> value;
				if (!(value >= 2000) && value > 0) {
					for (int i = 0; i < value; ++i) {
						numbers[i] = rand() % 100000;
						tempNum[i] = numbers[i];
					}
					cls;
					cout << endl << "\t###Bubble Sort##" << endl;
					cout << "Случайный ввод\t\tВывод" << endl;
					BubbleSort(numbers, value);
					for (int k = 0; k < value; ++k) {
						cout << tempNum[k] << "\t\t\t" << numbers[k] << endl;
						Sleep;
					}
					cout << endl << "Числа успешно отсортированы!" << endl;
				}
				else
				{
					MatrixOut("Вы вышли за границы массива!", true);
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
			MatrixOut("0-Выход", true);
			MatrixOut("1-Создать массив", true);
			MatrixOut("2-Изменить элемент", true);
			MatrixOut("3-Удалить массив", true);
			MatrixOut("4-Вывести массив", true);

			cin >> i;

			if (i == 1)
			{
				cls;
				int n, s;
				MatrixOut("Введите количество элементов: ", false);
				cin >> n;
				for (int j = 0; j < n; ++j)
				{
					cout <<"Введите элемент "<< j << ": ";
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
					MatrixOut("Изменить элемент или добавить?", true);
					MatrixOut("0-Выйти\n1-Изменить\n2-Добавить", true);
					cin >> change;
					if (change == 1)
					{
						int index = 1, in;
						MatrixOut("Введите индекс элемента в массиве: ", false);
						cin >> index;
						if (!(index < 0) && !(index >= mass.Capacity()))
						{
							MatrixOut("Введите элемент: ", false);
							cin >> in;
							mass.SetArray(in, index);
						}
						else
						{
							MatrixOut("Неправильно введён индекс", true);
							sleep_for(500ms);
						}
					}
					if (change == 2)
					{
						int choice = 0;
						MatrixOut("Хотите добавить элементы внутри массива или в конце?\n0-Выход\n1-Внутрь массива\n2-В конце массива", true);
						cin >> choice;
						if (choice == 1)
						{
							MatrixOut("Сколько элементов хотите добавить?", true);
							int index = 1, dent = 0, numb;
							cin >> numb;
							if (numb > 0)
							{
								if (numb == 1)
								{
									int n;
									MatrixOut("Введите индекс в который хотите добавить элемент: ", false);
									cin >> index;
									if (!(index < 0 && index < mass.Capacity()))
									{
										MatrixOut("Введите элемент:", false);
										cin >> n;
										mass.pushBetween(n, index);
									}
									else
									{
										MatrixOut("Вы вышли за границы массива!", false);
										sleep_for(500ms);
									}
								}
								else if (numb >= 1)
								{
									MatrixOut("Введите индекс после которого будут добавлены элементы: ", false);
									cin >> index;
									if (!(index < 0 && index < mass.Capacity()))
									{
										int number = index;
										int* arr = (int*)malloc(numb * sizeof(int));
										MatrixOut("Добавьте элементы:", true);
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
										MatrixOut("Вы вышли за границы массива!", false);
										sleep_for(500ms);
									}
								}
								else
								{
									MatrixOut("Вы ввели количество элементов меньше нуля", true);
									sleep_for(500ms);
								}
							}
							else
							{
								MatrixOut("Вы выбрали количество элементов меньше нуля", true);
								sleep_for(500ms);
							}
						}
						else if (choice == 2)
						{
							int elem = 0;
							MatrixOut("Сколько элементов хотите добавить в конец массива?", true);
							cin >> elem;
							if (elem == 1)
							{
								int n;
								cin >> n;
								mass.pushBack(n);
							}
							else if (elem >= 1)
							{
								MatrixOut("Введите все элементы, которые хотите добавить:", true);
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
					MatrixOut("Массив удалён!", true);
					sleep_for(500ms);
				}
				else
				{
					MatrixOut("Массив не создан", true);
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
					MatrixOut("Массив выведен!", true);
					cin >> stop;
				}
				else
				{
					MatrixOut("Массив не создан!", true);
					sleep_for(500ms);
				}
			}
		}
		cls;
	}
};
