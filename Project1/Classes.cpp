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
	
private:
	vector<Question> questions;
public:
	void getRandomQuestions(int numQuestions) {
		// Implementation for retrieving random questions from the question bank
	}
	void getQuestionsByCategory(string category) {
		// Implementation for retrieving questions by category from the question bank
	}

};


class InterviewSession {

private: 	
	   vector<Question> sessionQuestions;
	   // Other private members related to the interview session
	   User user;
	   int sessionScore = 0;

public:
	void startSession() {
		// Implementation for starting the interview session

		for (int i = 0; i < sessionQuestions.size(); i++) {
			// Display question and get user answer
			cout << sessionQuestions[i].displayQuestion() << endl;
			string userAnswer;
			cin >> userAnswer;
			if (sessionQuestions[i].checkAnswer(userAnswer)) {
				sessionScore++;
			}
		}
	}
	void endSession() {
		// Implementation for ending the interview session
		double percentageScore = (static_cast<double>(sessionScore) / sessionQuestions.size()) * 100;
		cout << "Interview session ended. Your score is: " << sessionScore	 <<"/" << sessionQuestions.size() << " (" << percentageScore << "%)" << endl;
		
		if (percentageScore >= 75) {
			cout << "Congratulations! You passed the interview." << endl;
		}
		else {
			cout << "You failed the interview." << endl;
		}
	}
	void recordResult(User user, double score) {
		// Implementation for recording the result of the interview session

	}

	int getScore() const {
		return sessionScore;
	}
	
	
};
