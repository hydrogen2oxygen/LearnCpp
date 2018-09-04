#include "pch.h"
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

// Because I use the namespace of std, I don't need to refer it to with the prefix std::... anymore!
using namespace std;

// First declare the functions (could also use a header file)
void menu();
void clear();
void waitForEnter();

// Then implement the main function
int main()
{
	menu();

}

// Now implement all other functions
void menu() {
	clear();
	cout << "MENU\n";
	cout << "====\na) show version\nb) show about\nexit) just exit!\n Type your choice:";

	string choice;
	cin >> choice;

	cout << "\nYour choice was: " << choice;

	if (choice == "exit") {
		return;
	} else {
		cout << "\nPress Enter to continue"; 
		waitForEnter();
		menu();
	}
}

void waitForEnter() {
	fgetc(stdin);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
* CSI[2J clears screen, CSI[H moves the cursor to top-left corner
**/
void clear() {
	
	std::cout << "\x1B[2J\x1B[H";
}