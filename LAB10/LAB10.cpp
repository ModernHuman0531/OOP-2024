/*
Write a program that contains three kinds of employees: part-timer, manager, and chairman.
the input file will give us total number of employees, and the input format of(Name Title Years_of_service)  
we need to print out the format like (Name Title Salary)f

Calculation of salary:


*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

// #define DEBUG

using namespace std;

class Employee{
    public:
        Employee(string name, double years_of_service):Name{name},Years_of_service{years_of_service} {}
        virtual void calculate_salary() = 0;
        virtual void print() {
            cout << Name << " " << Years_of_service << " " << Salary << endl;
        }//use this function to print out the format we want
        double Salary_value() const{
            return Salary;
        }

    protected://because the derived class will access these variables
        double Years_of_service,Salary;
        string Name;
};

class Parttimer:public Employee{
    public:
        Parttimer(string name,double years_of_service):Employee(name,years_of_service){}
        void calculate_salary(){
            Salary = 20000 + 1000 * Years_of_service;
        }
};

class Manager:public Employee{
    public:
        Manager(string name,double years_of_service):Employee(name,years_of_service){}
        void calculate_salary(){
            Salary = 20000 + 15000 + 5000 * Years_of_service;
        }
};

class Chairman:public Manager{
    public:
        Chairman(string name,double years_of_service):Manager(name,years_of_service){}
        void calculate_salary(){
            Manager::calculate_salary();
            Salary += 50000;
            }
};


int main(int argc, char **argv){
    string input_file = argv[1];
    ifstream ifs(input_file);
    if(!ifs){
        cout << "File not found" << endl;
    }
    int number_of_employee;
    string Name,Title;
    double Years_of_service;
    ifs >> number_of_employee;
    // vector<Employee*> employees;//must use the pointer because we have different types of employees, vector can be seen as a dynamic array
    Employee **employees = new Employee*[number_of_employee];

    for(int i = 0;i < number_of_employee;++i)
    {
        ifs >> Name >> Title >> Years_of_service;
        #ifdef DEBUG
        cout << Name << " " << Title << " " << Years_of_service << endl;
        #endif
        if(Title == "C"){
            employees[i] = new Chairman(Name,Years_of_service);
        }
        else if(Title == "M"){
            employees[i] = new Manager(Name,Years_of_service);
        }
        else if(Title == "P"){
            employees[i] = new Parttimer(Name,Years_of_service);
        }
        employees[i]->calculate_salary();
    }//store all the information of employees in the vector

    for(int i = 0; i < number_of_employee;++i){
        for(int j = i + 1;j < number_of_employee; ++j){
            if(employees[i] -> Salary_value() < employees[j] -> Salary_value()){
                Employee* temp;
                temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
    for(int i = 0;i < number_of_employee;++i){
        employees[i] -> print();
    }
    // for(const auto& e:employees){
    //     e->print();
    // }
    return 0;

}