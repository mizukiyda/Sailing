#ifndef INCLUDED_MAP
#define INCLUDED_MAP


#define MAP_SIZE	32			// マップチップ一つのドットサイズ
#define MAP_WIDTH	10			// マップの幅
#define MAP_HEIGHT	8			// マップの縦長さ

#define MAP_MAX 10				// MAPの最大数

extern int MAP_Init();
extern int MAP_Dpct();
extern int MAP_Draw();
extern int MAP_End();

int MAP_Data(int, int);        //マップの配列  Map_data[][]

int MAP_Player_Pos_Init_x();   //プレイヤーの初期x座標
int MAP_Player_Pos_Init_y();   //プレイヤーの初期y座標
int MAP_Enemy_Count_Init();      //Enemyの個数
int MAP_Enemy_Pos_Init_x(int);   //Enemyの初期X座標
int MAP_Enemy_Pos_Init_y(int);   //Enemyの初期Y座標

int MAP_GetHandleflag();
void MAP_SetHandleflag(int);

#endif
