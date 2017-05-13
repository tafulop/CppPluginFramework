#include "PluginManager.h"
#include <iostream>

PluginManager& PluginManager::get_instance()
{
	static PluginManager& instance = PluginManager();
	return instance;
}

void PluginManager::test()
{
	std::cout << "PluginManager::test()" << std::endl;
}


void PluginManager::load_plugins() {

	for (auto it = dll_names.begin(); it != dll_names.end(); ++it) {

		std::wstring temp(it->begin(), it->end());
		HMODULE handle = LoadLibrary(temp.c_str());

		if (handle != nullptr) {
			std::cout << *it << " loaded." << std::endl;
			m_storage.register_plugin(*it, handle);
		}
		else {
			std::cout << it->c_str() << " can not be loaded." << std::endl;
		}

		handle = nullptr;
	}
}

PluginManager::PluginManager() : m_storage(PluginStorage())
{
	dll_names.push_back("Plugin_01.dll");
	dll_names.push_back("Plugin_02.dll");
	dll_names.push_back("Plugin_03.dll");
}


PluginManager::~PluginManager()
{
	
}
