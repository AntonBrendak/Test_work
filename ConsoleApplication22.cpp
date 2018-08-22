// ConsoleApplication21.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <map>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void Auto_write(vector<int>& array, int);
void Auto_write(map <int, int>& array, int);


void Delete(vector<int>& array);
void Delete(map <int, int>& array);

void Synhr(vector<int>& arr1, map <int, int>& arr2);

int main()
{
	map <int, int> first;
	vector <int> second;
	srand(time(NULL));

	Auto_write(second, 20);
	Auto_write(first, 20);
	for (auto mi = first.cbegin(); mi != first.cend(); mi++)
		cout << mi->second << " ";
	cout << endl;
	for (int i = 0; i < second.size(); i++)
		cout << second[i] << " ";
	cout << endl << endl;
	Delete(first);
	Delete(second);
	for (auto mi = first.cbegin(); mi != first.cend(); mi++)
		cout << mi->second << " ";
	cout << endl;
	for (int i = 0; i < second.size(); i++)
		cout << second[i] << " ";
	cout << endl << endl;
	Synhr(second, first);
	for (auto mi = first.cbegin(); mi != first.cend(); mi++)
		cout << mi->second << " ";
	cout << endl;
	for (int i = 0; i < second.size(); i++)
		cout << second[i] << " ";
	cout << endl << endl;
	system("PAUSE");
	return 0;
}
//-------------------------------------------------------WRITE-------------------------------------
void Auto_write(vector <int>& array, int iter) {
	for (; iter > 0; iter--) {
		array.push_back(rand() % 10);
	}
}

void Auto_write(map <int, int>& array, int iter) {
	for (; iter > 0; iter--) {
		array.insert(pair< int, int>(iter, rand() % 10));
	}
}
//---------------------------------------------------------DELETE------------------------------

void Delete(vector<int>& array) {
	int count = rand() % 15;
	for (;count > 0; count--)
		array.erase(array.begin());
}
void Delete(map <int, int>& array) {
	int count = rand() % 15;
	for (auto it = array.cbegin(); it != array.cend(); )
		if (count > 0) {
			array.erase(it++);
			count--;
		}
		else ++it;
}
//------------------------------------------------------Synhronization---------------------

void Synhr(vector<int>& vec, map <int, int>& m) {
	vector <int> map;
	for (auto mi = m.cbegin(); mi != m.cend(); ) {
		if (find(vec.begin(), vec.end(), mi->second) == vec.end())
			m.erase(mi++->first);
		else ++mi;
	}
	for (auto mi = m.cbegin(); mi != m.cend(); )
		map.push_back(mi++->second);
	for (int i = 0; i < vec.size(); i++)
		if (find(map.begin(), map.end(), vec[i]) == map.end())
			vec.erase(vec.begin() + i);
}