#ifndef _DOCFILE_CPP
#define _DOCFILE_CPP

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

void docfile(vector<hocsinh> &studentVector, long &numOfStudent, vector<book> &bookVector, long &numOfBook)
{
  int line = -1;
  ifstream inputFile("data.csv");
  string username;
  string password;
  string borrow;
  string hotenn;

  while (inputFile.peek() != EOF)
  {
    line++;
    getline(inputFile, username, ',');
    getline(inputFile, password, ',');
    getline(inputFile, hotenn, ',');
    getline(inputFile, borrow, '\n');

    hocsinh temp;
    temp.setUserName(username);
    temp.setPassword(password);
    temp.hoten = hotenn;
    temp.borrow = borrow;
    studentVector.push_back(temp);
  }

  numOfStudent = line;
  inputFile.close();

  ifstream inputFile2("danhsachsach.csv");
  line = -1;
  while (inputFile2.peek() != EOF)
  {
    line++;
    book temp;
    getline(inputFile2, temp.code, ',');
    getline(inputFile2, temp.bookname, ',');
    getline(inputFile2, temp.category, ',');
    getline(inputFile2, temp.amount, '\n');
    //  getline(inputFile2,temp.price,'\n');
    bookVector.push_back(temp);
  }
  numOfBook = line;
  inputFile2.close();
}

#endif