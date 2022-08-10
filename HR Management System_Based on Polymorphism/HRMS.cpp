#include <iostream>
using namespace std;
#include "EmployeeManagement.h"
#include "Staff.h"
#include "Employee.h"
#include "Director.h"
#include "Manager.h"

//void testPloy() {
//	/*this is for testing ploymorphism*/
//	Employee* testEpl = NULL; // in case of wild pointer
//	testEpl = new Staff(1, "Momo", 1);
//	testEpl->showInfo();
//	delete testEpl;
//
//	testEpl = new Manager(1, "Momo", 1);
//	testEpl->showInfo();
//	delete testEpl;
//
//	testEpl = new Director(1, "Momo", 1);
//	testEpl->showInfo();
//	delete testEpl;
//}
int main(){
	//testPloy();



	//Instantiate EM object
	EmployeeManagement EM;
	//to storage user input
	int choice = 0;

	while (true) {
		//show the menu
		EM.ShowMenu();
		cout << "please type in your option: " << endl;
		cin >> choice;

		switch (choice) {
		case 0 : //exit out the system
			EM.ExitSystem();
			break;
		case 1: //add new
			EM.AddNew();
			break;
		case 2: //show list
			EM.showEmp();
			break;
		case 3: //delete
			EM.DeleEmp();
			break;
			/*{
				cout << "Dose ID exist?" << endl;
				int id;
				cin >> id;
				int a = EM.IsExist(id);
				cout << "index is " << a << " " << endl;
				break;
			}*/
		case 4: //edit
			EM.ModEmp();
			break;
		case 5: //find
			EM.FindEmp();
			break;
		case 6: //reorder
			EM.Sort();
			break;
		case 7: //clear file
			EM.ClearFile();
			break;
		default:
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}