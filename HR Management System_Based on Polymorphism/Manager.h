#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Employee.h"

class Manager : public Employee {
public: //need the public key words, otherwise won't be able to access it, it's default as private 
	Manager(int id, string name, int d_id);
	virtual void showInfo();

	virtual string getDeptName();
};

