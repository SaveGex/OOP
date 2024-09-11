#include <iostream>
#include <Windows.h>
#include <ctime>
#include <string>
#include <vector>
#include <cstring>

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


	static void cros_counter() {
		counter++;
	}
public:
	static int counter;

	Person(uint16_t idet, const char* surname, const char* name, const char* middle_name, uint16_t year, uint16_t month, uint16_t day)
		: id{ idet }, data_of_date{ year, month, day }
	{
		// Виділяємо пам'ять для кожного рядка
		data_of_name.name = new char[strlen(name) + 1];
		data_of_name.surname = new char[strlen(surname) + 1];
		data_of_name.middle_name = new char[strlen(middle_name) + 1];

		// Копіюємо рядки
		strcpy_s(data_of_name.name, strlen(name) + 1, name);
		strcpy_s(data_of_name.surname, strlen(surname) + 1, surname);
		strcpy_s(data_of_name.middle_name, strlen(middle_name) + 1, middle_name);

		cros_counter();  // Припустимо, що це якась функція
	}

	Person() : Person(0, nullptr, nullptr, nullptr, 0, 0, 0) {
		cout << "created zero guy";
	}
	
	Name getter_Fname() {
		return data_of_name;
	}

	uint16_t getter_id() {
		return id;
	}

	string getter_date() {
		string result = "";
		result += to_string(data_of_date.year) + '.';
		result += to_string(data_of_date.month) + '.';
		result += to_string(data_of_date.day) + '.';
		return result;
	}
	
	void setter_name() {
		cout << "Name: ";
		cin >> data_of_name.name;
		cout << "Surname: ";
		cin >> data_of_name.surname;
		cout << "Middle name: ";
		cin >> data_of_name.middle_name;
	}

	void setter_date() {
		cout << "Year: ";
		cin >> data_of_date.year;
		cout << "Month: ";
		cin >> data_of_date.month;
		cout << "Day: ";
		cin >> data_of_date.day;
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

int Person::counter = 0;

int main() {
	char* surname = new char[sizeof("surname") / sizeof(char)+1];
	char* name = new char[sizeof("name") / sizeof(char)+1];
	char* middle_name = new char[sizeof("middle_name") / sizeof(char)+1];

	strcpy_s(surname, sizeof("surname") / sizeof(char) + 1, "surname");
	strcpy_s(name, sizeof("name") / sizeof(char) + 1, "name");
	strcpy_s(middle_name, sizeof("middle_name") / sizeof(char) + 1, "middle_name");

	
	Person obj{ 1, "surname", "name", "middle_name", 2024, 9, 9 };

	obj.output();

	bool ticket = true;

	while (ticket) {
		uint16_t choose;
		cout << "Do you want to get \n[1] full name\n[2] full date(year.month.day) \n[3] id";
		cin >> choose;
		switch (choose) {
		case 1: cout << "Name: " << obj.getter_Fname().name << "\nSurname: " << obj.getter_Fname().surname << "\nMiddle name: " << obj.getter_Fname().middle_name << endl; break;
		case 2: cout << "yyyy.mm.dd\n" << obj.getter_date() << endl; break;
		case 3: cout << obj.getter_id() << endl; break;
		default: ticket = false;
		}
	}
	ticket = true;
	while (ticket) {
		uint16_t choose;
		cout << "Do you want to change \n[1] full name\n[2] full date(year.month.day)";
		cin >> choose;
		switch (choose) {
		case 1: obj.setter_name(); break;
		case 2: obj.setter_date(); break;
		default: ticket = false;
		}
	}
	Person obj2{ 1, surname, name, middle_name, 2024, 9, 9 };
	Person obj3{ 1, surname, name, middle_name, 2024, 9, 9 };

	
	cout << Person::counter;

	return 0;
}