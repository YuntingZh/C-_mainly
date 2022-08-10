#include "Staff.h"
Staff::Staff(int id, string name, int d_id) {
	this->e_id = id;
	this->e_name = name;
	this->d_id = d_id;
}
void Staff::showInfo() {
	cout << "Employee ID: " << this->e_id;
	cout << "\tEmployee name: " << this->e_name;
	cout << "\tEmployee ID: " << this->getDeptName();
	cout << "\tResponsibilities: Complete the work " << endl;

}

string Staff::getDeptName() {
	return "Staff";
}