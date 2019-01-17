#include<windows.h>
#include<stdlib.h>

#include "GlobalNum.h"

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
		GetMessage(&msg, NULL, 0, 0);	//���b�Z�[�W�L���[���烁�b�Z�[�W���擾
		DispatchMessage(&msg);	//���b�Z�[�W���E�B���h�E�v���V�[�W���փf�B�X�p�b�`
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_CREATE:	//������	

		break;
	case WM_DESTROY:	//�I��

		break;

	case WM_LBUTTONDOWN:	//�}�E�X���{�^���������ꂽ

		break;

	case WM_KEYDOWN:	//�L�[�������ꂽ

		break;

	case WM_PAINT:	//�`��

		break;
	}
	return DefWindowProc(hwnd, msg, wp, lp);
}