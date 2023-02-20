#ifndef _ADMIN_CPP
#define _ADMIN_CPP

#include <iostream>
#include <vector>
#include <string>
#include "data.cpp"
#include <stdlib.h>
#include "book.cpp"
#include <sstream>
#include "goto_draw.cpp"
#include "update.cpp"
#include "inkhung.cpp"
#include <algorithm>
#include "docfile.cpp"

using namespace std;

long kk;
book2 *bookStructPtr;
hs2 *studentStructPtr;

void xoatk(vector<hocsinh> &studentVector, long &numOfStudent, vector<book> &bookVector, long &numOfBook)
{
	map<string, int> chk;
	for (int i = 0; i <= numOfStudent; i++)
		chk[studentVector[i].getUserName()] = 1;
	int n;
	// system("cls");
	cout << "Ban muon xoa bao nhieu tai khoan: ";
	SetColor(0, 2);
	cin >> n;
	SetColor(0, 7);
	while ((n > numOfStudent) || (n <= 0))
	{
		cout << "Nhap hop le: ";
		cin >> n;
	}
	numOfStudent = numOfStudent - n;
	cout << "Nhap cac username, ngan cach boi enter" << endl;
	while (n > 0)
	{
		n--;
		string st;
		cout << (char)16;
		cin >> st;
		while ((chk[st] == 0) || (st == "admin"))
		{
			SetColor(0, 4);
			cout << "UserName khong ton tai, nhap lai" << endl;
			SetColor(0, 7);
			cout << (char)16;
			cin >> st;
		}
		chk[st] = 0;
		update2(studentVector, numOfStudent, bookVector, numOfBook, chk);
		studentVector.resize(0);
		bookVector.resize(0);
		docfile(studentVector, numOfStudent, bookVector, numOfBook);
		SetColor(0, 10);
		cout << "xoa thanh cong!" << endl;
		SetColor(0, 7);
	}
}

void xuat2(hs2 *studentVector, long numOfStudent, vector<book> bookVector, long numOfBook)
{
	SetColor(0, 10);
	cout << "++++++++++++++++++++++ DANH SACH CAC SINH VIEN DANG MUON SACH ++++++++++++++++++++++ " << endl
		 << endl;
	SetColor(0, 7);
	cout << "__________________________________________________________________________________" << endl;
	cout << setw(2) << left << "|";
	SetColor(0, 11);
	cout << setw(4) << left << "STT";
	SetColor(0, 7);
	cout << setw(10) << left << "|";
	SetColor(0, 11);
	cout << setw(24) << left << "Ten dang nhap";
	SetColor(0, 7);
	cout << setw(10) << left << "|";
	SetColor(0, 11);
	cout << setw(20) << left << "Ten sinh vien";
	SetColor(0, 7);
	cout << setw(2) << left << "|";
	SetColor(0, 11);
	cout << setw(9) << left << "So luong"
		 << "|" << endl;
	SetColor(0, 7);
	cout << "__________________________________________________________________________________" << endl;
	int i = 0;
	while (i < numOfStudent)
	{
		i++;
		cout << setw(3) << left << "|";
		cout << setw(3) << left << i;
		cout << setw(5) << left << "|";
		cout << setw(29) << studentVector[i].username;
		cout << setw(4) << left << "|";
		cout << setw(26) << studentVector[i].hoten;
		cout << setw(5) << left << "|";
		cout << setw(6) << left << studentVector[i].sl << "|" << endl;
	};
	cout << "__________________________________________________________________________________" << endl;
	cout << endl;
	SetColor(0, 10);
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
	SetColor(0, 7);
}

