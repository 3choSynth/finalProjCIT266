#pragma once
#include "Setup.h"
#include "History.h"

namespace FinalProjectGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ interview;
	protected:

	private: System::Windows::Forms::Button^ history;

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
			this->interview = (gcnew System::Windows::Forms::Button());
			this->history = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// interview
			// 
			this->interview->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->interview->FlatAppearance->BorderColor = System::Drawing::SystemColors::ActiveCaption;
			this->interview->FlatAppearance->BorderSize = 2;
			this->interview->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->interview->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->interview->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->interview->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->interview->ForeColor = System::Drawing::SystemColors::ControlText;
			this->interview->Location = System::Drawing::Point(106, 219);
			this->interview->Name = L"interview";
			this->interview->Size = System::Drawing::Size(450, 73);
			this->interview->TabIndex = 0;
			this->interview->Text = L"Interview";
			this->interview->UseVisualStyleBackColor = false;
			this->interview->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// history
			// 
			this->history->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->history->FlatAppearance->BorderColor = System::Drawing::SystemColors::ActiveCaption;
			this->history->FlatAppearance->BorderSize = 2;
			this->history->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->history->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->history->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->history->Location = System::Drawing::Point(106, 407);
			this->history->Name = L"history";
			this->history->Size = System::Drawing::Size(450, 73);
			this->history->TabIndex = 1;
			this->history->Text = L"View Progress";
			this->history->UseVisualStyleBackColor = false;
			this->history->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(674, 729);
			this->Controls->Add(this->history);
			this->Controls->Add(this->interview);
			this->Name = L"MyForm";
			this->Padding = System::Windows::Forms::Padding(50);
			this->ShowIcon = false;
			this->Text = L"Programming Interview Practice";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Setup^ setup = gcnew Setup(this);

		setup->Show();

		this->Hide();
	}
	
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		History^ history = gcnew History(this);

		history->Show();

		this->Hide();
	}
	};
}
