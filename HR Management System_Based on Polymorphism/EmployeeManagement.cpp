#include "EmployeeManagement.h"
//TODO:17 EDIT

EmployeeManagement::EmployeeManagement() {
	//3 conditions - 1: file does not exist
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "File does not exist" << endl;
		this->empNum = 0; //start with 0 people on record
		this->empArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3 conditions - 2: file exists but is empty
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "File is empty" << endl;
		this->empNum = 0; //start with 0 people on record
		this->empArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3 conditions - 3: file exists and has data
	int num = this->getEmpNum();
	cout << "The total num of employees: " << num << endl;
	this->empNum = num;
	//allocate new memory, read and store data into array
	this->empArray = new Employee * [this->empNum];
	this->initEmp();
	/*for (int i = 0; i < this->empNum; i++) {
		cout << "Employee ID: " << this->empArray[i]->e_id << " "
			<< "Name: " << this->empArray[i]->e_name << " "
			<< "Department ID: " << this->empArray[i]->d_id <<endl;
	}*/
}

void EmployeeManagement::ShowMenu(){
	cout << "*************************************************************" << endl;
	cout << "*************Welcome to our HR Management System*************" << endl;
	cout << "********************0.Exit management system*****************" << endl;
	cout << "********************1.Add employee information***************" << endl;
	cout << "********************2.Show employee information**************" << endl;
	cout << "********************3.Delete employee information************" << endl;
	cout << "********************4.Modify Employee Information************" << endl;
	cout << "********************5.Find Employee Information***************" << endl;
	cout << "********************6.Sort by number**************************" << endl;
	cout << "********************7.Clear all documents*********************" << endl;
	cout << "*************************************************************" << endl;
	cout << endl;
	}
