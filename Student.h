#include <string>

class Student {
private:
    std::string name;
    std::string surname;
    int age;
    bool active;

public:
    Student(std::string name, std::string surname, int age);
    std::string getName() const;
    std::string getSurname() const;
    int getAge() const;
    bool exist() const;
    void setSurname(std::string value);
    void setName(std::string value);
    void setAge(int value);
    void deactive();
};

