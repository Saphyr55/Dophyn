#ifndef SYSTEM_HPP
#define SYSTEM_HPP

bool is_win32()
{
#ifdef _WIN32
	return true;
#else
	return false;
#endif
}

bool is_linux()
{
#ifdef __LINUX__
	return true;
#else
	return false;
#endif
}

#endif