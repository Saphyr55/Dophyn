#pragma once

#include "utils/Color.hpp"
#include <string> 
#include <iostream>

namespace Dophyn
{
	namespace Logger
	{

		enum LogSeverity { INFO, WARNING, _ERROR, DEBUG };

		class Log
		{

		private:
			LogSeverity severity;
			Color::ColorLogger color;

		private:
			Log(LogSeverity severity, Color::ColorLogger color);
		public:
			~Log();

		public:
			template<typename T>
			Log& operator<<(const T& s) { std::cout << s; return *this; }

		public:
			static Log Warning();
			static Log Debug();
			static Log Info();
			static Log Error();

		private:
			void Send();
			static const char* severity_to_string(LogSeverity& property);

		};

	}
}
