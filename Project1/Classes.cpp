#include <iostream>;
#include <vector>
#include <string>
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
private:
	vector<Question> questions;

public:
	void addQuestion(Question question);
	void removeQuestion(int index);
	Question getQuestion(int index) const;

	vector<Question> getQuestionByCategory(string category);
	vector<Question> getQuestionByDifficulty(string difficulty);

	int getQuestionCount() const;
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
