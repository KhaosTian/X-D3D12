#include "Utility.h"
#include "pch.h"
#include "GameCore.h"
#include "GraphicsCore.h"

using namespace Math;

namespace Graphics {
void Graphics::Initialize() {
    Microsoft::WRL::ComPtr<ID3D12Device> pDevice;

    uint32_t useDebugLayer = 0;
#if _DEBUG
    useDebugLayer = 1;
#endif

    if (useDebugLayer) {
        Microsoft::WRL::ComPtr<ID3D12Debug> debugInterface;

        if (SUCCEEDED(D3D12GetDebugInterface(MY_IID_PPV_ARGS(&debugInterface)))) {
            debugInterface->EnableDebugLayer();
        } else {
            Utility::Print("WARNING: Failed to enable d3d12 debug validation layer.");
        }
    }
}
} // namespace Graphics