#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User {
public:
	string name;
	int totalInterviews;
	double averageScore;
};

class Question {

private:
	string category, correctAnswer, optionA, optionB, optionC, optionD, questionText;
	int difficulty; //levels from 1-5 maybe (5 being the highest)
public:

	string getQuestionText() const {
		return questionText;
	}

	string displayQuestion() const {
		return getQuestionText() + "\nA. " + optionA + "\nB. " + optionB + "\nC. " + optionC + "\nD. " + optionD;
	}

	bool checkAnswer(string userAnswer) const {
		if (userAnswer == correctAnswer) {
			cout<< "Correct!";
			return true;
		}
		cout << "Incorrect.";
		return false;
	
	}
};

class QuestionBank {

};


class InterviewSession {

private: 	
	   vector<Question> questions;
	   // Other private members related to the interview session
	   User user;
	   int score = 0;

public:
	void startSession() {
		// Implementation for starting the interview session

		for (int i = 0; i < questions.size(); i++) {
			// Display question and get user answer
			cout << questions[i].displayQuestion() << endl;
			string userAnswer;
			cin >> userAnswer;
			if (questions[i].checkAnswer(userAnswer)) {
				score++;
			}
		}
	}
	void endSession() {
		// Implementation for ending the interview session
	}
	void recordResult(User user, double score) {
		// Implementation for recording the result of the interview session

	}
	void print_Results() {
			// Implementation for printing interview results
			cout << getUserName() << ", your score in this interview is: " << getScore() << endl;
		}

	string getUserName() const {
		return user.name;
	}

	int getScore() const {
		return score;
	}
	
	
};
