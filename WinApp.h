#pragma once
#include <Windows.h>

//WindowsAPI
class WinApp
{
public: //静的メンバ関数
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public: //メンバ関数
	//初期化
	void Initialize();

	//メッセージ処理
	bool ProcessMessage();
	
	//getter
	HWND GetHwnd() const { return hwnd; }
	HINSTANCE GetHInstance() const { return w.hInstance; }
	//終了
	void Finalize();

public: //定数
	//ウィンドウ横幅
	static const int window_width = 1280;
	//ウィンドウ立幅
	static const int window_height = 720;
	
private:
	//ウィンドウハンドル
	HWND hwnd = nullptr;
	// ウィンドウクラスの設定
	WNDCLASSEX w{};
};