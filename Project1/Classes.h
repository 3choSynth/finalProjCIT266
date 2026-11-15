#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>
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

	string getOptionA() const { return optionA; }
	string getOptionB() const { return optionB; }
	string getOptionC() const { return optionC; }
	string getOptionD() const { return optionD; }
	string getCorrectAnswer() const { return correctAnswer; }
	string getDifficulty() const { return difficulty; }

	bool checkAnswer(string userAnswer) const {
		return userAnswer == correctAnswer;
	}

	string getQuestionText() const {
		return questionText;
	}

	string displayQuestion() const {
		return getQuestionText() + "\nA. " + optionA + "\nB. " + optionB + "\nC. " + optionC + "\nD. " + optionD;
	}

	friend class QuestionBank;
};

class QuestionBank {

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
			if (!answer.empty())
				tempStorage.correctAnswer = answer;

			//get difficulty
			getline(ss, level, '|');
			if (!level.empty())
				tempStorage.difficulty = level;

			//get category
			getline(ss, type, '|');
			if (!type.empty())
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



public:
	QuestionBank() { storedQuestions(); }

	vector<Question> getRandomQuestions(int numQuestions, const string& difficulty) {
		vector<Question> filtered;
		for (const Question& q : questions)
			if (q.difficulty == difficulty)
				filtered.push_back(q);

		std::random_device rd;
		std::mt19937 gen(rd());
		std::shuffle(filtered.begin(), filtered.end(), gen);

		if ((int)filtered.size() > numQuestions)
			filtered.resize(numQuestions);
		return filtered;
	}
	void getQuestionsByCategory(string category) {
		// Implementation for retrieving questions by category from the question bank
		getRandomQuestions(5, "Beginner");
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
