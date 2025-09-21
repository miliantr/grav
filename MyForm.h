#pragma once
#include <cmath>
#include "Oper.h"
#include "Tintegrator.h"
#include "Tmodel.h"
#include <fstream>
#include <sys/stat.h>
namespace graphic {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TextBox^ lambda;
	private: System::Windows::Forms::TextBox^ phi;
	private: System::Windows::Forms::TextBox^ date;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ UTC;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::GroupBox^ groupBox3;

	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Coor;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CGPZ;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NGPZ;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ AGPZ;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::TextBox^ v0;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ eks;


	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ a;

	private: System::Windows::Forms::TextBox^ w_lil;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ i;


	private: System::Windows::Forms::TextBox^ w_big;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ Tk;
	private: System::Windows::Forms::TextBox^ dt;
	private: System::Windows::Forms::TextBox^ T0;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->UTC = (gcnew System::Windows::Forms::TextBox());
			this->date = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->phi = (gcnew System::Windows::Forms::TextBox());
			this->lambda = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->Tk = (gcnew System::Windows::Forms::TextBox());
			this->dt = (gcnew System::Windows::Forms::TextBox());
			this->T0 = (gcnew System::Windows::Forms::TextBox());
			this->v0 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->eks = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->a = (gcnew System::Windows::Forms::TextBox());
			this->w_lil = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->i = (gcnew System::Windows::Forms::TextBox());
			this->w_big = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Coor = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CGPZ = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NGPZ = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AGPZ = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(16, 15);
			this->tabControl1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(696, 597);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->chart1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage1->Size = System::Drawing::Size(688, 568);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// chart1
			// 
			this->chart1->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(4, 4);
			this->chart1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->Name = L"Series2";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(680, 560);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->groupBox2);
			this->tabPage2->Controls->Add(this->groupBox1);
			this->tabPage2->Controls->Add(this->label1);
			this->tabPage2->Controls->Add(this->comboBox1);
			this->tabPage2->Controls->Add(this->button1);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage2->Size = System::Drawing::Size(684, 568);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->UTC);
			this->groupBox2->Controls->Add(this->date);
			this->groupBox2->Location = System::Drawing::Point(449, 380);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox2->Size = System::Drawing::Size(152, 94);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Дата и UTC";
			// 
			// UTC
			// 
			this->UTC->Location = System::Drawing::Point(8, 57);
			this->UTC->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->UTC->Name = L"UTC";
			this->UTC->Size = System::Drawing::Size(132, 22);
			this->UTC->TabIndex = 5;
			this->UTC->Text = L"3";
			this->UTC->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// date
			// 
			this->date->Location = System::Drawing::Point(8, 23);
			this->date->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->date->Name = L"date";
			this->date->Size = System::Drawing::Size(132, 22);
			this->date->TabIndex = 4;
			this->date->Text = L"21032022";
			this->date->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->phi);
			this->groupBox1->Controls->Add(this->lambda);
			this->groupBox1->Location = System::Drawing::Point(68, 382);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Size = System::Drawing::Size(153, 92);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Широта и долгота";
			// 
			// phi
			// 
			this->phi->Location = System::Drawing::Point(8, 23);
			this->phi->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->phi->Name = L"phi";
			this->phi->Size = System::Drawing::Size(132, 22);
			this->phi->TabIndex = 2;
			this->phi->Text = L"55,75";
			this->phi->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lambda
			// 
			this->lambda->Location = System::Drawing::Point(8, 55);
			this->lambda->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->lambda->Name = L"lambda";
			this->lambda->Size = System::Drawing::Size(132, 22);
			this->lambda->TabIndex = 3;
			this->lambda->Text = L"37,62";
			this->lambda->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(312, 441);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 5;
			this->label1->Text = L"label1";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Эволюция тени гнома на заданную дату", L"Эволюция продолжительности светового дня" });
			this->comboBox1->Location = System::Drawing::Point(68, 103);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(532, 24);
			this->comboBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(8, 183);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(665, 156);
			this->button1->TabIndex = 0;
			this->button1->Text = L"График";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->groupBox4);
			this->tabPage3->Controls->Add(this->groupBox3);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage3->Size = System::Drawing::Size(684, 568);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"tabPage3";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->label10);
			this->groupBox4->Controls->Add(this->label9);
			this->groupBox4->Controls->Add(this->label8);
			this->groupBox4->Controls->Add(this->Tk);
			this->groupBox4->Controls->Add(this->dt);
			this->groupBox4->Controls->Add(this->T0);
			this->groupBox4->Controls->Add(this->v0);
			this->groupBox4->Controls->Add(this->label7);
			this->groupBox4->Controls->Add(this->eks);
			this->groupBox4->Controls->Add(this->label6);
			this->groupBox4->Controls->Add(this->label5);
			this->groupBox4->Controls->Add(this->a);
			this->groupBox4->Controls->Add(this->w_lil);
			this->groupBox4->Controls->Add(this->label4);
			this->groupBox4->Controls->Add(this->i);
			this->groupBox4->Controls->Add(this->w_big);
			this->groupBox4->Controls->Add(this->label3);
			this->groupBox4->Controls->Add(this->label2);
			this->groupBox4->Controls->Add(this->button3);
			this->groupBox4->Location = System::Drawing::Point(8, 299);
			this->groupBox4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox4->Size = System::Drawing::Size(665, 258);
			this->groupBox4->TabIndex = 1;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Задание орбиты ИСЗ";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(344, 196);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(114, 16);
			this->label10->TabIndex = 18;
			this->label10->Text = L"Конечное время";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(228, 196);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(32, 16);
			this->label9->TabIndex = 17;
			this->label9->Text = L"Шаг";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(21, 196);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(123, 16);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Начальное время";
			// 
			// Tk
			// 
			this->Tk->Location = System::Drawing::Point(340, 215);
			this->Tk->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Tk->Name = L"Tk";
			this->Tk->Size = System::Drawing::Size(132, 22);
			this->Tk->TabIndex = 15;
			this->Tk->Text = L"10000";
			// 
			// dt
			// 
			this->dt->Location = System::Drawing::Point(183, 215);
			this->dt->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dt->Name = L"dt";
			this->dt->Size = System::Drawing::Size(132, 22);
			this->dt->TabIndex = 14;
			this->dt->Text = L"60";
			// 
			// T0
			// 
			this->T0->Location = System::Drawing::Point(17, 215);
			this->T0->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->T0->Name = L"T0";
			this->T0->Size = System::Drawing::Size(132, 22);
			this->T0->TabIndex = 13;
			this->T0->Text = L"0";
			// 
			// v0
			// 
			this->v0->Location = System::Drawing::Point(496, 142);
			this->v0->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->v0->Name = L"v0";
			this->v0->Size = System::Drawing::Size(132, 22);
			this->v0->TabIndex = 12;
			this->v0->Text = L"0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(477, 106);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(156, 32);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Истинная аномалия на\r\nначало эксперимента";
			// 
			// eks
			// 
			this->eks->Location = System::Drawing::Point(496, 60);
			this->eks->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->eks->Name = L"eks";
			this->eks->Size = System::Drawing::Size(132, 22);
			this->eks->TabIndex = 10;
			this->eks->Text = L"0,4";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(495, 41);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(129, 16);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Эксцентриситет, е";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(245, 122);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(185, 16);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Большая полуось орбиты, a";
			// 
			// a
			// 
			this->a->Location = System::Drawing::Point(273, 142);
			this->a->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->a->Name = L"a";
			this->a->Size = System::Drawing::Size(132, 22);
			this->a->TabIndex = 7;
			this->a->Text = L"10000";
			// 
			// w_lil
			// 
			this->w_lil->Location = System::Drawing::Point(273, 60);
			this->w_lil->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->w_lil->Name = L"w_lil";
			this->w_lil->Size = System::Drawing::Size(132, 22);
			this->w_lil->TabIndex = 6;
			this->w_lil->Text = L"0";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(257, 41);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(154, 16);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Широта перицентра, w";
			// 
			// i
			// 
			this->i->Location = System::Drawing::Point(39, 142);
			this->i->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->i->Name = L"i";
			this->i->Size = System::Drawing::Size(132, 22);
			this->i->TabIndex = 4;
			this->i->Text = L"45";
			// 
			// w_big
			// 
			this->w_big->Location = System::Drawing::Point(39, 60);
			this->w_big->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->w_big->Name = L"w_big";
			this->w_big->Size = System::Drawing::Size(132, 22);
			this->w_big->TabIndex = 3;
			this->w_big->Text = L"0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(35, 122);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(148, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Наклонение орбиты, i";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 41);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(201, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Долгота восходящего узла, W";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(481, 202);
			this->button3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(176, 49);
			this->button3->TabIndex = 0;
			this->button3->Text = L"Моделировать движение";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->dataGridView1);
			this->groupBox3->Controls->Add(this->button2);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox3->Location = System::Drawing::Point(4, 4);
			this->groupBox3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox3->Size = System::Drawing::Size(676, 292);
			this->groupBox3->TabIndex = 0;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Тестирование разработанных моделей";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Coor, this->CGPZ,
					this->NGPZ, this->AGPZ
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->dataGridView1->Location = System::Drawing::Point(4, 54);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(668, 234);
			this->dataGridView1->TabIndex = 3;
			// 
			// Coor
			// 
			this->Coor->HeaderText = L"Coords";
			this->Coor->MinimumWidth = 6;
			this->Coor->Name = L"Coor";
			this->Coor->Width = 125;
			// 
			// CGPZ
			// 
			this->CGPZ->HeaderText = L"CGPZ";
			this->CGPZ->MinimumWidth = 6;
			this->CGPZ->Name = L"CGPZ";
			this->CGPZ->Width = 125;
			// 
			// NGPZ
			// 
			this->NGPZ->HeaderText = L"NGPZ";
			this->NGPZ->MinimumWidth = 6;
			this->NGPZ->Name = L"NGPZ";
			this->NGPZ->Width = 125;
			// 
			// AGPZ
			// 
			this->AGPZ->HeaderText = L"AGPZ";
			this->AGPZ->MinimumWidth = 6;
			this->AGPZ->Name = L"AGPZ";
			this->AGPZ->Width = 125;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(21, 23);
			this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(147, 28);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Проверка";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(728, 626);
			this->Controls->Add(this->tabControl1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		ofstream test; test.open("test.txt"); Tintegrator* integr = new TDormand();
		Tmodel* model; Tvector X0;

		X0.resize(6);
		X0(0) = -2.741248720132488e7;	X0(1) = 1.332710216571607e8;	X0(2) = 5.780072873943681e7;
		X0(3) = -2.980512290685886e1;	X0(4) = -4.971761443577496;	    X0(5) = -2.154845308279276;
		
		
		vector <double> JD = { 2459580.5,	2459659.5,	2459752.5,	2459845.5,	2459935.5 };
		//						01.01.22	21.03.22	22.06.22	23.09.22	22.12.22

		if (comboBox1->SelectedIndex == 0) {
			double Date = double::Parse(date->Text), JD_end;
			int day = int(Date / 1e6),
				month = int(Date / 1e4) % 100,
				year = int(Date) % 10000,
				hour = 0,
				utc = int::Parse(UTC->Text);
			get_JD(year, month, day, 0, 0, 0);
			if (utc > 0) {
				if (day != 1) {
					day -= 1;
					hour = 24 - utc;
				}
				else {
					if (month == 3) {
						day = 28;
						month = 2;
						hour = 24 - utc;
					}
					else if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11) {
						day = 31;
						month -= 1;
						hour = 24 - utc;
					}
					else {
						day = 30;
						month -= 1;
						hour = 24 - utc;
					}
				}
			}
			if (utc < 0) {
					if (month == 4 || month == 6 || month == 9 || month == 11) {
						if (day == 30) {
							day = 1;
							month += 1;
							hour = utc;
						}
					}
					else if (month == 2){
						if (day == 28) {
							day = 1;
							month += 1;
							hour = utc;
						}
					}
					else {
						if (day == 31) {
							day = 1;
							month += 1;
							hour = utc;
						}
					}
			}
			JD_end = get_JD(year, month, day, hour, 0, 0);
			model = new TEarthModel(0, (JD_end - JD[0]) * 24 * 3600, (JD_end - JD[0]) * 24 * 3600, X0);
			integr->Run(model);
			int gnomon = 1000;
			//double gnomon = sqrt(pow(X0(0), 2) + pow(X0(1), 2) + pow(X0(2), 2));
			ofstream Res; Res.open("Result.txt");
			ofstream help; help.open("help.txt");
			help << "X\t\tY\t\tZ\n";

			Tmatrix Result = model->get_Result();
			for (int i = 1; i < 7; i++)
				X0(i-1) = Result(i, Result.get_size_j() - 1);
			/*	22.06
			X0(0) = -5.950325775423507e5; X0(1) = -1.392460026101214e8; X0(2) = -6.033041913263810e7;
			X0(3) = 2.930124801506698e1; X0(4) = 1.712420552181274e-2; X0(5) = 7.453919706606499e-3;
			*/
			
			/*	21.03
			X0(0) = -1.503101968223290e8;	X0(1) = 2.388181224842258e5;	X0(2) = 1.344286818174785e5;
			X0(3) = -4.633867856978692e-1;	X0(4) = -2.744939467460866e1;	X0(5) = -1.189889265709811e1;
			*/
			
			/*
			X0(0) = -5.950325775423507e5; X0(1) = -1.392460026101214e8; X0(2) = -6.033041913263810e7;
			X0(3) = 2.930124801506698e1; X0(4) = 1.712420552181274e-2; X0(5) = 7.453919706606499e-3;
			*/
			delete model;
			model = new TSunIModel(double::Parse(phi->Text), double::Parse(lambda->Text), double::Parse(date->Text), /*-*/-utc * 3600, 86400 - utc * 3600,/*60*/ 30, X0, false, utc);
			integr->Run(model);
			Result = model->get_Result();
			test << "X\t\tZ\n";
			chart1->Series["Series1"]->Points->Clear();
			chart1->Series["Series1"]->Color = Color::Red;
			double Dlin1 = sqrt(pow(Result(1, i), 2) + pow(Result(2, i), 2) + pow(Result(3, i), 2));
			for (int i = 0; i < Result.get()[0].size(); i++) {
				double Dlin = sqrt(pow(Result(1, i), 2) + pow(Result(2, i), 2) + pow(Result(3, i), 2));
				if (Dlin >= Dlin1) {
					chart1->Series["Series1"]->Points->AddXY(Result(3, i) / gnomon, Result(1, i) / gnomon);
					test << Result(1, i) / gnomon << "\t\t" << Result(3, i) / gnomon << endl;
				}
				else
					continue;
			}
			delete model;
		}
		else if (comboBox1->SelectedIndex == 1) {
			double Date = double::Parse(date->Text);
			int day = int(Date / 1e6),
				month = int(Date / 1e4) % 100,
				year = int(Date) % 10000,
				hour = 0,
				utc = int::Parse(UTC->Text);
			//get_JD(year, month, day, 0, 0, 0);
			if (utc > 0) {
				if (day != 1) {
					day -= 1;
					hour = 24 - utc;
				}
				else {
					if (month == 3) {
						day = 28;
						month = 2;
						hour = 24 - utc;
					}
					else if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11) {
						day = 31;
						month -= 1;
						hour = 24 - utc;
					}
					else {
						day = 30;
						month -= 1;
						hour = 24 - utc;
					}
				}
			}
			if (utc < 0) {
				if (month == 4 || month == 6 || month == 9 || month == 11) {
					if (day == 30) {
						day = 1;
						month += 1;
						hour = utc;
					}
				}
				else if (month == 2) {
					if (day == 28) {
						day = 1;
						month += 1;
						hour = utc;
					}
				}
				else {
					if (day == 31) {
						day = 1;
						month += 1;
						hour = utc;
					}
				}
			}
			
			ofstream Res_txt; Res_txt.open("Result.txt"); 
			Res_txt << "Time Rise\t\tTime SunSet\n";
			Res_txt.close();
			ofstream help; help.open("help.txt");
			help << "Num_of_Day\n";

			model = new TSunIModel(double::Parse(phi->Text), double::Parse(lambda->Text), double::Parse(date->Text), 0, 365 * 24 * 3600, 900, X0, true, utc);
			integr->Run(model);

			Tvector Res_rise = static_cast<TSunIModel*>(model)->getDur_Day(1); Res_rise = Res_rise + utc * 360;
			Tvector Res_SS = static_cast<TSunIModel*>(model)->getDur_Day(2); Res_SS = Res_SS + utc * 360;

			Tvector Res(Res_SS.size());
			Tvector old_Res = static_cast<TSunIModel*>(model)->getDur_Day(0);

			test << "Day\t\tTime\n";

			chart1->Series["Series2"]->Points->Clear();
			for (int i = 0; i < old_Res.size(); i++) {
				chart1->Series["Series1"]->Points->AddXY(i, old_Res(i) / 3600);
				test << i + 1 << "\t\t" << Res(i) << endl;
			}

			for (int i = 0; i < Res_SS.size(); i++) {
				if (Res_rise(i) >= 8 * 3600) {
					if (Res_SS(i) <= 20 * 3600)
						Res(i) = Res_SS(i) - Res_rise(i);
					else
						Res(i) = 20 * 3600 - Res_rise(i);
				}
				else {
					if (Res_SS(i) <= 20 * 3600)
						Res(i) = Res_SS(i) - 8 * 3600;
					else
						Res(i) = 20 * 3600 - 8 * 3600;
				}
			}

			chart1->Series["Series1"]->Points->Clear();
			chart1->Series["Series1"]->Color = Color::Blue;
			test << "i\t\tt\n";
			for (int i = 0; i < Res.size(); i++) {
				chart1->Series["Series1"]->Points->AddXY(i, Res(i)/3600);
				
			}

			delete model;
		}
		delete integr;
		test.close();
	}
