#include <iostream>
#include <stdio.h>
#include <time.h>
#include "core/Logger.hpp"
#include "utils/System.hpp"
#include "utils/Color.hpp"
#include "utils/Time.hpp"

	
namespace Logger
{	

	Log Log::Warning() { return Log(LogSeverity::WARNING, Color::ColorLogger::YELLOW); }
	Log Log::Debug() { return Log(LogSeverity::DEBUG, Color::ColorLogger::GREEN); }
	Log Log::Info() { return Log(LogSeverity::INFO, Color::ColorLogger::WHITE); }
	Log Log::Error() { return Log(LogSeverity::_ERROR, Color::ColorLogger::RED); }

	Log::Log(LogSeverity severity, Color::ColorLogger color) 
    { 	
        this->severity = severity; 
		this->color = color;
		Log::Send();
    }

	Log::~Log() { std::cout << "\033[0m\n"; }

	void Log::Send()
	{	
		std::cout << "[ " << Time::currentDateTimeLogger() << " ] ";
		std::cout << Color::convertToASCII(color) << severity_to_string(severity) << " : ";
	}

	const char* Log::severity_to_string(LogSeverity &property)
	{
		switch (property)
		{
		case LogSeverity::_ERROR:
			return "ERROR";
		case LogSeverity::DEBUG:
			return "DEBUG";
		case LogSeverity::INFO:
			return "INFO";
		case LogSeverity::WARNING:
			return "WARNING";
		default:
			return "INFO";
		}
	}

}


