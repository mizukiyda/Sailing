#ifndef PLAYER_DEFENCE
#define PLAYER_DEFENCE

typedef struct {
	int x;		//���݈ʒu
	int y;		//���݈ʒu
	int nx;		//�ړ���
	int ny;		//�ړ���
}P_PLAYER;	//Pos_Player

typedef struct {
	bool RIGHT;
	bool LEFT;
	bool UP;
	bool DOWN;
	bool NONE;
}P_DRCT;	//�v���C���[�̌���  Player_Direction
	
typedef struct {
	int P_wall;
	int P_load;
	int E_goal;
}E_Object;	//����


#endif 
