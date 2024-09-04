#pragma once
#include "Student_Class.h"
class Student {
private:
    char name[200];
    vector<vector<int>> date_of_birth;
    short number;
    string city;
    string counrty;
    string name_of_EI;
    string city_and_country_where_located;
    short number_group;
    //int marks[3];
public:
    float get_Aver();
    void setter_marks();
    /*int* getter_marks(int *marks[]);
    void setter_name(char *name[]);
    char* getter_name(char* name[]);*/
};