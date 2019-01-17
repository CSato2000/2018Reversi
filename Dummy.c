#include <windows.h>

#define APP_NAME TEXT("reversi")

#define WHITE        1  // �\���F�@��
#define BLACK        2  // �\���F�@��
#define GREEN        3  // �\���F�@��
#define RED          4  // �\���F�@��

#define EMP          0

// masu�͊O�����������邱�Ƃ���8x8�ł͂Ȃ��A10x10�Ƃ��Ă���
// ���������āA�L���͈͂́A1-8�܂ł̈ʒu�ƂȂ�
BYTE masu[10][10] = {
	{ 0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,1,2,0,0,0,0 },
{ 0,0,0,0,2,1,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0 }
};

POINT pt;
POINT cp;
int turncount = 1;
int turnflag = BLACK;


/*******************************************************************************
�֐��� : WindowProc
�@�\   : ���b�Z�[�W�������s��
����   : �ȗ�
�ԋp�l : �ȗ�
*******************************************************************************/
LRESULT CALLBACK WindowProc(
	HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam
) {
	HDC hdc;
	PAINTSTRUCT ps;
	static HBRUSH hBrush[3];
	int i, j;


	// �Ֆʏ�̏��������ۂ̍��W�_�i�`�掞�̊e���S���W�j
	static POINT dot[4] = {
		{ 100,100 },
	{ 300,100 },
	{ 100,300 },
	{ 300,300 }
	};

	switch (uMsg) {

	case WM_CREATE:  // �����������̏����i�������j

					 //�u���V�f�[�^�̒�`
		hBrush[0] = CreateSolidBrush(RGB(0, 0xAA, 0));          // �Ֆʁi�΁j
		hBrush[1] = CreateSolidBrush(RGB(0xFF, 0xFF, 0xFF));    // WHITE
		hBrush[2] = CreateSolidBrush(RGB(0, 0, 0));		        // BLACK
		return 0;

	case WM_DESTROY:  // �E�B���h�E�j�����̏���
					  // �u���V�̍폜
		for (i = 0; i < 2; i++) DeleteObject(hBrush[i]);
		PostQuitMessage(0);
		return 0;


	case WM_LBUTTONDOWN:
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);

		cp.x = (pt.x / 50);
		cp.y = (pt.y / 50);

		InvalidateRect(hWnd, NULL, FALSE);

	case WM_KEYDOWN:


	case WM_PAINT: // �`��C�x���g�������@�@�i��ʂɕω����������ۂɕp�ɂɌĂяo�����)

				   // �y�C���g�J�n
		hdc = BeginPaint(hWnd, &ps);

		// �I�Z���Ղ̕`��

		SelectObject(hdc, hBrush[0]);
		Rectangle(hdc, 0, 0, 401, 401);

		for (i = 0; i < 7; i++) {
			MoveToEx(hdc, 50 * (i + 1), 0, NULL);
			LineTo(hdc, 50 * (i + 1), 400);
			MoveToEx(hdc, 0, 50 * (i + 1), NULL);
			LineTo(hdc, 400, 50 * (i + 1));
		}

		//�����ȍ��ۂ̕`��
		SelectObject(hdc, hBrush[2]);
		for (i = 0; i < 4; i++) {
			Ellipse(hdc, dot[i].x - 5, dot[i].y - 5,
				dot[i].x + 5, dot[i].y + 5);
		}

		// �I�Z���Ղ̕\��
		for (i = 1; i <= 8; i++) {
			for (j = 1; j <= 8; j++) {
				if (masu[i][j] != EMP) {
					if (masu[i][j] == WHITE) {
						SelectObject(hdc, hBrush[1]);  //��
					}
					else if (masu[i][j] == BLACK) {
						SelectObject(hdc, hBrush[2]);  //��
					}
					Ellipse(hdc, (i - 1) * 50, (j - 1) * 50, i * 50, j * 50);
				}
			}
		}

		//�N���b�N�����Ƃ��̃R�}�̕`��
		if (pt.x > 0 && pt.x < 400 && pt.y>0 && pt.y<400) {
			if (turncount % 2 == 0) {
				SelectObject(hdc, hBrush[1]);
				turnflag = WHITE;
			}
			else {
				turnflag = BLACK;
				SelectObject(hdc, hBrush[2]);
			}
			Ellipse(hdc, cp.x * 50, cp.y * 50, cp.x * 50 + 50, cp.y * 50 + 50);
			masu[cp.x + 1][cp.y + 1] = turnflag;
			turncount++;
		}

		EndPaint(hWnd, &ps);
		return 0;

	} //switch���̏I��

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

/*******************************************************************************
�֐��� : WinMain
�@�\   : �Q�[���̏������ƃ��b�Z�[�W���[�v
����   : �ȗ�
�ԋp�l : �ȗ�
*******************************************************************************/

int WINAPI WinMain(
	HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow
) {
	WNDCLASS wc;
	MSG msg;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;  //WindowProcedure�̊֐������w�肷��
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_BACKGROUND + 1;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = APP_NAME;

	if (!RegisterClass(&wc)) return 0;

	if (CreateWindow(
		APP_NAME, TEXT(__FILE__),
		WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_MAXIMIZEBOX | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT,
		900, 450, // �����ŁA�E�B���h�E�̃T�C�Y�iWidth,Height)���w�肷�� 
		NULL, NULL, hInstance, NULL
	) == NULL) return 0;

	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		DispatchMessage(&msg);
	}

	return msg.wParam;
}