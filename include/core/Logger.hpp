#ifndef LOGGER_H
#define LOGGER_H

#ifdef _WIN32
#include <Windows.h>
#endif
#include "utils/Color.hpp"
#include <string> 

namespace Logger
{	

	enum LogProperty
	{
		DEBUG = 0,
		INFO = 1,
		WARNING = 2,
		_ERROR = 3,
	};

	class Log
	{
	public:
		template<typename... Args>
		static void Warning(char* message, Args... args);
		template<typename... Args>
		static void Debug(char* message, Args... args);
		template<typename... Args>
		static void Info(char* message, Args... args);
		template<typename... Args>
		static void Error(char* message, Args... args);

	private:
		template<typename... Args>
		static void Send(LogProperty p, Color::ColorLogger color, char*message, Args... args);
		template<typename... Args>
		static void SendWin32(LogProperty p, Color::ColorLogger color, char* message, Args... args);
		template<typename... Args>
		static void SendLinux(LogProperty p, Color::ColorLogger color, char* message, Args... args);
		static const char* property_to_string(LogProperty &property);
	};



}

#endif
