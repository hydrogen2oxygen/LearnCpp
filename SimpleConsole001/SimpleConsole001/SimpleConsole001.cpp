#include "pch.h"
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

#include <cstdio>
#include <memory>
#include <stdexcept>
#include <array>

// The <windows.h> header has had the min() and max() macros since time immemorial,
// and they frequently cause problems with C++. Fortunately, you can disable them 
// by adding #define NOMINMAX before including <windows.h>
#define NOMINMAX
#include <windows.h>

#include "simpleConsoleTools.h"

// Because I use the namespace of std, I don't need to refer it to with the prefix std::... anymore!
using namespace std;

// First declare the functions (could also use a header file)
void menu();
std::string executeCommand(const char* cmd);

SimpleConsoleTools sct;

// Then implement the main function
int main()
{
	sct = SimpleConsoleTools();
	// enter the menu
	menu();

}

// Now implement all other functions
void menu() {
	
	executeCommand("color 1F");
	sct.clear();
	sct.color(159);
	cout << "MENU\n";
	cout << "====\n";
	cout << "a) show version\n";
	cout << "b) show about\n";
	cout << "c) experimental dir cmd\n";
	cout << "d) show color table\n";
	cout << "exit) just exit!\n";
	sct.color(15);
	cout << "Type your choice : ";
	
	string choice;
	cin >> choice;

	sct.color(15);

	cout << "\nYour choice was: ";
	sct.color(15);
	cout << choice;
	sct.color(15);

	if (choice == "exit") {
		return;
	} else if (choice == "c") {
		cout << executeCommand("dir");
		sct.waitForEnter();
	}
	else if (choice == "d") {
		for (int x = 0; x < 256; x++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
			cout << "[" << x << "]";
		}

		sct.waitForEnter();
		sct.color(15);
	} else {
		cout << "\nPress Enter to continue"; 
		sct.waitForEnter();
	}

	menu();
}

/**
* CSI[2J clears screen, CSI[H moves the cursor to top-left corner
**/
void clear() {

	try {
		cout << "\x1B[2J\x1B[H";
		system("cls");
		sct.color(15);
	}
	catch (const exception& e) {
		cout << e.what();
	}
}



std::string executeCommand(const char* cmd) {

	try {
		
	
		std::array<char, 128> buffer;
		std::string result;
		std::shared_ptr<FILE> pipe(_popen(cmd, "r"), _pclose);
		if (!pipe) throw std::runtime_error("popen() failed!");
		while (!feof(pipe.get())) {
			if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
				result += buffer.data();
		}
		return result;

	}
	catch (const exception& e) {
		cout << e.what();
		return "error";
	}
}