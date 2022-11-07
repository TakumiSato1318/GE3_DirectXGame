#include"Input.h"
#include<cassert>
//#include<wrl.h>
//using namespace Microsoft::WRL;

//#define DIRECTINPUT_VERSION 0x0800 //バージョン指定
//#include<dinput.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")




void Input::Initialaize(WinApp* winApp) {

    HRESULT result;
    //借りてきたwinAppのインスタンスを記録
    this->winApp = winApp;

    //DirectXUnputのインスタンス生成
    ComPtr<IDirectInput8> directInput = nullptr;
    result = DirectInput8Create(
       this->winApp->GetHInstance(), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
    assert(SUCCEEDED(result));
    // キーボードデバイスの生成
    //ComPtr<IDirectInputDevice8> keyboard;
    result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
    // 入力データ形式のセット
    result = keyboard->SetDataFormat(&c_dfDIKeyboard); // 標準形式
    assert(SUCCEEDED(result));
    // 排他制御レベルのセット
    result = keyboard->SetCooperativeLevel(
        this->winApp->GetHwnd(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
    assert(SUCCEEDED(result));
}

void Input::Update() {

    HRESULT result;

    //前回のキー入力を保存
    memcpy(keyPre, key, sizeof(key));

    // キーボード情報の取得開始
    keyboard->Acquire();
    // 全キーの入力状態を取得する
    keyboard->GetDeviceState(sizeof(key), key);

}

bool Input::PushKey(BYTE keyNumber) {

    //指定キーを押していればtrueを返す
    if (key[keyNumber]) {
        return true;
    }
    return false;
}

bool Input::TriggerKey(BYTE keyNumber)
{
    if (!keyPre[keyNumber]&&key[keyNumber]) {
        return true;
    }
    return false;
}
