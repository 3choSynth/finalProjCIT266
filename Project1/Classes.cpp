#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <random>
using namespace std;

class User {
public:
	string name;
	int totalInterviews;
	double averageScore;

	//ask user for name
	void askName() {
		cout << "Please enter your name " << endl;
		cin >> name;
	}
};

class Question {

private:
	string category, correctAnswer, optionA, optionB, optionC, optionD, questionText, difficulty;
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

	friend class QuestionBank;
};

class QuestionBank : public Question {

private:
	vector<Question> questions;
	string line;
	string answer;
	string level;
	string type;

	void storedQuestions() {
		//file I/O to find question file and open it
		ifstream file("Questions.txt");
		if (!file.is_open()) {
			cerr << "Error: could not open question file!" << endl;
			return;
		}

		//read txt file
		while (getline(file, line)) {
			if (line.empty())continue;
			stringstream ss(line);
			Question tempStorage;

			//getting question text
			getline(ss, tempStorage.questionText, '|');

			//getting question options
			for (int i = 0;i < 4;i++) {
				if (i == 0)
					getline(ss, tempStorage.optionA, '|');
				if (i == 1)
					getline(ss, tempStorage.optionB, '|');
				if (i == 2)
					getline(ss, tempStorage.optionC, '|');
				if (i == 3)
					getline(ss, tempStorage.optionD, '|');
			}

			//get correct answer
			getline(ss, answer, '|');
			if (!answer.empty(); '|')
				tempStorage.correctAnswer = answer;

			//get difficulty
			getline(ss, level, '|');
			if (!level.empty(); '|')
				tempStorage.difficulty = level;

			//get category
			getline(ss, type, '|');
			if (!level.empty(); '|')
				tempStorage.category = type;

			//put question in vector bank
			questions.push_back(tempStorage);
		}

		//close txt file
		file.close();

		//checking loading questions
		if (questions.empty()) {
			cout << "No questions found in the file." << endl;
			return;
		}

	}

	void randomize() {
		//randomizes the questions
		default_random_engine rand;
		default_random_engine engine(rand());
	}



public:
	void getRandomQuestions(int numQuestions) {
		// Implementation for retrieving random questions from the question bank
		randomize();
		displayQuestion();

	}
	void getQuestionsByCategory(string category) {
		// Implementation for retrieving questions by category from the question bank
		getRandomQuestions(5);
	}

	friend class InterviewSession;

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
