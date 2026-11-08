#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
enum class Department {Therapy, Surgery, Cardiology, Unknown};
enum class PatientState {InQueue, InTreatment, Discharged};
string departmentToString(Department d) {
    switch (d) {
        case Department::Therapy:
            return "Терапия";
        case Department::Surgery:
            return "Хирургия";
        case Department::Cardiology:
            return "Кардиология";
        default:
            return "Неизвестно";
    }
}
string stateToString(PatientState d){
    switch (d){
        case PatientState::InQueue:
            return "В очереди";
        case PatientState::InTreatment:
            return "Лечится";
        case PatientState::Discharged:
            return "Выписан";
        default:
            return "Неизвестно";    
    }
}
class Patient{
private:
    string name;
    int age;
    Department department;
    PatientState state;
public:
    Patient(string name, int age, Department dept){
        this->name = name;
        this->age = age;
        department = dept;
        state = PatientState::InQueue;
    }   
    string getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
    Department getDepartment() const {
        return department;
    }
    PatientState getState() const {
        return state;
    }
    void setAge(int age) {
    if (age > 0) {
        this->age = age;
    } else {
        cout << "Ошибка: возраст должен быть больше 0" << endl;
    }
    }
    void setState(PatientState s) {
    state = s;
    }
    virtual string getDescription() const {
    return "Пациент: " + name +
           ", возраст: " + to_string(age) +
           ", отделение: " + departmentToString(department) +
           ", состояние: " + stateToString(state);
    }
    virtual ~Patient() = default;

};

class ChildPatient : public Patient {
private:
    string parentName;

public:
    
    ChildPatient(string name, int age, Department dept, string parentName)
    : Patient(move(name), age, dept) {
    this->parentName = parentName;
}


   string getDescription() const override {
    return "Ребёнок: " + getName() +
           ", возраст: " + to_string(getAge()) +
           ", отделение: " + departmentToString(getDepartment()) +
           ", состояние: " + stateToString(getState()) +
           ", родитель: " + parentName;
}
};


int main() {
    setlocale(LC_ALL, "Russian");
    Patient p("Иван Петров", 35, Department::Surgery);

    ChildPatient child("Маша Иванова", 8,Department::Therapy, "Ольга Иванова");

    cout << p.getDescription() << endl;
    cout << child.getDescription() << endl;

    p.setState(PatientState::InTreatment);

    cout << p.getDescription() << endl;


}

