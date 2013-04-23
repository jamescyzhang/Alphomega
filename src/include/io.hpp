#ifndef IO_HPP

#define IO_HPP

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

void getChar(char& ch);
void emit(string str);
void emitln(string str);
void error(string err);
void fatal(string err);
void expected(string toExpect);
void match(char a, char b);
bool isLetter(char x);
bool isNumber(char x);
char getLetter(char x);
char getNumber(char x);

void getChar(char& ch) {
	cin >> ch;
}

void emit(string str) {
	cout << str;
}

void emitln(string str) {
	cout << str << endl;
}

void error(string err) {
	emitln("ERROR: " + err);
}

void fatal(string err) {
	error(err);
	abort();
}

void expected(string toExpect) {
	fatal(toExpect + " EXPECTED");
}

void match(char a, char b) {
	if (a == b)
		getChar(a);
	else expected(&b);
}

bool isLetter(char x) {
	if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z'))
		return true;
	return false;
}

bool isNumber(char x) {
	if ((x >= '0' && x <= '9'))
		return true;
	return false;
}

char getLetter(char& x) {
	char ch;
	if (!isLetter(x)) {
		expected("IDENTIFIER");
	}
	ch = toupper(x);
	getChar(x);
	return ch;
}

char getNumber(char& x) {
	char ch;
	if (!isNumber(x)) {
		expected("INTEGER");
	}
	ch = toupper(x);
	getChar(x);
	return ch;
}

#endif
