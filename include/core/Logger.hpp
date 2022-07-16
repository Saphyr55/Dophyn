#ifndef LOGGER_H
#define LOGGER_H

namespace Logger
{

	enum struct LogProperty
	{
		TRACE,
		DEBUG,
		INFO,
		WARDING,
		ERROR,
		CRITICAL
	};

	class Log
	{

	public:
		static void send(const LogProperty, std::string message);

	private:
		static const std::string currentDateTime();
		static const std::string property_to_string(LogProperty property);


	};	

}

#endif
