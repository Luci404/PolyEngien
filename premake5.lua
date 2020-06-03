workspace "PolyEngien"
    architecture "x86_64"
    startproject "PolyViewer"
    configurations { 
        "Debug", 
        "Release", 
        "Dist" 
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "PolyEngien/vendor/GLFW/include"
IncludeDir["Glad"] = "PolyEngien/vendor/Glad/include"
IncludeDir["ImGui"] = "PolyEngien/vendor/imgui"
IncludeDir["glm"] = "PolyEngien/vendor/glm"
IncludeDir["stb_image"] = "PolyEngien/vendor/stb_image"

group "Dependencies"
    include "PolyEngien/vendor/GLFW"
    include "PolyEngien/vendor/Glad"
    include "PolyEngien/vendor/imgui"
group ""



project "PolyEngien"
    location "PolyEngien"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "pepch.h"
    pchsource "PolyEngien/src/pepch.cpp"

    files { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
    }

    defines {
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.stb_image}"
    }

    links {
        "GLFW",
        "GLAD",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest" 
        
        defines {
            "PE_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }
    
    filter "configurations:Debug"
        defines { "PE_DEBUG" }
        symbols "on"
       	runtime "Debug"

    filter "configurations:Release"
        defines { "PE_RELEASE" }
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines { "PE_DIST" }
        runtime "Release"
        optimize "on"



project "PolyViewer"
    location "PolyViewer"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp" 
    }

    includedirs {
        "PolyEngien/vendor/spdlog/include",
        "PolyEngien/src",
        "PolyEngien/vendor",
        "%{IncludeDir.glm}"
    }

    links {
        "PolyEngien"
    }

    filter "system:windows"
        systemversion "latest" 
        
        defines {
            "PE_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines { "PE_DEBUG" }
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines { "PE_RELEASE" }
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines { "PE_DIST" }
        runtime "Release"
        optimize "on"