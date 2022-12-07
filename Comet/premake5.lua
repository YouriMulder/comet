project "Comet"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "copch.hpp"
	pchsource "src/copch.cpp"

	files
	{
		"src/**.hpp",
		"src/**.cpp",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLEW}",
	}
	
	links 
	{
		"glew32",
		"opengl32",
		"GLFW",
	}

	libdirs {
		"vendor/GLEW/lib/Release/x64"
	}

	postbuildcommands{}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"COMET_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE",
		}

		filter { "system:windows" }
   			postbuildcommands { "{COPY} vendor/GLEW/bin/Release/x64/glew32.dll $(TargetDir)"}

	filter "configurations:Debug"
		defines "GLCORE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "GLCORE_RELEASE"
		runtime "Release"
		optimize "on"