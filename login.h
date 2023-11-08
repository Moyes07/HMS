#pragma
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Login
{
private:
	char username[25];
	int code;
public:
	Login()
	{
		for (int i = 0; i < 25; i++)
		{
			username[i] = 0;
		}
		code = 0;
	}
	Login(char* n, int p)
	{
		strcpy(username, n);
		code = p;
	}
	void setUsername(char*);
	void setUserpassword(int);
	string getUsername();
	int getUserpassword();
};
void Login::setUsername(char* n)
{
	strcpy(username, n);
}
void Login::setUserpassword(int p)
{
	code = p;
}
string Login::getUsername()
{
	return username;
}
int Login::getUserpassword()
{
	return code;
}