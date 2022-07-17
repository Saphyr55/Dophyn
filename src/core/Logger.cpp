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
#include <stdio.h>

	
namespace Logger
{	

	template<typename ...Args>
	void Log::Warning(char* message, Args ...args)
	{
		Log::Send(LogProperty::WARNING, Color::ColorLogger::YELLOW, message, args);
	}

	template<typename ...Args>
	void Log::Debug(char* message, Args ...args)
	{
		Log::Send(LogProperty::DEBUG, Color::ColorLogger::GREEN, message, args);
	}

	template<typename ...Args>
	void Log::Info(char* message, Args ...args)
	{
		Log::Send(LogProperty::INFO, Color::ColorLogger::WHITE, message, args);
	}

	template<typename ...Args>
	void Log::Error(char* message, Args ...args)
	{
		Log::Send(LogProperty::_ERROR, Color::ColorLogger::RED, message, args);
	}

	template<typename... Args>
	void Log::Send(LogProperty p, Color::ColorLogger color, char* message, Args... args)
	{	
		if (is_win32())
			SendWin32(p, color, message, args);
		else
			SendLinux(p, color, message, args);
	}

	template<typename... Args>
	void Log::SendWin32(LogProperty p, Color::ColorLogger color, char* message, Args... args)
	{
#ifdef _WIN32
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		printf("[ %s ] ", Time::currentDateTimeLogger());
		SetConsoleTextAttribute(handle, Color::convertToWin32(color));
		printf("%s : ", property_to_string(p));
		printf(message, args...);
		printf("\n")
		SetConsoleTextAttribute(handle, Color::convertToWin32(Color::ColorLogger::WHITE));
#endif
	}


	template<typename... Args>
	void Log::SendLinux(LogProperty p, Color::ColorLogger color, char* message, Args... args)
	{
		printf("[ %s ] ", Time::currentDateTimeLogger());
		printf("%s%s : ", Color::convertToASCII(color), property_to_string(p));
		printf(message, args...);
		printf("\033[0m\n");
	}

	const char* Log::property_to_string(LogProperty &property)
	{
		switch (property)
		{
		case LogProperty::_ERROR:
			return "ERROR";
		case LogProperty::DEBUG:
			return "DEBUG";
		case LogProperty::INFO:
			return "INFO";
		case LogProperty::WARNING:
			return "WARNING";
		default:
			return "INFO";
		}
	}

}


