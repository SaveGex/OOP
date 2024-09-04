#pragma once
#include <vector>
#include <string>

class Student {
private:
    char name[200];
    std::vector<std::vector<int>> dates_of_birth;
    char number[100];
    std::string city;
    std::string country;
    std::string name_of_EI;
    std::string city_and_country_where_located;
    short number_group;
    // int marks[3];

public:
    void setter_name();
    void setter_number();
    void setter_date_of_birth();
    void setter_city();
    void setter_country();
    void setter_name_of_EI();
    void setter_city_and_country_where_located();
    void setter_number_group();

    const char* getter_name();
    const char* getter_number();
    std::vector<std::vector<int>> getter_date_of_birth();
    std::string getter_city();
    std::string getter_country();
    std::string getter_name_of_EI();
    std::string getter_city_and_country_where_located();
    short getter_number_group();
    Student();
};
