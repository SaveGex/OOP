#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>
#include <vector>

#include "SQLite.h"
#include "Person.h"

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(static_cast<int>(time(nullptr)));
	vector<Person> people{ create_DB() };
	for (auto obj : people) {
		cout << obj.getter_Fname().name << endl;
	}
	return 0;
}