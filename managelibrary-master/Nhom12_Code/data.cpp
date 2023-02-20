#ifndef _DATA_CPP
#define _DATA_CPP

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class hocsinh
{
private:
	string un; // username
	string pw; // password

public:
	string hoten;
	string borrow;
	void setUserName(string un)
	{
		this->un = un;
	}
	string getUserName()
	{
		return un;
	}
	void setPassword(string pw)
	{
		this->pw = pw;
	}
	string getPassword()
	{
		return pw;
	}
};

struct hs2
{
	string hoten;
	int sl;
	string username;
};

#endif