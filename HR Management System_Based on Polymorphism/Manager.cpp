#include "Manager.h"
Manager::Manager(int id, string name, int d_id) {
	this->e_id = id;
	this->e_name = name;
	this->d_id = d_id;
}
void Manager::showInfo() {
	cout << "Employee ID: " << this->e_id;
	cout << "\tEmployee name: " << this->e_name;
	cout << "\tEmployee ID: " << this->getDeptName();
	cout << "\tResponsibilities: Assign work " << endl;

}

string Manager::getDeptName() {
	return "Manager";
}