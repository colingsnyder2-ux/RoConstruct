#define _CRT_SECURE_NO_DEPRECATE
#include "leaves2008/Log2008.h"
#include <windows.h>

static void timeStamp(std::ofstream& stream, bool includeDate)
{
	char buffer[256];

	SYSTEMTIME systemTime;
	GetLocalTime(&systemTime);

	if (includeDate)
	{
		sprintf(buffer, "%02u.%02u.%u ", systemTime.wDay, systemTime.wMonth, systemTime.wYear);
		stream << buffer;
	}

	sprintf(buffer, "%02u:%02u:%02u.%03u ", systemTime.wHour, systemTime.wMinute, systemTime.wSecond, systemTime.wMilliseconds);
	stream << buffer;

	stream.flush();
}

namespace RBX
{
	ILogProvider* Log::provider;

	void Log::setLogProvider(ILogProvider* provider)
	{
		Log::provider = provider;
	}

	std::string Log::formatMem(unsigned bytes)
	{
		char buffer[64];
		if (bytes < 1000)
			sprintf(buffer, "%dB", bytes);
		else if (bytes < 1000*1000)
			sprintf(buffer, "%dKB", bytes / 1000);
		else if (bytes < 1000*1000*1000)
			sprintf(buffer, "%dMB", bytes / (1000*1000));
		else
			sprintf(buffer, "%dGB", bytes / (1000*1000*1000));

		return buffer;
	}

	std::string Log::formatTime(double time)
	{
		char buffer[64];
		if (time == 0.0)
			sprintf(buffer, "0s");

		if (time < 0.0)
			sprintf(buffer, "%.3gs", time);
		else if (time >= 0.1)
			sprintf(buffer, "%.3gs", time);
		else
			sprintf(buffer, "%.3gms", time * 1000.0);

		return buffer;
	}

	static const char* information = "          ";
	static const char* warning     = " Warning: ";
	static const char* error       = " Error:   ";

	void Log::writeEntry(Severity severity, const char* message)
	{
		::timeStamp(stream, false);

		switch (severity)
		{
		case Information:
			stream << information;
			break;
		case Warning:
			stream << warning;
			break;
		case Error:
			stream << error;
			break;
		}

		stream << message;
		stream << '\n';
		stream.flush();
	}

	Log::Log(const char* logFile, const char* name)
		: name(name),
		  worstSeverity(Information),
		  logFile(logFile),
		  stream(logFile, 2, 64)
	{
		::timeStamp(stream, true);
		stream << "Log \"" << name << "\"\n";
		stream.flush();
	}

	Log::~Log()
	{
		::timeStamp(stream, true);
		stream << "End Log\n";
	}
}
