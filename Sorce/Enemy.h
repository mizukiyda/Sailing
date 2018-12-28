#ifndef INCLUDE_ENEMY
#define INCLUDE_ENEMY

extern int Enemy_Init();
extern int Enemy_Dpct();
extern int Enemy_Draw();
extern int Enemy_End();

extern int Enemy_MapDeta(int, int);

extern int Enemy_Attack_Down();
extern int Enemy_Attack_Up();
extern int Enemy_Attack_Right();
extern int Enemy_Attack_Left();
extern int Enemy_Hit();

typedef struct {	//構造体
	int x;		//enemyのx座標
	int y;		//enemyのy座標

	int ex;		//enemyのbulletのx座標
	int ey;		//enemyのbulletのy座標
} S_Enemy;

typedef enum {

	E_Drct_Stop,	//とまる	-> 0
	E_Drct_Up,		//上		-> 1
	E_Drct_Right,	//右		-> 2
	E_Drct_Down,	//下		-> 3
	E_Drct_Left,	//左		-> 4

} E_Drct;  //Drct = Direction(向き)

 //オブジェクトの当たり判定用
typedef enum {

	E_Object_Load,      //歩ける場所      -> 0
	E_Object_Wall,      //行けない場所    -> 1

}E_Object;

#endif