#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include "decomp.h"
#include "CrashReporter.h" // donor copy (rbxgs has an older one)
#include "util/Log.h"
#include "util/boost.hpp"

#include <shlwapi.h>
#include <atlpath.h>
#include <boost/scoped_ptr.hpp>
#include <exception>
#include <dbghelp.h> // imagehlp.h clashes with dbghelp.h in this SDK
#include <string>
#include <vector>
#include <windows.h>

class MainLogManager;

// VTABLE: WEBSERVICE 0x1025af44
// SIZE 0x28
class LogManager
{
	RBX::Log* log; // 0x04
	static bool logsEnabled;

protected:
	const DWORD threadID; // 0x08
	std::string name;     // 0x0c
	static MainLogManager* mainLogManager;

public:
	RBX::Log* getLog();
	static MainLogManager* getMainLogManger();
	static HRESULT ReportCOMError(const GUID&, const char*, HRESULT);
	static HRESULT ReportCOMError(const GUID&, const wchar_t*, HRESULT);
	static HRESULT ReportCOMError(const GUID&, HRESULT);
	static HRESULT ReportExceptionAsCOMError(const GUID&, const std::exception&);
	static void ReportException(const std::exception&);
	static void ReportLastError(const char*);
	static void ReportEvent(WORD, HRESULT, const char*, int);
	static void ReportEvent(WORD, const char*, const char*, int);
	static void ReportEvent(WORD type, const char* message);
	ATL::CPath GetLogPath() const;
	virtual ~LogManager();                    // vtable+0x00
	virtual std::string getLogFileName() = 0; // vtable+0x04

	// SYNTHETIC: WEBSERVICE 0x10001dd0
	// SYNTHETIC: ROBLOX 0x0042b9b0
	// LogManager::`scalar deleting destructor'

protected:
	LogManager(const char* name) : log(NULL), threadID(GetCurrentThreadId()), name(name) {}
};

DECOMP_SIZE_ASSERT(LogManager, 0x28)

// VTABLE: WEBSERVICE 0x1025af64
// SIZE 0x7d0
class RobloxCrashReporter : public CrashReporter
{
public:
	static bool silent;

	RobloxCrashReporter(const char* outputPath, const char* appName, MINIDUMP_TYPE mdType);

	virtual LONG ProcessException(_EXCEPTION_POINTERS* info); // vtable+0x00
};

DECOMP_SIZE_ASSERT(RobloxCrashReporter, 0x7d0)

// VTABLE: WEBSERVICE 0x1025af50 RBX::ILogProvider
// VTABLE: WEBSERVICE 0x1025af58 LogManager
// SIZE 0x4c
class MainLogManager : public RBX::ILogProvider, public LogManager
{
	boost::scoped_ptr<RobloxCrashReporter> crashReporter; // 0x2c

public:
	MainLogManager(const char* productName);
	virtual ~MainLogManager();

	// SYNTHETIC: WEBSERVICE 0x100026b0
	// SYNTHETIC: ROBLOX 0x0042bf20
	// MainLogManager::`scalar deleting destructor'

	virtual RBX::Log* provideLog();
	virtual std::string getLogFileName();

	std::string MakeLogFileName(const char* prefix);

	bool hasErrorLogs() const;
	bool hasCrashLogs() const;
	std::vector<std::string> archiveCrashLogs();
	void CullLogs(const char* folder, int maxLogs);
	void startCrashReporter();
	void WriteCrashDump() { startCrashReporter(); } // 2007 name

private:
	std::string guid; // 0x30

	static bool handleDebugAssert(
		const char* expression,
		const std::string& message,
		const char* filename,
		int lineNumber,
		bool& ignoreAlways,
		bool useGuiPrompt
	);
	static bool handleG3DFailure(
		const char* expression,
		const std::string& message,
		const char* filename,
		int lineNumber,
		bool& ignoreAlways,
		bool useGuiPrompt
	);
};

DECOMP_SIZE_ASSERT(MainLogManager, 0x4c)

// VTABLE: WEBSERVICE 0x1025af6c
// VTABLE: ROBLOX 0x00803e9c
// SIZE 0x28
class ThreadLogManager : public LogManager
{
	ThreadLogManager() : LogManager(RBX::get_thread_name()) {}

public:
	static ThreadLogManager* getCurrent();

	virtual ~ThreadLogManager() {}

	// SYNTHETIC: WEBSERVICE 0x10002810
	// SYNTHETIC: ROBLOX 0x0042bf40
	// ThreadLogManager::`scalar deleting destructor'

protected:
	virtual std::string getLogFileName();
};

DECOMP_SIZE_ASSERT(ThreadLogManager, 0x28)

// clang-format off
// SYNTHETIC: WEBSERVICE 0x10220f80
// SYNTHETIC: ROBLOX 0x007ef9e0
// `log_detail::init'::`2'::`dynamic atexit destructor for 'value''
// clang-format on

void FUN_0042b3c0(const std::exception& e);

#endif // LOGMANAGER_H
