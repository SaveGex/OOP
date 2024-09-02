#include <iostream>
#include <vector>
#include <Windows.h>
#include <ctime>
using namespace std;


class Student {
    public:
        char name[20];
        int marks[3];
        float get_Aver() {
            float result = 0;
            for (int i = 0; i < sizeof(marks) / sizeof(marks[0]); i++) {
                result = result + marks[i];
            }
            result = result / (sizeof(marks) / sizeof(marks[0]));
            return result;
        }
};

int main(){
    srand(time(nullptr));

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Student asd;
    
    for (int i = 0; i < sizeof(asd.marks) / sizeof(asd.marks[0]); i++) {
        asd.marks[i] = 0 + rand() % (0 - 12 - 1);
    }

    
    cout << "middle marks: " << asd.get_Aver();
}