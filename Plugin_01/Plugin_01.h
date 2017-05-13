// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the PLUGIN_01_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// PLUGIN_01_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef PLUGIN_01_EXPORTS
#define PLUGIN_01_API __declspec(dllexport)
#else
#define PLUGIN_01_API __declspec(dllimport)
#endif

#include <iostream>

extern "C" PLUGIN_01_API std::string get_name(void);
