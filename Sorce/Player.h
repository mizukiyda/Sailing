#ifndef PLAYER_DEFENCE
#define PLAYER_DEFENCE

typedef struct {
	int x;		//現在位置
	int y;		//現在位置
	int nx;		//移動先
	int ny;		//移動先
}P_PLAYER;	//Pos_Player

typedef struct {
	bool RIGHT;
	bool LEFT;
	bool UP;
	bool DOWN;
	bool NONE;
}P_DRCT;	//プレイヤーの向き  Player_Direction
	
typedef struct {
	int P_wall;
	int P_load;
	int E_goal;
}E_Object;	//物体


#endif 
