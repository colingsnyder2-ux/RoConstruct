// native-flags: /O2 /GS- /EHsc /MD /D_AFXDLL /D_MBCS /I{headers}/mfc-import-length /I{headers}/std-noinline-string /I{headers}/../../../tools/libs/mfc-9.0-rtm/atlmfc/include
// Recovered OpenRBX log manager methods; inactive pending provider and ABI proof.
#include <afxwin.h>
#include "CRobloxApp.h"
#include "util/FileSystem.h"
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

