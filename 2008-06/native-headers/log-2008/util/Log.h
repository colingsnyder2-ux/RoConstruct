#pragma once
// >>> native-status (generated) -- do not edit >>>
// Log | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 768e3747 | roc native-status --write
#include "util/Debug.h"
#include <string>
#include <fstream>

namespace RBX
{
	class Log;

	class ILogProvider
	{
	public:
		virtual Log* provideLog() = 0;
	};

	class Log
	{
	public:
		enum Severity
		{
			Information,
			Warning,
			Error
		};

	public:
		std::string name;
		Severity worstSeverity;
		const std::string logFile;
	private:
		std::ofstream stream;
	public:
		static Severity aggregateWorstSeverity;
	private:
		static ILogProvider* provider;

	public:
		void writeEntry(Severity severity, const char* message);
		void timeStamp(bool);
	public:
		Log(const char* logFile, const char* name);
		virtual ~Log();

	public:
		static std::string formatMem(unsigned bytes);
		static std::string formatTime(double time);
		static void setLogProvider(ILogProvider* provider);
		static Log* current()
		{
			return provider ? provider->provideLog() : NULL;
		}
	private:
		static std::ofstream& currentStream()
		{
			RBXASSERT(provider->provideLog());
			return provider->provideLog()->stream;
		}
	};
}
