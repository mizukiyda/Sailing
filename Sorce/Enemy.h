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

typedef struct {	//構造体
	int x;		//enemyのx座標
	int y;		//enemyのy座標

	int ex;		//enemyのbulletのx座標
	int ey;		//enemyのbulletのy座標
} S_Enemy;

typedef enum {

	E_Drct_Up,     //上
	E_Drct_Right,  //右
	E_Drct_Down,   //下
	E_Drct_Left,   //左

	E_Drct_None

} E_Drct;  //Drct = Direction(向き)

 //オブジェクトの当たり判定用
typedef enum {

	E_Object_Wall,      //行けない場所
	E_Object_Load,      //歩ける場所

}E_Object;

#endif