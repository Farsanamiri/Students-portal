#include "Student.h"

Student::Student(std::string name, std::string surname, int age)
{
    this->name = name;
    this->surname = surname;
    this->age = age;
    this->active = true;
}

int Student::getAge() const
{
    return this->age;
}

std::string Student::getName() const
{
    return this->name;
}

std::string Student::getSurname() const
{
    return this->surname;
}

void Student::setSurname(std::string value)
{
    this->surname = value;
}

void Student::setName(std::string value)
{
    this->name = value;
}

void Student::setAge(int value)
{
    this->age = value;
}

bool Student::exist() const
{
    return this->active;
}

void Student::deactive()
{
    this->active = false; 
}
