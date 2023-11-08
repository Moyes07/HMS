#pragma once 
#include <iostream>
#include <string>
#include <cstring>
#include"patient.h"

using namespace std;

class Faculty
{
protected:
	char name[25];
	int employeeID;
	Date doj;
public:
	Faculty() {}
	Faculty(char* n, int e,Date d)
	{
		std::strcpy(name, n);
		employeeID = e;
		doj = d;
	}
	~Faculty() {}
	void setDetail();
	void setName(char*);//get and set functions
	void setEmpID(int);
	void setDoj(Date);
	string getName();
	int getEmpID();
	Date getDoj();
	virtual void printEmpinfo();//print faculty Detail
};
void Faculty::setDetail()
{
	char nm[25];
	int id;
	int d, m, y;
	cout << "Enter Name" << endl;
	cin.getline(nm, 25);
	setName(nm);
	cout << "Enter User ID" << endl;
	cin >> id;
	setEmpID(id);
	cout << "Enter joining Date" << endl;
	cin >> d; cin >> m; cin >> y;
	Date date(d, m, y);
	setDoj(date);
}
void Faculty::setName(char* s)
{
	std::strcpy(name, s);
}
void Faculty::setEmpID(int id)
{
	employeeID = id;
}
void Faculty::setDoj(Date d)
{
	doj = d;
}
string Faculty::getName()
{
	return name;
}
int Faculty::getEmpID()
{
	return employeeID;
}
Date Faculty::getDoj()
{
	return doj;
}
void Faculty::printEmpinfo()
{
	cout << "Name : " << name << endl;
	cout << "Employee ID : " << employeeID << endl;
	cout << "Date of joining : "; doj.print_date();
}
class Admin :public Faculty //inheritenace used to inherit data members and function of faculty class
{
protected:
	char designation[25];
public:
	Admin() {}
	Admin(char* n, int a, Date d, char* post) :Faculty(n,a, d)//paramertized constructor
	{
		strcpy(designation, post);
	}
	~Admin() {}
	void setDetail();
	void setDesignation(char*);
	string getDesignation();
	void printEmpinfo();
};
void Admin::setDetail()
{
	char ds[25];
	Faculty::setDetail();
	cout << "Enter Designation" << endl;
	cin.getline(ds, 25);
	setDesignation(ds);
	
}
void Admin::setDesignation(char* s)
{
	std::strcpy(designation, s);
}
string Admin::getDesignation()
{
	return designation;
}
void Admin::printEmpinfo()
{
	Faculty::printEmpinfo();
	cout << "Designation : " << designation << endl;
}
class Doctor :public Faculty //inheritance used with faculty as parent class
{
private:
	int numofappointment;
	Appointment app[50];

public:
	Doctor() {
		numofappointment = 0;
	}
	Doctor(char* n, int a, Date d, int num) :Faculty(n,a, d)
	{
		numofappointment = num;
	}
	~Doctor() {}
	void setDetail();
	void setAppnum(int);
	int getAppnum();
	void printEmpinfo();
	void printAppInfo();
	void addAppointment(Appointment);
};
void Doctor::setDetail()
{
	int numapp;
	Faculty::setDetail();
	//cout << "Enter Number of Appoinments" << endl;
	//cin >> numapp;
	setAppnum(0);
}
void Doctor::setAppnum(int x)
{
	numofappointment = x;
}
int Doctor::getAppnum()
{
	return numofappointment;
}
void Doctor::printEmpinfo()
{
	Faculty::printEmpinfo();
	cout << "Number of Appointments : " << numofappointment << endl;
}
void Doctor::printAppInfo() 
{
	for (int i = 0; i < numofappointment; i++) 
	{
		this->app[i].printAppointment();
		cout << endl;
	}
}
void Doctor::addAppointment(Appointment a) {
	numofappointment++;
	for (int i = 0; i < numofappointment; i++) {
		if (app[i].getAppointNum() == 0) {
			app[i] = a;
			return;
		}
	}
}