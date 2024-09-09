#include <iostream>
#include <vector>
#include <Windows.h>
#include <ctime>
#include <vector>

using namespace std;

struct Name {
	char* name;
	char* surname;
	char* middle_name;
};

struct Date {
	uint16_t year;
	uint16_t month;
	uint16_t day;
};


class Person {
private:
	uint16_t id;
	Name data_of_name;
	Date data_of_date;
public:
	Person(uint16_t idet, char* surname, char* name, char* middle_name, uint16_t year, uint16_t month, uint16_t day) : id{ idet }, data_of_name{ name, surname, middle_name }, data_of_date{ year, month, day } {}

	Person() : Person(0, nullptr, nullptr, nullptr, 0, 0, 0) {
		cout << "created zero guy";
	}
	
	~Person() {
		delete[] data_of_name.name;
		delete[] data_of_name.surname;
		delete[] data_of_name.middle_name;
	}

	void output() {
		cout << "\nid: " << id <<"\nName: "<< data_of_name.name << "\nSurname: "<< data_of_name.surname <<"\nMiddle name: "<< data_of_name.middle_name <<"\nday: "<< data_of_date.day <<"\nmonth: "<< data_of_date.month << "\nyear: " << data_of_date.year;
	}
};

int main() {
	char* surname = new char[sizeof("surname") / sizeof(char)+1];
	char* name = new char[sizeof("name") / sizeof(char)+1];
	char* middle_name = new char[sizeof("middle_name") / sizeof(char)+1];

	strcpy_s(surname, sizeof("surname") / sizeof(char) + 1, "surname");
	
	Person obj{1, surname, name, middle_name, 2024, 9, 9};

	obj.output();


	return 0;
}