// native-flags: /O2 /GS- /EHsc /MD /D_AFXDLL /D_MBCS /I{headers}/mfc-import-length /I{headers}/std-noinline-string /I{headers}/../../../tools/libs/mfc-9.0-rtm/atlmfc/include
// Recovered OpenRBX log manager methods; inactive pending provider and ABI proof.
#include <afxwin.h>
#include "CRobloxApp.h"
#include "util/FileSystem.h"
#include "util/standardout.h"
#include <direct.h>
extern MainLogManager* mainLogManager;
MainLogManager* LogManager::getMainLogManger() { return mainLogManager; }

ATL::CPath LogManager::GetLogPath() const
{
	std::string result = RBX::FileSystem::getUserAppDataDirectory(true, "logs");
	return result.c_str();
}

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


std::string MainLogManager::MakeLogFileName(const char* prefix)
{
	ATL::CPath path = GetLogPath();

	std::string fileName = "log_";
	fileName += logIdentity;

	fileName.erase(12);
	fileName.erase(4, 3);
	fileName += prefix;
	fileName += ".txt";

	path.Append(fileName.c_str());

	return (LPCSTR) path;
}


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

