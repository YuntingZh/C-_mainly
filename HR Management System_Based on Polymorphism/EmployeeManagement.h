#pragma once //current source file to be included only once in a single compilation
#include <iostream>
#include <string>
using namespace std;
#include "Employee.h"
#include "Staff.h"
#include "Employee.h"
#include "Director.h"
#include "Manager.h"
#include <fstream>
#define FILENAME "hrmsFile.txt"

class EmployeeManagement {
public:
	EmployeeManagement();
	void ShowMenu();
	void ExitSystem();
	int empNum; //store the number of employee
	Employee** empArray;//employee array pointer
	void AddNew();
	void save();//save the file, when i put this line before AddNew()I get the error C4102 and also empty file
	bool m_FileIsEmpty;//check if the file is empty
	int getEmpNum();
	void initEmp();//initialize employee
	void showEmp();
	void DeleEmp();
	int IsExist(int id);
	void ModEmp();
	void FindEmp();
	void Sort();
	void ClearFile();
	~EmployeeManagement();

};