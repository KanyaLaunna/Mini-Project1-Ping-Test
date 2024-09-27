#pragma once

// uncomment to execute the rk1-utils:
//    #include "rk1_Utils_demo.h"  // shows how the rk1-utils can be used

#include "Header1.h"
#include "Header2.h"
#include <iostream>
#include <string>

namespace CppCLRWinFormsProject {

  using namespace System;
  using namespace System::ComponentModel;
  using namespace System::Collections;
  using namespace System::Windows::Forms;
  using namespace System::Data;
  using namespace System::Drawing;
  using namespace System::IO; // Include this for StreamReader
  using namespace System::Collections::Generic; // Required for List<T>


  /// <summary>
  /// Summary for Form1
  /// </summary>
  public ref class Form1 : public System::Windows::Forms::Form
  {
  public:
      Form1(void)
      {
          InitializeComponent();
          // Initialization code for buttons, text boxes, combo boxes, etc.
          this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());

          // Setup for BackgroundWorker
          this->backgroundWorker1->WorkerReportsProgress = true;
          this->backgroundWorker1->WorkerSupportsCancellation = true;
          this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker1_DoWork);
          this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &Form1::backgroundWorker1_ProgressChanged);
          this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Form1::backgroundWorker1_RunWorkerCompleted);
          //
          //TODO: Add the constructor code here
          //

          // uncomment to execute the rk1-utils:
          //    N_rk1_Utils_demo::execute(); // shows how the rk1-utils can be used

      }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~Form1()
    {
      if (components)
      {
        delete components;
      }
    }
  private: System::Windows::Forms::TextBox^ textbox1;

  protected:


  private: System::Windows::Forms::Button^ button1;
  private: System::Windows::Forms::Button^ button2;
  private: System::Windows::Forms::ComboBox^ comboBox1;

  private: System::Windows::Forms::Button^ button3;
  private: System::Windows::Forms::CheckBox^ checkbox1;





  private: System::Windows::Forms::Label^ label2;
  private: System::Windows::Forms::Label^ label1;
  private: System::Windows::Forms::ListView^ listview1;
         // ListView to display items
  private: System::Windows::Forms::ColumnHeader^ columnHeader1;
  private: System::Windows::Forms::Timer^ Timer;
  private: System::Windows::Forms::Label^ labelTimer;

  private: System::ComponentModel::IContainer^ components;
  private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
  

  protected:

  private:
      int Second;
      int Minute;
      List<String^>^ csvContentList = gcnew List<String^>();
      String^ selectedFilePath;
      String^ selectedIP;
      int pingCount;
    /// Required designer variable.
    /// </summary>


