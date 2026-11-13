#include <afxwin.h> // MFC first (donor 2007 file built against MFC)
#include <afxole.h> // COleException
#include "LogManager.h"

#include "VersionInfo.h"
#include "util/FileSystem.h"
#include "util/Guid.h"
#include "util/StandardOut.h"

#include <G3D/Log.h>
#include <G3D/debugAssert.h>
#include <algorithm>
#include <atlbase.h>
#include <atlcom.h>
#include <atltime.h>
#include <boost/thread/once.hpp>
#include <boost/thread/tss.hpp>
#include <direct.h>
#include <list>

// GLOBAL: ROBLOX 0x0095389c
static boost::thread_specific_ptr<ThreadLogManager>* ts;

bool LogManager::logsEnabled = true;

// GLOBAL: ROBLOX 0x009538a8
MainLogManager* LogManager::mainLogManager;
bool RobloxCrashReporter::silent;

// FUNCTION: ROBLOX 0x0042a550
MainLogManager* LogManager::getMainLogManger()
{
	return mainLogManager;
}

// FUNCTION: WEBSERVICE 0x10001df0
// FUNCTION: ROBLOX 0x0042a580
ATL::CPath LogManager::GetLogPath() const
{
	std::string result = RBX::FileSystem::getUserAppDataDirectory(true, "logs");
	return result.c_str();
}

// FUNCTION: WEBSERVICE 0x10001ea0
// FUNCTION: ROBLOX 0x0042a630
std::string MainLogManager::getLogFileName()
{
	ATL::CPath path = GetLogPath();

	std::string fileName = "log_";
	fileName += guid;

	fileName.erase(12);
	fileName.erase(4, 3);
	fileName += ".txt";

	path.Append(fileName.c_str());

	return (LPCSTR) path;
}

// FUNCTION: ROBLOX 0x0042a780
std::string MainLogManager::MakeLogFileName(const char* prefix)
{
	ATL::CPath path = GetLogPath();

	std::string fileName = "log_";
	fileName += guid;

	fileName.erase(12);
	fileName.erase(4, 3);
	fileName += prefix;
	fileName += ".txt";

	path.Append(fileName.c_str());

	return (LPCSTR) path;
}

// FUNCTION: WEBSERVICE 0x10001fd0
// FUNCTION: ROBLOX 0x0042a250
std::string ThreadLogManager::getLogFileName()
{
	std::string fileName = mainLogManager->getLogFileName();
	CString id;
	id.Format("_%s_%d", name.c_str(), threadID);
	fileName.insert(fileName.size() - 4, id);
	return fileName;
}

// FUNCTION: WEBSERVICE 0x100020c0
// STUB: ROBLOX 0x0042a320
RBX::Log* LogManager::getLog()
{
	if (log == NULL) {
		log = new RBX::Log(getLogFileName().c_str(), name.c_str());
	}

	return log;
}

// FUNCTION: WEBSERVICE 0x10002190
// FUNCTION: ROBLOX 0x0042d5e0
RBX::Log* MainLogManager::provideLog()
{
	if (GetCurrentThreadId() == threadID) {
		return getLog();
	}
	else {
		return ThreadLogManager::getCurrent()->getLog();
	}
}

// FUNCTION: WEBSERVICE 0x100021c0
// FUNCTION: ROBLOX 0x0042a400
RobloxCrashReporter::RobloxCrashReporter(const char* outputPath, const char* appName, MINIDUMP_TYPE mdType)
{
	controls.actionToTake = AOC_WRITE_TO_DISK | AOC_SILENT_MODE;
	controls.minidumpType = mdType;
	strcpy(controls.pathToMinidump, outputPath);

	strcpy(controls.appName, appName);

	CVersionInfo vi;
	vi.Load(ATL::_AtlBaseModule.GetModuleInstance());
	CString v = vi.GetFileVersionAsString();
	strcpy(controls.appVersion, v);
}

// FUNCTION: WEBSERVICE 0x100022e0
// FUNCTION: ROBLOX 0x0042a4f0
LONG RobloxCrashReporter::ProcessException(_EXCEPTION_POINTERS* info)
{
	LONG result = CrashReporter::ProcessException(info);
	static bool showedMessage = silent;
	if (!showedMessage) {
		showedMessage = true;
		MessageBox(NULL, "An unexpected error occurred and ROBLOX needs to quit.  We're sorry!", "ROBLOX Crash", MB_OK);
	}

	return result;
}

// FUNCTION: WEBSERVICE 0x10002340
// FUNCTION: ROBLOX 0x0042ac60
// 2008-06: MainLogManager::startCrashReporter 00428180 (same sequence; called from CRobloxApp::InitInstance)
void MainLogManager::startCrashReporter()
{
	std::string appName = "log_";
	appName += guid;
	appName.erase(12);
	appName.erase(4, 3);
	crashReporter.reset(new RobloxCrashReporter(GetLogPath(), appName.c_str(), MiniDumpWithDataSegs));
	crashReporter->Start();
}

