#pragma
#include <iostream>
#include <string>
#include <cstring>

using namespace std;


class Address
{
protected:
	int st_num;
	int h_num;
	char sector[10];
	char city[25];
public:
	Address()
	{
		st_num = 0;
		h_num = 0;
	}

	Address(int s, int h, char* sec, char* c)
	{
		st_num = s;
		h_num = h;
		strcpy(sector, sec);
		strcpy(city, c);
	}
	void setDetail();
	void setst(int);
	void sethnum(int);
	void setsector(char*);
	void setcity(char*);
	int getst();
	int gethnum();
	string getsec();
	string getcity();
	void display();
};
void Address::setDetail()
{
	int hnum, stnum;
	char sector[50];
	char city[50];
	string ss, ct;
	
	cout << "Enter House Number : " << endl;
	cin >> hnum;
	cout << "Enter Street Number : " << endl;
	cin >> stnum;
	setst(stnum);
	sethnum(hnum);
	cin.ignore();
	cout << "Enter Sector Number : " << endl;
	cin.getline(sector,50);
	cout << "Enter City : " << endl;
	cin.getline(city, 50);
	setsector(sector);
	setcity(city);
}
void  Address::setst(int s)
{
	this->st_num = s;
}
int  Address::getst()
{
	return st_num;
}
void  Address::sethnum(int h)
{
	this->h_num = h;
}
int  Address::gethnum()
{
	return h_num;
}

void  Address::setsector(char* sc)
{
	strcpy(this->sector, sc);
}
string  Address::getsec()
{
	return sector;
}
void  Address::setcity(char* c)
{
	strcpy(this->city, c);
}
string Address::getcity()
{
	return city;
}

void Address::display()
{
	cout << "House # :" << this->h_num << endl;
	cout << "street : " << this->st_num << endl;
	cout << "sector : " << this->sector << endl;
	cout<< "city : " << this->city << endl;
}