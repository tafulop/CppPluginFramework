#pragma once

#include <map>
#include <memory>
#include "Plugin.h"

class PluginStorage
{

private:
	std::map<std::string, HMODULE> m_plugins;
	

public:
	HMODULE get_plugin(std::string name);
	bool register_plugin(std::string name, HMODULE handle);

	PluginStorage();
	~PluginStorage();
};

