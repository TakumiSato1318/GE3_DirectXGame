#pragma once
#include<windows.h>
#include<wrl.h>

#define DIRECTINPUT_VERSION 0x0800 //�o�[�W�����w��
#include<dinput.h>

#include "WinApp.h"

//����
class Input{
public:
	//namespace�ȗ�
	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

public: //�����o�֐�
	//������
	void Initialaize(WinApp* winApp);
	//�X�V
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

private: //�����o�ϐ�
	//�L�[�{�[�h�̃f�o�C�X
	ComPtr<IDirectInputDevice8> keyboard;
	//�S�L�[�̏��
	BYTE key[256] = {};
	//�O��̑S�L�[�̏��
	BYTE keyPre[256] = {};
	//WindowAPI
	WinApp* winApp = nullptr;

};