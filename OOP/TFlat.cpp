#include "TFlat.h"

bool Flat::operator==(const Flat& other) const {
	return this->number_flat == other.number_flat;
}

Flat::Flat(vector<Person> residents, uint8_t number_of_residents, uint16_t number_flat) : residents{ residents }, number_of_residents{ number_of_residents }, number_flat{ number_flat } {}
Flat::Flat() : Flat({}, 0, 0) {};