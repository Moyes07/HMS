#pragma
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date():day(0),month(0),year(0){}
	Date(int day, int month, int year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	~Date() {}
	void setDate(int, int, int);
	void setday(int);
	void setmonth(int);
	void setyear(int);
	int getday();
	int getmonth();
	int getyear();
	void print_date();
}; 
class Time {
private:
	int hour;
	int min;
	int sec;
public:
	Time()
	{
		hour = 0;
		min = 0;
		sec = 0;
	}
	Time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}
	~Time() {}
	void sethour(int);
	void setmin(int);
	void setsec(int);
	int gethour();
	int getmin();
	int getsec();
	void print_time();
};
void Date::setday(int d)
{
	day = d;
}
int Date::getday()
{
	return day;
}
void Date::setmonth(int m)
{
	month = m;
}
int Date::getmonth()
{
	return month;
}
void Date::setyear(int y)
{
	year = y;
}
int Date::getyear()
{
	return year;
}
void Date::print_date()
{
	cout << day << "/" << month << "/" << year << endl;
}
void Date::setDate(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}
void Time::sethour(int h)
{
	hour = h;
}
int Time::gethour()
{
	return hour;
}
void Time::setmin(int m)
{
	min = m;
}
int Time::getmin()
{
	return min;
}
void Time::setsec(int s)
{
	sec = s;
}
int Time::getsec()
{
	return sec;
}
void Time::print_time()
{
	cout << hour << ":" << min << ":" << sec << endl;
}
