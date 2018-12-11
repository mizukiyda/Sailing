#include"Dxlib.h"
#include"Enemy.h"
#include"MAP.h"
#include"Player.h"

#define ENEMY_MAX 4						//�G�̍ő吔

S_Enemy enemy[ENEMY_MAX];					//�G�̔z��

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
int EnemyGyallaly[12];				//�G�̉摜�̕ϐ�
int EnemyShotGyallaly;				//�G�̒e�̉摜�̕ϐ�

//enemy�ւ̓����蔻��
int Enemy_Hit_Flg = false;

//�����Ă����Ԃ����
int OnActives = true;

int Enemy_Init() {
	//����������

	LoadDivGraph("resource/Image/", 12, 3, 4, 48, 48, EnemyGyallaly);								// �G�̉摜�����[�h
	LoadDivGraph("resource/Image/", 2, 2, 1, 11, 6, EnemyShotGyallaly);								//�G�̒e�̉摜�����[�h


	for (i = 0;i < ENEMY_MAX;i++) {
		enemy[i].x = MAP_Enemy_Pos_Init_x(i);					//MAP����G�l�~�[�̏���x���W�����炤
		enemy[i].y = MAP_Enemy_Pos_Init_y(i);					//MAP����G�l�~�[�̏���y���W�����炤
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

	enemy[ENEMY_MAX].ex = enemy[ENEMY_MAX].x;		//enemy�̒e��Enemy��x���W�Ɋi�[����
	enemy[ENEMY_MAX].ey = enemy[ENEMY_MAX].y;		//enemy�̒e��Enemy��y���W�Ɋi�[����

	Enemy_Hit_Flg = ;								//player�����������t���O������ϐ�

	if (Enemy_Hit_Flg == true) {					//�������������Ȃ�				
		OnActives = false;							//�����Ă����Ԃ�OFF�ɂ���
	}

	//�ڂ̑O���ǂ��ǂ����̔��ʂ�����ienemy��pMap�����Ĕ��f����) -> �ڂ̑O�����̂Ƃ�
	if (Enemy_MapDeta(enemy[ENEMY_MAX].x, enemy[ENEMY_MAX].y) == E_Object_Load) {
		Drct = (E_Drct)GetRand(4);					//�i�L���X�g���Z�j0�`4�܂ł̐����Ō����������_���ɑ������
	}

	/*************************************************  Enemy�̈ړ�����  *********************************************************************/

	switch (Drct)
	{
		//�~�܂�
	case E_Drct_Stop:					//�����Ȃ�

		break;

		//��
	case E_Drct_Up:						//��������Ȃ�(1)
		count_y--;						//�k���k��������
		break;

		//��
	case E_Drct_Left:					//���������Ȃ�(4)
		count_x--;						//�k���k��������
		break;

		//��
	case E_Drct_Down:					//���������Ȃ�(3)
		count_y++;						//�k���k��������
		break;

		//�E
	case E_Drct_Right:					//�������E�Ȃ�(2)
		count_x++;						//�k���k��������
		break;

	}

	//�ڂ̑O���ǂ��ǂ����̔��ʂ�����ienemy��pMap�����Ĕ��f����) -> �ڂ̑O���ǂ̂Ƃ�
	if (Enemy_MapDeta(enemy[ENEMY_MAX].x, enemy[ENEMY_MAX].y) == E_Object_Wall) {

		if (E_Drct_Up == true) {
			while (Drct == 1) {								//�ォ�痈������1�����������x��
				Drct = (E_Drct)GetRand(4);					//�i�L���X�g���Z�j0�`4�܂ł̐����Ō����������_���ɑ������
			}
		}

		if (E_Drct_Down == true) {
			while (Drct == 3) {								//�����痈������3�����������x��
				Drct = (E_Drct)GetRand(4);					//�i�L���X�g���Z�j0�`4�܂ł̐����Ō����������_���ɑ������
			}
		}

		if (E_Drct_Left == true) {
			while (Drct == 4) {								//�����痈������4�����������x��
				Drct = (E_Drct)GetRand(4);					//�i�L���X�g���Z�j0�`4�܂ł̐����Ō����������_���ɑ������
			}
		}

		if (E_Drct_Right == true) {
			while (Drct == 2) {								//�E���痈������2�����������x��
				Drct = (E_Drct)GetRand(4);					//�i�L���X�g���Z�j0�`4�܂ł̐����Ō����������_���ɑ������
			}
		}

		if (E_Drct_Stop == true) {
			while (Drct == 0) {								//��~���Ă�������0�����������x��
				Drct = (E_Drct)GetRand(4);					//�i�L���X�g���Z�j0�`4�܂ł̐����Ō����������_���ɑ������
			}
		}
	}

	//count_x/count_y�̂ǂꂩ�̃J�E���g���}64�Ȃ�@>>�@Player.x/y�̍��W�X�V�E�J�E���g�ƃt���O�̏�����
	if (count_x >= MAP_SIZE - 1 || count_y <= -MAP_SIZE + 1 || count_x <= -MAP_SIZE + 1 || count_y >= MAP_SIZE - 1)
	{
		//�J�E���g�̏�����
		count_x = 0;
		count_y = 0;
	}
		/**************************************************enemy�̍U������***********************************************/

	for (i = 0;i < 4;i++) {
		if (Drct == E_Drct_Left) {									//����enemy�����������Ă���
			if (enemy[i].x - MAP_SIZE * 5 <= player_x) {			//�Ȃ����G�l�~�[�̍�����v���C���[������Ȃ�
				Enemy_Attack_Left();
				Attack_Flg = true;
			}
		}

		if (Drct == E_Drct_Right) {									//����enemy���E�������Ă���
			if (enemy[i].x + MAP_SIZE * 5 >= player_x) {			//�Ȃ����G�l�~�[�̉E����v���C���[������Ȃ�
				Enemy_Attack_Right();
				Attack_Flg = true;
			}
		}

		if (Drct == E_Drct_Down) {									//����enemy�����������Ă���
			if (enemy[i].y - MAP_SIZE * 5 <= player_y) {			//�Ȃ����G�l�~�[�̉�����v���C���[������Ȃ�
				Enemy_Attack_Down();
				Attack_Flg = true;
			}
		}

		if (Drct == E_Drct_Up) {									//����enemy����������Ă���
			if (enemy[i].y + MAP_SIZE * 5 >= player_y) {			//�Ȃ����G�l�~�[�̏ォ��v���C���[������Ȃ�
				Enemy_Attack_Up();
				Attack_Flg = true;
			}
		}
	}
	return 0;
}
/********************************************* �e��łi��ɍU�����s�������j***********************************************************/
		
int Enemy_Attack_Left() {		//���ɒe��ł�

	enemy[ENEMY_MAX].ex -= 5;

	if (enemy[ENEMY_MAX].ex == player_x && enemy[ENEMY_MAX].ey == player_y) {			//����player�ɓ���������t���O��ON�ɂ��āAPlayer�ɓ����蔻���n��
		Player_Hit_Flg = true;
		Attack_Flg = false;																//����player�e�ƃG�l�~�[�e��������������ł���
	}

	if (enemy[ENEMY_MAX].ex >= enemy[ENEMY_MAX].x - MAP_SIZE * 5) {						//����enemy�̒e��enemy��x���W�𒆐S��3�}�X�𒴂�����A���ł���B
		Attack_Flg = false;
	}

	return Player_Hit_Flg;
}

int Enemy_Attack_Right() {		//�E�ɒe��ł�

	enemy[ENEMY_MAX].ex += 5;

	if (enemy[ENEMY_MAX].ex == player_x && enemy[ENEMY_MAX].ey == player_y) {			//����player�ɓ���������t���O��ON�ɂ��āAPlayer�ɓ����蔻���n��
		Player_Hit_Flg = true;
		Attack_Flg = false;																//����player�e�ƃG�l�~�[�e��������������ł���
	}

	if (enemy[ENEMY_MAX].ex >= enemy[ENEMY_MAX].x + MAP_SIZE * 5) {						//����enemy�̒e��enemy��x���W�𒆐S��3�}�X�𒴂�����A���ł���B
		Attack_Flg = false;
	}

	return Player_Hit_Flg;
}

int Enemy_Attack_Down() {		//���ɒe��ł�

	enemy[ENEMY_MAX].ey -= 5;

	if (enemy[ENEMY_MAX].ex == player_x && enemy[ENEMY_MAX].ey == player_y) {			//����player�ɓ���������t���O��ON�ɂ��āAPlayer�ɓ����蔻���n��
		Player_Hit_Flg = true;
		Attack_Flg = false;																//����player�e�ƃG�l�~�[�e��������������ł���
	}

	if (enemy[ENEMY_MAX].ey >= enemy[ENEMY_MAX].y - MAP_SIZE * 5) {						//����enemy�̒e��enemy��y���W�𒆐S��3�}�X�𒴂�����A���ł���B
		Attack_Flg = false;
	}

	return Player_Hit_Flg;
}

int Enemy_Attack_Up() {			//��ɒe��ł�

	enemy[ENEMY_MAX].ey += 5;

	if (enemy[ENEMY_MAX].ex == player_x && enemy[ENEMY_MAX].ey == player_y) {			//����player�ɓ���������t���O��ON�ɂ��āAPlayer�ɓ����蔻���n��
		Player_Hit_Flg = true;
		Attack_Flg = false;																//����player�e�ƃG�l�~�[�e��������������ł���
	}

	if (enemy[ENEMY_MAX].ey >= enemy[ENEMY_MAX].y + MAP_SIZE * 5) {						//����enemy�̒e��enemy��y���W�𒆐S��3�}�X�𒴂�����A���ł���B
		Attack_Flg = false;
	}

	return Player_Hit_Flg;
}

int Enemy_Draw() {
	//�`�揈��
	
	for (i = 0;i < 4;i++) {
		if (OnActives == true) {																								//����enemy�������Ă���̂Ȃ�
			DrawGraph(enemy[i].x * MAP_SIZE + count_x, enemy[i].y * MAP_SIZE + count_y, EnemyGyallaly[0], true);				//enemy�̕`��

			if (Attack_Flg = true) {																							//�����U����ԂȂ�
				DrawGraph(enemy[i].ex, enemy[i].ey, EnemyShotGyallaly, true);													//�U���̕`��								
			}
		}
	}
	return 0;
}

int Enemy_End() {
	//�I������

	return 0;
}