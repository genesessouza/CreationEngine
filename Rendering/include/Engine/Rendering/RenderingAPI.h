#pragma once

#ifdef _WIN32
	#ifdef RENDERING_BUILD_DLL
		#define RENDERING_API __declspec(dllexport)
	#else
		#define RENDERING_API __declspec(dllimport)
	#endif
#else
	#define RENDERING_API
#endif