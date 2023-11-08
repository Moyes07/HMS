#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include"DandT.h"

using namespace std;

class Appointment
{
private:
	int appointmentNum;
	Date appointmentDate;
	Time appointmentTime;
public:
	Appointment() {
		appointmentNum = 0;
	}
	Appointment(Date date, Time time) :appointmentNum(0), appointmentDate(date), appointmentTime(time) {}
	~Appointment() {}
	void setDetail();
	void setAppointNum(int);
	void setappointment(Date, int, Time);
	int getAppointNum();
	void printAppointment();
};

void Appointment::setAppointNum(int a) {
	this->appointmentNum = a;
}
void Appointment::setDetail()
{
	int d, m, y;
	int appnum;
	cout << "Enter Appoinment Date" << endl;
	cin >> d; cin >> m; cin >> y;
	Date date(d, m, y);
	int h, min;
	int sec = 0;
	cout << "Enter Appointment Time" << endl;
	cin >> h; cin >> min; cin >> sec;
	Time time(h, min, sec);
	appnum = (rand() % 9999) - 1000;
	setappointment(date, appnum, time);
}
void Appointment::setappointment(Date dt, int num, Time at)
{
	appointmentNum = num;
	appointmentDate.setDate(dt.getday(),dt.getmonth(),dt.getyear());
	appointmentTime = at;
}
int Appointment::getAppointNum()
{
	if(appointmentNum!=NULL)
		return appointmentNum;
	return 0;
}
void Appointment::printAppointment()
{
	cout << "Appointment Number : " << appointmentNum << endl;
	cout << "Date : "; appointmentDate.print_date();
	cout << "Time : "; appointmentTime.print_time();
}