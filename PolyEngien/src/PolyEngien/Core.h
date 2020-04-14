#pragma once

#ifdef PE_PLATFORM_WINDOWS
	#ifdef PE_BUILD_DLL
		#define POLYENGIEN_API __declspec(dllexport) 
	#else	
		#define POLYENGIEN_API __declspec(dllimport) 
	#endif
#else
	#error Poly engien only supports Windows!
#endif

#define BIT(x) (1 << x)