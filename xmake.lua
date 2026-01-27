set_project("laurel-d3d12")
set_version("0.1.0")

set_languages("c++20")

add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = "build"})
add_rules("plugin.vsxmake.autoupdate", {vs = "2026"})

includes("src/core/xmake.lua")
includes("src/sandbox/xmake.lua")