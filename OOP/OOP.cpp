#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>
#include <vector>

#include "SQLite.h"
#include "Person.h"
#include "TFlat.h"
#include "Home.h"

using namespace std;

int Person::counter = 0;


int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	srand(static_cast<int>(time(nullptr)));

	uint8_t floors = 2;
	uint8_t entrances = 5;
	uint8_t number_of_flats_at_floors = 3;
	uint8_t number_of_residents;
	uint8_t free_people = 0;
	uint8_t counter_for_free_people = 0;

	vector<Person> people{ create_DB() };
	vector<Flat> flats;
	vector<vector<Flat>> entrances_array;
	uint16_t index = 0, index_flat = 1;

	for (uint16_t a = 0; a < entrances; a++) {

		for (uint16_t s = 0; s < floors; s++) {

			for (uint8_t d = 0; d < number_of_flats_at_floors; d++) {

				number_of_residents = rand() % 5;
				counter_for_free_people += number_of_residents;

				vector <Person> residents;

				for (uint8_t a = 0; a < number_of_residents; a++) {

					residents.push_back(people[index]);
					index++;
				}

				
				flats.push_back(Flat(residents, residents.size(), static_cast<size_t>(index_flat)));
				index_flat++;
			}
		}

		entrances_array.push_back(flats);
	}

	Home native_home{ entrances_array, floors, entrances, number_of_flats_at_floors };


	while (true) {
		int choose;
		cout << "Write number if you want to \nInfo about home[1]\nInfo about entrances[2]\nInfo about flat[3]\nInfo about person[4]\n";
		cin >> choose;
		switch (choose) {
		case 1: native_home.info_about_home(); break;
		case 2: native_home.info_about_entrace(); break;
		case 3: native_home.info_about_flat(); break;
		case 4: native_home.info_about_person(); break;
		default: cout << "free people: " << people.size() - counter_for_free_people; return 1;
		}
	}

	return 0;
}