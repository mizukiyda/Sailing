#include"Dxlib.h"
#include"Enemy.h"

#define NUM 4			//�G�̍ő吔

S_Enemy enemy[NUM];		//�G�̔z��

						//for���p�Ɏg���ϐ�
int i, j, k;

//�ړ�
int count_x;			//�}�b�v�T�C�Y���J�E���g ��
int count_y;			//�}�b�v�T�C�Y���J�E���g ��

						//����
E_Drct Drct;			//�����̊Ǘ�

						//�摜
int Gyallaly[4];		//�G�̉摜�̕ϐ�

int Enemy_Init() {

	for (i = 0;i < 4;i++) {
		enemy[i].x = ;		//MAP����G�l�~�[�̏���x���W�����炤
		enemy[i].y = ;		//MAP����G�l�~�[�̏���y���W�����炤
	}

	return 0;
}

int Enemy_MapDeta(int x, int y) {		//enemy��p��Map�f�[�^�����[����

	return 0;
}

int Enemy_Move() {

	return 0;
}

int Enemy_Dpct() {

	//�ڂ̑O���ǂ��ǂ����̔��ʂ�����ienemy��pMap�����Ĕ��f����)
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