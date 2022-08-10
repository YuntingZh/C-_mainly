#include "Director.h"
Director::Director(int id, string name, int d_id) {
	this->e_id = id;
	this->e_name = name;
	this->d_id = d_id;
}
void Director::showInfo() {
	cout << "Employee ID: " << this->e_id;
	cout << "\tEmployee name: " << this->e_name;
	cout << "\tEmployee ID: " << this->getDeptName();
	cout << "\tResponsibilities: Manage all the managers " << endl;

}
string Director::getDeptName() {
	return "Director";
}