private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Tvector X1({ 0, 0, 1e7 }), X2({ 1e7, 0, 0 });
	for (int i = 0; i < 6; i++) {
		dataGridView1->Rows->Add();
		if(i==2 || i==3)
			dataGridView1->Rows[i]->Cells[0]->Value = "1e7";
		else
			dataGridView1->Rows[i]->Cells[0]->Value = "0";
	}
	
	TGravityModel* grav = new TCentralGravityModel();
	Tvector g_out1 = grav->getAcceleration(X1), g_out2 = grav->getAcceleration(X2);
	for (int i = 0; i < 3; i++) {
		dataGridView1->Rows[i]->Cells[1]->Value = g_out1(i);
		dataGridView1->Rows[i+3]->Cells[1]->Value = g_out2(i);
	}

	grav = new TNormalGravityModel();
	g_out1 = grav->getAcceleration(X1); g_out2 = grav->getAcceleration(X2);
	for (int i = 0; i < 3; i++) {
		dataGridView1->Rows[i]->Cells[2]->Value = g_out1(i);
		dataGridView1->Rows[i + 3]->Cells[2]->Value = g_out2(i);
	}

	grav = new TAnomalGravityModel();
	g_out1 = grav->getAcceleration(X1), g_out2 = grav->getAcceleration(X2);
	for (int i = 0; i < 3; i++) {
		dataGridView1->Rows[i]->Cells[3]->Value = g_out1(i);
		dataGridView1->Rows[i + 3]->Cells[3]->Value = g_out2(i);
	}
	delete grav;
}
private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	Tvector X0(6);
	Tmodel* model = new TSatellite(double::Parse(T0->Text), double::Parse(Tk->Text), double::Parse(dt->Text), X0);
	static_cast<TSatellite*>(model)->SetOrbit(double::Parse(w_big->Text) * M_PI / 180, double::Parse(i->Text) * M_PI / 180, double::Parse(w_lil->Text) * M_PI / 180,
		double::Parse(a->Text) * 1e3, double::Parse(eks->Text), double::Parse(v0->Text) * M_PI / 180);
	
	TGravityModel* grav = new TCentralGravityModel();
	static_cast<TSatellite*>(model)->setGM(grav);

	Tintegrator* intgr = new TDormand();
	intgr->Run(model);
	Tmatrix Results[3];
	Results[0] = model->get_Result();
	model->clr_Results();

	grav = new TNormalGravityModel();
	static_cast<TSatellite*>(model)->setGM(grav);
	intgr->Run(model);
	Results[1] = model->get_Result();
	model->clr_Results();

	grav = new TAnomalGravityModel();
	static_cast<TSatellite*>(model)->setGM(grav);
	intgr->Run(model);
	Results[2] = model->get_Result();
	model->clr_Results();

	ofstream files; files.open("Central_Normal_Anomal.txt");
	files << "Time\t\tXc\t\tYc\t\tZc\t\tXn\t\tYn\t\tZn\t\tXa\t\tYa\t\tZa\n";
	for (int i = 0; i < Results[0].get_size_j(); i++) {
		files << Results[0](0, i) << "\t\t";
		for(int r = 0; r<3; r++)
			files << Results[r](1, i) << "\t\t" << Results[r](2, i) << "\t\t" << Results[r](3, i) << "\t\t";
		files << endl;
	}
	files.close();

	delete grav, model, intgr;
}
};
}
	