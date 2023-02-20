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
int search(string st);
void check(int h);
void signIn();

int tt = 0;
string mk;
string tk;
long sohs, sosach;
vector<hocsinh> hs;
vector<book> sach;
bool kkt = false;

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
	string st;
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

	while (mk != lmk)
	{
		GoTo(26, 6);
		cout << "                 ";
		GoTo(30, 7);
		cout << "                 ";
		bool kk = true;
		GoTo(27, 5);
		cout << "                 ";
		GoTo(27, 5);
		cin >> tk;
		while (kk == true)
		{
			for (int i = 0; i <= sohs; i++)
				if (tk == hs[i].getUserName())
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
				cin >> tk;
			}
		}
		GoTo(26, 6);
		cin >> mk;
		GoTo(30, 7);
		cin >> lmk;
		if (mk != lmk)
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
	getline(cin, st);

	fstream fout;
	fout.open("data.csv", ios::out | ios::app);

	hocsinh temp;
	fout << tk << "," << mk << "," << st << ",0;" << endl;
	fout.close();
	temp.setUserName(tk);
	temp.setPassword(mk);
	temp.hoten = st;
	temp.borrow = "0;";
	hs.push_back(temp);

	sohs++;
	user(hs, sohs, sach, sosach, sohs);
}

int search(string st)
{
	for (int i = 0; i <= sohs; i++)
	{
		if ((st == hs[i].getUserName()) && (st == "admin"))
		{
			kkt = true;
			return i;
		}
		if (st == hs[i].getUserName())
			return i;
	}
	return -1;
}

void check(int h)
{
	if (h == -1)
	{
		// system("cls");
		SetColor(0, 4);
		GoTo(11, 7);
		cout << "Khong co tai khoan hop le, nhap lai " << (char)30;
		SetColor(0, 7);
		GoTo(27, 5);
		cout << "                    ";
		GoTo(26, 6);
		cout << "                    ";
		GoTo(27, 5);
		cin >> tk;
		GoTo(26, 6);
		cin >> mk;
		check(search(tk));
	}
	else
	{
		// system("cls");

		if (hs[h].getPassword() == mk)
		{
			if (kkt == true)
			{
				admin(hs, sohs, sach, sosach);
				kkt = false;
			}
			else
				user(hs, sohs, sach, sosach, h);
		}
		else
		{
			GoTo(11, 7);
			cout << "                                     ";
			SetColor(0, 4);
			GoTo(11, 7);
			cout << (char)19 << " Mat khau sai";
			kkt = false;
			SetColor(0, 7);
			GoTo(26, 6);
			cout << "                    ";
			GoTo(26, 6);
			cin >> mk;
			check(search(tk));
		}
	};
}

void signIn()
{
	// SetConsoleOutputCP(65001);
	system("cls");
	draw(9, 2, 47, 8);
	SetColor(0, 2);
	GoTo(14, 4);
	cout << "DANG NHAP";
	SetColor(0, 7);
	GoTo(11, 5);
	cout << "Nhap tai khoan: ";
	GoTo(11, 6);
	cout << "Nhap mat khau: ";
	GoTo(27, 5);
	cin >> tk;
	GoTo(11, 6);
	cout << "Nhap mat khau: ";
	cin >> mk;
	check(search(tk));
};

int main()
{
	system("title Quan ly thu vien - Nhom12");

	docfile(hs, sohs, sach, sosach);
	// cout << hs[7].hoten;
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
	// cout << (char)175 << " Nguyễn Văn Đức-20213886";

	// SetColor(0, 7);
	// SetColor(0, 9);
	// //
	SetConsoleOutputCP(65001);
	GoTo(11, 5);
	cout << "1. Dang nhap " << endl;
	GoTo(11, 6);
	cout << "2. Dang ky " << endl;
	SetColor(0, 7);
	GoTo(11, 7);

	int option;
	cout << "Nhap lua chon cua ban: ";
	cin >> option;
	switch (option)
	{
	case 1:
		signIn();
		break;
	case 2:
		signUp();
	}

	return 0;
}
