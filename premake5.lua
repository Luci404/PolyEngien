workspace "PolyEngien"
    architecture "x64"
    configurations { 
        "Debug", 
        "Release", 
        "Dist" 
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

includeDir = {}
includeDir["GLFW"] = "PolyEngien/vendor/GLFW/include"

include "PolyEngien/vendor/GLFW"

project "PolyEngien"
    location "PolyEngien"
    kind "SharedLib"
    language "C++"
   
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "pepch.h"
    pchsource "PolyEngien/src/pepch.cpp"

    files { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp" 
    }

    includedirs {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
        "%{includeDir.GLFW}"
    }

    links {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest" 
        
        defines {
            "PE_PLATFORM_WINDOWS",
            "PE_BUILD_DLL"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/PolyViewer")
        }
    
filter "configurations:Debug"
    defines { "PE_DEBUG" }
    symbols "On"
    defines {
        "PE_ENABLE_ASSERTS"
	}

filter "configurations:Release"
    defines { "PE_RELEASE" }
    optimize "On"

filter "configurations:Dist"
    defines { "PE_DIST" }
    optimize "On"

project "PolyViewer"
    location "PolyViewer"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp" 
    }

    includedirs {
        "PolyEngien/vendor/spdlog/include",
        "PolyEngien/src"
    }

    links {
        "PolyEngien"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest" 
        
        defines {
            "PE_PLATFORM_WINDOWS"
        }
    
filter "configurations:Debug"
    defines { "PE_DEBUG" }
    symbols "On"

filter "configurations:Release"
    defines { "PE_RELEASE" }
    optimize "On"

filter "configurations:Dist"
    defines { "PE_DIST" }
    optimize "On"