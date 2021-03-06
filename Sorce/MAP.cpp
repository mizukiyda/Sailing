
// マップ表示基本
#include "DxLib.h"
#include "MAP.h"
#include "Player.h"
#include "Scene_Mgr.h"

int FileHandle, y;
static int i = 0, j = 0;
char buf[256];
char c1, c2;				    //MAPとPlayer,Enemyに使うchar
int MAP[MAP_HEIGHT][MAP_WIDTH]; //マップ
int px, py;				    	//受け取るプレイヤーの変数
int Enemy_Count;				    //受け取るEnemyの変数;
static int Enemy_Pos_x[10];		//受け取るEnemyのx座標変数
static int Enemy_Pos_y[10];		//受け取るEnemyのy座標変数
int lflag;

int Image_Wall  = 0;
int Image_Load  = 0;
int Image_Goal  = 0;

char MAPHandle[256];
int Handleflag = 1;


//10はdefineかconstで定義すべき
//むしろ構造体を共通すべき


//プレイヤーの初期x座標を受け取る
int MAP_Player_Pos_Init_x(){

	return px;		//初期化したプレイヤーのx座標を戻す
}

//プレイヤーの初期y座標を受け取る
int MAP_Player_Pos_Init_y() {

	return py;		//初期化したプレイヤーのy座標を戻す
}

//MAPの座標
int MAP_Data(int x, int y) {	

	return MAP[y][x];
}

//Enemyの個数を受け取る
int MAP_Enemy_Count_Init() {

	return Enemy_Count;
}

//Enemyの初期X座標
int MAP_Enemy_Pos_Init_x(int num) {

	return Enemy_Pos_x[num];
}

//Enemyの初期Y座標
int MAP_Enemy_Pos_Init_y(int num) {

	return Enemy_Pos_y[num];
}

//初期化
int MAP_Init() {
	memset(MAP, -1, sizeof(MAP));
	Enemy_Count = 1;	//受け取ったEnemyの数の初期化
	i = 0; j = 0;

	//画像の読み込み
	//ImageWall = LoadGraph("");
	//ImageLoad = LoadGraph("");	//画像入れたらコメントアウト解除
	//ImageGoal = LoadGraph("");
	
	char Handletmp[256];	// 結果的にこの名前のパスでファイルを開く
	char flagtmp[256];		// MAP_〇…〇の部分

	strcpy_s(MAPHandle, "resauce/MAP/MAP_");	// MAPHandleに固定文をコピー

	sprintf_s(flagtmp, "%d", Handleflag);		// falgtmpにMAP_SetHandleflagから数字を入れる

	strcpy_s(Handletmp, MAPHandle);			// MAPHandleにコピーしたのをコピー

	strcat_s(Handletmp, flagtmp);				// flagtmpにコピーしたのをコピー

	strcat_s(Handletmp, ".csv");				// 最後に.csvをコピー

	// resauce/MAP/MAP_ / %d / .csv	で区画分けしている

	// MAPの読み込み
	FileHandle = FileRead_open( Handletmp );	// 一行読み込み
													// ファイルの終端が来るまで表示する
	if (FileHandle == 0) {

//		WaitKey();
		Scene_Mgr_ChangeScene(E_Scene_StartMenu);
		return -1;

	}

	while (FileRead_eof(FileHandle) == 0) {			// 一行読み込み

		//c1 = MAPのchar
		c1 = FileRead_getc(FileHandle);		//1文字読み込む
		if ('0' <= c1 && c1 <= '9') {		//もし0〜9だったら
			MAP[i][j] = c1 - '0';				//MAPに代入
		}
		else if (c1 == ',') {				//もし","を読み込んだら
			j++;							//右の数字を読み込む
		}
		else if (c1 == '\n') {					//もし"\n"を読み込んだら
			j = 0;							//右に行くのをやめる
			i++;							//次の行に行く
		}
	} 

	// ファイルを閉じる
	FileRead_close(FileHandle);

	strcpy_s(Handletmp, MAPHandle);

	strcat_s(Handletmp, flagtmp);

	strcat_s(Handletmp, ".txt");


	
	// Playerの座標読み込み
	FileHandle = FileRead_open( Handletmp );	//1行読み込み
													// ファイルの終端が来るまで表示する
	if (FileHandle == 0) {

//		WaitKey();
		Scene_Mgr_ChangeScene(E_Scene_StartMenu);
		return -1;

	}

	//c2 = PlayerとEnemyのchar
	
	c2 = FileRead_getc(FileHandle);		//1文字読み込む	
	px = c2 - '0';				    //PlayerのX座標に代入
	
	FileRead_getc(FileHandle);

	c2 = FileRead_getc(FileHandle);						//右の数字を読み込む
	py = c2 - '0';

	FileRead_getc(FileHandle);

	
	Enemy_Count = 0;

	
	while (1) {
		FileRead_getc(FileHandle);
		if (c2 == EOF)break;
		c2 = FileRead_getc(FileHandle);
		if (c2 == EOF)break;
		Enemy_Pos_x[Enemy_Count] = c2 - '0';;
		
		FileRead_getc(FileHandle);
		if (c2 == EOF)break;
		c2 = FileRead_getc(FileHandle);
		if (c2 == EOF)break;
		Enemy_Pos_y[Enemy_Count] = c2 - '0';;
		FileRead_getc(FileHandle);
		if (c2 == EOF)break;
		Enemy_Count++;
	}
	
	
	// ファイルを閉じる
	FileRead_close(FileHandle);

	return 0;

}



