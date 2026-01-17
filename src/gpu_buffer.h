#pragma once

#include "pch.h"
#include "gpu_resource.h"

class gpu_buffer_c : public gpu_resource_c
{
protected:
    size_t m_buffer_size;
    uint32_t m_ele_count;
    uint32_t m_ele_size;
    D3D12_RESOURCE_FLAGS m_resource_flags;

    D3D12_CPU_DESCRIPTOR_HANDLE m_uav;
    D3D12_CPU_DESCRIPTOR_HANDLE m_srv;

public:
    virtual ~gpu_buffer_c() { destroy(); }

    void create(const std::wstring& name, uint32_t ele_nums, uint32_t ele_size, const void* init_data = nullptr);

};