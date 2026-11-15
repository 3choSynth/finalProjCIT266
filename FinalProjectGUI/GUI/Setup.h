#pragma once
#include "Interview.h"

namespace FinalProjectGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Setup
	/// </summary>
	public ref class Setup : public System::Windows::Forms::Form
	{
	public:
		Setup(System::Windows::Forms::Form^ menu)
		{
			InitializeComponent();
			mainMenu = menu;
			cmbDifficulty->SelectedIndex = 0;
			this->FormClosed += gcnew FormClosedEventHandler(this, &Setup::Setup_FormClosed);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Setup()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btnStart;
	private: System::Windows::Forms::Form^ mainMenu;

	private: System::Windows::Forms::ComboBox^ cmbDifficulty;
	private: System::Windows::Forms::Button^ btnBack;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ numQuestions;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	protected:

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
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->cmbDifficulty = (gcnew System::Windows::Forms::ComboBox());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numQuestions = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numQuestions))->BeginInit();
			this->SuspendLayout();
			// 
			// btnStart
			// 
			this->btnStart->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnStart->FlatAppearance->BorderColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnStart->FlatAppearance->BorderSize = 2;
			this->btnStart->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->btnStart->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnStart->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStart->Location = System::Drawing::Point(118, 603);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(450, 73);
			this->btnStart->TabIndex = 1;
			this->btnStart->Text = L"Start";
			this->btnStart->UseVisualStyleBackColor = false;
			this->btnStart->Click += gcnew System::EventHandler(this, &Setup::btnStart_Click);
			// 
			// cmbDifficulty
			// 
			this->cmbDifficulty->AllowDrop = true;
			this->cmbDifficulty->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->cmbDifficulty->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbDifficulty->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbDifficulty->FormattingEnabled = true;
			this->cmbDifficulty->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Beginner", L"Intermediate", L"Expert" });
			this->cmbDifficulty->Location = System::Drawing::Point(118, 332);
			this->cmbDifficulty->Name = L"cmbDifficulty";
			this->cmbDifficulty->Size = System::Drawing::Size(450, 47);
			this->cmbDifficulty->TabIndex = 2;
			// 
			// btnBack
			// 
			this->btnBack->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnBack->FlatAppearance->BorderColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnBack->FlatAppearance->BorderSize = 2;
			this->btnBack->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 7.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBack->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->btnBack->Location = System::Drawing::Point(53, 53);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(100, 50);
			this->btnBack->TabIndex = 3;
			this->btnBack->Text = L"Back";
			this->btnBack->UseVisualStyleBackColor = false;
			this->btnBack->Click += gcnew System::EventHandler(this, &Setup::btnBack_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(111, 267);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(207, 39);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Difficulty";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(111, 442);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(378, 39);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Number of Questions";
			// 
			// numQuestions
			// 
			this->numQuestions->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numQuestions->Location = System::Drawing::Point(118, 502);
			this->numQuestions->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numQuestions->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numQuestions->Name = L"numQuestions";
			this->numQuestions->Size = System::Drawing::Size(120, 46);
			this->numQuestions->TabIndex = 6;
			this->numQuestions->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(162, 131);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(350, 45);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Interview Setup";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(104, 187);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(475, 29);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Configure your practice interview";
			// 
			// Setup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(674, 729);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->numQuestions);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->cmbDifficulty);
			this->Controls->Add(this->btnStart);
			this->Name = L"Setup";
			this->Padding = System::Windows::Forms::Padding(50);
			this->ShowIcon = false;
			this->Text = L"Programming Interview Practice";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numQuestions))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	System::Void Setup_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		mainMenu->Show();
	}
	
	private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnStart_Click(System::Object^ sender, System::EventArgs^ e) {
		if (cmbDifficulty->SelectedIndex == -1) {
			MessageBox::Show(L"Please choose a difficulty.", L"Missing difficulty");
			return;
		}
		String^ diff = cmbDifficulty->SelectedItem->ToString();
		int count = (int)numQuestions->Value;

		Interview^ interview = gcnew Interview(mainMenu, diff, count);
		interview->Show();

		this->FormClosed -= gcnew FormClosedEventHandler(this, &Setup::Setup_FormClosed);
		this->Close();
	}
};
}
