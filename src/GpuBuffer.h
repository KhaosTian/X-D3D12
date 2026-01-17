#pragma once

#include "pch.h"
#include "GpuResource.h"

class GpuBuffer : public GpuResource
{
protected:
    size_t m_buffer_size;
    uint32_t m_element_count;
    uint32_t m_element_size;
    D3D12_RESOURCE_FLAGS m_resource_flags;

    D3D12_CPU_DESCRIPTOR_HANDLE m_uav;
    D3D12_CPU_DESCRIPTOR_HANDLE m_srv;

public:
    virtual ~GpuBuffer() { Destroy(); }

    void Create(const std::wstring& name, uint32_t element_count, uint32_t element_size, const void* initial_data = nullptr);

};