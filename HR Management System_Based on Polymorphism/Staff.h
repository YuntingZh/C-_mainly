#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Employee.h"

 class Staff : public Employee {
 public: //need the public key words, otherwise won't be able to access it, it's default as private 
	Staff(int id, string name, int d_id);
	virtual void showInfo() ;

	virtual string getDeptName();
};
