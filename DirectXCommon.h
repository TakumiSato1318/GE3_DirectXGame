#pragma once
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include <vector>
#include<chrono>

#include"WinApp.h"

class DirectXCommon
{
public://メンバ関数
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(WinApp* winApp);

	void PreDraw();

	void PostDraw();

	//デバイス取得
	ID3D12Device* GetDevice() const { return device.Get(); }

	//コマンドリスト取得
	ID3D12GraphicsCommandList* GetCommandList() const { return commandList.Get(); }

private:
	/// <summary>
	/// 
	/// </summary>
	void InitializeDevice();

	/// <summary>
	/// コマンド初期化
	/// </summary>
	void InitilaizeCommand();

	/// <summary>
	/// 
	/// </summary>
	void InitilaizeSwapchain();

	/// <summary>
	/// 
	/// </summary>
	void InitilaizeRenderTargetView();

	/// <summary>
	/// 
	/// </summary>
	void InitializeDepthBuffer();

	/// <summary>
	/// 
	/// </summary>
	
	void InitilaizeFence();

	void InitializeFixFPS();

	void UpdateFPS();

private:
	WinApp* winApp=nullptr;

	//DirectX12デバイス
	Microsoft::WRL::ComPtr<ID3D12Device> device;
	//DXGIファクトリ
	Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;

	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator;
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue;

	Microsoft::WRL::ComPtr<IDXGISwapChain4> swapChain;
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};
	//バックバッファ
	std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> backBuffers;

	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvHeap;

	Microsoft::WRL::ComPtr<ID3D12Resource> depthBuff;
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvHeap;

	Microsoft::WRL::ComPtr<ID3D12Fence> fence;
	UINT64 fenceVal = 0;
	//記録時間(FPS固定用)
	std::chrono::steady_clock::time_point reference_;
};