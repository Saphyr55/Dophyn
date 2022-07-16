#include <iostream>
#include "core/Logger.hpp"
#include <stdio.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include "utils/System.hpp"
#include "utils/Color.hpp"
#include "utils/Time.hpp"

namespace Dophyn
{		

	void Log::Warning(std::string message, ...) { Send(LogProperty::WARDING, Color::ColorLogger::YELLOW, message); }

	void Log::Error(std::string message, ...) { Send(LogProperty::_ERROR, Color::ColorLogger::RED, message); }
	
	void Log::Info(std::string message, ...) { Send(LogProperty::INFO, Color::ColorLogger::WHITE, message); }

	void Log::Debug(std::string message, ...) { Send(LogProperty::DEBUG, Color::ColorLogger::GREEN, message); }

	void Log::Send(const LogProperty property, Color::ColorLogger color, std::string message)
	{	
		if (is_win32())
			SendWin32(property, color, message);
		else 
			SendLinux(property, color, message);
	}

	
	void Log::SendWin32(const LogProperty property, Color::ColorLogger color, std::string message)
	{	
		#ifdef _WIN32
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		std::cout << "[" << Time::currentDateTimeLogger() << "] ";
		SetConsoleTextAttribute(handle, Color::convertToWin32(color));
		std::cout << property_to_string(property) << " : " << message << std::endl;
		SetConsoleTextAttribute(handle, Color::convertToWin32(Color::ColorLogger::WHITE));
		#endif
	}
	
	void Log::SendLinux(const LogProperty property, Color::ColorLogger color, std::string message)
	{
		std::cout << "[" << Time::currentDateTimeLogger() << "] ";
		std::cout << Color::convertToASCII(color) << property_to_string(property) << " : " << message << "\033[0m" << std::endl;
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
