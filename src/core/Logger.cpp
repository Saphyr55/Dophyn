#include <iostream>
#include "core/Logger.hpp"
#include <stdio.h>
#include <time.h>

void Logger::Log::send(const Logger::LogProperty property = Logger::LogProperty::INFO, std::string message = "")
{	
	std::cout << "[" << currentDateTime() << "] " << property_to_string(property) << " : " << message << std::endl;
}

const std::string Logger::Log::currentDateTime()
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d | %X", &tstruct);
	return buf;
}

const std::string Logger::Log::property_to_string(Logger::LogProperty property)
{	
	switch (property)
	{
	case Logger::LogProperty::TRACE:
		return "TRACE";
	case Logger::LogProperty::DEBUG:
		return "DEBUG";
	case Logger::LogProperty::INFO:
		return "INFO";
	case Logger::LogProperty::WARDING:
		return "WARNING";
	case Logger::LogProperty::ERROR:
		return "ERROR";
	case Logger::LogProperty::CRITICAL:
		return "CRITICAL";
	default:
		return "INFO";
	}
}
