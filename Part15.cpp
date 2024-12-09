#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Student.h"

using namespace std;

struct User
{
    string username;
    int password;
};

void printStudent(const vector<Student>& db);
void addStudent(vector<Student>& db);
void editStudent(vector<Student>& db);
void deleteStudent(vector<Student>& db);

int main() {
    string line;
    User usinfo;

    ifstream file("/Users/telia/Downloads/cpp/date.txt");

    vector<Student> db;

    while (getline(file, line))
    {
        string name, surname;
        int age;
        
        istringstream iss(line);
        iss >> name >> surname >> age;
        
        Student student(name, surname, age);

        db.push_back(student);
    }
    file.close();

    cout << "Username: ";
    cin >> usinfo.username;
    cout << "Password: ";
    cin >> usinfo.password;

    if (usinfo.username == "Admin" && usinfo.password == 123)
    {
        while (true)
        {
            int user;
            cout << "1. Add" << endl << "2. Edit" << endl << "3. Show" << endl << "4. Delete" << endl << "5.None" << endl;
            cin >> user;

            if (user == 1) {addStudent(db);}
            else if (user == 2) {editStudent(db);}
            else if (user == 3) {printStudent(db);}
            else if (user == 4) {deleteStudent(db);}
            else if (user == 5) {break;}

            ofstream outFile("/Users/telia/Downloads/cpp/date.txt");
            for (const Student& student : db) {
                if (student.exist()) {
                    outFile << student.getName() << " " << student.getSurname() << " " << student.getAge() << endl;
                }
            }
            outFile.close();
        }
       
    }
    else if (usinfo.username == "Guess" && usinfo.password == 123)
    {
        int user;
        cout << "1. Show" << endl;
        cin >> user;
        if (user == 1)
        {
            printStudent(db);
        }
    }
    
    else
    {
        cout << "Username or password is worng " << endl;
    }

    return 0;
}

void editStudent(vector<Student>& db) {
    string search;
    cout << "Surname: ";
    cin >> search;

    for (int i = 0; i < db.size(); i++) {
        if (db[i].getSurname() == search && db[i].exist()) {
            string newName;
            string newSurname;
            int newAge;

            cout << "Name: ";
            cin >> newName;
            cout << "Surname: ";
            cin >> newSurname;
            cout << "Age: ";
            cin >> newAge;

            db[i].setSurname(newSurname);
            db[i].setName(newName);
            db[i].setAge(newAge);
            cout << "Student updated successfully!" << endl;
            return;
        }
    }
    cout << "Student not found!" << endl;
}

void deleteStudent(vector<Student>& db) {
    string search;
    cout << "Surname: ";
    cin >> search;

    for (int i = 0; i < db.size(); i++) {
        if (db[i].getSurname() == search && db[i].exist()) {
            db[i].deactive();
            cout << "Student deactivated successfully!" << endl;
            return;
        }
    }
    cout << "Student not found!" << endl; 
}

void addStudent(vector<Student>& db) {
    string name, surname;
    int age;

    cout << "Name: ";
    cin >> name;
    cout << "Surname: ";
    cin >> surname;
    cout << "Age: ";
    cin >> age;

    Student student(name, surname, age);
    db.push_back(student);
    cout << "Student added successfully!" << endl;
}

void printStudent(const vector<Student>& db) {
    cout << "Students List:" << endl;
    for (const Student& student : db)
    {
        if (student.exist())
        {
            cout << "Name: " << student.getName() << ", Surname: " << student.getSurname() << ", Age: " << student.getAge() << endl;
        }
    }
}
