#pragma once
#include<windows.h>
#include<wrl.h>

#define DIRECTINPUT_VERSION 0x0800 //�o�[�W�����w��
#include<dinput.h>

//����
class Input{
public:
	//namespace�ȗ�
	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

public: //�����o�֐�
	//������
	void Initialaize(HINSTANCE hInstance,HWND hwnd);
	//�X�V
	void Update();
	//
	bool PushKey(BYTE keyNumber);

private: //�����o�ϐ�
	//�L�[�{�[�h�̃f�o�C�X
	ComPtr<IDirectInputDevice8> keyboard;
	//�S�L�[�̏��
	BYTE key[256] = {};

};