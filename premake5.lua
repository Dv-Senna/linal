workspace "NickelLib"
	configurations {"debug", "release"}


-- project "lib"
-- 	kind "StaticLib"
-- 	language "C++"
-- 	cppdialect "c++20"
-- 	targetdir "lib/bin"
-- 	objdir "lib/obj"
-- 	targetname "linal"
-- 	warnings "Extra"

-- 	defines {"LINAL_BUILD_LIB"}

-- 	files {
-- 		"lib/src/**.cpp",
-- 		"lib/include/**.hpp",
-- 		"lib/include/**.inl"
-- 	}

-- 	includedirs {
-- 		"lib/include/linal",
-- 		"vendors/SDL2/include"
-- 	}

-- 	filter "configurations:debug"
-- 		defines {"DEBUG", "LINAL_DEBUG"}
-- 		symbols "On"

-- 	filter "configurations:release"
-- 		defines {"NDEBUG", "LINAL_NO_DEBUG", "LINAL_RELEASE"}
-- 		optimize "On"

-- 	filter "system:Windows"
-- 		defines {"LINAL_PLATEFORM_WINDOWS"}

-- 	filter "system:Unix"
-- 		defines {"LINAL_PLATEFORM_UNIX"}

-- 	filter "system:Mac"
-- 		defines {"LINAL_PLATEFORM_MACOS"}


project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "c++20"
	targetdir "sandbox/bin"
	objdir "sandbox/obj"
	targetname "sandbox"
	warnings "Extra"

	files {
		"sandbox/src/**.cpp",
		"sandbox/include/**.hpp",
		"sandbox/include/**.inl"
	}

	includedirs {
		"sandbox/include",
		"lib/include",
	}

	-- libdirs {
	-- 	"lib/bin",
	-- }

	-- links {
	-- 	"linal",
	-- }


	filter {"system:Windows", "toolset:gcc"}
		links "mingw32"

	filter "configurations:debug"
		defines {"DEBUG", "PL_DEBUG"}
		symbols "On"

	filter "configurations:release"
		defines {"NDEBUG", "LINAL_NO_DEBUG", "LINAL_RELEASE"}
		optimize "On"

	filter "system:Windows"
		defines {"LINAL_PLATEFORM_WINDOWS"}

	filter "system:Unix"
		defines {"LINAL_PLATEFORM_UNIX"}

	filter "system:Mac"
		defines {"LINAL_PLATEFORM_MACOS"}




