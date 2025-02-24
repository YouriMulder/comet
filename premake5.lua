include "dependencies.lua"

workspace "Comet"
	architecture "x64"
	startproject "Comet"

	configurations
	{
		"Debug",
		"Release"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "comet/lib/glfw"
group ""

group "core"
	include "comet"
group ""