#ifndef PERSON_H
#define PERSON_H

#include <cstdint> // для uint16_t
#include <Windows.h>
#include <string>


using namespace std;

#pragma region Data_classes

class Name {
public:
	string name;
	string surname;
	string middle_name;

	// Конструктор з параметрами
	Name(const string& name = "", const string& surname = "", const string& middle_name = "")
		: name(name), surname(surname), middle_name(middle_name) {}

	// Конструктор копіювання
	Name(const Name& other) : name(other.name), surname(other.surname), middle_name(other.middle_name) {}

	// Оператор присвоєння
	Name& operator=(const Name& other) {
		if (this == &other) return *this;
		name = other.name;
		surname = other.surname;
		middle_name = other.middle_name;
		return *this;
	}
};


class Date {
public:
	uint16_t year;
	uint16_t month;
	uint16_t day;
};
#pragma endregion

class Person {
private:
	uint16_t id;
	Name data_of_name;
	Date data_of_date;

	static void cros_counter() {
		counter++;
	}

public:    
	
	static int counter;
	Person(uint16_t idet, Name nickname, uint16_t year, uint16_t month, uint16_t day);
	Person();
	Name getter_Fname();
	uint16_t getter_id();
	string getter_date();
	void setter_name(Name new_name);
	void setter_date();
	void print_all();
	//~Person();
};
#endif