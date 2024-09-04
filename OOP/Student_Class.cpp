#include <iostream>
#include <vector>
#include <string>
#include "Student_Class.h"
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


	if ((sizeof(number) / sizeof(number[0])) > 10) {
		ticket = true;
	}
	while (ticket == true) {
		cout << "your input more than 10 symbols or less than 10 symbols!\n write less: ";
		cin >> number;
		if ((sizeof(number) / sizeof(number[0])) == 10) {
			ticket == false;
		}
	};
	number = "+38" + number;
};



Student::Student() {
	void setter_number();
	void setter_name();
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