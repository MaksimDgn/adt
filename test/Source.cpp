//Класс кнопок
//file:///E:/NotBoock/BooK_S/txt/PETZOLD/text/vol1/Ch-08.doc
// стр.380

//#include <iostream>
//c:\Windows\System32\user32.dll
//using namespace std;



#include <windows.h>
#include <Winuser.h>
#include <string.h>
#include <stdio.h>

//#pragma comment(lib,"User32.lib")
#define NUM (sizeof button / sizeof button[0])
#define IDC_SMALLER 20
#define IDC_LARGER 21
#define IDC_0 1
#define IDC_1 2
#define IDC_2 3
#define IDC_3 4
#define IDC_4 5
#define IDC_5 6 // id - идентификатор кнопок
#define IDC_6 7
#define IDC_7 8
#define IDC_8 9
#define IDC_9 10
#define IDC_10 11
#define IDC_11 12
#define IDC_12 13
#define IDC_E 15

#define BTN_WIDTH (8 * cxChar)
#define BTN_HEIGHT (4 * cyChar)



struct {
	long style;
	char *text;
	int id;
	}
	button[] =
	{
		BS_PUSHBUTTON, "msgMyButton", IDC_0,
		BS_PUSHBUTTON, "PUSHBUTTON", IDC_1,
		BS_DEFPUSHBUTTON, "DEFPUSHBUTTON", IDC_2,
		BS_CHECKBOX, "CHECKBOX", IDC_3,
		BS_AUTOCHECKBOX, "AUTOCHECKBOX", IDC_4,
		BS_RADIOBUTTON, "RADIOBUTTON", IDC_5,
		BS_3STATE, "3STATE", IDC_6,
		BS_AUTO3STATE, "AUTO3STATE", IDC_7,
		BS_GROUPBOX, "GROUPBOX", IDC_8,
		BS_PUSHBUTTON, "PUSHBUTTON", IDC_9,
		BS_PUSHBUTTON, "PUSHBUTTON", IDC_10,
		BS_RADIOBUTTON, "RADIOBUTTON", IDC_11,
		BS_PUSHBUTTON, "Edit", IDC_12, };

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int cxChar, cyChar;
HINSTANCE hInst;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{


	static LPCTSTR szAppName = "msgMyButton";
	HWND        hwnd;
	MSG         msg;
	WNDCLASSEX  wndclass;		// Структура для хранения атрибутов  окна 

	wndclass.cbSize = sizeof (wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);


	hwnd = CreateWindow(szAppName,         // window class name
		szAppName,     // window caption
		WS_OVERLAPPEDWINDOW,     // window style
		CW_USEDEFAULT,           // initial x position
		CW_USEDEFAULT,           // initial y position
		CW_USEDEFAULT,           // initial x size
		CW_USEDEFAULT,           // initial y size
		NULL,                    // parent window handle
		NULL,                    // window menu handle
		hInstance,               // program instance handle
		NULL);		             // creation parameters

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

/*
void ShowKey(HWND hwnd, int iType, char *szMessage, WPARAM wParam, LPARAM lParam)
{
	static char *szFormat[2] = { "%-14s %3d %c %6u %4d %3s %3s %4s %4s",
		"%-14s %3d %c %6u %4d %3s %3s %4s %4s" };
	char szBuffer[80];
	HDC hdc;
	ScrollWindow(hwnd, 0, -cyChar, &rect, &rect);
	hdc = GetDC(hwnd);
	SelectObject(hdc, GetStockObject(SYSTEM_FIXED_FONT));
	TextOut(hdc, cxChar, rect.bottom - cyChar, szBuffer,
		wsprintf(szBuffer, szFormat[iType],
		szMessage, wParam,
		(BYTE)(iType ? wParam : ' '),
		LOWORD(lParam),
		HIWORD(lParam) & 0xFF,
		(PSTR)(0x01000000 & lParam ? "Yes" : "No"),
		(PSTR)(0x20000000 & lParam ? "Yes" : "No"),
		(PSTR)(0x40000000 & lParam ? "Down" : "Up"),
		(PSTR)(0x80000000 & lParam ? "Up" : "Down")));
	ReleaseDC(hwnd, hdc);
	ValidateRect(hwnd, NULL);
}*/



// my(); - выводит на канвас строку с заданным отступом вниз
/*
void my(HWND hwnd, int iColum, char *str){
	HDC hdc;
	static RECT rect;
	hdc = GetDC(hwnd);
	SelectObject(hdc, GetStockObject(SYSTEM_FIXED_FONT));

	//GetWindowLong(hwnd, GWL_HINSTANCE);

	int iColumTo = iColum + 50;
	TextOut(hdc, 440, iColumTo, "1:", sizeof("1:"));
	TextOut(hdc, 460, iColumTo, str, sizeof(str));
	TextOut(hdc, 475, iColumTo, "***", sizeof("***"));

ReleaseDC(hwnd, hdc);
	ValidateRect(hwnd, &rect);

}
*/
// my(); - выводит на канвас строку с заданным отступом вниз
void my(HWND hwnd, int btnId, int iColum, char *str){
	HDC hdc;
	static RECT rect;
	hdc = GetDC(hwnd);
	
	int iLength;
	char szBuffer[100];
	
	SelectObject(hdc, GetStockObject(SYSTEM_FIXED_FONT));


	//возвращаемым значением sprintf является длина строки

	iLength = wsprintf(szBuffer, "id: %d кнопки координата y: %d %s", btnId, iColum, str, sizeof(str));
	/*Если вам не нужно выводить числа с плавающей точкой, то вместо sprintf вам
лучше использовать функцию wsprintf. Синтаксис функции wsprintf такой же,
как и sprintf, но она включена в Windows, поэтому ее использование не
увеличит размер вашего EXE-файла.*/


TextOut(hdc, 400, iColum, szBuffer, iLength);
//szBuffer = "";

ReleaseDC(hwnd, hdc);
ValidateRect(hwnd, &rect);

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	
	static HWND hwndSmaller, hwndLarger, hwndEdit;
		
		static HWND  hwndButton[NUM];//создание 10 кнопак
	static RECT rect;
	static int  cxClient, cyClient;
	static char szTop[] =
		"Message Key Char Repeat Scan Ext ALT Prev Tran";
	static char szUnd[] =
		"_______ ___ ____ ______ ____ ___ ___ ____ ____";
	     HDC         hdc ;
	int         i,iY=25;
	int			ic = 110;
	     PAINTSTRUCT ps ;
		static int  cxChar,  cyChar;
	    TEXTMETRIC  tm ;
		static char szBufer[40];
		char url[40];

		static int id, idd, idS, idL;
		
static LPCTSTR szBtnText[] = { "Text BUTTON 1", "Text BUTTON 2", "Text BUTTON 3", "Text BUTTON 4" };
//long szBtnStyle[] = { BS_PUSHBUTTON, BS_CHECKBOX, BS_RADIOBUTTON, BS_RADIOBUTTON };

	switch (iMsg)
	{
		
	case WM_CREATE:
		hdc = GetDC(hwnd);
			SelectObject(hdc, GetStockObject(SYSTEM_FIXED_FONT));
			GetTextMetrics(hdc, &tm);
			cxChar = tm.tmAveCharWidth;
			cyChar = tm.tmHeight + tm.tmExternalLeading;
		ReleaseDC(hwnd, hdc);

		
			
		// Create the owner-draw pushbuttons
		hwndSmaller = CreateWindow("BUTTON",
									"Smaller",
			WS_CHILD | WS_VISIBLE | BS_OWNERDRAW,
			230,
			0,
			BTN_WIDTH, BTN_HEIGHT,
			//hwnd, NULL, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
			hwnd,
			(HMENU)IDC_SMALLER,
			hInst,
			NULL);
		hwndLarger = CreateWindow("button", "Larger",
			WS_CHILD | WS_VISIBLE | BS_OWNERDRAW,
			330, 50, BTN_WIDTH, 25, //330, 50, BTN_WIDTH, BTN_HEIGHT,
			hwnd, (HMENU)IDC_LARGER, hInst, NULL);

		idS = GetWindowLong(hwndSmaller, GWL_ID);
		idL = GetWindowLong(hwndLarger, GWL_ID);

		hwndEdit = CreateWindow("edit", "EditText",
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,
			400, 50, 250, 25,
			hwnd, (HMENU)IDC_E,
			((LPCREATESTRUCT)lParam)->hInstance, NULL);

//создание 10 кнопак
		for (i= 0; i < NUM; i++)
		{
			//hwndButton[i] = CreateWindow("BUTTON", szBtnText[i], WS_CHILD | WS_VISIBLE | szBtnStyle[i],
			hwndButton[i] = CreateWindow("BUTTON", button[i].text, WS_CHILD | WS_VISIBLE | button[i].style,
				//20, iY, 200, 25, hwnd, NULL, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
				20, iY, 200, 25, hwnd, (HMENU)button[i].id, ((LPCREATESTRUCT)lParam)->hInstance, NULL);

	//		id = GetWindowLong(hwndButton[i], GWL_ID);
	//		idd = GetWindowLong(hwndButton[i], GWL_ID);
			iY=iY + 50;
		}
		return 0;
		



	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		return 0;
		

	case WM_PAINT:
		
		InvalidateRect(hwnd, &rect, TRUE);
		hdc = BeginPaint(hwnd, &ps);
		SelectObject(hdc, GetStockObject(SYSTEM_FIXED_FONT));
		SetBkMode(hdc, TRANSPARENT);
		TextOut(hdc, 500, 50, "50символов:", 11);
		TextOut(hdc, 510, 75, "11---11", 10);

		/*
		for (int iqw = 0; iqw < 10; iqw++)
		{//	int			ic = 110;
			TextOut(hdc, 500, ic, szBufer, wsprintf(szBufer, "ic = %d", ic));
			ic = ic + 50;
		};
		*/
		TextOut(hdc, 515+cxChar, cyChar / 2, szUnd, (sizeof szUnd) - 1);
		EndPaint(hwnd, &ps);
		return 0;
//
// Задача: вывести id и описатель кнопки на экран		
//
//	case WM_DRAWITEM:
	case	WM_COMMAND:
		//	id = GetWindowLong(hwndSmaller, GWL_HINSTANCE);
		//	id2 = GetWindowLong(hwndLarger, GWL_HINSTANCE);
		//idd = GetWindowLong(hwndLarger, GWL_ID);

		
		// обрабатывает нажатие на кнопки
		// my(); - выводит на канвас строку с заданным отступом вниз
		case BN_CLICKED:
			// id - идентификатор кнопки
			id = LOWORD(wParam);
			//my(hwndButton[1], 145, "a");
			
			switch (LOWORD(wParam)){
		case IDC_0:			
			//вставить текст в окно редактирования
			//SetWindowText(hwndButton[12], url);

			// получить текст из окна редактирования
			GetWindowText(hwndEdit, url, sizeof(url));
			

			my(hwndButton[id], id, 20, url);
				break;
		
		case	IDC_1:
			my(hwndButton[id], id, 2, "b");
					break;

		case	IDC_2 :
			my(hwndButton[id], id, 2, "c");
			break;
		case	IDC_3:
			my(hwndButton[id], id, 1, "D");
			break;
			}

		//break;
		


			break;




/*	case WM_KEYDOWN:
		ShowKey(hwnd, 0, "WM_KEYDOWN", wParam, lParam);
		return 0;
	case WM_KEYUP:
		ShowKey(hwnd, 0, "WM_KEYUP", wParam, lParam);
		return 0;
	case WM_CHAR:
		ShowKey(hwnd, 1, "WM_CHAR", wParam, lParam);
		return 0;
	case	WM_COMMAND:*/
		

		
		// hwndChild=GetDlgItem(hwnd, vi);
	/*		hdc = GetDC(hwnd);
			TextOut(hdc, 500, ic, szBufer, wsprintf(szBufer, "id = %d / vi2 =%d", vi,vi2));
			ReleaseDC(hwnd, hdc);
			ValidateRect(hwnd, &rect);
		
		break;*/


	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
