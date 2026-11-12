#include <iostream>;
using namespace std;

class Question {
public:
	int difficulty; //levels from 1-5 maybe (5 being the highest)


};

class InterviewSession {
public:

};

class User {
public:
	string name;
	double score;
};

class QuestionBank {

};

class menu :public User {
public:
	void print_main_menu() {
		cout << "Hello, welcome to the Coding Interview Simulator! \n would you like to: " << endl;
		cout << "A. Start the Interview \n B. See Last Interview's Results \n C. Exit" << endl;
	}

	void print_Results() {
		
	}
};
