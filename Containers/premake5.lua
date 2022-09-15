workspace "Containers"
    configurations { "Debug" }

project "Containers"
    kind "ConsoleApp"
    language "C++"
    targetdir "build/%{cfg.buildcfg}"

    files{"Source/**"}