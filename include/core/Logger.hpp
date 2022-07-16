#ifndef LOGGER_H
#define LOGGER_H

#include <Windows.h>

namespace Logger
{

	enum ColorLogger
	{	
		YELLOW = 6,
		WHITE = 7,
		RED = 4,
		GREEN = 2
	};

	enum LogProperty
	{
		DEBUG = 0,
		INFO = 1,
		WARDING = 2,
		_ERROR = 3,
	};

	class Log
	{
		
	public:
		static void Warning(std::string message);
		static void Error(std::string message);
		static void Info(std::string message);
		static void Debug(std::string message);
		static void Send(const LogProperty, ColorLogger color, std::string message);

	private:
		static void bracketsTime();
		static const std::string currentDateTime();
		static const std::string property_to_string(LogProperty property);


	};	

}

#endif
