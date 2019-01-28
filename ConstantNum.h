#ifndef _CONSTANT_NUM_INCLUDE_
#define _CONSTANT_NUM_INCLUDE_

/*
定数を使うときはこのファイルをインクルードしてください。
*/

//マスの状態
#define EMPTY 0  //空
#define BLACK 1  //黒
#define WHITE 2  //白

//シーンの状態
//#define TITLE 0   //タイトル画面
#define INGAME 0    //ゲーム中
#define RESULT 1  //結果画面


//マスの情報を持った構造体　二次元配列で定義する
typedef struct {
	int type;  //マスの状態 0:空 1:黒のコマが置かれている状態 2:白のコマが置かれている状態
	int putflag;  //そのマスにコマを置けるかどうか 0:置けない状態 1:置ける状態
}sMASS;

#endif