workspace "PolyEngien"
    architecture "x64"
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
IncludeDir["ImGui"] = "PolyEngien/vendor/ImGui"
IncludeDir["glm"] = "PolyEngien/vendor/glm"

group "Dependencies"
    include "PolyEngien/vendor/GLFW"
    include "PolyEngien/vendor/Glad"
    include "PolyEngien/vendor/ImGui"
group ""



project "PolyEngien"
    location "PolyEngien"
    kind "SharedLib"
    language "C++"
    staticruntime "off"
   
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "pepch.h"
    pchsource "PolyEngien/src/pepch.cpp"

    files { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
    }

    includedirs {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}"
    }

    links {
        "GLFW",
        "GLAD",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
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
       	runtime "Debug"

    filter "configurations:Release"
        defines { "PE_RELEASE" }
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines { "PE_DIST" }
        runtime "Release"
        optimize "On"



project "PolyViewer"
    location "PolyViewer"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp" 
    }

    includedirs {
        "PolyEngien/vendor/spdlog/include",
        "PolyEngien/src",
        "%{IncludeDir.glm}"
    }

    links {
        "PolyEngien"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest" 
        
        defines {
            "PE_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines { "PE_DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "PE_RELEASE" }
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines { "PE_DIST" }
        runtime "Release"
        optimize "On"