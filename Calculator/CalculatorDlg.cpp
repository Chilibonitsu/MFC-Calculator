
// CalculatorDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include <stack>
#include <regex>
#include <iostream>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CCalculatorDlg



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, output(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RES, output);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON0, &CCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CCalculatorDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CCalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CCalculatorDlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CCalculatorDlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_EQUALS, &CCalculatorDlg::OnBnClickedButtonEquals)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CCalculatorDlg::OnBnClickedButtonClear)
END_MESSAGE_MAP()


// Обработчики сообщений CCalculatorDlg

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCalculatorDlg::addDigit(char symbol)
{	

	if (output.GetLength() == 0)
	{
		output += symbol;
	}
	
	else if (output[output.GetLength() - 1] != symbol && 
		output[output.GetLength() - 1] != '+' && symbol &&
		output[output.GetLength() - 1] != '-' && symbol && output[output.GetLength() - 1] != '*' && symbol && 
		output[output.GetLength() - 1] != '/' || 
		symbol >='0' && symbol <='9')
	{
		output += symbol;
	}


	UpdateData(FALSE);

}



void CCalculatorDlg::OnBnClickedButton0()
{
	addDigit('0');
}


void CCalculatorDlg::OnBnClickedButton1()
{
	addDigit('1');
}


void CCalculatorDlg::OnBnClickedButton2()
{
	addDigit('2');
}


void CCalculatorDlg::OnBnClickedButton3()
{
	addDigit('3');
}


void CCalculatorDlg::OnBnClickedButton4()
{
	addDigit('4');
}


void CCalculatorDlg::OnBnClickedButton5()
{
	addDigit('5');
}


void CCalculatorDlg::OnBnClickedButton6()
{
	addDigit('6');
}


void CCalculatorDlg::OnBnClickedButton7()
{
	addDigit('7');
}


void CCalculatorDlg::OnBnClickedButton8()
{
	addDigit('8');
}


void CCalculatorDlg::OnBnClickedButton9()
{
	addDigit('9');
}


void CCalculatorDlg::OnBnClickedButtonPlus()
{
	addDigit('+');
}


void CCalculatorDlg::OnBnClickedButtonMinus()
{
	addDigit('-');
}


void CCalculatorDlg::OnBnClickedButtonMul()
{
	addDigit('*');
}


void CCalculatorDlg::OnBnClickedButtonDivide()
{
	addDigit('/');
}
bool isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrecedence(char op) {
	if (op == '+' || op == '-') {
		return 1;
	}
	else if (op == '*' || op == '/') {
		return 2;
	}
	return 0;
}

CString infixToPostfix(const CString& infix) {
	stack<char> operators;
	CString postfix;
	CString numStr;

	for (int i = 0; i < infix.GetLength(); ++i) {
		char c = infix.GetAt(i);//берем символ
		if (isdigit(c)) {
			numStr += c;
		}
		else if (isOperator(c)) {
			if (!numStr.IsEmpty()) {
				postfix += numStr;
				postfix += ' ';
				numStr.Empty();
			}

			while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(c)) {
				postfix += operators.top();
				postfix += ' ';  
				operators.pop();
			}
			operators.push(c);
		}
	}

	if (!numStr.IsEmpty()) {
		postfix += numStr;
		postfix += ' '; 
	}

	while (!operators.empty()) {
		postfix += operators.top();
		postfix += ' ';  
		operators.pop();
	}

	return postfix;
}

double evaluatePostfix(const CString& postfix) {
	stack<double> operands;
	CString numStr;

	for (int i = 0; i < postfix.GetLength(); ++i) {
		char c = postfix.GetAt(i);
		if (isdigit(c)) {
			numStr += c;
		}
		else if (c == ' ') {
			if (!numStr.IsEmpty()) {
				operands.push(_ttof((LPCTSTR)numStr));
				numStr.Empty();
			}
		}
		else if (isOperator(c)) {
			double operand2 = operands.top();
			operands.pop();
			double operand1 = operands.top();
			operands.pop();

			switch (c) {
			case '+':
				operands.push(operand1 + operand2);
				break;
			case '-':
				operands.push(operand1 - operand2);
				break;
			case '*':
				operands.push(operand1 * operand2);
				break;
			case '/':
				operands.push(operand1 / operand2);
				break;
			}
		}
	}

	return operands.top();
}
double solve(CString input)
{


	CString postfix = infixToPostfix(input);
	double result = evaluatePostfix(postfix);

	return result;
}

void CCalculatorDlg::OnBnClickedButtonEquals()
{

	CString expression = output;
	expression += '=';

		if (output.GetLength() != 0)
		{
			if (output[output.GetLength() - 1] == '+' ||
				output[output.GetLength() - 1] == '-' ||
				output[output.GetLength() - 1] == '*' ||
				output[output.GetLength() - 1] == '/')
			{
				output.Delete(output.GetLength() - 1, 1);
			}

			CString result = 0;
			result.Format(_T("%f"), solve(output));
			CheckToDo = false;

			CEdit* out = (CEdit*)GetDlgItem(IDC_EDIT_RES);
			expression += result;
			out->SetWindowText(expression);

		}
	
} 



void CCalculatorDlg::OnBnClickedButtonClear()
{
	// Получаем указатель на объект CEdit
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_RES);
	output.Empty();

	// Очищаем поле для ввода
	pEdit->SetWindowText(_T(""));
}
