#pragma once
#include "../Project1/Classes.h"

namespace FinalProjectGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Shows previous scores
	/// </summary>
	public ref class History : public System::Windows::Forms::Form
	{
	public:
		History(System::Windows::Forms::Form^ menu)
		{
			InitializeComponent();
			mainMenu = menu;
			this->FormClosed += gcnew FormClosedEventHandler(this, &History::History_FormClosed);

			LoadHistory();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~History()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ lblTitle;
	private: System::Windows::Forms::Form^ mainMenu;

	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Date;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Difficulty;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Score;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Percentage;
	private: System::Windows::Forms::Label^ lblLatestTitle;

	private: System::Windows::Forms::Panel^ pnlSummary;
	private: System::Windows::Forms::Label^ lblBestTitle;
	private: System::Windows::Forms::Label^ lblAverageTitle;
	private: System::Windows::Forms::Label^ lblLatest;
	private: System::Windows::Forms::Label^ lblAverage;
	private: System::Windows::Forms::Label^ lblBest;
	private: System::Windows::Forms::Label^ lblSummaryTitle;
	private: System::Windows::Forms::Panel^ panel1;


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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Difficulty = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Score = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Percentage = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->lblLatestTitle = (gcnew System::Windows::Forms::Label());
			this->pnlSummary = (gcnew System::Windows::Forms::Panel());
			this->lblAverage = (gcnew System::Windows::Forms::Label());
			this->lblBest = (gcnew System::Windows::Forms::Label());
			this->lblLatest = (gcnew System::Windows::Forms::Label());
			this->lblAverageTitle = (gcnew System::Windows::Forms::Label());
			this->lblBestTitle = (gcnew System::Windows::Forms::Label());
			this->lblSummaryTitle = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->pnlSummary->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->ColumnHeadersDefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Date, this->Difficulty,
					this->Score, this->Percentage
			});
			this->dataGridView1->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::ControlText;
			this->dataGridView1->Location = System::Drawing::Point(53, 455);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 82;
			this->dataGridView1->RowTemplate->Height = 33;
			this->dataGridView1->Size = System::Drawing::Size(568, 249);
			this->dataGridView1->TabIndex = 0;
			// 
			// Date
			// 
			this->Date->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Date->DividerWidth = 2;
			this->Date->FillWeight = 110;
			this->Date->HeaderText = L"Date";
			this->Date->MinimumWidth = 10;
			this->Date->Name = L"Date";
			this->Date->ReadOnly = true;
			this->Date->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Date->HeaderCell->Style->Alignment = DataGridViewContentAlignment::MiddleCenter;
			// 
			// Difficulty
			// 
			this->Difficulty->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Difficulty->DividerWidth = 2;
			this->Difficulty->FillWeight = 110;
			this->Difficulty->HeaderText = L"Difficulty";
			this->Difficulty->MinimumWidth = 10;
			this->Difficulty->Name = L"Difficulty";
			this->Difficulty->ReadOnly = true;
			this->Difficulty->HeaderCell->Style->Alignment = DataGridViewContentAlignment::MiddleCenter;
			// 
			// Score
			// 
			this->Score->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Score->DividerWidth = 2;
			this->Score->HeaderText = L"Score";
			this->Score->MinimumWidth = 10;
			this->Score->Name = L"Score";
			this->Score->ReadOnly = true;
			this->Score->HeaderCell->Style->Alignment = DataGridViewContentAlignment::MiddleCenter;
			// 
			// Percentage
			// 
			this->Percentage->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Percentage->DividerWidth = 2;
			this->Percentage->HeaderText = L"Percentage";
			this->Percentage->MinimumWidth = 10;
			this->Percentage->Name = L"Percentage";
			this->Percentage->ReadOnly = true;
			this->Percentage->HeaderCell->Style->Alignment = DataGridViewContentAlignment::MiddleCenter;
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = false;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitle->Location = System::Drawing::Point(136, 130);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(394, 45);
			this->lblTitle->TabIndex = 8;
			this->lblTitle->Text = L"Interview History";
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
			this->btnBack->TabIndex = 9;
			this->btnBack->Text = L"Back";
			this->btnBack->UseVisualStyleBackColor = false;
			this->btnBack->Click += gcnew System::EventHandler(this, &History::btnBack_Click);
			// 
			// lblLatestTitle
			// 
			this->lblLatestTitle->AutoSize = false;
			this->lblLatestTitle->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblLatestTitle->Location = System::Drawing::Point(0, 85);
			this->lblLatestTitle->Name = L"lblLatestTitle";
			this->lblLatestTitle->Size = System::Drawing::Size(186, 29);
			this->lblLatestTitle->TabIndex = 10;
			this->lblLatestTitle->Text = L"Latest Score";
			this->lblLatestTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			
			// 
			// pnlSummary
			// 
			this->pnlSummary->Controls->Add(this->lblAverage);
			this->pnlSummary->Controls->Add(this->lblBest);
			this->pnlSummary->Controls->Add(this->lblLatest);
			this->pnlSummary->Controls->Add(this->lblAverageTitle);
			this->pnlSummary->Controls->Add(this->lblBestTitle);
			this->pnlSummary->Controls->Add(this->lblLatestTitle);
			this->pnlSummary->Location = System::Drawing::Point(61, 206);
			this->pnlSummary->Name = L"pnlSummary";
			this->pnlSummary->Size = System::Drawing::Size(558, 125);
			this->pnlSummary->TabIndex = 11;
			// 
			// lblAverage
			// 
			this->lblAverage->AutoSize = false;
			this->lblAverage->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAverage->Location = System::Drawing::Point(372, 18);
			this->lblAverage->Name = L"lblAverage";
			this->lblAverage->Size = System::Drawing::Size(186, 45);
			this->lblAverage->TabIndex = 14;
			this->lblAverage->Text = L"0%";
			this->lblAverage->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblBest
			// 
			this->lblBest->AutoSize = false;
			this->lblBest->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBest->Location = System::Drawing::Point(186, 18);
			this->lblBest->Name = L"lblBest";
			this->lblBest->Size = System::Drawing::Size(186, 45);
			this->lblBest->TabIndex = 13;
			this->lblBest->Text = L"0/0";
			this->lblBest->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblLatest
			// 
			this->lblLatest->AutoSize = false;
			this->lblLatest->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblLatest->Location = System::Drawing::Point(0, 18);
			this->lblLatest->Name = L"lblLatest";
			this->lblLatest->Size = System::Drawing::Size(186, 45);
			this->lblLatest->TabIndex = 12;
			this->lblLatest->Text = L"0/0";
			this->lblLatest->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblAverageTitle
			// 
			this->lblAverageTitle->AutoSize = false;
			this->lblAverageTitle->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAverageTitle->Location = System::Drawing::Point(372, 85);
			this->lblAverageTitle->Name = L"lblAverageTitle";
			this->lblAverageTitle->Size = System::Drawing::Size(186, 29);
			this->lblAverageTitle->TabIndex = 12;
			this->lblAverageTitle->Text = L"Average";
			this->lblAverageTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblBestTitle
			// 
			this->lblBestTitle->AutoSize = false;
			this->lblBestTitle->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBestTitle->Location = System::Drawing::Point(186, 85);
			this->lblBestTitle->Name = L"lblBestTitle";
			this->lblBestTitle->Size = System::Drawing::Size(186, 29);
			this->lblBestTitle->TabIndex = 11;
			this->lblBestTitle->Text = L"Best Score";
			this->lblBestTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblSummaryTitle
			// 
			this->lblSummaryTitle->AutoSize = true;
			this->lblSummaryTitle->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSummaryTitle->Location = System::Drawing::Point(136, 376);
			this->lblSummaryTitle->Name = L"lblSummaryTitle";
			this->lblSummaryTitle->Size = System::Drawing::Size(394, 45);
			this->lblSummaryTitle->TabIndex = 12;
			this->lblSummaryTitle->Text = L"Previous Attempts";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Location = System::Drawing::Point(53, 199);
			this->panel1->Name = L"panel1";
			this->panel1->Padding = System::Windows::Forms::Padding(10);
			this->panel1->Size = System::Drawing::Size(572, 139);
			this->panel1->TabIndex = 15;
			// 
			// History
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(674, 729);
			this->Controls->Add(this->lblSummaryTitle);
			this->Controls->Add(this->pnlSummary);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->lblTitle);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->panel1);
			this->Name = L"History";
			this->Padding = System::Windows::Forms::Padding(50);
			this->ShowIcon = false;
			this->Text = L"Interview History";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->pnlSummary->ResumeLayout(false);
			this->pnlSummary->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//Loads History when form opens

	private: void LoadHistory() {
		std::vector<HistoryEntry> list = loadHistory();
		if (list.empty()) return;

		double sum = 0, bestPct = -1;
		int bestIdx = 0;
		for (int i = 0; i < (int)list.size(); i++) {
			const HistoryEntry& e = list[i];
			double pct = e.total > 0 ? 100.0 * e.score / e.total : 0;
			sum += pct;
			if (pct > bestPct) { bestPct = pct; bestIdx = i; }

			// Insert at the top so the newest attempt shows first
			dataGridView1->Rows->Insert(0,
				gcnew String(e.date.c_str()),
				gcnew String(e.difficulty.c_str()),
				String::Format(L"{0}/{1}", e.score, e.total),
				String::Format(L"{0:F0}%", pct));
		}

		const HistoryEntry& last = list.back();
		const HistoryEntry& best = list[bestIdx];
		lblLatest->Text = String::Format(L"{0}/{1}", last.score, last.total);
		lblBest->Text = String::Format(L"{0}/{1}", best.score, best.total);
		lblAverage->Text = String::Format(L"{0:F0}%", sum / list.size());
	}

	private: System::Void History_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
			mainMenu->Show();
		}

	private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();   // History_FormClosed shows the menu
	}
};
}
