set_project("X-D3D12")
set_version("0.1.0")

set_languages("c++20")

add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})
add_rules("plugin.vsxmake.autoupdate", {vs = "2022"})

target("D3D12")
    set_kind("binary")
    add_files("src/**.cpp")
    add_headerfiles("src/**.h")
    set_pcxxheader("src/Core/pch.h", {force = true})
    add_includedirs("src")
    add_defines("_WINDOWS", "UNICODE")

    if is_mode("debug") then
        add_defines("_DEBUG")
    elseif is_mode("release") then
        add_defines("NDEBUG")
    end

    add_syslinks("user32", "gdi32", "d3d12", "dxgi", "dxguid", "d3dcompiler")
target_end()
