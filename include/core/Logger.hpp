#ifndef LOGGER_H
#define LOGGER_H

#include <Windows.h>
#include "utils/Color.hpp"

namespace Dophyn
{

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
		static void Warning(std::string message, ...);
		static void Error(std::string message, ...);
		static void Info(std::string message, ...);
		static void Debug(std::string message, ...);
		static void Send(const LogProperty property, Color::ColorLogger color, std::string message);

	private:
		static void SendWin32(const LogProperty property, Color::ColorLogger color, std::string message);
		static void SendLinux(const LogProperty property, Color::ColorLogger color, std::string message);
		static const std::string property_to_string(LogProperty property);


	};	

}

#endif
