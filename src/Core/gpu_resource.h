#pragma once

class gpu_resource_c {
private:
    Microsoft::WRL::ComPtr<ID3D12Resource> m_resource;
    D3D12_RESOURCE_STATES                  m_usage_state;
    D3D12_RESOURCE_STATES                  m_transition_state;
    D3D12_GPU_VIRTUAL_ADDRESS              m_gpu_va;

    void* m_user_allocated_memory;

public:
    gpu_resource_c()
        : m_gpu_va(D3D12_GPU_VIRTUAL_ADDRESS_NULL),
          m_usage_state(D3D12_RESOURCE_STATE_COMMON),
          m_transition_state((D3D12_RESOURCE_STATES)-1),
          m_user_allocated_memory(nullptr) {}

    virtual void destroy() {
        m_resource = nullptr;
        m_gpu_va   = D3D12_GPU_VIRTUAL_ADDRESS_NULL;
    }

    ID3D12Resource*       operator->() { return m_resource.Get(); }
    const ID3D12Resource* operator->() const { return m_resource.Get(); }

    ID3D12Resource*       get_resource() { return m_resource.Get(); }
    const ID3D12Resource* get_resource() const { return m_resource.Get(); }

    D3D12_GPU_VIRTUAL_ADDRESS get_gpu_va() const { return m_gpu_va; }
};