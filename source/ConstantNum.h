#ifndef _CONSTANT_NUM_INCLUDE_
#define _CONSTANT_NUM_INCLUDE_

/*
定数を使うときはこのファイルをインクルードしてください。
*/

//マスの状態
#define ENPTY 0  //空
#define BLACK 1  //黒
#define WHITE 2  //白

//シーンの状態
#define TITLE 0   //タイトル画面
#define GAME 1    //ゲーム中
#define RESULT 2  //結果画面

typedef struct {
	int type;
	int putflag;
}sMASS;

#endif