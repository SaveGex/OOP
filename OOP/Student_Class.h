#pragma once
#include <vector>
#include <string>

class Student {
private:
    char name[200];
    std::vector<std::vector<int>> date_of_birth;
    std::string number;
    std::string city;
    std::string country;
    std::string name_of_EI;
    std::string city_and_country_where_located;
    short number_group;
    // int marks[3];

public:
    void setter_name();
    void setter_number();

    Student();
};
