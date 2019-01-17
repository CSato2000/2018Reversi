#include <windows.h>

#define APP_NAME TEXT("reversi")

#define WHITE        1  // 表示色　白
#define BLACK        2  // 表示色　黒
#define GREEN        3  // 表示色　緑
#define RED          4  // 表示色　赤

#define EMP          0

// masuは外周を検索することから8x8ではなく、10x10としている
// したがって、有効範囲は、1-8までの位置となる
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
関数名 : WindowProc
機能   : メッセージ処理を行う
引数   : 省略
返却値 : 省略
*******************************************************************************/
LRESULT CALLBACK WindowProc(
	HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam
) {
	HDC hdc;
	PAINTSTRUCT ps;
	static HBRUSH hBrush[3];
	int i, j;


	// 盤面上の小さい黒丸の座標点（描画時の各中心座標）
	static POINT dot[4] = {
		{ 100,100 },
	{ 300,100 },
	{ 100,300 },
	{ 300,300 }
	};

	switch (uMsg) {

	case WM_CREATE:  // 初期生成時の処理（初期化）

					 //ブラシデータの定義
		hBrush[0] = CreateSolidBrush(RGB(0, 0xAA, 0));          // 盤面（緑）
		hBrush[1] = CreateSolidBrush(RGB(0xFF, 0xFF, 0xFF));    // WHITE
		hBrush[2] = CreateSolidBrush(RGB(0, 0, 0));		        // BLACK
		return 0;

	case WM_DESTROY:  // ウィンドウ破棄時の処理
					  // ブラシの削除
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


	case WM_PAINT: // 描画イベント発生時　　（画面に変化があった際に頻繁に呼び出される)

				   // ペイント開始
		hdc = BeginPaint(hWnd, &ps);

		// オセロ盤の描画

		SelectObject(hdc, hBrush[0]);
		Rectangle(hdc, 0, 0, 401, 401);

		for (i = 0; i < 7; i++) {
			MoveToEx(hdc, 50 * (i + 1), 0, NULL);
			LineTo(hdc, 50 * (i + 1), 400);
			MoveToEx(hdc, 0, 50 * (i + 1), NULL);
			LineTo(hdc, 400, 50 * (i + 1));
		}

		//小さな黒丸の描画
		SelectObject(hdc, hBrush[2]);
		for (i = 0; i < 4; i++) {
			Ellipse(hdc, dot[i].x - 5, dot[i].y - 5,
				dot[i].x + 5, dot[i].y + 5);
		}

		// オセロ盤の表示
		for (i = 1; i <= 8; i++) {
			for (j = 1; j <= 8; j++) {
				if (masu[i][j] != EMP) {
					if (masu[i][j] == WHITE) {
						SelectObject(hdc, hBrush[1]);  //白
					}
					else if (masu[i][j] == BLACK) {
						SelectObject(hdc, hBrush[2]);  //黒
					}
					Ellipse(hdc, (i - 1) * 50, (j - 1) * 50, i * 50, j * 50);
				}
			}
		}

		//クリックしたときのコマの描画
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

	} //switch文の終了

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

/*******************************************************************************
関数名 : WinMain
機能   : ゲームの初期化とメッセージループ
引数   : 省略
返却値 : 省略
*******************************************************************************/

int WINAPI WinMain(
	HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow
) {
	WNDCLASS wc;
	MSG msg;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;  //WindowProcedureの関数名を指定する
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
		900, 450, // ここで、ウィンドウのサイズ（Width,Height)を指定する 
		NULL, NULL, hInstance, NULL
	) == NULL) return 0;

	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		DispatchMessage(&msg);
	}

	return msg.wParam;
}