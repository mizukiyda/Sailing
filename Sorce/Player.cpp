#include"DxLib.h"
#include"Player.h"
#include"MAP.h"


/************************************************
*												*
*												*
*												*
************************************************/

//ÉãÅ[Évóp
static int i, j, k;

P_PLAYER player;
P_DRCT drct;
E_Object obj;

int PGHandle;

int Player_Init() {
	player.x = MAP_Player_Pos_Init_x();
	player.y = MAP_Player_Pos_Init_y();
	LoadDivGraph("", 0);
}

int Player_Drct() {

}

int Player_Move() {

}

int Player_Object() {

}

int Player_Draw() {

}