void xuat3(vector<hocsinh> studentVector, long numOfStudent, book2 *bookVector, long numOfBook)
{
	system("cls");
	cout << kk;
	SetColor(0, 10);
	cout << "+++++++++++++++++++++++++ SO LUONG SACH DANG DUOC MUON +++++++++++++++++++++++++" << endl
		 << endl;
	SetColor(0, 7);
	cout << "________________________________________________________________________________" << endl;
	cout << setw(2) << left << "|";
	SetColor(0, 11);
	cout << setw(8) << left << "Ma bookVector";
	SetColor(0, 7);
	cout << setw(11) << left << "|";
	SetColor(0, 11);
	cout << setw(33) << left << "Ten bookVector";
	SetColor(0, 7);
	cout << setw(3) << left << "|";
	SetColor(0, 11);
	cout << setw(11) << left << "The loai";
	SetColor(0, 7);
	cout << setw(2) << left << "|";
	SetColor(0, 11);
	cout << setw(9) << left << "So luong"
		 << "|" << endl;
	SetColor(0, 7);
	cout << "________________________________________________________________________________" << endl;
	string st;
	long long T = 0;
	for (int j = 1; j <= numOfBook; j++)
	{

		cout << setw(5) << left << "|";
		cout << setw(5) << left << bookVector[j].code;

		cout << setw(4) << left << "|";
		cout << setw(40) << bookVector[j].bookname;
		cout << setw(2) << left << "|";
		cout << setw(12) << left << bookVector[j].category;
		cout << setw(6) << left << "|";
		cout << setw(5) << left << bookVector[j].sl << "|" << endl;
		T = T + bookVector[j].sl;
		//   k++;
	}
	cout << "________________________________________________________________________________" << endl;
	SetColor(0, 11);
	cout << setw(49) << left << "Tong cong	 ";
	SetColor(0, 7);
	cout << setw(15) << left << T << endl;
	cout << "________________________________________________________________________________" << endl
		 << endl;
	SetColor(0, 10);
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
	SetColor(0, 7);
}

bool temp1(book2 x, book2 y)
{
	return x.sl > y.sl;
};

bool temp2(book2 x, book2 y)
{
	return x.sl < y.sl;
};

bool cmp1(hs2 x, hs2 y)
{
	return x.sl > y.sl;
};
bool cmp2(hs2 x, hs2 y)
{
	return x.sl < y.sl;
};

void xuat4(vector<hocsinh> studentVector, long numOfStudent, book2 *bookVector, long numOfBook)
{
	system("cls");
	SetColor(0, 10);
	cout << "+++++++++++++++++++++ SO LUONG SACH HIEN CO TRONG THU VIEN +++++++++++++++++++++" << endl;
	SetColor(0, 7);
	cout << "-----------------------------------------------------------------------------" << endl;
	SetColor(0, 11);
	cout << "Ma bookVector";
	SetColor(0, 7);
	cout << " |";
	SetColor(0, 11);
	cout << "      Ten bookVector        ";
	SetColor(0, 7);
	cout << " 	   | ";
	SetColor(0, 11);
	cout << "    The loai  ";
	SetColor(0, 7);
	cout << "      | ";
	SetColor(0, 11);
	cout << "So luong";
	SetColor(0, 7);
	cout << " |" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;

	for (int i = 1; i < numOfBook; i++)
	{ //	kk++;

		if (stoi(bookVector[i].code, 0) < 10)
			cout << " ";
		cout << "   " << bookVector[i].code << "   | ";
		cout << bookVector[i].bookname;
		for (int ii = bookVector[i].bookname.length(); ii <= 36; ii++)
			if (ii == 33)
				cout << "| ";
			else
				cout << " ";
		cout << bookVector[i].category;
		for (int ii = bookVector[i].category.length(); ii <= 20; ii++)
			if (ii == 17)
				cout << "| ";
			else
				cout << " ";
		cout << bookVector[i].sl;
		string tt = to_string(bookVector[i].sl);
		for (int i = 1; i < 7 - tt.length(); i++)
			cout << " ";
		cout << "|" << endl;
	}
	cout << "-----------------------------------------------------------------------------" << endl;
	SetColor(0, 10);
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	SetColor(0, 7);
}

