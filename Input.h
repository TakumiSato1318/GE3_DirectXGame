#pragma once
#include<windows.h>
#include<wrl.h>

#define DIRECTINPUT_VERSION 0x0800 //バージョン指定
#include<dinput.h>

//入力
class Input{
public:
	//namespace省略
	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

public: //メンバ関数
	//初期化
	void Initialaize(HINSTANCE hInstance,HWND hwnd);
	//更新
	void Update();
	/// <summary>
	/// 
	/// </summary>
	/// <param name="keyNumber"></param>
	/// <returns></returns>
	bool PushKey(BYTE keyNumber);
	/// <summary>
	/// 
	/// </summary>
	bool TriggerKey(BYTE keyNumber);

private: //メンバ変数
	//キーボードのデバイス
	ComPtr<IDirectInputDevice8> keyboard;
	//全キーの状態
	BYTE key[256] = {};
	//前回の全キーの状態
	BYTE keyPre[256] = {};

};