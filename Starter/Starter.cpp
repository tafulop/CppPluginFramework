#include <stdio.h>
#include "..\PluginFramework\PluginManager.h"
#include <Windows.h>
#include <iostream>
#include <typeinfo>  //for 'typeid' to work  
#include "..\Plugin_01\PluginLogic.h"


int main(int argc, char* argv[])
{
	PluginManager& manager = PluginManager::get_instance();
	manager.load_plugins();

	plugin_get_name_funct caller;


	// PLUGIN 01 normal function call
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


	// PLUGIN 02 normal function call
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

	// PLUGIN 03 class member function call
	HMODULE handle_3 = manager.get_plugin("Plugin_03.dll");
	
	typedef Plugin* (_stdcall *construct_plugin)();

	construct_plugin plugin_call;

	if (handle_3) {

		plugin_call = (construct_plugin)GetProcAddress(handle_3, "create_plugin");

		if (NULL != caller)
		{
			Plugin* plg_ptr = plugin_call();

			std::cout << plg_ptr->get_name();

			PluginLogic* plg_logic = dynamic_cast<PluginLogic*>(plg_ptr);
			if (plg_logic) {
				plg_logic->custom_mfunct();
				std::cout << "sadfsad";
			}
		}
	}
	else
	{
		std::cout << "can not find plugin" << std::endl;
	}

	return 0;
}