#include"Dxlib.h"
#include"Enemy.h"
#include"MAP.h"
#include"Player.h"

#define NUM 4						//�G�̍ő吔

S_Enemy enemy[NUM];					//�G�̔z��

//for���p�Ɏg���ϐ�
int i, j, k;

//�ړ�	
int count_x;						//�}�b�v�T�C�Y���J�E���g ��
int count_y;						//�}�b�v�T�C�Y���J�E���g ��

//����
E_Drct Drct;						//�����̊Ǘ�

//�U���̃t���O�i��ɉ摜�̕`��Ɏg���Ă���j
int Attack_Flg = false;

//player�̍��W
int player_x;						//player��x���W
int player_y;						//player��y���W

//player�ւ̓����蔻��
int Player_Hit_Flg = false;

//�摜
int EnemyGyallaly[4];				//�G�̉摜�̕ϐ�
int EnemyShotGyallaly;				//�G�̒e�̉摜�̕ϐ�

int Enemy_Init() {
	//����������

	LoadDivBmpToGraph("Image/", 2, 2, 1, 11, 6, EnemyGyallaly[4]);								// �G�̉摜�����[�h
	LoadDivBmpToGraph("Image/", 2, 2, 1, 11, 6, EnemyShotGyallaly);								//�G�̒e�̉摜�����[�h


	for (i = 0;i < 4;i++) {
		enemy[i].x = ;					//MAP����G�l�~�[�̏���x���W�����炤
		enemy[i].y = ;					//MAP����G�l�~�[�̏���y���W�����炤
	}

	player_x = ;						//player��x���W�����邽�߂̕ϐ�
	player_y = ;						//player��y���W�����邽�߂̕ϐ�

	return 0;
}

int Enemy_MapDeta(int x, int y) {		
	//enemy��p��Map�f�[�^�����[����

	return 0;
}

int Enemy_Dpct() {

	enemy[NUM].ex = enemy[NUM].x;		//enemy�̒e��Enemy��x���W�Ɋi�[����
	enemy[NUM].ey = enemy[NUM].y;		//enemy�̒e��Enemy��y���W�Ɋi�[����

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

	for (i = 0;i < 4;i++) {
		if (Drct == E_Drct_Left) {									//����enemy�����������Ă���
			if (enemy[i].x - MAP_SIZE * 3 <= player_x) {			//�Ȃ����G�l�~�[�̍�����v���C���[������Ȃ�
				Enemy_Attack_Left();
				Attack_Flg = true;
			}
		}

		if (Drct == E_Drct_Right) {									//����enemy���E�������Ă���
			if (enemy[i].x + MAP_SIZE * 3 >= player_x) {			//�Ȃ����G�l�~�[�̉E����v���C���[������Ȃ�
				Enemy_Attack_Right();
				Attack_Flg = true;
			}
		}

		if (Drct == E_Drct_Down) {									//����enemy�����������Ă���
			if (enemy[i].y - MAP_SIZE * 3 <= player_y) {			//�Ȃ����G�l�~�[�̉�����v���C���[������Ȃ�
				Enemy_Attack_Down();
				Attack_Flg = true;
			}
		}

		if (Drct == E_Drct_Up) {									//����enemy����������Ă���
			if (enemy[i].y + MAP_SIZE * 3 >= player_y) {			//�Ȃ����G�l�~�[�̏ォ��v���C���[������Ȃ�
				Enemy_Attack_Up();
				Attack_Flg = true;
			}
		}
	}
	return 0;
}
/********************************************* �e��łi��ɍU�����s�������j***********************************************************/
		
int Enemy_Attack_Left() {		//���ɒe��ł�

	enemy[NUM].ex -= 5;

	if (enemy[NUM].ex == player_x && enemy[NUM].ey == player_y) {			//����player�ɓ���������t���O��ON�ɂ��āAPlayer�ɓ����蔻���n��
		Player_Hit_Flg = true;
	}

	if (enemy[NUM].ex == player_x && enemy[NUM].ey == player_y) {			//����player�e�ƃG�l�~�[�e��������������ł���
		Attack_Flg = false;
	}

	if (enemy[NUM].ex >= enemy[NUM].x - MAP_SIZE * 3) {						//����enemy�̒e��enemy��x���W�𒆐S��3�}�X�𒴂�����A���ł���B
		Attack_Flg = false;
	}

	return Player_Hit_Flg;
}

int Enemy_Attack_Right() {		//�E�ɒe��ł�

	enemy[NUM].ex += 5;

	if (enemy[NUM].ex == player_x && enemy[NUM].ey == player_y) {			//����player�ɓ���������t���O��ON�ɂ��āAPlayer�ɓ����蔻���n��
		Player_Hit_Flg = true;
	}

	if (enemy[NUM].ex == player_x && enemy[NUM].ey == player_y) {			//����player�e�ƃG�l�~�[�e��������������ł���
		Attack_Flg = false;
	}

	if (enemy[NUM].ex >= enemy[NUM].x + MAP_SIZE * 3) {						//����enemy�̒e��enemy��x���W�𒆐S��3�}�X�𒴂�����A���ł���B
		Attack_Flg = false;
	}

	return Player_Hit_Flg;
}

int Enemy_Attack_Down() {		//���ɒe��ł�

	enemy[NUM].ey -= 5;

	if (enemy[NUM].ex == player_x && enemy[NUM].ey == player_y) {			//����player�ɓ���������t���O��ON�ɂ��āAPlayer�ɓ����蔻���n��
		Player_Hit_Flg = true;
	}

	if (enemy[NUM].ex == player_x && enemy[NUM].ey == player_y) {			//����player�e�ƃG�l�~�[�e��������������ł���
		Attack_Flg = false;
	}

	if (enemy[NUM].ey >= enemy[NUM].y - MAP_SIZE * 3) {						//����enemy�̒e��enemy��y���W�𒆐S��3�}�X�𒴂�����A���ł���B
		Attack_Flg = false;
	}

	return Player_Hit_Flg;
}

int Enemy_Attack_Up() {			//��ɒe��ł�

	enemy[NUM].ey += 5;

	if (enemy[NUM].ex == player_x && enemy[NUM].ey == player_y) {			//����player�ɓ���������t���O��ON�ɂ��āAPlayer�ɓ����蔻���n��
		Player_Hit_Flg = true;
	}

	if (enemy[NUM].ex == player_x && enemy[NUM].ey == player_y) {			//����player�e�ƃG�l�~�[�e��������������ł���
		Attack_Flg = false;
	}

	if (enemy[NUM].ey >= enemy[NUM].y + MAP_SIZE * 3) {						//����enemy�̒e��enemy��y���W�𒆐S��3�}�X�𒴂�����A���ł���B
		Attack_Flg = false;
	}

	return Player_Hit_Flg;
}

int Enemy_Draw() {
	//�`�揈��
	for (i = 0;i < 4;i++) {					
		DrawGraph(enemy[i].x * MAP_SIZE + count_x, enemy[i].y * MAP_SIZE + count_y, EnemyGyallaly[0], true);				//enemy�̕`��

		if (Attack_Flg = true) {																							//�����U����ԂȂ�
			DrawGraph(enemy[i].ex, enemy[i].ey, EnemyShotGyallaly, true);													//�U���̕`��								
		}
	}

	return 0;
}

int Enemy_End() {
	//�I������

	return 0;
}