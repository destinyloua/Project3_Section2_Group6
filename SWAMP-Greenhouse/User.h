#pragma once
#include <string>
#include <iostream>
using namespace std;
class User
{
	int userId;
	string userName;
	string password;

public:
	User();
	bool CreateUser(string userName, string password);
	bool ValidateLogin(string userName, string password);
	bool UpdateUser(string newUserName, string newPassword);
	bool DeleteUser();
};

