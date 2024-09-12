#pragma once
#ifndef HOME_T
#define HOME_T

#include <vector>
#include <cstdlib>
#include "TFlat.h"

using namespace std;

class Home{
private: 
	
	vector<vector<Flat>> entrances_array;
	uint8_t floors;
	uint8_t entrances;
	uint8_t number_of_flats_at_floors;

#pragma region private_functions


	int count_recidents_at_entrance(int choose) {

		int counter = 0;
		vector<Flat> buffer_array{entrances_array[choose]};

		for (int i = 0; i < buffer_array.size(); i++) {

			counter += buffer_array[i].getter_residents_number();

		}
		return counter;
	}


	string print_name_residents_at_flat(vector<Person> flat) {

		string result;

		for (int i = 0; i < flat.size(); i++) {
			Person person{ flat[i] };
			result += "\n" + person.getter_Fname().surname + ' ' + person.getter_Fname().name + ' ' + person.getter_Fname().middle_name + "\n";
		}
		return result;
	}


	vector<Flat>choose_entrance() const {

		int choose;

		cout << "\nTo choose from 1 till " << static_cast<int>(entrances) << " which entrance you want to check: \n";
		cin >> choose;


		while (choose < 1 and choose > entrances) {

			cout << "\033[31m\nTo choose from 1 till " << static_cast<int>(entrances) << " which entrance you want to check: \n\033[0m";
			cin >> choose;

		}

		choose -= 1;
	}


	Flat choose_flat(vector<Flat> flats_array) {

		int choose_flat_val;

		cout << "\nTo choose from 1 till " << flats_array.size() << " which flat you want to check: \n";
		cin >> choose_flat_val;

		while (choose_flat_val < 1 and choose_flat_val > flats_array.size() - 1) {

			cout << "\nTo choose from 1 till " << flats_array.size() << " which flat you want to check: \n";
			cin >> choose_flat_val;

		}

		choose_flat_val -= 1;

		Flat flat{ flats_array[choose_flat_val] };

		return flat;
	}



#pragma endregion

public:

	//static uint8_t getter_floors() { return  floors; }
	Home(vector<vector<Flat>> flats, uint8_t floors, uint8_t entrances, uint8_t number_of_flats_at_floors) : entrances_array{ flats }, floors{ floors }, entrances{ entrances }, number_of_flats_at_floors{ number_of_flats_at_floors } {  };

#pragma region functions
	void info_about_home() const {
		cout << "\nFloors of home: " << static_cast<int>(floors)
			<< "\nThe number of house entrances: " << static_cast<int>(entrances)
			<< "\nNumber of flats at floors: " << static_cast<int>(number_of_flats_at_floors)
			<< endl;
	}


	void info_about_entrace() {

		vector<Flat> flats_buffer_array{ choose_entrance()};

		uint8_t position_el_flat_at_entraces_array = static_cast<int>(find(entrances_array.begin(), entrances_array.end(), flats_buffer_array) - entrances_array.begin() + 1);

		cout << "Info about " << static_cast<int>(position_el_flat_at_entraces_array) << " entrance\nAmount flats: " << flats_buffer_array.size() << "\nAmount recidents at this entrance" << count_recidents_at_entrance(static_cast<int>(position_el_flat_at_entraces_array)) << endl;

	}


	void info_about_flat() {

		vector<Flat> flats_buffer_array{ choose_entrance() };
		Flat buffer_flat{ choose_flat(flats_buffer_array) };
		uint8_t position_el_flat_at_entraces_array = static_cast<int>(find(entrances_array.begin(), entrances_array.end(), flats_buffer_array) - entrances_array.begin() + 1);

		
		cout << "The number of flat: " << buffer_flat.getter_number_flat() << "\nAmount residents at flat" << buffer_flat.getter_residents_number() << "\nResidents at that flat: " << print_name_residents_at_flat(buffer_flat.getter_residents_array()) << endl;
		
	}


	void info_about_person() {
		int choose, choose_flat, choose_person;

		cout << "\nTo choose from 1 till " << static_cast<int>(entrances) << " which entrance you want to check: \n";
		cin >> choose;

		while (choose < 1 and choose > static_cast<int>(entrances)) {

			cout << "\nTo choose from 1 till " << static_cast<int>(entrances) << " which entrance you want to check: \n";
			cin >> choose;

		}

		choose -= 1;

		cout << "\nTo choose from 1 till " << entrances_array[choose].size() << " which flat you want to check: \n";
		cin >> choose_flat;

		while (choose_flat < 1 and choose_flat > entrances_array[choose].size() - 1) {

			cout << "\nTo choose from 1 till " << entrances_array[choose].size() << " which flat you want to check: \n";
			cin >> choose_flat;

		}

		choose_flat -= 1;

		cout << "\nTo choose from 1 till " << entrances_array[choose][choose_flat].getter_residents_array().size() << " which person you want to check: \n";
		cin >> choose_person;

		while (choose_person < 1 and choose_person > entrances_array[choose][choose_flat].getter_residents_array().size() - 1) {

			cout << "\nTo choose from 1 till " << entrances_array[choose][choose_flat].getter_residents_array().size() << " which person you want to check: \n";
			cin >> choose_person;

		}

		choose_person -= 1;
		cout << '\n' << entrances_array[choose][choose_flat].getter_residents_array()[choose_person].getter_Fname().surname << ' ' << entrances_array[choose][choose_flat].getter_residents_array()[choose_person].getter_Fname().name << ' ' << entrances_array[choose][choose_flat].getter_residents_array()[choose_person].getter_Fname().middle_name << endl;

	}
#pragma endregion
};

#endif // HOME_T