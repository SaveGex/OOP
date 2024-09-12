#include <iostream>
#include <string>
#include <cstring>


#include "sqlite3.h"

#include "Person.h"
using namespace std;



#pragma region Constructors
Person::Person(uint16_t idet, Name nickname, uint16_t year, uint16_t month, uint16_t day) : id{ idet }, data_of_name(nickname), data_of_date{ year, month, day }{
		cros_counter();
	}



Person::Person() : Person(0, {"", "", ""}, 0, 0, 0) {
		cout << "created zero guy";
	}
#pragma endregion


#pragma region Functions
Name Person::getter_Fname() {
	return data_of_name;
}

uint16_t Person::getter_id() {
	return id;
}

string Person::getter_date() {
	string result = "";
	result += to_string(data_of_date.year) + '.';
	result += to_string(data_of_date.month) + '.';
	result += to_string(data_of_date.day) + '.';
	return result;
}


void Person::setter_name(Name new_name) { data_of_name = new_name; }
//void Person::setter_name() {/*
	//cout << "Name: ";
	/*cin >> data_of_name.name;
	cout << "Surname: ";
	cin >> data_of_name.surname;
	cout << "Middle name: ";
	cin >> data_of_name.middle_name;
}*/

void Person::setter_date() {
	cout << "Year: ";
	cin >> data_of_date.year;
	cout << "Month: ";
	cin >> data_of_date.month;
	cout << "Day: ";
	cin >> data_of_date.day;
}

void Person::print_all() {
	cout << "\nid: " << id << "\nName: " << data_of_name.name << "\nSurname: " << data_of_name.surname << "\nMiddle name: " << data_of_name.middle_name << "\nday: " << data_of_date.day << "\nmonth: " << data_of_date.month << "\nyear: " << data_of_date.year;
}
#pragma endregion


//Person::~Person() {
//
//}




int Person::counter = 0;