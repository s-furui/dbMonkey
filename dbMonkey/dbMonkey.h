#pragma once

#include <db_cxx.h>

namespace dbMonkey {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// dbMonkey の概要
	/// </summary>
	public ref class dbMonkey : public System::Windows::Forms::Form
	{
	public:
		dbMonkey(void);

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~dbMonkey();
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::BindingSource^  bindingSource1;



	private: System::ComponentModel::IContainer^  components;
	private: Db *db;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Key;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Data;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ファイルFToolStripMenuItem;


	private: Dbc *cursorp;
	protected:

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->Key = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Data = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->ファイルFToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoGenerateColumns = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->Key, this->Data });
			this->dataGridView1->DataSource = this->bindingSource1;
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(0, 24);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 21;
			this->dataGridView1->Size = System::Drawing::Size(284, 237);
			this->dataGridView1->TabIndex = 0;
			// 
			// Key
			// 
			this->Key->DataPropertyName = L"Key";
			this->Key->FillWeight = 20;
			this->Key->HeaderText = L"Key";
			this->Key->Name = L"Key";
			// 
			// Data
			// 
			this->Data->DataPropertyName = L"Data";
			this->Data->FillWeight = 80;
			this->Data->HeaderText = L"Data";
			this->Data->Name = L"Data";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ファイルFToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(284, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point(0, 239);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(284, 22);
			this->statusStrip1->TabIndex = 2;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// ファイルFToolStripMenuItem
			// 
			this->ファイルFToolStripMenuItem->Name = L"ファイルFToolStripMenuItem";
			this->ファイルFToolStripMenuItem->Size = System::Drawing::Size(66, 20);
			this->ファイルFToolStripMenuItem->Text = L"ファイル(&F)";
			// 
			// dbMonkey
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"dbMonkey";
			this->Text = L"dbMonkey";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