void EmployeeManagement::ExitSystem() {
	cout << "bye:)" << endl;
	system("pause");
	exit(0); //exit
}
void EmployeeManagement::AddNew() {
	cout << "Please type in how many people you want to add" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum <=0) {
		cout << "Invaild input!" << endl;
		//press any key, clear the screen and back to menu
		system("pause");
		system("cls");
	}
	else {
		//add
		//calculate the size of +new 
		int newSize = this->empNum + addNum; //new size of the current empNum + new
		//make a new space
		Employee ** newSpace =  new Employee* [newSize];
		//1. copy the current data to th new space first
		if (this->empArray != NULL) {
			for (int i = 0; i < this->empNum; i++) {
				newSpace[i] = this->empArray[i];
			}
		}
		//2.also put the new data in
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int pos;// the number for position
			cout << "For the person " << i+1<< ", please type in its employee ID: "<<endl;
			cin >> id;
			for (int i = 0; i < empNum - 1; i++) {
				if (id == this->empArray[i]->e_id){
					cout << "This employee ID is already in the system, please re-enter a unique employee ID: " << endl;
				}
			}
			cin >> id;
			cout << "Please type in the name: " << endl;
			cin >> name;

			cout << "Please select his/her position:" << endl;
			cout << "1.Staff" << endl;
			cout << "2.Manager" << endl;
			cout << "3.Director" << endl;
			cin >> pos;
			Employee* em = NULL;
			switch (pos)
			{
			case 1:
				em = new Staff(id, name, 1);
				break;
			case 2:
				em = new Manager(id, name, 2);
				break;
			case 3:
				em = new Director(id, name, 3);
				break;
			default:
				break;
			}
			//save em the pointer to our array
			newSpace[this->empNum + i] = em;
		}
		delete[] this->empArray;
		this->empArray = newSpace;
		//update the employee number
		this->empNum = newSize;
		this->save();
		this->m_FileIsEmpty = false;
		cout << "Great! You have sucessfully add " << addNum << " employees!" << endl;
		cout << "Now the total is " << this->empNum << " ." << endl;
		//add data to file
		

	}

}
void EmployeeManagement::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //write 
	for (int i = 0; i < this->empNum; i++) {
		ofs << this->empArray[i]->e_id << " "
			<< this->empArray[i]->e_name << " "
			<< this->empArray[i]->d_id << endl;
	}
	//close file
	ofs.close();
}
int EmployeeManagement::getEmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int e_id;
	string name;
	int d_id;
	int num =0 ;
	while (ifs >> e_id && ifs >> name && ifs >> d_id) {
		num++;
	}
	cout << "getEMpNUM " << num << endl;
	return num;
	
}
void EmployeeManagement::initEmp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int e_id;
	string name;
	int d_id;
	int index = 0;
	while(ifs >>e_id&& ifs >> name && ifs >>d_id){
		Employee* emp = NULL;
		if (d_id == 1) {
			emp = new Staff(e_id, name, d_id);
		}
		else if (d_id == 2) {
			emp = new Manager(e_id, name, d_id);
		}
		else if (d_id == 3) {
			emp = new Director(e_id, name, d_id);
		}
		this->empArray[index] = emp;
		index++;
	}
	ifs.close();
}
void EmployeeManagement::showEmp() {
	//check FileIsEmpty
	
	if (this ->m_FileIsEmpty || this->empNum == 0) {
		cout << "File does not exist or is empty" << endl;
	}
	else {
		for (int i = 0; i < empNum; i++) {
			this->empArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
void EmployeeManagement::DeleEmp() {

	if (this->m_FileIsEmpty || this->empNum == 0) { //need this->empNum == 0 otherwise it will just jump it to the else
		cout << "File does not exist or is empty!" << endl;
	}
	else {
		int id = 0;
		cout << "please type in the Employee ID of the person you want to delete : " << endl;	
		cin >> id;
		int index = this->IsExist(id);
		if (index!= -1) {
			for (int i = index; i < this->empNum-1; i++) {
				this->empArray[i] = this->empArray[i + 1];	//move forward 	
			}
			this->empNum--;
			//also update to file
			this->save();
			cout << "Deleted successfully!" << endl;
		}
		else {
			cout << "Invaid ID" << endl;
		}
	}
	system("pause");
	system("cls");
}
int EmployeeManagement::IsExist(int id) {
	//so 2 conditions: found it return i (find the ID and return the place index); can not find it return -1
	int index = -1; //set as not exist at first
	for (int i = 0; i < this->empNum; i++) {
		if (this->empArray[i]->e_id ==id) {
			index = i;
			break;
			//return index; Here nonono if user try to find a invalid ID, id like 9099 and this for lopp will throw a really large number instead of -1 
		}
		//return index; IF RETURN IS HERE, ANY ID INPUT(EXPECT THE FIRST ONE)WILL GET A -1 INDEX OF COURSE TAT
	}
	return index;
	//cout << "index is " << index << " " << endl;
}
void EmployeeManagement::ModEmp() {
	if (this->m_FileIsEmpty) {
		cout << "File does not exist or is empty" << endl;
	}
	else {
		cout << "Please type in the employee ID of the person you want to edit: " << endl;
		int id;
		cin >> id;
		int index = this->IsExist(id);
		
		if (index != -1) {
			//found it!
			delete this->empArray[index];

			int newID = 0;
			string newName = "";
			int newPos = 0;
			
			cout << "Found employee ID " << id << ", please type in new employee ID: " << endl;
			cin >> newID;
			cout << "please type in new name" << endl;
			cin >> newName;
			cout << "Please select his/her position:" << endl;
			cout << "1.Staff" << endl;
			cout << "2.Manager" << endl;
			cout << "3.Director" << endl;
			cin >> newPos;

			Employee *em = NULL;
			switch (newPos)
			{
			case 1:
				em = new Staff(newID, newName, newPos);
				break;
			case 2:
				em = new Manager(newID, newName, newPos);
				break;
			case 3:
				em = new Director(newID, newName, newPos);
				break;
			default:
				break;
			}
			//update it to the array
			this->empArray[index] = em;
			cout << "Updated sucessfully!" << endl;
			this->save();

		}
		else {
			cout << "Invaid ID." << endl;
		}
	}
	system("pause");
	system("cls");
}
void EmployeeManagement::FindEmp() {
	if (this->m_FileIsEmpty) {
		cout << "File does not exist or is empty" << endl;
	}
	else {
		cout << "Please choose the way to search: \n1. by employee number; \n2. by name." << endl;
		int input;
		cin >> input;
		if (input == 1) {
			int id;
			cout << "Please type in employee ID:" << endl;
			cin >> id;
			int index = this->IsExist(id);
			cout << "index is " << index << endl;
			if (index == -1) {
				cout <<"The search failed, invalid ID." << endl;
			}
			else {
				cout << "Here is the information of this employee:" << endl;
				this->empArray[index]->showInfo();
			}
		}
		else if (input == 2) {
			string name;
			cout << "Please type in employee's name:" << endl;
			cin >> name;
			bool flag = false; //a flag that marks sucessful find
			for (int i = 0; i < empNum;i++) {
				if (empArray[i]->e_name == name) {
					cout << "Here is the information of this employee:" << endl;
					this->empArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false) {
				cout << "The search failed, invalid name." << endl;
			}
		}
		else {
			cout << "invalid input." << endl;
		}
	}
	system("pause");
	system("cls");
}
void EmployeeManagement::Sort() {
	if (this->m_FileIsEmpty) {
		cout << "File does not exist or is empty" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "Please choose the sorting method: \n1. Ascending order by employee ID; \n2. Descending order by employee ID." << endl;
		int input;
		cin >> input;
		for (int i = 0; i < empNum ; i++) {
			int MinorMax = i;
			for (int j = i + 1; j < empNum; j++) {
				if (input == 1) { //Ascending
					if (empArray[MinorMax]->e_id > empArray[j]->e_id) { // find min
						MinorMax = j;
					}
				}
				else if (input == 2) { //Descending
					if (empArray[MinorMax]->e_id < empArray[j]->e_id) { // find max
						MinorMax = j;
					}
				}
				else {
					cout << "invalid input." << endl;
				}

				if (i != MinorMax) {
					Employee* temp = empArray[i];
					empArray[i] = empArray[MinorMax];
					empArray[MinorMax] = temp;
				}
			}
		}

		cout << "The result is:" << endl;
		this->save();
		this->showEmp();
		
	}
}
void EmployeeManagement::ClearFile() {
	if (this->m_FileIsEmpty) {
		cout << "File does not exist or is empty." << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "Please confirm that you want to clear all the data: \n1.YES; \n2.NO" << endl;
		int input;
		cin >> input;
		if (input == 1) { //yes
			//ios::trunc if exist, delete and recreate
			ofstream ofs(FILENAME, ios::trunc);
			ofs.close();
			if (this->empArray != NULL) {
				for (int i = 0; i < this->empNum; i++) {
					if (this->empArray[i] != NULL) {
						delete this->empArray[i];
					}
				}
				this->empNum = 0;
				delete[] this->empArray;
				this->empArray = NULL;
				this->m_FileIsEmpty = true;
			}
			cout << "ALL CLEAR:)" << endl;
		}
		else if (input == 2) { //no
			return;
		}
		else {
			cout << "invalid input." << endl;
		}
	}
	system("pause");
	system("cls");
}
EmployeeManagement::~EmployeeManagement() {
	if (this->empArray != NULL) {
		delete[] this->empArray;
		this->empArray = NULL;
	}
}
