#pragma once
#ifndef TFLAT_T
#define TFLAT_T

#include <vector>
#include <cstdlib>
#include "Person.h"

class Flat {
private:
	uint16_t number_flat;
	vector<Person> residents;
	uint8_t number_of_residents;

	static uint8_t number_of_flat;
	static void cros_number_flat() { number_of_flat++; }
public:

	// Оператор порівняння == . Seem i already said... I don't know how to write operators equals
	bool operator==(const Flat& other) const {
		return number_flat == other.number_flat &&
			number_of_residents == other.number_of_residents &&
			residents == other.residents;
	}


	static uint8_t getter_number_of_flat() { return  number_of_flat; }
	Flat(vector<Person> residents, uint8_t number_of_residents, uint16_t number_flat) : residents{ residents }, number_of_residents{ number_of_residents }, number_flat{ number_flat } {};
	Flat() : Flat({}, 0, 0) {};
	uint8_t getter_residents_number() {
		return number_of_residents;
	}
	vector<Person> getter_residents_array() {
		return residents;
	}
	uint16_t getter_number_flat() {
		return number_flat;
	}
};
#endif // !TFLAT_T
