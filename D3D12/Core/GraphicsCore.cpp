#include "pch.h"
#include <combaseapi.h>
#include <d3d12.h>
#include <intsafe.h>
#include <wrl/client.h>
#include "GraphicsCore.h"

#pragma comment(lib, "d3d12.lib")

using namespace Math;

namespace Graphics {
void Graphics::Initialize() {
    ComPtr<ID3D12Device> pDevice;

    uint32_t useDebugLayer = 0;
#if _DEBUG
    useDebugLayer = 1;
#endif

    if (useDebugLayer) {
        ComPtr<ID3D12Debug> debugInterface;

        if (SUCCEEDED(D3D12GetDebugInterface(MY_IID_PPV_ARGS(&debugInterface)))) {}
    }
}
} // namespace Graphics