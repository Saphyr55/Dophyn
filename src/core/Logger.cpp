#include <iostream>
#include "core/Logger.hpp"
#include <stdio.h>
#include <time.h>
#include <windows.h>

namespace Logger
{	
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	void Log::Warning(std::string message) { Send(LogProperty::WARDING, ColorLogger::YELLOW, message); }

	void Log::Error(std::string message) { Send(LogProperty::_ERROR, ColorLogger::RED, message); }

	void Log::Info(std::string message) { Send(LogProperty::INFO, ColorLogger::WHITE, message); }

	void Log::Debug(std::string message) { Send(LogProperty::DEBUG, ColorLogger::GREEN, message); }

	void Log::Send(const LogProperty property, ColorLogger color, std::string message)
	{	
		std::cout << "[" << currentDateTime() << "] ";
		SetConsoleTextAttribute(handle, color);
		std::cout << property_to_string(property) << " : " << message << std::endl;
		SetConsoleTextAttribute(handle, ColorLogger::WHITE);
	}

	const std::string Log::currentDateTime()
	{
		time_t     now = time(0);
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%Y-%m-%d | %X", &tstruct);
		return buf;
	}

	const std::string Log::property_to_string(LogProperty property)
	{
		switch (property)
		{
		case LogProperty::_ERROR:
			return "ERROR";
		case LogProperty::DEBUG:
			return "DEBUG";
		case LogProperty::INFO:
			return "INFO";
		case LogProperty::WARDING:
			return "WARNING";
		default:
			return "INFO";
		}
	}
}