// FUNCTION: WEBSERVICE 0x10002490
// FUNCTION: ROBLOX 0x0042ada0
static void __cdecl purecallHandler()
{
	CString eventMessage;
	eventMessage.Format("Pure Call Error");
	LogManager::ReportEvent(EVENTLOG_ERROR_TYPE, eventMessage);

	int* p = NULL;
	*p = p[1];
}

// FUNCTION: WEBSERVICE 0x10002530
// FUNCTION: ROBLOX 0x0042cba0
MainLogManager::MainLogManager(const char* productName) : LogManager(productName)
{
	RBX::Guid::generateGUID(guid);
	CullLogs("\\", 32);
	CullLogs("error\\", 32);
	CullLogs("archive\\", 32);

	std::string g3dLogFile = getLogFileName();
	g3dLogFile.erase(g3dLogFile.size() - 4);
	g3dLogFile += "_G3D.txt";
	new G3D::Log(g3dLogFile);

	mainLogManager = this;
	RBX::Log::setLogProvider(this);

	G3D::setAssertionHook(handleDebugAssert);
	G3D::setFailureHook(handleG3DFailure);

	_set_purecall_handler(purecallHandler);
}

// FUNCTION: WEBSERVICE 0x100026d0
// FUNCTION: ROBLOX 0x0042ae20
std::string MoveRelative(const char* fileName, std::string path)
{
	ATL::CPath dir(fileName);
	dir.RemoveFileSpec();
	dir.Append(path.c_str());
	if (!PathFileExists(dir)) {
		_mkdir(dir);
	}
	ATL::CPath file(fileName);
	file.StripPath();
	dir.Append(file);
	MoveFile(fileName, dir);
	return (LPCSTR) dir;
}

// FUNCTION: ROBLOX 0x0042aff0
bool MainLogManager::hasCrashLogs() const
{
	ATL::CPath path = GetLogPath();
	path.AddBackslash();

	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = FindFirstFile(path + "*.dmp", &FindFileData);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				return true;
			}
		} while (FindNextFile(hFind, &FindFileData));
	}

	return false;
}

// STUB: WEBSERVICE 0x10002840
// FUNCTION: ROBLOX 0x0042cd30
std::vector<std::string> MainLogManager::archiveCrashLogs()
{
	std::vector<std::string> result;

	ATL::CPath path = GetLogPath();
	path.AddBackslash();

	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = FindFirstFile(path + "*.dmp", &FindFileData);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				result.push_back(MoveRelative(path + FindFileData.cFileName, "archive\\"));

				std::string wildCard = FindFileData.cFileName;
				wildCard = wildCard.substr(0, 9) + "*.*";

				WIN32_FIND_DATA FindOtherFileData;
				HANDLE hFindOther = FindFirstFile(path + wildCard.c_str(), &FindOtherFileData);
				if (hFindOther != INVALID_HANDLE_VALUE) {
					do {
						if (!(FindOtherFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
							result.push_back(MoveRelative(path + FindOtherFileData.cFileName, "archive\\"));
						}
					} while (FindNextFile(hFindOther, &FindOtherFileData));
				}
			}
		} while (FindNextFile(hFind, &FindFileData));
	}

	return result;
}

struct DateCompare
{
	ATL::CFileTime fileTime;

	DateCompare(const WIN32_FIND_DATA& data) : fileTime(data.ftCreationTime) {}

	bool operator()(WIN32_FIND_DATA data) const { return fileTime < ATL::CFileTime(data.ftCreationTime); }
};

// STUB: WEBSERVICE 0x10002c00
// FUNCTION: ROBLOX 0x0042c780
void MainLogManager::CullLogs(const char* folder, int maxLogs)
{
	ATL::CPath path = GetLogPath();
	path.Append(folder);
	path.AddBackslash();

	std::list<WIN32_FIND_DATA> files;

	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = FindFirstFile(path + "*.*", &FindFileData);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				files.insert(std::find_if(files.begin(), files.end(), DateCompare(FindFileData)), FindFileData);
			}
		} while (FindNextFile(hFind, &FindFileData));
	}

	std::list<WIN32_FIND_DATA>::iterator iter = files.begin();
	for (size_t i = maxLogs; i < files.size(); ++i) {
		DeleteFile(path + iter->cFileName);
		++iter;
	}
}

// FUNCTION: WEBSERVICE 0x10002e90
// FUNCTION: ROBLOX 0x0042b9d0
MainLogManager::~MainLogManager()
{
	if (G3D::Log::common()) {
		std::string g3dLogFile = G3D::Log::getCommonLogFilename();
		delete G3D::Log::common();

		if (RBX::Log::aggregateWorstSeverity == RBX::Log::Error) {
			MoveRelative(g3dLogFile.c_str(), "error\\");
		}
		else {
			MoveRelative(g3dLogFile.c_str(), "archive\\");
		}
	}

	mainLogManager = NULL;
}

