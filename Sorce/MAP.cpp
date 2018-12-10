// �}�b�v�\����{
#include "DxLib.h"
#include "MAP.h"
#include "Player.h"
#include "Scene_Mgr.h"



int FileHandle, y;
static int i = 0, j = 0;
char buf[256];
char c1, c2;				    //MAP��Player,Enemy�Ɏg��char
int MAP[MAP_HEIGHT][MAP_WIDTH]; //�}�b�v
int px, py;				    	//�󂯎��v���C���[�̕ϐ�
int Enemy_Count;				    //�󂯎��Enemy�̕ϐ�;
static int Enemy_Pos_x[10];		//�󂯎��Enemy��x���W�ϐ�
static int Enemy_Pos_y[10];		//�󂯎��Enemy��y���W�ϐ�
int lflag;

int Image_Wall  = 0;
int Image_Load  = 0;
int Image_Goal  = 0;

char MAPHandle[256];
int Handleflag = 1;


//10��define��const�Œ�`���ׂ�
//�ނ���\���̂����ʂ��ׂ�


//�v���C���[�̏���x���W���󂯎��
int MAP_Player_Pos_Init_x(){

	return px;		//�����������v���C���[��x���W��߂�
}

//�v���C���[�̏���y���W���󂯎��
int MAP_Player_Pos_Init_y() {

	return py;		//�����������v���C���[��y���W��߂�
}

//MAP�̍��W
int MAP_Data(int x, int y) {

	return MAP[y][x];
}

//Enemy�̌����󂯎��
int MAP_Enemy_Count_Init() {

	return Enemy_Count;
}

//Enemy�̏���X���W
int MAP_Enemy_Pos_Init_x(int num) {

	return Enemy_Pos_x[num];
}

//Enemy�̏���Y���W
int MAP_Enemy_Pos_Init_y(int num) {

	return Enemy_Pos_y[num];
}

//������
int MAP_Init() {
	memset(MAP, -1, sizeof(MAP));
//	px = px;			//�󂯎�����v���C���[��x���W��������
//	py = py;			//�󂯎�����v���C���[��y���W��������
	Enemy_Count = 1;	//�󂯎����Enemy�̐��̏�����
//	Enemy_Pos_x = 5;	//�󂯎����Enemy��x���W�̏�����
//	Enemy_Pos_y = 5;	//�󂯎����Enemy��y���W�̏�����
	i = 0; j = 0;

	//�摜�̓ǂݍ���
	//ImageWall = LoadGraph("");
	//ImageLoad = LoadGraph("");
	//ImageGoal = LoadGraph("");

	strcpy(MAPHandle, "resource/MAP/MAP_");
	

	char Handletmp[256];

	char flagtmp[256];
	sprintf(flagtmp, "%d", Handleflag);



	/*
	char flagtmp[64];	//�ˊ� ���v�P�O�i�X�j�}�b�v�܂�
	flagtmp[0] = Handleflag + '0';
	flagtmp[1] = NULL;
	*/
	strcpy(Handletmp, MAPHandle);

	strcat(Handletmp, flagtmp);

	strcat(Handletmp, ".csv");

	// MAP�̓ǂݍ���
	FileHandle = FileRead_open( Handletmp );	// ��s�ǂݍ���
													// �t�@�C���̏I�[������܂ŕ\������
	if (FileHandle == 0) {

//		WaitKey();
		Scene_Mgr_ChangeScene(E_Scene_StartMenu);
		return -1;

	}

	while (FileRead_eof(FileHandle) == 0) {			// ��s�ǂݍ���

		//c1 = MAP��char
		c1 = FileRead_getc(FileHandle);		//1�����ǂݍ���
		if ('0' <= c1 && c1 <= '9') {		//����0�`9��������
			MAP[i][j] = c1 - '0';				//MAP�ɑ��
		}
		else if (c1 == ',') {				//����","��ǂݍ��񂾂�
			j++;							//�E�̐�����ǂݍ���
		}
		else if (c1 == '\n') {					//����"\n"��ǂݍ��񂾂�
			j = 0;							//�E�ɍs���̂���߂�
			i++;							//���̍s�ɍs��
		}
	}

	// �t�@�C�������
	FileRead_close(FileHandle);

	strcpy(Handletmp, MAPHandle);

	strcat(Handletmp, flagtmp);

	strcat(Handletmp, ".txt");


	
	// Player�̍��W�ǂݍ���
	FileHandle = FileRead_open( Handletmp );	//1�s�ǂݍ���
													// �t�@�C���̏I�[������܂ŕ\������
	if (FileHandle == 0) {

//		WaitKey();
		Scene_Mgr_ChangeScene(E_Scene_StartMenu);
		return -1;

	}

	//c2 = Player��Enemy��char
	
	c2 = FileRead_getc(FileHandle);		//1�����ǂݍ���	
	px = c2 - '0';				    //Player��X���W�ɑ��
	
	FileRead_getc(FileHandle);

	c2 = FileRead_getc(FileHandle);						//�E�̐�����ǂݍ���
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
	
	
	// �t�@�C�������
	FileRead_close(FileHandle);

	return 0;

}



//�v�Z
int MAP_Dpct() {
	//Dpct�͖��t���[���Ă΂��

	return 0;
}


//�`��
int MAP_Draw() {
	//�����������t���[���Ă΂�邪�v�Z�Ƃ͕ʂɏ����܂�

	// �}�b�v��`��
	for (i = 0; i < MAP_HEIGHT; i++)
	{
		for (j = 0; j < MAP_WIDTH; j++)
		{

			/*
			typedef enum
{
	E_Object_Wall,      //�s���Ȃ��ꏊ
	E_Object_Load,      //������ꏊ
	E_Object_Goal,      //�S�[��
}E_Object;
			������*/




			if (MAP[i][j] == E_Object_Wall)	// �v���C���[�w�b�_�[��
			{
				//DrawEnemy(j * MAP_SIZE, i * MAP_SIZE,j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE,GetColor(0, 230, 0), TRUE);

				DrawGraph(j * MAP_SIZE, i * MAP_SIZE, Image_Wall, TRUE);

			}
			if (MAP[i][j] == E_Object_Load)
			{
				//DrawEnemy(j * MAP_SIZE, i * MAP_SIZE,j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE,GetColor(122, 255, 122), TRUE);
			
				DrawGraph(j * MAP_SIZE, i * MAP_SIZE, Image_Load, TRUE);
				
			}
			if (MAP[i][j] == E_Object_Goal)
			{
				//DrawEnemy(j * MAP_SIZE, i * MAP_SIZE,j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE,GetColor(122, 122, 255), TRUE);

				DrawGraph(j * MAP_SIZE, i * MAP_SIZE, Image_Goal, TRUE);
			}
		}
	}
	DrawFormatString(100, 200, GetColor(255, 0, 0), "MAP Draw�����Ă���");
	return 0;
}


void MAP_SetHandleflag(int num) {
	Handleflag = num;
}

int MAP_GetHandleflag() {
	return Handleflag;
}

//�I��
int MAP_End() {
	DeleteGraph(Image_Wall);
	DeleteGraph(Image_Load);
	DeleteGraph(Image_Goal);

	return 0;
}