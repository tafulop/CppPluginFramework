#include <stdio.h>
#include "..\PluginFramework\PluginManager.h"
#include <Windows.h>
#include <iostream>


int main(int argc, char* argv[])
{
	PluginManager& manager = PluginManager::get_instance();
	manager.load_plugins();

	plugin_get_name_funct caller;

	HMODULE handle = manager.get_plugin("Plugin_01.dll");

	if (handle) {

		caller = (plugin_get_name_funct)GetProcAddress(handle, "get_name");

		if (NULL != caller)
		{
			std::cout << caller();
		}
	}
	else
	{
		std::cout << "can not find plugin" << std::endl;
	}

	return 0;
}