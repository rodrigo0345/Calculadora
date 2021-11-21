// wxWidgets "Hello World" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include<string.h>
#include "calculadora.h"
#include <string>

//global Variables
bool ReadyToAlgebra = 1; //este boleano serve para indicar se 
							//o usuário já carregou em algum botão de algebra		
bool ReadyToSum = 0;
bool ReadyToMult = 0;
bool ReadyToDiv = 0;
bool ReadyToSubt = 0;

std::string resultN1, resultN2;

char number1[20];
char number2[20];

float StoreNumber1 =0;
float StoreNumber2 =0;

double SavedResult = 0;

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};
class MyFrame : public wxFrame
{
public:
    MyFrame();
protected:
	wxButton* m_button0;
	wxButton* m_button1;
	wxButton* m_button2;
	wxButton* m_button3;
	wxButton* m_button4;
	wxButton* m_button5;
	wxButton* m_button6;
	wxButton* m_button7;
	wxButton* m_button8;
	wxButton* m_button9;
	wxButton* m_buttonMult;
	wxButton* m_buttonDiv;
	wxButton* m_buttonSum;
	wxButton* m_buttonSubt;
	wxButton* m_buttonDelete;
	wxButton* m_buttonEqual;

	wxButton* m_textCtrl;
private:
	void AddButtons_to_Grid();
	void CreateButtons();
	void BindButtons();
	void DisableAlgebra();
	void EnableAlgebra();
	void Clear();

	void button0(wxCommandEvent& event);
	void button1(wxCommandEvent& event);
	void button2(wxCommandEvent& event);
	void button3(wxCommandEvent& event);
	void button4(wxCommandEvent& event);
	void button5(wxCommandEvent& event);
	void button6(wxCommandEvent& event);
	void button7(wxCommandEvent& event);
	void button8(wxCommandEvent& event);
	void button9(wxCommandEvent& event);
	void buttonMult(wxCommandEvent& event);
	void buttonDiv(wxCommandEvent& event);
	void buttonSum(wxCommandEvent& event);
	void buttonSubt(wxCommandEvent& event);
	void buttonDelete(wxCommandEvent& event);
	void buttonEqual(wxCommandEvent& event);

	void DisableNum();
	void UpdateMainScreen();
	void EnableNum();
};

enum
{
    
};

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame();
    frame->Show(true);
    return true;
}

MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, "Calculadora")
{

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	m_textCtrl = new wxButton(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 0);
	MyFrame::CreateButtons();
	MyFrame::AddButtons_to_Grid();

	MyFrame::BindButtons();

	wxFont font(48, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTENCODING_DEFAULT);
	m_textCtrl->SetFont(font);

	this->Layout();

	this->Centre(wxBOTH);
}


wxIMPLEMENT_APP(MyApp);



void MyFrame::AddButtons_to_Grid() {

	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer(2, 0, 0, 0);

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer(wxVERTICAL);

	gSizer2->Add(bSizer3, 1, wxEXPAND | wxALIGN_BOTTOM, 5);

	bSizer3->Add(m_textCtrl, 1, wxALL | wxEXPAND, 5);

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer(wxVERTICAL);

	wxGridSizer* gSizer4;
	gSizer4 = new wxGridSizer(4, 4, 0, 0);

	gSizer4->Add(m_button1, 0, wxALL | wxEXPAND, 5);
	gSizer4->Add(m_button2, 0, wxALL | wxEXPAND, 5);
	gSizer4->Add(m_button3, 0, wxALL | wxEXPAND, 5);
	gSizer4->Add(m_buttonDiv, 0, wxALL | wxEXPAND, 5);
	gSizer4->Add(m_button4, 0, wxALL | wxEXPAND, 5);
	gSizer4->Add(m_button5, 0, wxALL | wxEXPAND, 5);
	gSizer4->Add(m_button6, 0, wxALL | wxEXPAND, 5);
	gSizer4->Add(m_buttonMult, 0, wxALL | wxEXPAND, 5);
	gSizer4->Add(m_button7, 0, wxALL | wxEXPAND, 5);
	gSizer4->Add(m_button8, 0, wxALL | wxEXPAND, 5);
	gSizer4->Add(m_button9, 0, wxALL | wxEXPAND, 5);
	gSizer4->Add(m_buttonSubt, 0, wxALL | wxEXPAND, 5);
	gSizer4->Add(m_buttonDelete, 0, wxALL | wxEXPAND, 5);
	gSizer4->Add(m_button0, 0, wxALL | wxEXPAND, 5);
	gSizer4->Add(m_buttonEqual, 0, wxALL | wxEXPAND, 5);
	gSizer4->Add(m_buttonSum, 0, wxALL | wxEXPAND, 5);

	bSizer4->Add(gSizer4, 0, wxEXPAND, 5);
	gSizer2->Add(bSizer4, 1, wxEXPAND, 5);

	this->SetSizer(gSizer2);
}

