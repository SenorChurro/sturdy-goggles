#include "Graphics.h"
// this tells our compiler to link the d3d11 library for us 
// so that we dont have to do it in the linker 
#pragma comment(lib,"d3d11.lib")
Graphics::Graphics(HWND hWnd)
{
	DXGI_SWAP_CHAIN_DESC sd = {};
	sd.BufferDesc.Width = 0;
	sd.BufferDesc.Height = 0;
	sd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 0;
	sd.BufferDesc.RefreshRate.Denominator = 0;
	sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.BufferCount = 1;
	sd.OutputWindow = hWnd;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	sd.Flags = 0;

	D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		0,
		nullptr,
		0,
		D3D11_SDK_VERSION,
		&sd,
		&pSwap,
		&pDevice,
		nullptr,
		&pContext
	);
	// get the back buffer
	ID3D11Resource* pBackBuffer = nullptr;
	//0 indicates that we want the back buffer
	pSwap->GetBuffer(0, __uuidof(ID3D11Resource), reinterpret_cast<void**>( &pBackBuffer));
	pDevice->CreateRenderTargetView(
		pBackBuffer,
		nullptr,
		&pTarget
	);

	//no longer need the buffer after rendering
	pBackBuffer->Release();
}

Graphics::~Graphics()
{
	if (pTarget != nullptr) {
		pTarget->Release();
	}
	if (pContext != nullptr) {
		pContext->Release();
	}

	if (pSwap != nullptr) {
		pSwap->Release();
	}

	if (pDevice != nullptr) {
		pDevice->Release();
	}
}

void Graphics::EndFrame()
{
	// aiming for 60 fps
	pSwap->Present(1u, 0u);
}
