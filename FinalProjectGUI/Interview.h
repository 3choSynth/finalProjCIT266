#pragma once
#include "../Project1/Classes.h"
#include <msclr/marshal_cppstd.h>

namespace FinalProjectGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class QuestionData {
	public:
		String^ text;
		cli::array<String^>^ options;
		int correct;   // 0=A, 1=B, 2=C, 3=D
		QuestionData(String^ t, String^ a, String^ b, String^ c, String^ d, int correctIndex) {
			text = t;
			options = gcnew cli::array<String^>(4) { a, b, c, d };
			correct = correctIndex;
		}
	};

	public ref class Interview : public System::Windows::Forms::Form
	{
	public:
		Interview(Form^ menu, String^ diff, int count)
		{
			InitializeComponent();
			mainMenu = menu;
			difficulty = diff;
			currentIndex = 0;
			score = 0;

			btnSubmit->Click += gcnew EventHandler(this, &Interview::btnSubmit_Click);
			btnContinue->Click += gcnew EventHandler(this, &Interview::btnContinue_Click);
			this->FormClosed += gcnew FormClosedEventHandler(this, &Interview::Interview_FormClosed);

			lblDifficulty->Text = L"Difficulty: " + difficulty;
			LoadQuestions(count);   // the first question is shown in Interview_Load
		}

	private:std::string DifficultyStd() {
		String^ d = difficulty;   // local copy, so it can be passed by reference
		return msclr::interop::marshal_as<std::string>(d);
	}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Interview()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblQuestionCount;
	private: System::Windows::Forms::Button^ btnSubmit;
	private: System::Windows::Forms::Label^ lblDifficulty;
	private: System::Windows::Forms::Panel^ pnlQuestion;
	private: System::Windows::Forms::Label^ lblPick;

	private: System::Windows::Forms::Label^ lblQuestion;
	private: System::Windows::Forms::RadioButton^ rdoD;
	private: System::Windows::Forms::RadioButton^ rdoC;
	private: System::Windows::Forms::RadioButton^ rdoB;
	private: System::Windows::Forms::RadioButton^ rdoA;
	private: System::Windows::Forms::Panel^ pnlFeedback;

	private: System::Windows::Forms::Button^ btnContinue;
	private: System::Windows::Forms::Label^ lblFeedback;
	private: System::Windows::Forms::Label^ lblFeedbackTitle;

	private: Form^ mainMenu;
	private: String^ difficulty;
	private: int currentIndex;
	private: int score;
	private: List<QuestionData^>^ questions;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblQuestionCount = (gcnew System::Windows::Forms::Label());
			this->btnSubmit = (gcnew System::Windows::Forms::Button());
			this->lblDifficulty = (gcnew System::Windows::Forms::Label());
			this->pnlQuestion = (gcnew System::Windows::Forms::Panel());
			this->rdoD = (gcnew System::Windows::Forms::RadioButton());
			this->rdoC = (gcnew System::Windows::Forms::RadioButton());
			this->rdoB = (gcnew System::Windows::Forms::RadioButton());
			this->rdoA = (gcnew System::Windows::Forms::RadioButton());
			this->lblPick = (gcnew System::Windows::Forms::Label());
			this->lblQuestion = (gcnew System::Windows::Forms::Label());
			this->pnlFeedback = (gcnew System::Windows::Forms::Panel());
			this->btnContinue = (gcnew System::Windows::Forms::Button());
			this->lblFeedback = (gcnew System::Windows::Forms::Label());
			this->lblFeedbackTitle = (gcnew System::Windows::Forms::Label());
			this->pnlQuestion->SuspendLayout();
			this->pnlFeedback->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblQuestionCount
			// 
			this->lblQuestionCount->AutoSize = true;
			this->lblQuestionCount->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 7.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblQuestionCount->Location = System::Drawing::Point(470, 20);
			this->lblQuestionCount->Name = L"lblQuestionCount";
			this->lblQuestionCount->Size = System::Drawing::Size(168, 25);
			this->lblQuestionCount->TabIndex = 11;
			this->lblQuestionCount->Text = L"Question \?/\?";
			// 
			// btnSubmit
			// 
			this->btnSubmit->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnSubmit->FlatAppearance->BorderColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnSubmit->FlatAppearance->BorderSize = 2;
			this->btnSubmit->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnSubmit->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSubmit->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSubmit->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btnSubmit->Location = System::Drawing::Point(86, 506);
			this->btnSubmit->Name = L"btnSubmit";
			this->btnSubmit->Size = System::Drawing::Size(450, 73);
			this->btnSubmit->TabIndex = 12;
			this->btnSubmit->Text = L"Submit Answer";
			this->btnSubmit->UseVisualStyleBackColor = false;
			// 
			// lblDifficulty
			// 
			this->lblDifficulty->AutoSize = true;
			this->lblDifficulty->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 7.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDifficulty->Location = System::Drawing::Point(23, 20);
			this->lblDifficulty->Name = L"lblDifficulty";
			this->lblDifficulty->Size = System::Drawing::Size(272, 25);
			this->lblDifficulty->TabIndex = 13;
			this->lblDifficulty->Text = L"Difficulty: Beginner";
			// 
			// pnlQuestion
			// 
			this->pnlQuestion->Controls->Add(this->rdoD);
			this->pnlQuestion->Controls->Add(this->btnSubmit);
			this->pnlQuestion->Controls->Add(this->rdoC);
			this->pnlQuestion->Controls->Add(this->rdoB);
			this->pnlQuestion->Controls->Add(this->rdoA);
			this->pnlQuestion->Controls->Add(this->lblPick);
			this->pnlQuestion->Controls->Add(this->lblQuestion);
			this->pnlQuestion->Location = System::Drawing::Point(23, 104);
			this->pnlQuestion->Name = L"pnlQuestion";
			this->pnlQuestion->Padding = System::Windows::Forms::Padding(20);
			this->pnlQuestion->Size = System::Drawing::Size(628, 602);
			this->pnlQuestion->TabIndex = 14;
			// 
			// rdoD
			// 
			this->rdoD->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rdoD->Location = System::Drawing::Point(23, 425);
			this->rdoD->Name = L"rdoD";
			this->rdoD->Size = System::Drawing::Size(582, 45);
			this->rdoD->TabIndex = 20;
			this->rdoD->TabStop = true;
			this->rdoD->Text = L"D: ";
			this->rdoD->UseVisualStyleBackColor = true;
			// 
			// rdoC
			// 
			this->rdoC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rdoC->Location = System::Drawing::Point(23, 370);
			this->rdoC->Name = L"rdoC";
			this->rdoC->Size = System::Drawing::Size(582, 45);
			this->rdoC->TabIndex = 19;
			this->rdoC->TabStop = true;
			this->rdoC->Text = L"C: ";
			this->rdoC->UseVisualStyleBackColor = true;
			// 
			// rdoB
			// 
			this->rdoB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rdoB->Location = System::Drawing::Point(23, 315);
			this->rdoB->Name = L"rdoB";
			this->rdoB->Size = System::Drawing::Size(582, 45);
			this->rdoB->TabIndex = 18;
			this->rdoB->TabStop = true;
			this->rdoB->Text = L"B: ";
			this->rdoB->UseVisualStyleBackColor = true;
			// 
			// rdoA
			// 
			this->rdoA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rdoA->Location = System::Drawing::Point(23, 260);
			this->rdoA->Name = L"rdoA";
			this->rdoA->Size = System::Drawing::Size(582, 45);
			this->rdoA->TabIndex = 17;
			this->rdoA->TabStop = true;
			this->rdoA->Text = L"A: ";
			this->rdoA->UseVisualStyleBackColor = true;
			// 
			// lblPick
			// 
			this->lblPick->AutoSize = true;
			this->lblPick->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPick->Location = System::Drawing::Point(23, 213);
			this->lblPick->Name = L"lblPick";
			this->lblPick->Size = System::Drawing::Size(139, 29);
			this->lblPick->TabIndex = 16;
			this->lblPick->Text = L"Pick One:";
			// 
			// lblQuestion
			// 
			this->lblQuestion->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 10.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblQuestion->Location = System::Drawing::Point(23, 20);
			this->lblQuestion->Name = L"lblQuestion";
			this->lblQuestion->Size = System::Drawing::Size(582, 173);
			this->lblQuestion->TabIndex = 15;
			this->lblQuestion->Text = L"Question goes here...";
			this->lblQuestion->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// pnlFeedback
			// 
			this->pnlFeedback->Controls->Add(this->btnContinue);
			this->pnlFeedback->Controls->Add(this->lblFeedback);
			this->pnlFeedback->Controls->Add(this->lblFeedbackTitle);
			this->pnlFeedback->Location = System::Drawing::Point(23, 104);
			this->pnlFeedback->Name = L"pnlFeedback";
			this->pnlFeedback->Padding = System::Windows::Forms::Padding(20);
			this->pnlFeedback->Size = System::Drawing::Size(628, 602);
			this->pnlFeedback->TabIndex = 21;
			this->pnlFeedback->Visible = false;
			// 
			// btnContinue
			// 
			this->btnContinue->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnContinue->FlatAppearance->BorderColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnContinue->FlatAppearance->BorderSize = 2;
			this->btnContinue->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnContinue->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->btnContinue->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnContinue->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnContinue->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btnContinue->Location = System::Drawing::Point(86, 506);
			this->btnContinue->Name = L"btnContinue";
			this->btnContinue->Size = System::Drawing::Size(450, 73);
			this->btnContinue->TabIndex = 12;
			this->btnContinue->Text = L"Continue";
			this->btnContinue->UseVisualStyleBackColor = false;
			// 
			// lblFeedback
			// 
			this->lblFeedback->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFeedback->Location = System::Drawing::Point(24, 110);
			this->lblFeedback->Name = L"lblFeedback";
			this->lblFeedback->Size = System::Drawing::Size(582, 346);
			this->lblFeedback->TabIndex = 16;
			this->lblFeedback->Text = L"Feedback";
			// 
			// lblFeedbackTitle
			// 
			this->lblFeedbackTitle->AutoSize = true;
			this->lblFeedbackTitle->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFeedbackTitle->Location = System::Drawing::Point(113, 20);
			this->lblFeedbackTitle->Name = L"lblFeedbackTitle";
			this->lblFeedbackTitle->Size = System::Drawing::Size(397, 39);
			this->lblFeedbackTitle->TabIndex = 15;
			this->lblFeedbackTitle->Text = L"Correct! / Incorrect";

			// 
			// Interview
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(674, 729);
			this->Controls->Add(this->lblDifficulty);
			this->Controls->Add(this->lblQuestionCount);
			this->Controls->Add(this->pnlQuestion);
			this->Controls->Add(this->pnlFeedback);
			this->Name = L"Interview";
			this->Padding = System::Windows::Forms::Padding(20);
			this->ShowIcon = false;
			this->Text = L"Interview";
			this->Load += gcnew System::EventHandler(this, &Interview::Interview_Load);
			this->pnlQuestion->ResumeLayout(false);
			this->pnlQuestion->PerformLayout();
			this->pnlFeedback->ResumeLayout(false);
			this->pnlFeedback->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private:
			void LoadQuestions(int count) {

				QuestionBank bank;   // reads Questions.txt
				std::vector<Question> picked = bank.getRandomQuestions(
					count, DifficultyStd());

				questions = gcnew List<QuestionData^>();
				for (const Question& q : picked) {
					std::string ca = q.getCorrectAnswer();
					int idx = -1;

					// Check if answer is stored as letter.
					if (ca.size() == 1) {
						char answerLetter = static_cast<char>(
							toupper(static_cast<unsigned char>(ca[0]))
							);

						if (answerLetter >= 'A' && answerLetter <= 'D') {
							idx = answerLetter - 'A';
						}
					}

					// compare it against the answer text
					else {
						if (ca == q.getOptionA()) idx = 0;
						else if (ca == q.getOptionB()) idx = 1;
						else if (ca == q.getOptionC()) idx = 2;
						else if (ca == q.getOptionD()) idx = 3;
					}

					// Skip questions with invalid correct answer
					if (idx == -1) {
						continue;
					}

					questions->Add(gcnew QuestionData(
						msclr::interop::marshal_as<String^>(q.getQuestionText()),
						msclr::interop::marshal_as<String^>(q.getOptionA()),
						msclr::interop::marshal_as<String^>(q.getOptionB()),
						msclr::interop::marshal_as<String^>(q.getOptionC()),
						msclr::interop::marshal_as<String^>(q.getOptionD()),
						idx
					));
				}
			}

			//Display question in the form
			void ShowQuestion() {
				QuestionData^ q = questions[currentIndex];
				lblQuestionCount->Text = String::Format(L"Question {0}/{1}", currentIndex + 1, questions->Count);
				lblQuestion->Text = q->text;
				rdoA->Text = L"A: " + q->options[0];
				rdoB->Text = L"B: " + q->options[1];
				rdoC->Text = L"C: " + q->options[2];
				rdoD->Text = L"D: " + q->options[3];
				rdoA->Checked = false; rdoB->Checked = false;
				rdoC->Checked = false; rdoD->Checked = false;
				pnlFeedback->Visible = false;
				pnlQuestion->Visible = true;
			}

			System::Void Interview_Load(System::Object^ sender, System::EventArgs^ e) {
				if (questions->Count == 0) {
					MessageBox::Show(L"No questions found for this difficulty. Check Questions.txt.", L"No questions");
					this->Close();   // FormClosed shows the menu
					return;
				}
				ShowQuestion();
			}

			//Submit button action
			System::Void btnSubmit_Click(System::Object^ sender, System::EventArgs^ e) {
				int picked = -1;
				if (rdoA->Checked) picked = 0;
				else if (rdoB->Checked) picked = 1;
				else if (rdoC->Checked) picked = 2;
				else if (rdoD->Checked) picked = 3;

				if (picked == -1) {
					MessageBox::Show(L"Please pick an answer.", L"No answer selected");
					return;
				}

				QuestionData^ q = questions[currentIndex];
				String^ letters = L"ABCD";
				if (picked == q->correct) {
					score++;
					lblFeedbackTitle->Text = L"Correct!";
					lblFeedback->Text = L"Nice work.";
				}
				else {
					lblFeedbackTitle->Text = L"Incorrect";
					lblFeedback->Text = L"The correct answer was " + letters->Substring(q->correct, 1) +
						L": " + q->options[q->correct];
				}

				btnContinue->Text = (currentIndex == questions->Count - 1) ? L"See Results" : L"Continue";
				pnlQuestion->Visible = false;
				pnlFeedback->Visible = true;
			}

			System::Void btnContinue_Click(System::Object^ sender, System::EventArgs^ e) {
				currentIndex++;
				if (currentIndex < questions->Count) {
					ShowQuestion();
					return;
				}

				double pct = 100.0 * score / questions->Count;
				saveResult(DifficultyStd(), score, questions->Count);
				MessageBox::Show(String::Format(L"Final score: {0}/{1} ({2:F0}%)", score, questions->Count, pct),
					L"Interview Complete");
				this->Close();   // FormClosed shows the menu
			}

			System::Void Interview_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
				mainMenu->Show();
			}
};
}