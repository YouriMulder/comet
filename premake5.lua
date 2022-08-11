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
	include "Comet/vendor/GLFW"
group ""

include "Comet"