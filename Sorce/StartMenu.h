#pragma once

typedef struct {	//�\����
	int x, y, num;  //���W�̕ϐ�
	char name[256];     //���ږ��̕ϐ�
} MenuElement_t;

// �摜�̍\����
typedef struct {
	// ����:�I��łȂ����@�@On_: �I��ł��鎞
	int Start;
	int On_Start;
	int End;
	int On_End;
	int MAP;
	int On_MAP;
	int Back;
	int On_Back;
	int Number[10];
	int On_Number[10];

} Image_t;

extern int StartMenu_Init();
extern int StartMenu_Dpct();
extern int StartMenu_Draw();
extern int StartMenu_End();