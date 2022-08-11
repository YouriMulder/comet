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
		"%{IncludeDir.GLEW}"
	}

	libdirs 
	{
		"vendor/GLEW/lib/Release/x64"
	}
	links 
	{
		"GLFW",
		"GLEW32",
		"opengl32"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"COMET_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "GLCORE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "GLCORE_RELEASE"
		runtime "Release"
		optimize "on"