void MyFrame::CreateButtons()
{
	m_button1 = new wxButton(this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0);
	m_button2 = new wxButton(this, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0);
	m_button3 = new wxButton(this, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0);
	m_buttonDiv = new wxButton(this, wxID_ANY, wxT("/"), wxDefaultPosition, wxDefaultSize, 0);
	m_button4 = new wxButton(this, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0);
	m_button5 = new wxButton(this, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0);
	m_button6 = new wxButton(this, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, 0);
	m_buttonMult = new wxButton(this, wxID_ANY, wxT("*"), wxDefaultPosition, wxDefaultSize, 0);
	m_button7 = new wxButton(this, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, 0);
	m_button8 = new wxButton(this, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, 0);
	m_button9 = new wxButton(this, wxID_ANY, wxT("9"), wxDefaultPosition, wxDefaultSize, 0);
	m_buttonSubt = new wxButton(this, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, 0);
	m_buttonDelete = new wxButton(this, wxID_ANY, wxT("<-"), wxDefaultPosition, wxDefaultSize, 0);
	m_button0 = new wxButton(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0);
	m_buttonEqual = new wxButton(this, wxID_ANY, wxT("="), wxDefaultPosition, wxDefaultSize, 0);
	m_buttonSum = new wxButton(this, wxID_ANY, wxT("+"), wxDefaultPosition, wxDefaultSize, 0);
}

void MyFrame::button0(wxCommandEvent& event) {

	if (ReadyToAlgebra)
	{
		strcat(number1, "0");
		resultN1 = number1;
		StoreNumber1 = std::stoi(resultN1);
		MyFrame::UpdateMainScreen();  //Updates the screen
	}
	else
	{
		strcat(number2, "0");
		resultN2 = number2;
		StoreNumber2 = std::stoi(resultN2);
		MyFrame::UpdateMainScreen();  //Updates the screen
	}
}
void MyFrame::button1(wxCommandEvent& event){
	if (ReadyToAlgebra)
	{
		strcat(number1, "1");
		resultN1 = number1;
		StoreNumber1 = std::stoi(resultN1);
		MyFrame::UpdateMainScreen();  //Updates the screen
	}
	else
	{
		strcat(number2, "1");
		resultN2 = number2;
		StoreNumber2 = std::stoi(resultN2);
		MyFrame::UpdateMainScreen();  //Updates the screen
	}
}

void MyFrame::button2(wxCommandEvent& event) {
	if (ReadyToAlgebra)
	{
		strcat(number1, "2");
		resultN1 = number1;
		StoreNumber1 = std::stoi(resultN1);
		MyFrame::UpdateMainScreen();  //Updates the screen
	}
	else
	{
		strcat(number2, "2");
		resultN2 = number2;
		StoreNumber2 = std::stoi(resultN2);
		MyFrame::UpdateMainScreen();  //Updates the screen
	}
}

void MyFrame::button3(wxCommandEvent& event) {
	if (ReadyToAlgebra)
	{
		strcat(number1, "3");
		resultN1 = number1;
		StoreNumber1 = std::stoi(resultN1);
		MyFrame::UpdateMainScreen();  //Updates the screen
	}
	else
	{
		strcat(number2, "3");
		resultN2 = number2;
		StoreNumber2 = std::stoi(resultN2);
		MyFrame::UpdateMainScreen();  //Updates the screen
	}
}

