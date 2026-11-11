#pragma once
// >>> native-status (generated) -- do not edit >>>
// Log2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 6a8308cd | roc native-status --write
// 2008-06 native RBX::Log (inactive). Declared under a non-colliding name: the donor util/Log.h is included by
// native-classes/CRobloxDoc.cpp (and by the donor App sources), so a unit must not include both headers.
// Every field and slot below is read from the 2008-06 binary:
//   RTTI     vtable 008341b8 .?AVLog@RBX@@ (no bases), one slot: scalar deleting destructor 005a6fb0.
//   ctor     005a6da0 Log(const char* logFile, const char* name), ret 8: vtable; std::string +0x04 from the second
//            argument (name); +0x20 = 0 (worstSeverity, Information); std::string +0x24 from the first argument
//            (logFile); std::ofstream +0x40 opened with (logFile, 2, 0x40); then the file-local timeStamp(stream,
//            true) 005a6d10 and `stream << "Log \"" << name << "\"\n"` (008341a8 / 008341b0), flush.
//            The donor Log has no name member: its logFile string would sit at +0x08.
//   dtor     005a6e60: timeStamp(stream, true), "End Log\n" (008341bc), then ~ofstream / ~string +0x24 / ~string +0x04.
//   statics  provider 00976b4c (setLogProvider 005a6bb0); the severity prefixes information / warning / error are
//            .data pointers 0094c420 / 0094c424 / 0094c428 read by writeEntry 005a6ef0.
// The size (0x40 + sizeof(std::ofstream)) is not passed to new in any code found here; it follows from the members.
#include <string>
#include <fstream>

struct NativeLeaves2008Layout;

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
		friend struct ::NativeLeaves2008Layout;

	public:
		enum Severity
		{
			Information,
			Warning,
			Error
		};

	private:
		std::string name;              // +0x04 (ctor 005a6da0, second argument)
	public:
		Severity worstSeverity;        // +0x20
		const std::string logFile;     // +0x24
	private:
		std::ofstream stream;          // +0x40
	private:
		static ILogProvider* provider; // 00976b4c

	public:
		void writeEntry(Severity severity, const char* message);   // 005a6ef0
	public:
		Log(const char* logFile, const char* name);                // 005a6da0
		virtual ~Log();                                            // 005a6e60 (??_G 005a6fb0)

	public:
		static std::string formatMem(unsigned bytes);              // 005a6bc0
		static std::string formatTime(double time);                // 005a6c60
		static void setLogProvider(ILogProvider* provider);        // 005a6bb0
		static Log* current()
		{
			return provider ? provider->provideLog() : NULL;
		}
	};
}
