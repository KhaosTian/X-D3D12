set_project("laurel-dx12")
set_version("0.1.0")

set_languages("c++20")

add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})
add_rules("plugin.vsxmake.autoupdate", {vs = "2022"})

includes("src/xmake.lua")
includes("sandbox/xmake.lua")
