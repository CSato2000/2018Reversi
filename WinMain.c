#include<windows.h>
#include<stdlib.h>

#include"GlobalNum.h"
#include"Init.h"
#include"BoardDraw.h"
#include"UI.h"
#include"SearchMouse.h"
#include"KeyController.h"


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow) {
	HWND hwnd;
	MSG msg;
	WNDCLASS winc;
	winc.style = CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc = WndProc;
	winc.cbClsExtra = winc.cbWndExtra = 0;
	winc.hInstance = hInstance;
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winc.hCursor = LoadCursor(NULL, IDC_ARROW);
	winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName = NULL;
	winc.lpszClassName = TEXT("Window01");
	if (!RegisterClass(&winc)) return 0;
	hwnd = CreateWindow(
		TEXT("Window01"), TEXT("Reversi"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100, 900, 450, NULL, NULL,
		hInstance, NULL
	);
	if (hwnd == NULL) return 0;
	while (TRUE) {
		GetMessage(&msg, NULL, 0, 0);	//メッセージキューからメッセージを取得
		DispatchMessage(&msg);	//メッセージをウィンドウプロシージャへディスパッチ
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_CREATE:	//初期化	
		Init();
		break;
	case WM_DESTROY:	//終了
		PostQuitMessage(0);
		exit(0);
		break;

	case WM_LBUTTONDOWN:	//マウス左ボタンが押された
		
		SearchMouse(lp);
		InvalidateRect(hwnd, NULL, FALSE);
		break;

	case WM_KEYDOWN:	//キーが押された
		KeyController(wp);
		InvalidateRect(hwnd, NULL, FALSE);
		break;

	case WM_PAINT:	//描画
		BoardDraw(hwnd);
		UI(hwnd);
		InvalidateRect(hwnd, NULL, FALSE);
		break;
	}
	return DefWindowProc(hwnd, msg, wp, lp);
}