//計算
int MAP_Dpct() {
	//Dpctは毎フレーム呼ばれる

	return 0;
}


//描写
int MAP_Draw() {
	//こっちも毎フレーム呼ばれるが計算とは別に書きます
	
	// マップを描く
	for (i = 0; i < MAP_HEIGHT; i++)
	{
		for (j = 0; j < MAP_WIDTH; j++)
		{

			
			if (MAP[i][j] == P_wall)		// 壁の描画処理
			{
				//DrawEnemy(j * MAP_SIZE, i * MAP_SIZE,j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE,GetColor(0, 230, 0), TRUE);
				DrawGraph(j * MAP_SIZE, i * MAP_SIZE, Image_Wall, TRUE);
			}

			if (MAP[i][j] == P_load)		// 床の描画処理
			{
				//DrawEnemy(j * MAP_SIZE, i * MAP_SIZE,j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE,GetColor(122, 255, 122), TRUE);
				DrawGraph(j * MAP_SIZE, i * MAP_SIZE, Image_Load, TRUE);
			}
			if (MAP[i][j] == E_goal)		// ゴールの描画処理
			{
				//DrawEnemy(j * MAP_SIZE, i * MAP_SIZE,j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE,GetColor(122, 122, 255), TRUE);
				DrawGraph(j * MAP_SIZE, i * MAP_SIZE, Image_Goal, TRUE);
			}
			
			/*
			if (MAP[i][j] == 0)		// 壁の描画処理
			{
				DrawBox(j * MAP_SIZE, i * MAP_SIZE, j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE, GetColor(0, 230, 0), TRUE);
				//DrawGraph(j * MAP_SIZE, i * MAP_SIZE, Image_Wall, TRUE);
			}

			if (MAP[i][j] == 1)		// 床の描画処理
			{
				DrawBox(j * MAP_SIZE, i * MAP_SIZE, j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE, GetColor(122, 255, 122), TRUE);
				//DrawGraph(j * MAP_SIZE, i * MAP_SIZE, Image_Load, TRUE);
			}
			if (MAP[i][j] == 2)		// ゴールの描画処理
			{
				DrawBox(j * MAP_SIZE, i * MAP_SIZE, j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE, GetColor(122, 122, 0), TRUE);
				//DrawGraph(j * MAP_SIZE, i * MAP_SIZE, Image_Goal, TRUE);
			}
			*/
			
		}
		
	}
	
	DrawFormatString(100, 200, GetColor(255, 0, 0), "MAP Draw動いてるよん");
	return 0;
}


void MAP_SetHandleflag(int num) {
	Handleflag = num;
}

int MAP_GetHandleflag() {
	return Handleflag;
}

//終了
int MAP_End() {
	DeleteGraph(Image_Wall);
	DeleteGraph(Image_Load);
	DeleteGraph(Image_Goal);

	return 0;
}