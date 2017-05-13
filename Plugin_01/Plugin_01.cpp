// Plugin_01.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Plugin_01.h"

// This is an example of an exported function.
PLUGIN_01_API std::string get_name(void)
{
    return std::string("Plugin 01 is my name");
}