void ad1(vector<hocsinh> studentVector, long numOfStudent, vector<book> bookVector, long numOfBook)
{
	long k = 1;

	string st;
	cout << "Nhap username cua nguoi ma ban muon tra cuu: ";
	SetColor(0, 9);
	cin >> st;
	bool chay = false;
	SetColor(0, 7);
	for (int i = 1; i <= numOfStudent; i++)
		if (st == studentVector[i].getUserName())
		{
			chay = true;
			cout << "Ho va ten: ";
			SetColor(0, 10);
			cout << studentVector[i].hoten << endl;
			SetColor(0, 7);
			if (studentVector[i].borrow == "0;")
			{
				SetColor(0, 4);
				cout << " !!! Hiện tại học sinh này chưa mượn sách của thư viện" << endl;
			}
			else
			{
				SetColor(0, 2);
				cout << "Các sách đang mượn: " << endl;
				SetColor(0, 7);
				inkhung();
				st = studentVector[i].borrow;
				string sst;
				for (int i = 0; i < st.length(); i++)
					if (st[i] == ';')
					{

						int num;
						stringstream ss;
						ss << sst;
						ss >> num; // CHUYEN XAU SANG SO - 1
						cout << setw(5) << left << "|";
						cout << setw(5) << left << bookVector[num].code;
						cout << setw(4) << left << "|";
						cout << setw(40) << bookVector[num].bookname;
						cout << setw(2) << left << "|";
						cout << setw(16) << bookVector[num].category << "|" << endl;
						k++;
						sst = "";
					}
					else
						sst = sst + st[i];
				cout << "_________________________________________________________________________" << endl;
			}
			break; // kiem duoc thi dung ko kiem nua
		}
	if (chay == false)
	{
		system("cls");
		cout << "Username khong ton tai" << endl;
		ad1(studentVector, numOfStudent, bookVector, numOfBook);
	}
}
void ad2(vector<hocsinh> studentVector, long numOfStudent, vector<book> bookVector, long numOfBook)
{
	system("cls");
	string t;
	string st;
	int i = 1;
	int sl[20];
	for (int i = 1; i <= numOfStudent; i++)
	{
		sl[i] = 0;
	}
	SetColor(0, 10);
	cout << "++++++++++++++++++++++ DANH SACH CAC SINH VIEN DANG MUON SACH ++++++++++++++++++++++ " << endl
		 << endl;
	SetColor(0, 7);
	cout << "__________________________________________________________________________________" << endl;
	cout << setw(2) << left << "|";
	SetColor(0, 11);
	cout << setw(4) << left << "STT";
	SetColor(0, 7);
	cout << setw(10) << left << "|";
	SetColor(0, 11);
	cout << setw(24) << left << "Ten dang nhap";
	SetColor(0, 7);
	cout << setw(10) << left << "|";
	SetColor(0, 11);
	cout << setw(20) << left << "Ten sinh vien";
	SetColor(0, 7);
	cout << setw(2) << left << "|";
	SetColor(0, 11);
	cout << setw(9) << left << "So luong"
		 << "|" << endl;
	SetColor(0, 7);
	cout << "__________________________________________________________________________________" << endl;
	for (int i = 1; i <= numOfStudent; i++)
	{
		st = studentVector[i].borrow;
		string sst;
		for (int j = 0; j < st.length(); j++)
			if (st[j] == ';')
			{
				sl[i] = sl[i] + 1;
				sst = "";
			}
			else
				sst = sst + st[j];
	}

	int j = 1;
	studentStructPtr = new hs2[numOfStudent + 1];
	while (i <= numOfStudent)
	{
		t = studentVector[i].borrow;
		if (t == "0;")
			sl[i] = 0;

		cout << setw(3) << left << "|";
		cout << setw(3) << left << j;
		studentStructPtr[j].hoten = studentVector[i].hoten;
		studentStructPtr[j].sl = sl[i];
		studentStructPtr[j].username = studentVector[i].getUserName();
		cout << setw(5) << left << "|";
		cout << setw(29) << studentVector[i].getUserName();
		cout << setw(4) << left << "|";
		cout << setw(26) << studentVector[i].hoten;
		cout << setw(5) << left << "|";
		cout << setw(6) << left << sl[i] << "|" << endl;

		j++;
		i++;
	};
	kk = j;
	cout << "__________________________________________________________________________________" << endl;
	cout << endl;
	SetColor(0, 10);
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
	SetColor(0, 7);
}
void ad3(vector<hocsinh> studentVector, long numOfStudent, vector<book> bookVector, long numOfBook)
{

	int sl[numOfBook + 1];
	int T = 0;
	for (int i = 1; i <= numOfBook; i++)
	{
		sl[i] = 0;
	}
	// long k = 1;
	system("cls");
	SetColor(0, 10);
	cout << "+++++++++++++++++++++++++ SỐ LƯỢNG SÁCH ĐANG ĐƯỢC MƯỢN +++++++++++++++++++++++++" << endl
		 << endl;
	SetColor(0, 7);
	cout << "________________________________________________________________________________" << endl;
	cout << setw(2) << left << "|";
	SetColor(0, 11);
	cout << setw(8) << left << "Mã sách";
	SetColor(0, 7);
	cout << setw(11) << left << "|";
	SetColor(0, 11);
	cout << setw(33) << left << "Tên sách";
	SetColor(0, 7);
	cout << setw(3) << left << "|";
	SetColor(0, 11);
	cout << setw(11) << left << "Thể loại";
	SetColor(0, 7);
	cout << setw(2) << left << "|";
	SetColor(0, 11);
	cout << setw(9) << left << "Số lượng"
		 << "|" << endl;
	SetColor(0, 7);
	cout << "________________________________________________________________________________" << endl;
	string st;
	for (int i = 1; i <= numOfStudent; i++)
	{
		st = studentVector[i].borrow;
		string sst;
		for (int i = 0; i < st.length(); i++)
			if (st[i] == ';')
			{
				int num = stoi(sst);
				sl[num] = sl[num] + 1;
				sst = "";
			}
			else
				sst = sst + st[i];
	};
	kk = 0;
	bookStructPtr = new book2[numOfBook + 1];
	for (int j = 1; j <= numOfBook; j++)
	{
		if (sl[j] != 0)
		{
			kk++;
			cout << setw(5) << left << "|";
			cout << setw(5) << left << bookVector[j].code;
			bookStructPtr[kk].code = bookVector[j].code;
			bookStructPtr[kk].bookname = bookVector[j].bookname;
			bookStructPtr[kk].sl = sl[j];
			bookStructPtr[kk].category = bookVector[j].category;
			cout << setw(4) << left << "|";
			cout << setw(40) << bookVector[j].bookname;
			cout << setw(2) << left << "|";
			cout << setw(12) << left << bookVector[j].category;
			cout << setw(6) << left << "|";
			cout << setw(5) << left << sl[j] << "|" << endl;
			T = T + sl[j];
			// k++;
		}
	}
	cout << "________________________________________________________________________________" << endl;
	SetColor(0, 11);
	cout << setw(49) << left << "Tong cong	 ";
	SetColor(0, 7);
	cout << setw(15) << left << T << endl;
	cout << "________________________________________________________________________________" << endl
		 << endl;
	SetColor(0, 10);
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
	SetColor(0, 7);
}
void ad4(vector<book> bookVector, long numOfBook)
{
	SetColor(0, 10);
	cout << "+++++++++++++++++++++ SỐ LƯỢNG SÁCH HIỆN CÓ TRONG THƯ VIỆN +++++++++++++++++++++" << endl;
	SetColor(0, 7);
	cout << "-----------------------------------------------------------------------------" << endl;
	SetColor(0, 11);
	cout << "Mã sách";
	SetColor(0, 7);
	cout << " |";
	SetColor(0, 11);
	cout << "      Tên sách        ";
	SetColor(0, 7);
	cout << " 	   | ";
	SetColor(0, 11);
	cout << "    Thể loại  ";
	SetColor(0, 7);
	cout << "      | ";
	SetColor(0, 11);
	cout << "Số lượng";
	SetColor(0, 7);
	cout << " |" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	kk = 0;

	bookStructPtr = new book2[numOfBook + 1];
	for (int i = 1; i < numOfBook + 1; i++)
	{
		kk++;

		if (stoi(bookVector[i].code, 0) < 10)
			cout << " ";
		cout << "   " << bookVector[i].code << "   | ";
		cout << bookVector[i].bookname;
		for (int ii = bookVector[i].bookname.length(); ii <= 36; ii++)
			if (ii == 33)
				cout << "| ";
			else
				cout << " ";
		bookStructPtr[kk].code = bookVector[i].code;
		bookStructPtr[kk].bookname = bookVector[i].bookname;
		bookStructPtr[kk].category = bookVector[i].category;
		bookStructPtr[kk].sl = stoi(bookVector[i].amount);
		cout << bookVector[i].category;
		for (int ii = bookVector[i].category.length(); ii <= 20; ii++)
			if (ii == 17)
				cout << "| ";
			else
				cout << " ";
		cout << bookVector[i].amount;
		string tt = bookVector[i].amount;
		for (int i = 1; i < 7 - tt.length(); i++)
			cout << " ";
		cout << "|" << endl;
	}
	cout << "-----------------------------------------------------------------------------" << endl;
	SetColor(0, 10);
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	SetColor(0, 7);
}
void ad5(vector<hocsinh> &studentVector, long &numOfStudent, vector<book> &bookVector, long &numOfBook)
{
	cout << "Ban muon nhap them bao nhieu dau bookVector:	";
	int n;
	cin >> n; // fstream fout;	fout.open("danhsachsach.csv", ios::out | ios::app);
	for (int i = 1; i <= n; i++)
	{
		SetColor(0, 2);
		cout << "Nhập thông tin mã sách thư " << i << ":" << endl;
		string ten;
		string sl, theloai;
		fflush(stdin);
		SetColor(0, 6);
		cout << "  " << (char)16 << "Nhập tên sách: ";
		getline(cin, ten);
		fflush(stdin);
		cout << "  " << (char)16 << "Nhập thể loại: ";
		getline(cin, theloai);
		cout << "  " << (char)16 << "Nhập số lượng: ";
		cin >> sl;
		cout << "-------" << endl;
		stringstream ss2;
		ss2 << numOfBook + i;
		string masach = ss2.str(); // CHUYEN SO SANG XAU - 2
								   //			fout << masach << "," << ten << "," << sl << "\n";
		book bookStructPtr;
		bookStructPtr.code = masach;
		bookStructPtr.bookname = ten;
		bookStructPtr.category = theloai;
		bookStructPtr.amount = sl;
		bookVector.push_back(bookStructPtr);
	};
	numOfBook = numOfBook + n; // cout << numOfBook;
	update(studentVector, numOfStudent, bookVector, numOfBook, 0);
	SetColor(0, 10);
	cout << "Nhập thêm sách thành công!";
	SetColor(0, 7);
}

