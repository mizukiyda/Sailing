#include"DxLib.h"
#include"Keyboard.h"

static int Key_State[256];	//キーボードの状態

void Keyboard_Update() {
	char tmpKey[256];			//現在のキー入力を受け取る
	GetHitKeyStateAll(tmpKey);	//全てのキー入力をtmpKeyに格納。

	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) {	//キーが押されると、i番のtmpKeyに格納されるため、0にならない。
			Key_State[i]++;
		}
		else {					//押されてない状態なら、0に戻す。
			Key_State[i] = 0;
		}
	}
}

//
int Keyboard_Get(int KeyCode) {
	return Key_State[KeyCode];
}