#include"Dxlib.h"
#include"Enemy.h"
#include"MAP.h"
#include"Player.h"

#define ENEMY_MAX 4						//敵の最大数

S_Enemy enemy[ENEMY_MAX];					//敵の配列

//for文用に使う変数
int i, j, k;

//移動	
int count_x;						//マップサイズ分カウント ｘ
int count_y;						//マップサイズ分カウント ｙ

//向き
E_Drct Drct;						//向きの管理

//攻撃のフラグ（主に画像の描画に使っている）
int Attack_Flg = false;

//playerの座標
int player_x;						//playerのx座標
int player_y;						//playerのy座標

//playerへの当たり判定
int Player_Hit_Flg = false;

//画像
int EnemyGyallaly[12];				//敵の画像の変数
int EnemyShotGyallaly;				//敵の弾の画像の変数

//enemyへの当たり判定
int Enemy_Hit_Flg = false;

//生きている状態を作る
int OnActives = true;

int Enemy_Init() {
	//初期化処理

	LoadDivGraph("resource/Image/", 12, 3, 4, 48, 48, EnemyGyallaly);								// 敵の画像をロード
	LoadDivGraph("resource/Image/", 2, 2, 1, 11, 6, EnemyShotGyallaly);								//敵の弾の画像をロード


	for (i = 0;i < ENEMY_MAX;i++) {
		enemy[i].x = MAP_Enemy_Pos_Init_x(i);					//MAPからエネミーの初期x座標をもらう
		enemy[i].y = MAP_Enemy_Pos_Init_y(i);					//MAPからエネミーの初期y座標をもらう
	}

	player_x = ;						//playerのx座標を入れるための変数
	player_y = ;						//playerのy座標を入れるための変数

	return 0;
}

int Enemy_MapDeta(int x, int y) {		
	//enemy専用のMapデータを収納する

	return 0;
}

int Enemy_Dpct() {

	enemy[ENEMY_MAX].ex = enemy[ENEMY_MAX].x;		//enemyの弾をEnemyのx座標に格納する
	enemy[ENEMY_MAX].ey = enemy[ENEMY_MAX].y;		//enemyの弾をEnemyのy座標に格納する

	Enemy_Hit_Flg = ;								//playerからもらったフラグを入れる変数

	if (Enemy_Hit_Flg == true) {					//もし当たったなら				
		OnActives = false;							//生きている状態をOFFにする
	}

	//目の前が壁かどうかの判別をする（enemy専用Mapを見て判断する) -> 目の前が道のとき
	if (Enemy_MapDeta(enemy[ENEMY_MAX].x, enemy[ENEMY_MAX].y) == E_Object_Load) {
		Drct = (E_Drct)GetRand(4);					//（キャスト演算）0～4までの数字で向きをランダムに代入する
	}

	/*************************************************  Enemyの移動制御  *********************************************************************/

	switch (Drct)
	{
		//止まる
	case E_Drct_Stop:					//動かない

		break;

		//上
	case E_Drct_Up:						//向きが上なら(1)
		count_y--;						//ヌルヌル動かす
		break;

		//左
	case E_Drct_Left:					//向きが左なら(4)
		count_x--;						//ヌルヌル動かす
		break;

		//下
	case E_Drct_Down:					//向きが下なら(3)
		count_y++;						//ヌルヌル動かす
		break;

		//右
	case E_Drct_Right:					//向きが右なら(2)
		count_x++;						//ヌルヌル動かす
		break;

	}

	//目の前が壁かどうかの判別をする（enemy専用Mapを見て判断する) -> 目の前が壁のとき
	if (Enemy_MapDeta(enemy[ENEMY_MAX].x, enemy[ENEMY_MAX].y) == E_Object_Wall) {

		if (E_Drct_Up == true) {
			while (Drct == 1) {								//上から来たから1が来たらも一度回す
				Drct = (E_Drct)GetRand(4);					//（キャスト演算）0～4までの数字で向きをランダムに代入する
			}
		}

		if (E_Drct_Down == true) {
			while (Drct == 3) {								//下から来たから3が来たらも一度回す
				Drct = (E_Drct)GetRand(4);					//（キャスト演算）0～4までの数字で向きをランダムに代入する
			}
		}

		if (E_Drct_Left == true) {
			while (Drct == 4) {								//左から来たから4が来たらも一度回す
				Drct = (E_Drct)GetRand(4);					//（キャスト演算）0～4までの数字で向きをランダムに代入する
			}
		}

		if (E_Drct_Right == true) {
			while (Drct == 2) {								//右から来たから2が来たらも一度回す
				Drct = (E_Drct)GetRand(4);					//（キャスト演算）0～4までの数字で向きをランダムに代入する
			}
		}

		if (E_Drct_Stop == true) {
			while (Drct == 0) {								//停止していたから0が来たらも一度回す
				Drct = (E_Drct)GetRand(4);					//（キャスト演算）0～4までの数字で向きをランダムに代入する
			}
		}
	}

	//count_x/count_yのどれかのカウントが±64なら　>>　Player.x/yの座標更新・カウントとフラグの初期化
	if (count_x >= MAP_SIZE - 1 || count_y <= -MAP_SIZE + 1 || count_x <= -MAP_SIZE + 1 || count_y >= MAP_SIZE - 1)
	{
		//カウントの初期化
		count_x = 0;
		count_y = 0;
	}
		/**************************************************enemyの攻撃準備***********************************************/

	for (i = 0;i < 4;i++) {
		if (Drct == E_Drct_Left) {									//もしenemyが左を向いていて
			if (enemy[i].x - MAP_SIZE * 5 <= player_x) {			//なおかつエネミーの左からプレイヤーが来るなら
				Enemy_Attack_Left();
				Attack_Flg = true;
			}
		}

		if (Drct == E_Drct_Right) {									//もしenemyが右を向いていて
			if (enemy[i].x + MAP_SIZE * 5 >= player_x) {			//なおかつエネミーの右からプレイヤーが来るなら
				Enemy_Attack_Right();
				Attack_Flg = true;
			}
		}

		if (Drct == E_Drct_Down) {									//もしenemyが下を向いていて
			if (enemy[i].y - MAP_SIZE * 5 <= player_y) {			//なおかつエネミーの下からプレイヤーが来るなら
				Enemy_Attack_Down();
				Attack_Flg = true;
			}
		}

		if (Drct == E_Drct_Up) {									//もしenemyが上を向いていて
			if (enemy[i].y + MAP_SIZE * 5 >= player_y) {			//なおかつエネミーの上からプレイヤーが来るなら
				Enemy_Attack_Up();
				Attack_Flg = true;
			}
		}
	}
	return 0;
}
/********************************************* 弾を打つ（主に攻撃を行う処理）***********************************************************/
		
