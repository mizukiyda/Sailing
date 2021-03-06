#pragma once
extern void Scene_Mgr_Init();
extern void Scene_Mgr_Dpct();
extern void Scene_Mgr_Draw();
extern void Scene_Mgr_End();

typedef enum {
	E_Scene_StartMenu,
	E_Scene_Game,
	E_Scene_GameMenu,
	E_Scene_Result,
	E_Scene_None,
}E_Scene;

//引数 NextScene にシーンを変更する
void Scene_Mgr_ChangeScene(E_Scene NextScene);