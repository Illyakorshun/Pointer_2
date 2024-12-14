#include <iostream>
#include <conio.h>
#include <random>

using std::cout;
using std::endl;
using std::cin;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

int* arr_size = new int{};
int* arr = nullptr;

void _delete(int index)
{
	for (int i = index; i < *arr_size - 1; i++)
	{
		arr[i] = arr[i + 1];
	}

	(*arr_size)--;
}

int main()
{
	int selected;

	cout << "Enter the size of array: ";
	cin >> *arr_size;

	do {
		cout << endl
			<< "Select an option:" << endl
			<< "1. Delete even numbers" << endl
			<< "2. Delete odd numbers" << endl
			<< "Selected: ";
		cin >> selected;
	} while (selected > 2 || selected < 1);

	arr = new int[*arr_size];

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 50);

	cout << endl << endl << "Array:" << endl;
	for (int* ptr = arr; ptr < arr + *arr_size; ptr++)
	{
		*ptr = dist(gen);
		cout << *ptr << " ";
	}
	cout << endl;

	for (int j = 0; j < *arr_size; j++)
	{
		if ((selected == 1 && arr[j] % 2 == 0) || (selected == 2 && arr[j] % 2 != 0))
		{
			_delete(j);
			j--;
		}
	}

	cout << "Result:" << endl;
	for (int* ptr = arr; ptr < arr + *arr_size; ptr++)
	{
		cout << *ptr << " ";
	}
	cout << endl;

	_getch();

	delete[] arr;
	delete arr_size;

	return 0;
}