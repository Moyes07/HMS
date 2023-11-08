#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include"appointment.h"
#include"address.h"


using namespace std;

class Patient
{
protected:
	char patientName[25];
	int patientID;
	Appointment appointment;
	Address address;
public:
	Patient() {
		appointment.setAppointNum(0);
	}
	Patient(char* n, int id, Appointment app, Address adrs)
	{
		strcpy(patientName, n);
		patientID = id;
		appointment = app;
		address = adrs;
	}
	~Patient() {}
	void setDetail();
	void setPatientname(char*);
	void setPatID(int);
	void setAppointment(Appointment);
	void setAddress(Address);
	string getPatientname();
	int getPatID();
	Appointment getAppointment();
	Address getAddress();
	void printPatdetail();
};
void Patient::setDetail()
{
	char un[25];
	int id;
	int d, m, y;
	cout << "Enter Patient Name" << endl;
	cin.getline(un, 25);
	cout << "Enter Patient ID" << endl;
	cin >> id;
	this->address.setDetail();
	setPatientname(un);
	setPatID(id);
}
void Patient::setPatientname(char* n)
{
	strcpy(patientName, n);
}
void Patient::setPatID(int i)
{
	patientID = i;
}
void Patient::setAppointment(Appointment a)
{
	appointment = a;
}
void Patient::setAddress(Address ad)
{
	address = ad;
}
string Patient::getPatientname()
{
	return patientName;
}
int Patient::getPatID()
{
	return patientID;
}
Appointment Patient::getAppointment()
{
	return appointment;
}
Address Patient::getAddress()
{
	return address;
}
void Patient::printPatdetail()
{
	cout << "Patient Name : " << patientName << endl;
	cout << "Patient ID : " << patientID << endl;
	//appointment.printAppointment();
	//this->address.display();
}