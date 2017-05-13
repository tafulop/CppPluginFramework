#pragma once
#include <string>
#include <Windows.h>
#include <iostream>

typedef std::string(WINAPI *plugin_get_name_funct)(void);

class Plugin 
{
	
public:
	virtual std::string get_name() = 0;

};