// FUNCTION: WEBSERVICE 0x10002fe0
// FUNCTION: ROBLOX 0x0042b110
LogManager::~LogManager()
{
	if (log) {
		std::string logFile = log->logFile;
		RBX::Log::Severity severity = log->worstSeverity;
		delete log;
		log = NULL;

		if (severity == RBX::Log::Error) {
			MoveRelative(logFile.c_str(), "error\\");
		}
		else {
			MoveRelative(logFile.c_str(), "archive\\");
		}
	}
}

// FUNCTION: WEBSERVICE 0x10003100
// FUNCTION: ROBLOX 0x0042b230
bool MainLogManager::handleDebugAssert(
	const char* expression,
	const std::string& message,
	const char* filename,
	int lineNumber,
	bool& ignoreAlways,
	bool useGuiPrompt
)
{
	CString eventMessage;
	if (message.length() > 0) {
		eventMessage.Format(
			"Assertion failed: %s\n\nMessage: %s\n\n%s(%d)", expression, message.c_str(), filename, lineNumber
		);
	}
	else {
		eventMessage.Format("Assertion failed: %s\n%s(%d)", expression, filename, lineNumber);
	}
	ReportEvent(EVENTLOG_WARNING_TYPE, eventMessage);

	return false;
}

// FUNCTION: WEBSERVICE 0x100031f0
// FUNCTION: ROBLOX 0x0042b2f0
bool MainLogManager::handleG3DFailure(
	const char* expression,
	const std::string& message,
	const char* filename,
	int lineNumber,
	bool& ignoreAlways,
	bool useGuiPrompt
)
{
	CString eventMessage;
	if (message.length() > 0) {
		eventMessage.Format(
			"G3D Error: %s\n\nMessage: %s\n\n%s(%d)", expression, message.c_str(), filename, lineNumber
		);
	}
	else {
		eventMessage.Format("G3D Error: %s\n%s(%d)", expression, filename, lineNumber);
	}
	ReportEvent(EVENTLOG_ERROR_TYPE, eventMessage);

	int* p = NULL;
	*p = p[1];

	return false;
}

// FUNCTION: ROBLOX 0x0042b3c0
void FUN_0042b3c0(const std::exception& e)
{
	RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, e.what());
}

// FUNCTION: WEBSERVICE 0x100032e0
// FUNCTION: ROBLOX 0x0042a970
void LogManager::ReportEvent(WORD type, const char* message)
{
	switch (type) {
	case EVENTLOG_SUCCESS:
		RBX::StandardOut::singleton()->print(RBX::MESSAGE_INFO, "%s", message);
		break;
	case EVENTLOG_ERROR_TYPE:
		RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, "%s", message);
		break;
	case EVENTLOG_INFORMATION_TYPE:
		RBX::StandardOut::singleton()->print(RBX::MESSAGE_INFO, "%s", message);
		break;
	case EVENTLOG_AUDIT_SUCCESS:
		RBX::StandardOut::singleton()->print(RBX::MESSAGE_INFO, "%s", message);
		break;
	case EVENTLOG_AUDIT_FAILURE:
		RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, "%s", message);
		break;
	}
}

#ifdef _AFXDLL
// FUNCTION: ROBLOX 0x0042aae0
void LogManager::ReportEvent(WORD type, HRESULT hr, const char* file, int line)
{
	COleException exception;
	exception.m_sc = hr;
	char message[1024];
	exception.GetErrorMessage(message, 1024);

	CString text;
	text.Format("HRESULT = %d: %s\n%s(%d)", hr, message, file, line);
	ReportEvent(type, text);
}
#endif

// FUNCTION: ROBLOX 0x0042bf70
HRESULT LogManager::ReportCOMError(const GUID& guid, const char* message, HRESULT hr)
{
	ReportEvent(EVENTLOG_ERROR_TYPE, message);
	return AtlReportError(guid, message, GUID_NULL, hr);
}

// FUNCTION: ROBLOX 0x0042bfa0
HRESULT LogManager::ReportExceptionAsCOMError(const GUID& guid, const std::exception& e)
{
	return ReportCOMError(guid, e.what(), S_OK);
}

namespace log_detail {

// GLOBAL: ROBLOX 0x009538ac
boost::once_flag once_init = BOOST_ONCE_INIT;

// FUNCTION: WEBSERVICE 0x10003440
// FUNCTION: ROBLOX 0x0042d490
void init()
{
	static boost::thread_specific_ptr<ThreadLogManager> value;

	::ts = &value;
}

} // namespace log_detail

// FUNCTION: WEBSERVICE 0x100034b0
// FUNCTION: ROBLOX 0x0042d500
ThreadLogManager* ThreadLogManager::getCurrent()
{
	boost::call_once(&log_detail::init, log_detail::once_init);
	ThreadLogManager* logManager = ts->get();
	if (logManager == NULL) {
		logManager = new ThreadLogManager();
		ts->reset(logManager);
	}

	return logManager;
}