#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void)
    {
        this->components = (gcnew System::ComponentModel::Container());
        this->textbox1 = (gcnew System::Windows::Forms::TextBox());
        this->button1 = (gcnew System::Windows::Forms::Button());
        this->button2 = (gcnew System::Windows::Forms::Button());
        this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
        this->button3 = (gcnew System::Windows::Forms::Button());
        this->checkbox1 = (gcnew System::Windows::Forms::CheckBox());
        this->listview1 = (gcnew System::Windows::Forms::ListView());
        this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->Timer = (gcnew System::Windows::Forms::Timer(this->components));
        this->labelTimer = (gcnew System::Windows::Forms::Label());
        this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
        this->SuspendLayout();
        // 
        // textbox1
        // 
        this->textbox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
            | System::Windows::Forms::AnchorStyles::Left)
            | System::Windows::Forms::AnchorStyles::Right));
        this->textbox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->textbox1->Location = System::Drawing::Point(142, 10);
        this->textbox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
        this->textbox1->Name = L"textbox1";
        this->textbox1->Size = System::Drawing::Size(579, 35);
        this->textbox1->TabIndex = 0;
        // 
        // button1
        // 
        this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
        this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->button1->Location = System::Drawing::Point(609, 55);
        this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
        this->button1->Name = L"button1";
        this->button1->Size = System::Drawing::Size(112, 35);
        this->button1->TabIndex = 2;
        this->button1->Text = L"Start";
        this->button1->UseVisualStyleBackColor = true;
        this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
        // 
        // button2
        // 
        this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
        this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->button2->Location = System::Drawing::Point(609, 479);
        this->button2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
        this->button2->Name = L"button2";
        this->button2->Size = System::Drawing::Size(112, 35);
        this->button2->TabIndex = 3;
        this->button2->Text = L"Exit";
        this->button2->UseVisualStyleBackColor = true;
        this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
        // 
        // comboBox1
        // 
        this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->comboBox1->FormattingEnabled = true;
        this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1", L"2", L"3", L"4" });
        this->comboBox1->Location = System::Drawing::Point(142, 433);
        this->comboBox1->Name = L"comboBox1";
        this->comboBox1->Size = System::Drawing::Size(60, 34);
        this->comboBox1->TabIndex = 4;
        // 
        // button3
        // 
        this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
        this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->button3->Location = System::Drawing::Point(609, 436);
        this->button3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
        this->button3->Name = L"button3";
        this->button3->Size = System::Drawing::Size(112, 35);
        this->button3->TabIndex = 6;
        this->button3->Text = L"Open";
        this->button3->UseVisualStyleBackColor = true;
        this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
        // 
        // checkbox1
        // 
        this->checkbox1->AutoSize = true;
        this->checkbox1->Location = System::Drawing::Point(17, 481);
        this->checkbox1->Name = L"checkbox1";
        this->checkbox1->Size = System::Drawing::Size(158, 24);
        this->checkbox1->TabIndex = 8;
        this->checkbox1->Text = L"read from .csv file";
        this->checkbox1->UseVisualStyleBackColor = true;
        // 
        // listview1
        // 
        this->listview1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(1) { this->columnHeader1 });
        this->listview1->HideSelection = false;
        this->listview1->Location = System::Drawing::Point(17, 98);
        this->listview1->Name = L"listview1";
        this->listview1->Size = System::Drawing::Size(704, 326);
        this->listview1->TabIndex = 12;
        this->listview1->UseCompatibleStateImageBehavior = false;
        this->listview1->View = System::Windows::Forms::View::Details;
        // 
        // columnHeader1
        // 
        this->columnHeader1->Text = L"C:\\Users\\Kanya>ping";
        this->columnHeader1->Width = 1000;
        // 
        // label2
        // 
        this->label2->AutoSize = true;
        this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label2->Location = System::Drawing::Point(12, 436);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(116, 25);
        this->label2->TabIndex = 10;
        this->label2->Text = L"Ping Times:";
        // 
        // label1
        // 
        this->label1->AutoSize = true;
        this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label1->Location = System::Drawing::Point(12, 16);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(103, 25);
        this->label1->TabIndex = 11;
        this->label1->Text = L"IP Adress:";
        // 
        // Timer
        // 
        this->Timer->Enabled = true;
        this->Timer->Interval = 1000;
        // 
        // labelTimer
        // 
        this->labelTimer->AutoSize = true;
        this->labelTimer->Location = System::Drawing::Point(314, 499);
        this->labelTimer->Name = L"labelTimer";
        this->labelTimer->Size = System::Drawing::Size(77, 20);
        this->labelTimer->TabIndex = 13;
        this->labelTimer->Text = L"Starting...";
        this->labelTimer->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // backgroundWorker1
        // 
        this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker1_DoWork);
        // 
        // Form1
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::PowderBlue;
        this->ClientSize = System::Drawing::Size(741, 528);
        this->Controls->Add(this->labelTimer);
        this->Controls->Add(this->label1);
        this->Controls->Add(this->label2);
        this->Controls->Add(this->listview1);
        this->Controls->Add(this->checkbox1);
        this->Controls->Add(this->button3);
        this->Controls->Add(this->comboBox1);
        this->Controls->Add(this->button2);
        this->Controls->Add(this->button1);
        this->Controls->Add(this->textbox1);
        this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
        this->Name = L"Form1";
        this->Text = L"Ping Test";
        this->ResumeLayout(false);
        this->PerformLayout();

    }

