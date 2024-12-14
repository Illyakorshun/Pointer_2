#include <iostream>
#include <conio.h>
#include <random>

using std::cout;
using std::endl;
using std::cin;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

int main()
{
	int first_arr_size;
	int second_arr_size;

	cout << "Enter the size of first array: ";
	cin >> first_arr_size;
	cout << "Enter the size of second array: ";
	cin >> second_arr_size;

	int* first_arr = new int[first_arr_size];
	int* second_arr = new int[second_arr_size];
	int* third_arr = new int[first_arr_size + second_arr_size];

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 50);

	cout << endl << endl << "Array A:" << endl;
	for (int* ptr = first_arr; ptr < first_arr + first_arr_size; ptr++)
	{
		*ptr = dist(gen);
		cout << *ptr << " ";
	}

	cout << endl << "Array B:" << endl;
	for (int* ptr = second_arr; ptr < second_arr + second_arr_size; ptr++)
	{
		*ptr = dist(gen);
		cout << *ptr << " ";
	}

	cout << endl << endl << "Array C:" << endl;
	int i = 0;

	for (int* ptr3 = third_arr, *ptr1 = first_arr; i < first_arr_size; i++, ptr3++, ptr1++)
	{
		*ptr3 = *ptr1;
		cout << *ptr3 << " ";
	}
	for (int* ptr3 = third_arr + first_arr_size, *ptr2 = second_arr; i < first_arr_size + second_arr_size; i++, ptr3++, ptr2++)
	{
		*ptr3 = *ptr2;
		cout << *ptr3 << " ";
	}

	_getch();

	delete[] first_arr;
	delete[] second_arr;
	delete[] third_arr;

	return 0;
}