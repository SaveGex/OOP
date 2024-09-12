#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <cstdlib>

#include "SQLite.h"
#include "Person.h"
#include "sqlite3.h"

using namespace std;

const int8_t ERROR_OPEN_DB = -1;
const int8_t ERROR_PREPARE_STMT = -2;
const int8_t ERROR_EXECUTE_STMT = -3;
const int8_t ERROR_CREAETE_DB = -4;
const int8_t ERROR_BIND_TEXT = -5;


vector<Person> create_DB() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    srand(static_cast<int>(time(nullptr)));

    sqlite3* DB;
    sqlite3_stmt* stmt;
    int errors;
    vector<Person> people;

    errors = sqlite3_open("SQLite.db", &DB);
    if (errors) {
        cerr << "Failed to open DB" << endl;
        return people;
    }

    const char* sql = "SELECT Surname, Name, Middle_Name FROM People;";

    sqlite3_prepare_v2(DB, sql, -1, &stmt, 0);

    uint16_t id = 1;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int year = 1970 + rand() % 40;
        int month = 1 + rand() % 12;
        int day = 1 + rand() % 31;

        string surname = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        string middle_name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));

        Name nickname(name, surname, middle_name);
        Person obj(id, nickname, year, month, day);
        people.push_back(obj);
        id++;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(DB);

    return people;
}