#pragma
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Room
{
private:
	int roomNo;
	int roomFloor;
	bool vacancy;
	Patient p;
public:
	Room() {}
	Room(int n,int f)
	{
		roomNo = n;
		roomFloor = f;
		vacancy = true;
	}
	~Room() {}
	void setNum(int);
	void setFloor(int);
	bool checkVacancy(char);
	int getNum();
	int getFloor();
	void setDetail();
	void print();
	bool addPatient(Patient);
};

void Room::setNum(int n)
{
	roomNo = n;
}
void Room::setFloor(int n)
{
	roomFloor = n;
}
bool Room::checkVacancy(char v)
{
	if (v == 'Y' || v == 'y')
	{
		vacancy = true;
		return vacancy;
	}
	else vacancy = false;
	return vacancy;
}
int Room::getNum()
{
	return roomNo;
}
int Room::getFloor()
{
	return roomFloor;
}
void Room::print()
{
	cout << roomNo << endl;
	cout << roomFloor << endl;
	if (vacancy == true)
	{
		cout << "Room is Vacant" << endl;
	}
	else cout << "Room is Occupied" << endl;
}

bool Room::addPatient(Patient p) {
	this->p = p;
	vacancy = false;
	return true;
}

void Room::setDetail() {
	cout<<"Enter room number : "<<endl;
	cin >> roomNo;
	cout << "Enter room floor : " << endl;
	cin >> roomFloor;
	vacancy = true;
}
