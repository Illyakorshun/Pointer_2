#include <iostream>
#include <conio.h>
#include <random>

using std::cout;
using std::endl;
using std::cin;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

bool _presence(int* arr, int arr_size, int value) {
	for (int i = 0; i < arr_size; ++i) {
		if (arr[i] == value) {
			return true;
		}
	}

	return false;
}

int main()
{
	int first_arr_size;
	int second_arr_size;

	int i = 0;

	cout << "Enter the size of first array: ";
	cin >> first_arr_size;
	cout << "Enter the size of second array: ";
	cin >> second_arr_size;

	int* first_arr = new int[first_arr_size];
	int* second_arr = new int[second_arr_size];
	int* third_arr = new int[first_arr_size + second_arr_size] {};

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

	cout << endl << endl << "Array C:";
	for (int* ptr = first_arr; ptr < first_arr + first_arr_size; ptr++)
	{
		if (!_presence(second_arr, second_arr_size, *ptr) && !_presence(third_arr, i, *ptr))
		{
			third_arr[i++] = *ptr;
		}
	}
	for (int* ptr = second_arr; ptr < second_arr + second_arr_size; ptr++)
	{
		if (!_presence(first_arr, first_arr_size, *ptr) && !_presence(third_arr, i, *ptr))
		{
			third_arr[i++] = *ptr;
		}
	}

	if (i > 0)
	{
		cout << endl;
		for (int* ptr = third_arr; ptr < third_arr + i; ptr++)
		{
			cout << *ptr << " ";
		}
		cout << endl;
	}
	else
	{
		cout << " empty" << endl;
	}

	_getch();

	delete[] first_arr;
	delete[] second_arr;
	delete[] third_arr;

	return 0;
}