int Enemy_Attack_Left() {		//左に弾を打つ

	enemy[ENEMY_MAX].ex -= 5;

	if (enemy[ENEMY_MAX].ex == player_x && enemy[ENEMY_MAX].ey == player_y) {			//もしplayerに当たったらフラグをONにして、Playerに当たり判定を渡す
		Player_Hit_Flg = true;
		Attack_Flg = false;																//もしplayer弾とエネミー弾が当たったら消滅する
	}

	if (enemy[ENEMY_MAX].ex >= enemy[ENEMY_MAX].x - MAP_SIZE * 5) {						//もしenemyの弾がenemyのx座標を中心に3マスを超えたら、消滅する。
		Attack_Flg = false;
	}

	return Player_Hit_Flg;
}

int Enemy_Attack_Right() {		//右に弾を打つ

	enemy[ENEMY_MAX].ex += 5;

	if (enemy[ENEMY_MAX].ex == player_x && enemy[ENEMY_MAX].ey == player_y) {			//もしplayerに当たったらフラグをONにして、Playerに当たり判定を渡す
		Player_Hit_Flg = true;
		Attack_Flg = false;																//もしplayer弾とエネミー弾が当たったら消滅する
	}

	if (enemy[ENEMY_MAX].ex >= enemy[ENEMY_MAX].x + MAP_SIZE * 5) {						//もしenemyの弾がenemyのx座標を中心に3マスを超えたら、消滅する。
		Attack_Flg = false;
	}

	return Player_Hit_Flg;
}

int Enemy_Attack_Down() {		//下に弾を打つ

	enemy[ENEMY_MAX].ey -= 5;

	if (enemy[ENEMY_MAX].ex == player_x && enemy[ENEMY_MAX].ey == player_y) {			//もしplayerに当たったらフラグをONにして、Playerに当たり判定を渡す
		Player_Hit_Flg = true;
		Attack_Flg = false;																//もしplayer弾とエネミー弾が当たったら消滅する
	}

	if (enemy[ENEMY_MAX].ey >= enemy[ENEMY_MAX].y - MAP_SIZE * 5) {						//もしenemyの弾がenemyのy座標を中心に3マスを超えたら、消滅する。
		Attack_Flg = false;
	}

	return Player_Hit_Flg;
}

int Enemy_Attack_Up() {			//上に弾を打つ

	enemy[ENEMY_MAX].ey += 5;

	if (enemy[ENEMY_MAX].ex == player_x && enemy[ENEMY_MAX].ey == player_y) {			//もしplayerに当たったらフラグをONにして、Playerに当たり判定を渡す
		Player_Hit_Flg = true;
		Attack_Flg = false;																//もしplayer弾とエネミー弾が当たったら消滅する
	}

	if (enemy[ENEMY_MAX].ey >= enemy[ENEMY_MAX].y + MAP_SIZE * 5) {						//もしenemyの弾がenemyのy座標を中心に3マスを超えたら、消滅する。
		Attack_Flg = false;
	}

	return Player_Hit_Flg;
}

int Enemy_Draw() {
	//描画処理
	
	for (i = 0;i < 4;i++) {
		if (OnActives == true) {																								//もしenemyが生きているのなら
			DrawGraph(enemy[i].x * MAP_SIZE + count_x, enemy[i].y * MAP_SIZE + count_y, EnemyGyallaly[0], true);				//enemyの描写

			if (Attack_Flg = true) {																							//もし攻撃状態なら
				DrawGraph(enemy[i].ex, enemy[i].ey, EnemyShotGyallaly, true);													//攻撃の描写								
			}
		}
	}
	return 0;
}

int Enemy_End() {
	//終了処理

	return 0;
}