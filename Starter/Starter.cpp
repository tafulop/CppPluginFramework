#include <stdio.h>
#include "..\PluginFramework\PluginManager.h"
#include <Windows.h>
#include <iostream>


int main(int argc, char* argv[])
{
	PluginManager& manager = PluginManager::get_instance();
	manager.load_plugins();

	plugin_get_name_funct caller;

	HMODULE handle_1 = manager.get_plugin("Plugin_01.dll");

	if (handle_1) {

		caller = (plugin_get_name_funct)GetProcAddress(handle_1, "get_name");

		if (NULL != caller)
		{
			std::cout << caller() << std::endl;
		}
	}
	else
	{
		std::cout << "can not find plugin" << std::endl;
	}



	HMODULE handle_2 = manager.get_plugin("Plugin_02.dll");

	if (handle_2) {

		caller = (plugin_get_name_funct)GetProcAddress(handle_2, "get_name");

		if (NULL != caller)
		{
			std::cout << caller() << std::endl;;
		}
	}
	else
	{
		std::cout << "can not find plugin" << std::endl;
	}

	return 0;
}