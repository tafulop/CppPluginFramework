#pragma once
#include "Plugin.h"
#include <vector>
#include <Windows.h>
#include "PluginStorage.h"

class PluginManager
{
public:
	static PluginManager& get_instance();

	HMODULE get_plugin(std::string name) {
		return m_storage.get_plugin(name);
	}

	void load_plugins();

	void test();

private:

	std::vector<std::string> dll_names;
	
	PluginStorage m_storage;


	PluginManager();
	~PluginManager();
};

