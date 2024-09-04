#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include "Student.h"
using namespace std;

void Student::setter_name() {
	cout << "Write your name: ";
	cin >> name;
	cout << name;
};

void Student::setter_number() {
	bool ticket = false;

	cout << "Write your number:";
	cin >> number;

	if (strlen(number) != 10) {
		ticket = true;
	}
	while (ticket == true) {
		cout << number;
		cout << (sizeof(number) / sizeof(number[0]));
		cout << "your input more than 10 symbols or less than 10 symbols!\n write less: ";
		cin >> number;
		if ((sizeof(number) / sizeof(number[0])) == 10) {
			ticket == false;
		}
	};
	char uk[15] = "+38";
	strcat_s(uk, number);
	strcpy_s(number, uk);
	cout << endl;
};


void Student::setter_date_of_birth() {
	vector<int> date;
	short day, month, year;

	cout << "write day: ";
	cin >> day;
	cout << "write month: ";
	cin >> month;
	cout << "write year: ";
	cin >> year;
	date.push_back(day);
	date.push_back(month);
	date.push_back(year);

	dates_of_birth.push_back(date);
}

void Student::setter_city(){
	cout << "Write student city: ";
	cin >> city;
}

void Student::setter_country(){
	cout << "Write student country: ";
	cin >> country;
}
void Student::setter_name_of_EI(){
	cout << "write name edcation institution: ";
	cin >> name_of_EI;
}
void Student::setter_city_and_country_where_located(){
	cout << "Write city and country at one row where student is are: ";
	cin >> city_and_country_where_located;
}
void Student::setter_number_group(){
	cout << "Write number group: ";
	cin >> number_group;
};


const char* Student::getter_name() {
	return name;
}
const char* Student::getter_number() {
	return number;
}
vector<vector<int>> Student::getter_date_of_birth() {
	return dates_of_birth;
}
string Student::getter_city() {
	return city;
}
string Student::getter_name_of_EI() {
	return name_of_EI;
}
string Student::getter_country(){
	return country;
}
string Student::getter_city_and_country_where_located(){
	return city_and_country_where_located;
}
short Student::getter_number_group(){
	return number_group;
}



Student::Student() {
	setter_number();
	setter_name();
	setter_date_of_birth();
	setter_city();
	setter_country();
	setter_name_of_EI();
	setter_city_and_country_where_located();

	cout << getter_name() << '\n';
	cout << getter_number() << '\n';
	cout << getter_city() << '\n';
	cout << getter_country() << '\n';
	cout << getter_name_of_EI() << '\n';
	cout << getter_city_and_country_where_located() << '\n';
	cout << getter_number_group() << '\n';
}
//float Student::get_Aver() {
//    float result = 0;
//    for (int i = 0; i < sizeof(marks) / sizeof(marks[0]); i++) {
//        result = result + marks[i];
//    }
//    result = result / (sizeof(marks) / sizeof(marks[0]));
//    return result;
//}
//
//
//
//
//void Student::setter_marks() {
//    marks[0] = 1;
//    marks[1] = 2;
//    marks[2] = 3;
//
//
//
//    for (int i = 0; i < (sizeof(marks) / sizeof(marks[0])); i++) {
//        cout << "id: " << i << "element: " << marks[i] << endl;
//    }
//    
//    short max_number = sizeof(marks) / sizeof(marks[0]);
//
//    while (true) {
//        int change, index;
//        //string value;
//        short value;
//
//        cout << "Element index: ";
//        cin >> index;
//        
//        if (index > max_number) {
//            cout << "You wrote index which highest than size of array";
//            cout << "Write index from " << 0 << "to " << max_number;
//            while (index > max_number or index < 0) {
//                cout << "index: ";
//                cin >> index;
//            }
//        }
//
//        cout << "write here value: ";
//        cin >> value;
//
//        marks[index] = value;
//
//        cout << "You want to change other elements?\n [1] Yes, [2] Not";
//        cin >> change;
//        if (change != 1) {
//            break;
//        }
//    }
//}