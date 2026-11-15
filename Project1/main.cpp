#include <iostream>
#include "Classes.cpp"

using namespace std;


int main() {

	char userChoice = ' ';

	//display main menu
	cout << "Hello, welcome to the Coding Interview Simulator! \n would you like to: " << endl;
	cout << "A. Start the Interview \n B. See Last Interview's Results \n C. Exit" << endl;
	cin >> userChoice;
	
	InterviewSession session; // Create an instance of InterviewSession
	User newUser;

	switch (userChoice) {
	case 'A':
		//start interview session
		newUser.askName();// call the askname method
		session.startSession(); // Call the startSession method
		break;
	case 'B':
		//display last interview results
		break;
	case 'C':
		cout << "Thank you for using the Coding Interview Simulator. Goodbye!" << endl;
		return 0;
	default:
		cout << "Invalid choice. Please select A, B, or C." << endl;
		break;
	}

}