#pragma once
#include <d3d12.h>
#include <cstdint>
#include <wrl/client.h>


class GpuResource {
private:
    Microsoft::WRL::ComPtr<ID3D12Resource> m_resource;
    D3D12_RESOURCE_STATES                  m_usage_state;
    D3D12_RESOURCE_STATES                  m_transitioning_state;
    D3D12_GPU_VIRTUAL_ADDRESS              m_gpu_virtual_address;

    uint32_t m_version_id = 0;

public:
    GpuResource()
        : m_gpu_virtual_address(D3D12_GPU_VIRTUAL_ADDRESS_NULL),
          m_usage_state(D3D12_RESOURCE_STATE_COMMON),
          m_transitioning_state((D3D12_RESOURCE_STATES)-1) {}

    ~GpuResource() { Destroy(); }

    virtual void Destroy() {
        m_resource = nullptr;
        m_gpu_virtual_address   = D3D12_GPU_VIRTUAL_ADDRESS_NULL;
        ++m_version_id;
    }

    ID3D12Resource*       operator->() { return m_resource.Get(); }
    const ID3D12Resource* operator->() const { return m_resource.Get(); }

    ID3D12Resource*       GetResource() { return m_resource.Get(); }
    const ID3D12Resource* GetResource() const { return m_resource.Get(); }

    D3D12_GPU_VIRTUAL_ADDRESS GetGpuVirtualAddress() const { return m_gpu_virtual_address; }
};