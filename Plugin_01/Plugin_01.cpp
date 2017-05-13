// Plugin_01.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Plugin_01.h"
#include "PluginLogic.h"

// This is an example of an exported function.
 std::string get_name(void)
{
    return std::string("Plugin 02 is my name, let us play my game!");
}

Plugin* create_plugin() {
	return new PluginLogic();
}
