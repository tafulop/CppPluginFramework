#include "PluginStorage.h"

PluginStorage::PluginStorage()
{
}


PluginStorage::~PluginStorage()
{
	for (auto it = m_plugins.begin(); it != m_plugins.end(); ++it) {
		if (FreeLibrary(it->second)) {
			std::cout << "Plugin unloaded: " << it->first.c_str() << std::endl;
		}
		else {
			std::cout << "Plugin unload FAILED: " << it->first.c_str() << std::endl;
		}
	}

}


bool PluginStorage::register_plugin(std::string name, HMODULE handle) {
	
	auto it = m_plugins.find(name);

	if (it == m_plugins.end()) {
		m_plugins.emplace(name, handle);
		return true;
	}

	return false;
}


HMODULE PluginStorage::get_plugin(std::string name) {
	auto it = m_plugins.find(name);
	return (it != m_plugins.end()) ? it->second : nullptr;
}