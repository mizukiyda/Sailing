#ifndef INCLUDE_ENEMY
#define INCLUDE_ENEMY

extern int Enemy_Init();
extern int Enemy_Dpct();
extern int Enemy_Draw();
extern int Enemy_End();

extern int Enemy_MapDeta(int, int);
extern int Enemy_Move();

typedef struct {	//�\����
	int x;		//x���W
	int y;		//y���W

} S_Enemy;

typedef enum {

	E_Drct_Up,     //��
	E_Drct_Right,  //�E
	E_Drct_Down,   //��
	E_Drct_Left,   //��

	E_Drct_None

} E_Drct;  //Drct = Direction(����)

typedef enum {

	E_Object_Wall,      //�s���Ȃ��ꏊ
	E_Object_Load,      //������ꏊ

}E_Object;

#endif