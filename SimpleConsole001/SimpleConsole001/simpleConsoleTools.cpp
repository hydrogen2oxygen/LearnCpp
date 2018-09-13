#include "pch.h"
#define NOMINMAX
#include <windows.h>
#include <iostream>
#include <limits>
#include "simpleConsoleTools.h"

using namespace std;

void SimpleConsoleTools::clear() {
	try {
		cout << "\x1B[2J\x1B[H";
		system("cls");
		color(15);
	}
	catch (const exception& e) {
		cout << e.what();
	}
};

void SimpleConsoleTools::waitForEnter() {
	fgetc(stdin);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
};

void SimpleConsoleTools::color(int c) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
};