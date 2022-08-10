#pragma once
#include <iostream>
#include <string>
using namespace std;
//There is 3 types of Employee in the company: 1. Director; 2.Manager;3.Staff
class Employee {
public:
	//show personal info
	virtual void showInfo() = 0;
	//show the name of the department 
	virtual string getDeptName() = 0;
	//employee_id
	int e_id;
	string e_name;
	//department_id
	int d_id;

};