void admin(vector<hocsinh> &studentVector, long &numOfStudent, vector<book> &bookVector, long &numOfBook)
{
	system("cls");
	SetColor(0, 2);
	cout << "Đăng nhập thành công! " << endl;
	SetColor(0, 14);
	cout << "1. Tìm kiếm thông tin sinh viên" << endl;
	cout << "2. Thống kê sinh viên mượn sách - Sắp xếp - Xóa TK" << endl;
	cout << "3. Thống kê sách đang được mượn - Sắp xếp" << endl;
	cout << "4. Thống kê sách hiện tại của thư viện" << endl;
	cout << "5. Thêm đầu sách mới" << endl;
	// cout << "6. Xóa tài khoản người dùng" << endl;
	// cout << "6. Xóa đầu sách" << endl;
	cout << "6. Đăng xuất" << endl;

	int option;
	SetColor(0, 7);
	cout << "Nhập lựa chọn của bạn: " << endl;
	// cout << " " << (char)16 << (char)16;

	cin >> option;
	switch (option)
	{

	case 1:
		system("cls");
		ad1(studentVector, numOfStudent, bookVector, numOfBook);
		cout << "Bạn muốn làm gì nữa không? " << endl;
		SetColor(0, 14);
		cout << "1. Trở về màn hình chọn " << endl;
		cout << "2. Kết thúc " << endl;
		SetColor(0, 7);
		cout << " " << (char)16 << (char)16;
		int option;
		cin >> option;
		if (option == 1)
		{
			system("cls");
			admin(studentVector, numOfStudent, bookVector, numOfBook);
		}
		break; // Hai
	case 2:
		ad2(studentVector, numOfStudent, bookVector, numOfBook);
		cout << "\nBạn muốn làm gì nữa không? " << endl;
		SetColor(0, 14);
		cout << "	1. Trở về màn hình chọn " << endl;
		cout << "	2. Sắp xếp giảm dần theo số lượng sách" << endl;
		cout << "	3. Sắp xếp tăng dần theo số lượng sách" << endl;
		cout << "	4. Xóa tài khoản" << endl;
		SetColor(0, 7);

		cin >> option;
		// switch (option)
		if (option == 1)
		{

			system("cls");
			admin(studentVector, numOfStudent, bookVector, numOfBook);
			break;
		}
		if (option == 2)
		{

			system("cls");
			sort(studentStructPtr + 1, studentStructPtr + numOfStudent + 1, cmp1);
			xuat2(studentStructPtr, numOfStudent, bookVector, numOfBook);
			cout << "\nBạn muốn làm gì nữa không? " << endl;
			SetColor(0, 14);
			cout << "1. Trở về màn hình chọn " << endl;
			cout << "2. Kết thúc " << endl;
			SetColor(0, 7);

			cin >> option;
			if (option == 1)
			{
				system("cls");
				admin(studentVector, numOfStudent, bookVector, numOfBook);
			}
			break;
		}
		if (option == 3)
		{

			system("cls");
			sort(studentStructPtr + 1, studentStructPtr + numOfStudent + 1, cmp2);
			xuat2(studentStructPtr, numOfStudent, bookVector, numOfBook);
			cout << "\nBạn muốn làm gì nữa không? " << endl;
			SetColor(0, 14);
			cout << "1. Trở về màn hình chọn " << endl;
			cout << "2. Kết thúc " << endl;
			SetColor(0, 7);

			cin >> option;
			if (option == 1)
			{
				system("cls");
				admin(studentVector, numOfStudent, bookVector, numOfBook);
			}
			break;
		}
		if (option == 4)
		{
			xoatk(studentVector, numOfStudent, bookVector, numOfBook);
		}
		cout << "\nBạn muốn làm gì nữa không? " << endl;
		SetColor(0, 14);
		cout << "1. Trở về màn hình chọn " << endl;
		cout << "2. Kết thúc " << endl;
		SetColor(0, 7);

		cin >> option;
		if (option == 1)
		{
			system("cls");
			admin(studentVector, numOfStudent, bookVector, numOfBook);
		}
		break;

	case 3:
		ad3(studentVector, numOfStudent, bookVector, numOfBook);
		cout << "\nBạn muốn làm gì nữa không? " << endl;
		SetColor(0, 14);
		cout << "	1. Trở về màn hình chọn " << endl;
		cout << "	2. Sắp xếp giảm dần theo số lượng sách" << endl;
		cout << "	2. Sắp xếp tăng dần theo số lượng sách" << endl;
		SetColor(0, 7);

		cin >> option;
		// switch (option)
		if (option == 1)
		{

			system("cls");
			admin(studentVector, numOfStudent, bookVector, numOfBook);
			break;
		}
		if (option == 2)
		{

			system("cls");
			sort(bookStructPtr + 1, bookStructPtr + kk + 1, temp1);
			xuat3(studentVector, numOfStudent, bookStructPtr, kk);
			cout << "\nBạn muốn làm gì nữa không? " << endl;
			SetColor(0, 14);
			cout << "1. Trở về màn hình chọn " << endl;
			cout << "2. Kết thúc " << endl;
			SetColor(0, 7);

			cin >> option;
			if (option == 1)
			{
				system("cls");
				admin(studentVector, numOfStudent, bookVector, numOfBook);
			}
			break;
		}
		if (option == 3)
		{

			system("cls");
			sort(bookStructPtr + 1, bookStructPtr + kk + 1, temp2);
			xuat3(studentVector, numOfStudent, bookStructPtr, kk);
			cout << "\nBạn có muốn làm gì nữa không? " << endl;
			SetColor(0, 14);
			cout << "1. Trở về màn hình chọn " << endl;
			cout << "2. Kết thúc " << endl;
			SetColor(0, 7);

			cin >> option;
			if (option == 1)
			{
				system("cls");
				admin(studentVector, numOfStudent, bookVector, numOfBook);
			}
			break;
		}
	case 4:
		ad4(bookVector, numOfBook);
		cout << "\nBạn có muốn làm gì nữa không?" << endl;
		SetColor(0, 14);
		cout << "	1. Trở về màn hình chọn " << endl;
		cout << "	2. Sắp xếp giản dần theo số lượng sách" << endl;
		cout << "	3. Sắp xếp tăng dần theo số lượng sách" << endl;
		SetColor(0, 7);

		cin >> option;
		// switch (option)
		if (option == 1)
		{

			system("cls");
			admin(studentVector, numOfStudent, bookVector, numOfBook);
			break;
		}
		if (option == 2)
		{

			system("cls");
			sort(bookStructPtr + 1, bookStructPtr + kk + 1, temp1);
			xuat4(studentVector, numOfStudent, bookStructPtr, numOfBook);
			cout << "\nBạn có muốn làm gì nữa không? " << endl;
			SetColor(0, 14);
			cout << "1. Trở về màn hình chọn " << endl;
			cout << "2. Kết thúc " << endl;
			SetColor(0, 7);

			cin >> option;
			if (option == 1)
			{
				system("cls");
				admin(studentVector, numOfStudent, bookVector, numOfBook);
			}
			break;
		}
		if (option == 3)
		{

			system("cls");
			sort(bookStructPtr + 1, bookStructPtr + kk + 1, temp2);
			xuat4(studentVector, numOfStudent, bookStructPtr, numOfBook);
			cout << "\nBạn có muốn làm gì nữa không? " << endl;
			SetColor(0, 14);
			cout << "1. Trở về màn hình chọn " << endl;
			cout << "2. Kết thúc " << endl;
			SetColor(0, 7);

			cin >> option;
			if (option == 1)
			{
				system("cls");
				admin(studentVector, numOfStudent, bookVector, numOfBook);
			}
			break;
		}
	case 5:
		ad5(studentVector, numOfStudent, bookVector, numOfBook); // Hai
		cout << "\nBạn có muốn làm gì nữa không? " << endl;
		SetColor(0, 14);
		cout << "1. Trờ về màn hình chọn " << endl;
		cout << "2. Kết thúc " << endl;
		SetColor(0, 7);

		cin >> option;
		if (option == 1)
		{
			system("cls");
			admin(studentVector, numOfStudent, bookVector, numOfBook);
		}
		break;
	}
}

#endif