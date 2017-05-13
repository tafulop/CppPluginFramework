#pragma once

#include "..\PluginFramework\Plugin.h"

extern "C" class PluginLogic : public Plugin
{
public:
	virtual std::string get_name();

	PluginLogic();
	 ~PluginLogic();
};