#pragma endregion

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    DisableControls(true);
    Random^ rand = gcnew Random();
    String^ inputText = textbox1->Text;

    // Clear the list view for every new IP input
    listview1->Items->Clear();

    if (!String::IsNullOrEmpty(inputText)) {
        selectedIP = inputText;
    }
    else if (checkbox1->Checked && csvContentList->Count > 0) {
        int randomIndex = rand->Next(0, csvContentList->Count);
        selectedIP = csvContentList[randomIndex];
    }
    else {
        MessageBox::Show("Please enter a valid IP Address or select a CSV file", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        DisableControls(false);
        return;
    }

    Second = 0;
    Minute = 0;
    labelTimer->Text = ". . . . . .";
    pingCount = Int32::Parse(comboBox1->SelectedItem->ToString());

    if (!backgroundWorker1->IsBusy) {
        backgroundWorker1->RunWorkerAsync();
    }

    Timer->Start();
    textbox1->Clear();
    textbox1->Focus();
}

System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
{
  if (MessageBox::Show("Do you want to exit?", "Exit Prompt", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes) {
      Application::Exit();
  }
}

System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
{
  OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
  openFileDialog->Filter = "CSV files (*.csv)|*.csv|All files (*.*)|*.*";

    if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
    {
    ReadCSVContent(openFileDialog->FileName);
    MessageBox::Show("File has been selected.");
    }
}


System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
    int successfulPings = pingCount;

    // Start timer
    System::Diagnostics::Stopwatch^ stopwatch = gcnew System::Diagnostics::Stopwatch();
    stopwatch->Start();

    for (int i = 0; i < pingCount; i++) {
        System::Threading::Thread::Sleep(20); // Simulate network delay

        // Get the elapsed time in milliseconds
        int elapsedTime = (int)stopwatch->Elapsed.TotalMilliseconds;

        // Format ping result with elapsed time
        String^ result = String::Format("Pinging {0} with 32 bytes of data:\n  bytes=32  time={1}ms TTL=115",
            selectedIP, elapsedTime);

        backgroundWorker1->ReportProgress(i, result);

        if (backgroundWorker1->CancellationPending) {
            e->Cancel = true;
            return;
        }
    }

    String^ stats = String::Format("Ping statistics for {0}:\n  Packets: Sent = {1}, Received = {2}, Lost = {3} ({4}% loss)",
        selectedIP, pingCount, successfulPings, 0, 0);
    e->Result = stats;
}

System::Void backgroundWorker1_ProgressChanged(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e) {
    String^ pingResult = dynamic_cast<String^>(e->UserState);
    listview1->Items->Add(gcnew ListViewItem(pingResult)); // Update ListView with progress
}

System::Void backgroundWorker1_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {
    if (e->Cancelled) {
        listview1->Items->Add(gcnew ListViewItem("Ping operation cancelled."));
    }
    else if (e->Error != nullptr) {
        listview1->Items->Add(gcnew ListViewItem("Error occurred during ping."));
    }
    else {
        String^ finalStats = dynamic_cast<String^>(e->Result);
        listview1->Items->Add(gcnew ListViewItem(finalStats)); // Add final result
    }

    // Reset after completion
    DisableControls(false);
    Second = 0;
    Minute = 0;
    labelTimer->Text = "Ping Test Done!";
    Timer->Stop();
}


// Read CSV file function (remains unchanged)
void ReadCSVContent(String^ filePath)
{
 String^ line;
  try
  {
    StreamReader^ reader = gcnew StreamReader(filePath);
    csvContentList->Clear();

      while ((line = reader->ReadLine()) != nullptr)
      {
        array<String^>^ fields = line->Split(',');
           if (fields->Length > 0) {
               csvContentList->Add(fields[0]);
           }
      }

      reader->Close();
   }
    catch (Exception^ ex)
    {
     MessageBox::Show("Error: " + ex->Message, "File Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

// Disable/Enable controls function (remains unchanged)
void DisableControls(bool disable)
{
  textbox1->Enabled = !disable;
  button1->Enabled = !disable;
  button3->Enabled = !disable;
  comboBox1->Enabled = !disable;
  checkbox1->Enabled = !disable;
  button2->Enabled = true;
}
};
}