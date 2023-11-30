
// CalculatorDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CCalculatorDlg
class CCalculatorDlg : public CDialogEx
{
// Создание
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMul();
	afx_msg void OnBnClickedButtonDivide();
	afx_msg void OnBnClickedButtonEquals();
private:
	void addDigit(char digit);
	CString output;
	bool CheckToDo = false;
public:
	afx_msg void OnBnClickedButtonClear();
};
