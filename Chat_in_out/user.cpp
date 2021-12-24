#include <string>
#include "user.h"
using namespace std;

string &User::getUserLogin()
{
	return _login;
}

void User::setUserLogin(const string& login)
{
	_login = login;
}

string &User::getUserName()
{
	return _name;
}

void User::setUserName(const string& name)
{
	_name = name;
}

string &User::getUserPassword()
{
	return _password;
}

void User::setUserPassword(const string& password)
{
	_password = password;
}

ostream& operator <<(ostream& os, const User& u)
{
	os << u._login;
	os << ' ';
	os << u._name;
	os << ' ';
	os << u._password;
	return os;
}

fstream& operator >>(fstream& is, User& u)
{
	is >> u._login;
	is >> u._name;
	is >> u._password;
	return is;
}
