#include <iostream>
#include "Home.h"

using namespace std;

int Home::count_recidents_at_entrance(int choose) {

	int counter = 0;
	vector<Flat> buffer_array{ entrances_array[choose] };

	for (int i = 0; i < buffer_array.size(); i++) {

		counter += buffer_array[i].getter_residents_number();

	}
	return counter;
}

string Home::print_name_residents_at_flat(vector<Person> flat) {

	string result;

	for (int i = 0; i < flat.size(); i++) {
		Person person{ flat[i] };
		result += "\n" + person.getter_Fname().surname + ' ' + person.getter_Fname().name + ' ' + person.getter_Fname().middle_name + "\n";
	}
	return result;
}

vector<Flat> Home::choose_entrance() {

	int choose;
	//doesn't working
	do {
		cout << "\nTo choose from 1 to " << static_cast<int>(entrances) << " which entrance you want to check: \n";
		cin >> choose;

	} while (choose > entrances || choose < 1);

	choose -= 1;

	return entrances_array[choose];
}

Flat Home::choose_flat(vector<Flat> flats_array) {

	int choose_flat_val;

	do {
		cout << "\nTo choose from 1 to " << flats_array.size() << " which flat you want to check: \n";
		cin >> choose_flat_val;

	} while (choose_flat_val > flats_array.size() || choose_flat_val < 1);

	choose_flat_val -= 1;

	Flat flat{ flats_array[choose_flat_val] };

	return flat;
}

Person Home::choose_person(Flat buffer_flat) {

	int choose_person;

	do {
		cout << "\nTo choose from 1 to " << buffer_flat.getter_residents_array().size() << " which flat you want to check: \n";
		cin >> choose_person;

	} while (choose_person > buffer_flat.getter_residents_array().size() || choose_person < 1);

	choose_person -= 1;
	Person person{ buffer_flat.getter_residents_array()[choose_person] };

	return person;
}

Home::Home(Home&& obj) noexcept{
	if (this != &obj) {
		this->entrances_array = obj.entrances_array;
		this->floors = obj.floors;
		this->entrances = obj.entrances;
		this->number_of_flats_at_floors = obj.number_of_flats_at_floors;

		obj.entrances_array = {};
		obj.floors = 0;
		obj.entrances = 0;
		obj.number_of_flats_at_floors = 0;
	}
}

Home& Home::operator=(Home&& obj) noexcept{
	if (this != &obj) {
		this->entrances_array = obj.entrances_array;
		this->floors = obj.floors;
		this->entrances = obj.entrances;
		this->number_of_flats_at_floors = obj.number_of_flats_at_floors;

		obj.entrances_array = {};
		obj.floors = 0;
		obj.entrances = 0;
		obj.number_of_flats_at_floors = 0;
	}

	return *this;
}

void Home::info_about_home() const {
	cout << "\nFloors of home: " << static_cast<int>(floors)
		<< "\nThe number of house entrances: " << static_cast<int>(entrances)
		<< "\nNumber of flats at floors: " << static_cast<int>(number_of_flats_at_floors)
		<< endl;
}

void Home::info_about_entrace() {

	vector<Flat> flats_buffer_array{ choose_entrance() };
	uint8_t position_el_flat_at_entraces_array = find(entrances_array.begin(), entrances_array.end(), flats_buffer_array) - entrances_array.begin();

	cout << "Info about " << static_cast<int>(position_el_flat_at_entraces_array) + 1 << " entrance\nAmount flats: " << flats_buffer_array.size() << "\nAmount recidents at this entrance: " << count_recidents_at_entrance(static_cast<int>(position_el_flat_at_entraces_array)) << endl;

}

void Home::info_about_flat() {

	vector<Flat> flats_buffer_array{ choose_entrance() };
	Flat buffer_flat{ choose_flat(flats_buffer_array) };
	uint8_t position_el_flat_at_entraces_array = static_cast<int>(find(entrances_array.begin(), entrances_array.end(), flats_buffer_array) - entrances_array.begin() + 1);


	cout << "The number of flat: " << buffer_flat.getter_number_flat() << "\nAmount residents at flat" << buffer_flat.getter_residents_number() << "\nResidents at that flat: " << print_name_residents_at_flat(buffer_flat.getter_residents_array()) << endl;

}

void Home::info_about_person() {

	vector<Flat> flats_buffer_array{ choose_entrance() };
	Flat buffer_flat{ choose_flat(flats_buffer_array) };
	Person buffer_person{ choose_person(buffer_flat) };

	cout << '\n' << buffer_person.getter_Fname().surname << ' ' << buffer_person.getter_Fname().name << ' ' << buffer_person.getter_Fname().middle_name << "\nAge: " << static_cast<int>(buffer_person.generete_age_for_person()) << endl;

}