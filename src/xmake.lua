-- Core library target (src/Core)
target("X-D3D12")
    set_kind("static")
    add_files("**.cpp")
    add_headerfiles("**.h")
    set_pcxxheader("pch.h")
    add_includedirs(".", {public = true})
    add_syslinks("user32", "gdi32", {public = true})
    add_defines("_WINDOWS", "UNICODE")

    if is_mode("debug") then
        add_defines("_DEBUG")
    elseif is_mode("release") then
        add_defines("NDEBUG")
    end

target_end()