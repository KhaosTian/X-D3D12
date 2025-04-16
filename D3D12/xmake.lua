target("D3D12")
    set_kind("static")

    add_files("./**.cpp")
    add_headerfiles("./**.h")

    set_pcxxheader("./Core/pch.h")
    
    add_includedirs(".")
    add_includedirs("./Core")

    set_runtimes("MD")

    add_defines("_WINDOWS", "UNICODE")
    add_syslinks("user32", "gdi32" , "d3d12", "dxgi", "dxguid", "d3dcompiler")

    if is_mode("debug") then
        add_defines("_DEBUG")
        add_syslinks("msvcrtd", "ucrtd", "vcruntimed" )
    end

    if is_mode("release") then
        add_defines("NDEBUG")
        add_syslinks("msvcrt", "ucrt", "vcruntime" )
    end
target_end()