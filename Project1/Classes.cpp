#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Question {

private:
	string category, correctAnswer, optionA, optionB, optionC, optionD, questionText;
	int difficulty; //levels from 1-5 maybe (5 being the highest)
public:
	
	int getDifficulty() const {
		return difficulty;
	}
	string getCategory() const {
		return category;
	}

	string getQuestionText() const {
		return questionText;
	}

	string getCorrectAnswer() const {
		return correctAnswer;
	}
	string getOptionA() const {
		return optionA;
	}
	string getOptionB() const {
		return optionB;
	}
	string getOptionC() const {
		return optionC;
	}
	string getOptionD() const {
		return optionD;
	}

};

class InterviewSession {

private: 	vector<Question> questions;
	   // Other private members related to the interview session
	   User user;
	   int score;
	   int totalQuestions;

public:
	void startSession() {
		// Implementation for starting the interview session
	}
	void endSession() {
		// Implementation for ending the interview session
	}
	void recordResult(User user, double score) {
		// Implementation for recording the result of the interview session
	}
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
	vector<Question> getQuestionByDifficulty(int difficulty);

	int getQuestionCount() const;
};

class Menu {

	string mainMenuChoice;

public:
	void print_main_menu() {
		cout << "Hello, welcome to the Coding Interview Simulator! \n would you like to: " << endl;
		cout << "A. Start the Interview \n B. See Last Interview's Results \n C. Exit" << endl;
	}

	void print_Results() {
		// Implementation for printing interview results

	}
};
