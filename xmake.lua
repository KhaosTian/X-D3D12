set_project("X-D3D12")
set_version("0.1.0")

set_arch("x64")
set_plat("windows")
set_toolchains("msvc")
set_languages("c++14")

add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})
add_rules("plugin.vsxmake.autoupdate")

includes("D3D12/xmake.lua")
includes("Sample/xmake.lua")
