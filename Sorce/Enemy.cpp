#include"Dxlib.h"
#include"Enemy.h"

#define NUM 4			//敵の最大数

S_Enemy enemy[NUM];		//敵の配列

						//for文用に使う変数
int i, j, k;

//移動
int count_x;			//マップサイズ分カウント ｘ
int count_y;			//マップサイズ分カウント ｙ

						//向き
E_Drct Drct;			//向きの管理

						//画像
int Gyallaly[4];		//敵の画像の変数

int Enemy_Init() {

	for (i = 0;i < 4;i++) {
		enemy[i].x = ;		//MAPからエネミーの初期x座標をもらう
		enemy[i].y = ;		//MAPからエネミーの初期y座標をもらう
	}

	return 0;
}

int Enemy_MapDeta(int x, int y) {		//enemy専用のMapデータを収納する

	return 0;
}

int Enemy_Move() {

	return 0;
}

int Enemy_Dpct() {

	//目の前が壁かどうかの判別をする（enemy専用Mapを見て判断する)
	if (Enemy_MapDeta(enemy[NUM].x, enemy[NUM].y) == E_Object_Wall) {

		if (E_Drct_Up == true) {
			Drct = E_Drct_Down;
		}
		if (E_Drct_Down == true) {
			Drct = E_Drct_Up;
		}
		if (E_Drct_Left == true) {
			Drct = E_Drct_Right;
		}
		if (E_Drct_Right == true) {
			Drct = E_Drct_Left;
		}

	}
	return 0;
}

int Enemy_Draw() {

	for (i = 0;i < 4;i++) {
		DrawGraph(enemy[i].x * MAP_SIZE + count_x, enemy[i].y * MAP_SIZE + count_y, Gyallaly[0], true);
	}
	return 0;
}

int Enemy_End() {

	return 0;
}