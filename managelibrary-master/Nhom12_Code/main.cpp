#include <bits/stdc++.h>
#include "data.cpp"
#include "admin.cpp"
#include "user.cpp"
#include "book.cpp"
#include <windows.h>
#include "goto_draw.cpp"
#include "docfile.cpp"
using namespace std;

void drawBook();
void signUp();
int search(string nameAccount);
void check(int index);
void logIn();

int tt = 0;
string password;
string account;
long numOfStudent, numOfBook;
vector<hocsinh> studentVector;
vector<book> bookVector;
bool isAdmin = false;

void drawBook()
{
	system("cls");
	SetColor(0, 8);
	GoTo(73, 2);
	cout << "_______________" << endl;
	for (int i = 0; i <= 6; i++)
	{
		GoTo(73, 3 + i);
		cout << "| |            |" << endl;
	}
	GoTo(77, 9);
	cout << "___________" << endl;
	GoTo(78, 5);
	cout << "Manage";
	GoTo(79, 6);
	cout << "Library";
	SetColor(0, 7);
	draw(65, 1, 100, 10);
	GoTo(80, 11);
	for (int i = 0; i <= 5; i++)
		cout << (char)219;
}

void signUp()
{
	system("cls");
	draw(9, 2, 61, 11);
	string lmk = " ";
	string nameAccount;
	SetColor(0, 2);
	GoTo(14, 4);
	cout << "DANG KY";
	SetColor(0, 7);
	GoTo(11, 5);
	cout << "Nhap tai khoan: ";
	GoTo(11, 6);
	cout << "Nhap mat khau: ";
	GoTo(11, 7);
	cout << "Nhap lai mat khau: ";

	while (password != lmk)
	{
		GoTo(26, 6);
		cout << "                 ";
		GoTo(30, 7);
		cout << "                 ";
		bool kk = true;
		GoTo(27, 5);
		cout << "                 ";
		GoTo(27, 5);
		cin >> account;
		while (kk == true)
		{
			for (int i = 0; i <= numOfStudent; i++)
				if (account == studentVector[i].getUserName())
				{
					GoTo(11, 8);
					cout << "                                            ";
					GoTo(11, 8);
					cout << "Tai khoan da ton tai" << endl;
					kk = true;
					break;
				}
				else
					kk = false;
			if (kk == true)
			{
				GoTo(27, 5);
				cout << "                 ";
				GoTo(27, 5);
				cin >> account;
			}
		}
		GoTo(26, 6);
		cin >> password;
		GoTo(30, 7);
		cin >> lmk;
		if (password != lmk)
		{
			//	system("cls");
			GoTo(11, 8);
			cout << "Vui long dang ky lai theo dung yeu cau" << endl;
		}
	}

	GoTo(11, 8);
	cout << "                                           ";
	GoTo(11, 8);
	SetColor(0, 2);
	cout << "Dang ky thanh cong" << endl;
	SetColor(0, 7);
	fflush(stdin);
	GoTo(11, 9);
	cout << "Nhap ho ten cua ban: ";
	getline(cin, nameAccount);

	fstream fout;
	fout.open("data.csv", ios::out | ios::app);

	hocsinh temp;
	fout << account << "," << password << "," << nameAccount << ",0;" << endl;
	fout.close();
	temp.setUserName(account);
	temp.setPassword(password);
	temp.hoten = nameAccount;
	temp.borrow = "0;";
	studentVector.push_back(temp);

	numOfStudent++;
	user(studentVector, numOfStudent, bookVector, numOfBook, numOfStudent);
}

int search(string nameAccount)
{
	for (int i = 0; i <= numOfStudent; i++)
	{
		if ((nameAccount == studentVector[i].getUserName()) && (nameAccount == "admin"))
		{
			isAdmin = true;
			return i;
		}
		if (nameAccount == studentVector[i].getUserName())
			return i;
	}
	return -1;
}

void check(int index)
{
	if (index == -1)
	{
		// system("cls");
		SetColor(0, 4);
		GoTo(11, 7);
		cout << "Không có tài khoản hợp lệ, nhập lại! " << (char)30;
		SetColor(0, 7);
		GoTo(27, 5);
		cout << "                    ";
		GoTo(26, 6);
		cout << "                    ";
		GoTo(27, 5);
		cin >> account;
		GoTo(26, 6);
		cin >> password;
		check(search(account));
	}
	else
	{
		// system("cls");

		if (studentVector[index].getPassword() == password)
		{
			if (isAdmin == true)
			{
				admin(studentVector, numOfStudent, bookVector, numOfBook);
				isAdmin = false;
			}
			else
				user(studentVector, numOfStudent, bookVector, numOfBook, index);
		}
		else
		{
			GoTo(11, 7);
			cout << "                                     ";
			SetColor(0, 4);
			GoTo(11, 7);
			cout << (char)19 << "Mật khẩu sai!";
			isAdmin = false;
			SetColor(0, 7);
			GoTo(26, 6);
			cout << "                    ";
			GoTo(26, 6);
			cin >> password;
			check(search(account));
		}
	};
}

void logIn()
{
	SetConsoleOutputCP(CP_UTF8);
	system("cls");
	draw(9, 2, 47, 8);
	SetColor(0, 2);
	GoTo(14, 4);
	cout << "ĐĂNG NHẬP";
	SetColor(0, 7);
	GoTo(11, 5);
	cout << "Nhập tài khoản: ";
	GoTo(11, 6);
	cout << "Nhập mật khẩu: ";
	GoTo(27, 5);
	cin >> account;
	GoTo(11, 6);
	cout << "Nhập mật khẩu: ";
	cin >> password;
	check(search(account));
};

int main()
{
	system("title Quan ly thu vien - Nhom12");

	docfile(studentVector, numOfStudent, bookVector, numOfBook);
	// cout << studentVector[7].hoten;
	drawBook();
	SetColor(0, 4);
	GoTo(10, 2);
	cout << "QUAN LY THU VIEN";
	// //
	// GoTo(75, 25);
	// cout << "Cau truc du lieu va giai thuat - 137284:";
	// GoTo(78, 26);
	// cout << (char)175 << " Dang Van Tuan-20182855";
	// GoTo(78, 27);
	// cout << (char)175 << " Nguyen Lịnh Trang-20182829";
	// GoTo(78, 28);
	// cout << (char)175 << " Phan Văn Chiến-20200086";
	// GoTo(78, 29);
	// cout << (char)175 << " Nguyễn Văn Đức 20213886";

	// SetColor(0, 7);
	// SetColor(0, 9);
	// //
	SetConsoleOutputCP(CP_UTF8);
	GoTo(11, 5);
	cout << "1. Đăng nhập " << endl;
	GoTo(11, 6);
	cout << "2. Đăng kí " << endl;
	SetColor(0, 7);
	GoTo(11, 7);

	int option;
	cout << "Nhập lựa chọn của bạn: ";
	cin >> option;
	switch (option)
	{
	case 1:
		logIn();
		break;
	case 2:
		signUp();
		break;
	}

	return 0;
}