void MyFrame::button4(wxCommandEvent& event) {
	if (ReadyToAlgebra)
	{
		strcat(number1, "4");
		resultN1 = number1;
		StoreNumber1 = std::stoi(resultN1);
		MyFrame::UpdateMainScreen();  //Updates the screen
	}
	else
	{
		strcat(number2, "4");
		resultN2 = number2;
		StoreNumber2 = std::stoi(resultN2);
		MyFrame::UpdateMainScreen();  //Updates the screen
	}
}

void MyFrame::button5(wxCommandEvent& event) {
	if (ReadyToAlgebra)
	{
		strcat(number1, "5");
		resultN1 = number1;
		StoreNumber1 = std::stoi(resultN1);
		MyFrame::UpdateMainScreen();  //Updates the screen
	}
	else
	{
		strcat(number2, "5");
		resultN2 = number2;
		StoreNumber2 = std::stoi(resultN2);
		MyFrame::UpdateMainScreen();  //Updates the screen
	}
}

void MyFrame::button6(wxCommandEvent& event) {
	if (ReadyToAlgebra)
	{
		strcat(number1, "6");
		resultN1 = number1;
		StoreNumber1 = std::stoi(resultN1);
		MyFrame::UpdateMainScreen();  //Updates the screen
	}
	else
	{
		strcat(number2, "6");
		resultN2 = number2;
		StoreNumber2 = std::stoi(resultN2);
		MyFrame::UpdateMainScreen();  //Updates the screen
	}
}

void MyFrame::button7(wxCommandEvent& event) {
	if (ReadyToAlgebra)
	{
		strcat(number1, "7");
		resultN1 = number1;
		StoreNumber1 = std::stoi(resultN1);
		MyFrame::UpdateMainScreen();  //Updates the screen
	}
	else
	{
		strcat(number2, "7");
		resultN2 = number2;
		StoreNumber2 = std::stoi(resultN2);
		MyFrame::UpdateMainScreen();  //Updates the screen
	}
}

void MyFrame::button8(wxCommandEvent& event) {
	if (ReadyToAlgebra)
	{
		strcat(number1, "8");
		resultN1 = number1;
		StoreNumber1 = std::stoi(resultN1);
		MyFrame::UpdateMainScreen();  //Updates the screen
	}
	else
	{
		strcat(number2, "8");
		resultN2 = number2;
		StoreNumber2 = std::stoi(resultN2);
		MyFrame::UpdateMainScreen();  //Updates the screen
	}
}

void MyFrame::button9(wxCommandEvent& event) {
	if (ReadyToAlgebra)
	{
		strcat(number1, "9");
		resultN1 = number1;
		StoreNumber1 = std::stoi(resultN1);
		MyFrame::UpdateMainScreen();
	}
	else
	{
		strcat(number2, "9");
		resultN2 = number2;
		StoreNumber2 = std::stoi(resultN2);
		MyFrame::UpdateMainScreen();  //Updates the screen
	}
}

void MyFrame::buttonMult(wxCommandEvent& event){
	ReadyToAlgebra = false;

	strcat(number1, "x");
	resultN1 = number1;

	ReadyToMult = true;
	MyFrame::DisableAlgebra();

	MyFrame::UpdateMainScreen();  //Updates the screen
}

void MyFrame::buttonDiv(wxCommandEvent& event) {
	ReadyToAlgebra = false;

	strcat(number1, ":");
	resultN1 = number1;
	
	ReadyToDiv = true;
	MyFrame::DisableAlgebra();
	m_button0->Disable();

	MyFrame::UpdateMainScreen();  //Updates the screen
}

void MyFrame::buttonSum(wxCommandEvent& event) {
	ReadyToAlgebra = false;

	strcat(number1, "+");
	resultN1 = number1;

	ReadyToSum = true;
	MyFrame::DisableAlgebra();

	MyFrame::UpdateMainScreen();  //Updates the screen
}

void MyFrame::buttonSubt(wxCommandEvent& event) {
	ReadyToAlgebra = false;

	strcat(number1, "-");
	resultN1 = number1;

	ReadyToSubt = true;
	MyFrame::DisableAlgebra();

	MyFrame::UpdateMainScreen();  //Updates the screen
}

void MyFrame::buttonDelete(wxCommandEvent& event) { //caso especial, tenho de o fazer mais tarde
	EnableNum();
	Clear();
}

