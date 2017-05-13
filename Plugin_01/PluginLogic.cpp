#include "PluginLogic.h"



PluginLogic::PluginLogic()
{
}


PluginLogic::~PluginLogic()
{
}

std::string PluginLogic::get_name() {
	std::cout << "PluginLogic::get_name()" << std::endl;
	return "my fance name";
}

void PluginLogic::custom_mfunct() {
	std::cout << "PluginLogic::custom_mfunct()" << std::endl;
}

