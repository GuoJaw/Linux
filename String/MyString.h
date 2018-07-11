#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include<iostream>
using namespace std;

class MyString
{
public:
	MyString();
	MyString(int len);
	MyString(const char* str);
	MyString(const MyString& another);
	~MyString();
public:
	MyString& operator=(const MyString& another);
	MyString operator+(const MyString& another);
	MyString& operator+=(const MyString& another);
	bool operator==(const MyString& another);
	bool operator!=(const MyString& another);
	char& operator[](int index);
	friend ostream& operator<<(ostream& cout, const MyString& myStr);
	friend istream& operator>>(istream& cin, MyString& myStr);

private:
	int len;
	char* str;
};