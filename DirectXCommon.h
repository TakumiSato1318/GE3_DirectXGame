#pragma once
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include <vector>
#include<chrono>

#include"WinApp.h"

class DirectXCommon
{
public://�����o�֐�
	/// <summary>
	/// ������
	/// </summary>
	void Initialize(WinApp* winApp);

	void PreDraw();

	void PostDraw();

	//�f�o�C�X�擾
	ID3D12Device* GetDevice() const { return device.Get(); }

	//�R�}���h���X�g�擾
	ID3D12GraphicsCommandList* GetCommandList() const { return commandList.Get(); }

private:
	/// <summary>
	/// 
	/// </summary>
	void InitializeDevice();

	/// <summary>
	/// �R�}���h������
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

	//DirectX12�f�o�C�X
	Microsoft::WRL::ComPtr<ID3D12Device> device;
	//DXGI�t�@�N�g��
	Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;

	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator;
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue;

	Microsoft::WRL::ComPtr<IDXGISwapChain4> swapChain;
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};
	//�o�b�N�o�b�t�@
	std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> backBuffers;

	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvHeap;

	Microsoft::WRL::ComPtr<ID3D12Resource> depthBuff;
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvHeap;

	Microsoft::WRL::ComPtr<ID3D12Fence> fence;
	UINT64 fenceVal = 0;
	//�L�^����(FPS�Œ�p)
	std::chrono::steady_clock::time_point reference_;
};