void MyFrame::buttonEqual(wxCommandEvent& event) {//Mostrar o conteudo da variável FinalResult no ecrã
	
	strcat(number2, "=");
	resultN2 = number2;

	if (ReadyToSum)
	{
		SavedResult = Sum(StoreNumber1, StoreNumber2);
		MyFrame::EnableAlgebra();
		MyFrame::UpdateMainScreen();  //Updates the screen
	}
	else if (ReadyToDiv)
	{
		SavedResult = Div(StoreNumber1, StoreNumber2);
		MyFrame::EnableAlgebra();
		MyFrame::UpdateMainScreen();  //Updates the screen
	}
	else if (ReadyToMult)
	{
		SavedResult = Mult(StoreNumber1, StoreNumber2);
		MyFrame::EnableAlgebra();
		MyFrame::UpdateMainScreen();  //Updates the screen
	}
	else if (ReadyToSubt)
	{
		SavedResult = Subt(StoreNumber1, StoreNumber2);
		MyFrame::EnableAlgebra();
		  //Updates the screen
	}
	else
	{
		SavedResult = StoreNumber1;
	}
	std::string mensagem = std::to_string(SavedResult);
	resultN2 += mensagem;

	MyFrame::UpdateMainScreen();
	MyFrame::DisableNum();
}

void MyFrame::DisableAlgebra() 
{
	m_buttonMult->Disable();
	m_buttonDiv->Disable();
	m_buttonSum->Disable();
	m_buttonSubt->Disable();
}
void MyFrame::EnableAlgebra()
{
	m_buttonMult->Enable();
	m_buttonDiv->Enable();
	m_buttonSum->Enable();
	m_buttonSubt->Enable();
}

void MyFrame::BindButtons()
{
	m_button0->Connect(wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(MyFrame::button0), NULL , this);
	m_button1->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::button1), NULL, this);
	m_button2->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::button2), NULL, this);
	m_button3->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::button3), NULL, this);
	m_button4->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::button4), NULL, this);
	m_button5->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::button5), NULL, this);
	m_button6->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::button6), NULL, this);
	m_button7->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::button7), NULL, this);
	m_button8->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::button8), NULL, this);
	m_button9->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::button9), NULL, this);
	m_buttonMult->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::buttonMult), NULL, this);
	m_buttonDiv->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::buttonDiv), NULL, this);
	m_buttonSum->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::buttonSum), NULL, this);
	m_buttonSubt->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::buttonSubt), NULL, this);
	m_buttonDelete->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::buttonDelete), NULL, this);
	m_buttonEqual->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::buttonEqual), NULL, this);
}

void MyFrame::Clear()
{
	MyFrame::EnableAlgebra();
	ReadyToAlgebra = true; 
	ReadyToSum = 0;
	ReadyToMult = 0;
	ReadyToDiv = 0;
	ReadyToSubt = 0;
	resultN1 = "", resultN2 = "";
	strcpy(number1, "");
	strcpy(number2, "");
	StoreNumber1 = 0;
	StoreNumber2 = 0;
	SavedResult = 0;
	m_textCtrl->SetLabelText("");
}

void MyFrame::UpdateMainScreen()
{
	m_textCtrl->SetLabelText(resultN1 + resultN2);
}

void MyFrame::DisableNum()
{
	m_button0->Disable();
	m_button1->Disable();
	m_button2->Disable();
	m_button3->Disable();
	m_button4->Disable();
	m_button5->Disable();
	m_button6->Disable();
	m_button7->Disable();
	m_button8->Disable();
	m_button9->Disable();
	m_buttonMult->Disable();
	m_buttonDiv->Disable();
	m_buttonSum->Disable();
	m_buttonSubt->Disable();
	m_buttonEqual->Disable();
}

void MyFrame::EnableNum()
{
	m_button0->Enable();
	m_button1->Enable();
	m_button2->Enable();
	m_button3->Enable();
	m_button4->Enable();
	m_button5->Enable();
	m_button6->Enable();
	m_button7->Enable();
	m_button8->Enable();
	m_button9->Enable();
	m_buttonMult->Enable();
	m_buttonDiv->Enable();
	m_buttonSum->Enable();
	m_buttonSubt->Enable();
	m_buttonEqual->Enable();
}