#pragma once
#ifndef HOME_T
#define HOME_T

#include <vector>
#include <cstdlib>
#include "TFlat.h"

using namespace std;

class Home {
private:

	vector<vector<Flat>> entrances_array;
	uint8_t floors;
	uint8_t entrances;
	uint8_t number_of_flats_at_floors;

#pragma region private_functions
	int count_recidents_at_entrance(int choose);
	string print_name_residents_at_flat(vector<Person> flat);
	vector<Flat>choose_entrance();
	Flat choose_flat(vector<Flat> flats_array);
	Person choose_person(Flat buffer_flat);
#pragma endregion

public:

	//static uint8_t getter_floors() { return  floors; }
	Home(vector<vector<Flat>> flats, uint8_t floors, uint8_t entrances, uint8_t number_of_flats_at_floors) : entrances_array{ flats }, floors{ floors }, entrances{ entrances }, number_of_flats_at_floors{ number_of_flats_at_floors } {  };
	Home(Home&& obj) noexcept;
	Home& operator=(Home&& obj) noexcept;

#pragma region functions
	void info_about_home() const;
	void info_about_entrace();
	void info_about_flat();
	void info_about_person();
#pragma endregion
};

#endif // HOME_T