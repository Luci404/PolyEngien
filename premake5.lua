workspace "PolyEngien"
    architecture "x64"
    startproject "PolyViewer"
    configurations { 
        "Debug", 
        "Release", 
        "Dist" 
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

includeDir = {}
includeDir["GLFW"] = "PolyEngien/vendor/GLFW/include"
includeDir["Glad"] = "PolyEngien/vendor/Glad/include"
includeDir["ImGui"] = "PolyEngien/vendor/ImGui"

group "Dependencies"
    include "PolyEngien/vendor/GLFW"
    include "PolyEngien/vendor/Glad"
    include "PolyEngien/vendor/ImGui"
group ""

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
        "%{includeDir.GLFW}",
        "%{includeDir.Glad}",
        "%{includeDir.ImGui}"
    }

    links {
        "GLFW",
        "GLAD",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest" 
        
        defines {
            "PE_PLATFORM_WINDOWS",
            "PE_BUILD_DLL",
            "GLFW_INCLUDE_NONE",
            "IMGUI_IMPL_OPENGL_LOADER_GLAD"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/PolyViewer/\"")
        }
    
filter "configurations:Debug"
    defines { "PE_DEBUG" }
    symbols "On"
    buildoptions "/MDd"
    defines {
        "PE_ENABLE_ASSERTS"
	}

filter "configurations:Release"
    defines { "PE_RELEASE" }
    buildoptions "/MD"
    optimize "On"

filter "configurations:Dist"
    defines { "PE_DIST" }
    buildoptions "/MD"
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
    buildoptions "/MDd"
    symbols "On"

filter "configurations:Release"
    defines { "PE_RELEASE" }
    buildoptions "/MD"
    optimize "On"

filter "configurations:Dist"
    defines { "PE_DIST" }
    buildoptions "/MD"
    optimize "On"