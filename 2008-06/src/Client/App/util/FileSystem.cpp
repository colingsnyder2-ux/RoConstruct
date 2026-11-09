#include <atlpath.h>
#include "util/FileSystem.h"
#include <atlutil.h>

namespace RBX
{
	VistaAPIs::VistaAPIs()
		: getKnownFolderPath(NULL)
	{
		gShell32DLLInst = LoadLibraryA("Shell32.dll");
		if (gShell32DLLInst)
		{
			getKnownFolderPath = (GetKnownFolderPathPtr)GetProcAddress(gShell32DLLInst, "SHGetKnownFolderPath");
		}
	}

	VistaAPIs::~VistaAPIs()
	{
		if (gShell32DLLInst)
			FreeLibrary(gShell32DLLInst);
	}

	HRESULT VistaAPIs::SHGetKnownFolderPath(REFKNOWNFOLDERID rfid, DWORD dwFlags, HANDLE hToken, PWSTR* ppszPath)
	{
		if (!getKnownFolderPath)
			return E_NOTIMPL;

		return getKnownFolderPath(rfid, dwFlags, hToken, ppszPath);
	}

	HRESULT VistaAPIs::GetIntegrity(PUCHAR pVal)
	{
		*pVal = 0;

		OSVERSIONINFOA osvi = {0};
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOA);

		GetVersionExA(&osvi);
		
		if (osvi.dwMajorVersion < 6) // anything earlier than Windows Vista
			return S_OK;

		HANDLE hToken;
		HANDLE hProcess = GetCurrentProcess();
		if (!OpenProcessToken(hProcess, TOKEN_QUERY | TOKEN_QUERY_SOURCE, &hToken))
			return S_OK;

		DWORD dwLengthNeeded;
		if (!GetTokenInformation(hToken, TokenIntegrityLevel, NULL, 0L, &dwLengthNeeded))
		{
			if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
			{
				PTOKEN_MANDATORY_LABEL pTIL;
				pTIL = (PTOKEN_MANDATORY_LABEL)LocalAlloc(LMEM_FIXED, dwLengthNeeded);

				if (pTIL)
				{
					if (GetTokenInformation(hToken, TokenIntegrityLevel, pTIL, dwLengthNeeded, &dwLengthNeeded))
					{
						DWORD dwIntegrityLevel = *GetSidSubAuthority(pTIL->Label.Sid, (DWORD)(UCHAR)(*GetSidSubAuthorityCount(pTIL->Label.Sid) - 1));

						if (dwIntegrityLevel < SECURITY_MANDATORY_MEDIUM_RID)
							*pVal = 1;
						else if (dwIntegrityLevel < SECURITY_MANDATORY_HIGH_RID)
							*pVal = 2;
						else
							*pVal = 3;
					}

					LocalFree(pTIL);
				}
			}
		}

		CloseHandle(hToken);
		return S_OK;
	}

	std::string FileSystem::getCacheDirectory(bool create)
	{
		VistaAPIs apis;

		UCHAR integrity;
		apis.GetIntegrity(&integrity);

		if (integrity == 1)
		{
			KNOWNFOLDERID folderID;
			CLSIDFromString(OLESTR("{352481E8-33BE-4251-BA85-6007CAEDCF9D"), &folderID); // FOLDERID_InternetCache
			
			PWSTR lppwstrPath = NULL;
			if (apis.SHGetKnownFolderPath(folderID, KF_FLAG_CREATE, NULL, &lppwstrPath) != E_NOTIMPL)
			{
				ATL::CString s = lppwstrPath;
				CoTaskMemFree(lppwstrPath);
				s.Append("\\Roblox\\");

				if (create)
				{
					if (!CreateDirectoryA(s, NULL))
					{
						if (GetLastError() != ERROR_ALREADY_EXISTS)
							return "";
					}
				}

				ATL::CPath path = s;
				path.AddBackslash();
				return std::string(path);
			}
		}

		char path[MAX_PATH];
		if (SHGetFolderPathAndSubDirA(NULL, (create ? CSIDL_FLAG_CREATE : 0L) | CSIDL_COMMON_APPDATA, NULL, 0L, "Roblox\\Cache", path) == S_OK)
			return path;

		return "";
	}
}

namespace RBX {
std::string FileSystem::getUserAppDataDirectory(bool create, const char* subDirectory) {
 VistaAPIs apis;
 UCHAR integrity;
 apis.GetIntegrity(&integrity);
 if(integrity>0) {
  GUID folder;
  if(integrity==1) CLSIDFromString(L"{A520A1A4-1780-4FF6-BD18-167343C5AF16}",&folder);
  else CLSIDFromString(L"{F1B32785-6FBA-4FCF-9D55-7B8E7F157091}",&folder);
  PWSTR knownPath=NULL;
  if(apis.SHGetKnownFolderPath(folder,create?0x8000:0,NULL,&knownPath)!=E_NOTIMPL) {
   ATL::CStringA path(knownPath);
   CoTaskMemFree(knownPath);
   path += "\\Roblox\\";
   if(create) { if(!CreateDirectoryA(path,NULL)) { if(GetLastError()!=ERROR_ALREADY_EXISTS) return ""; } }
   if(subDirectory) {
    path += subDirectory;
    if(create) { if(!CreateDirectoryA(path,NULL)) { if(GetLastError()!=ERROR_ALREADY_EXISTS) return ""; } }
   }
   ATL::CPath directory(path);
   directory.AddBackslash();
   return (LPCSTR)directory;
  }
 }
 int flags=create?CSIDL_FLAG_CREATE:0;
 std::string subPath("Roblox\\");
 if(subDirectory) subPath += subDirectory;
 ATL::CPath path;
 HRESULT result=SHGetFolderPathAndSubDirA(NULL,CSIDL_APPDATA|flags,NULL,SHGFP_TYPE_CURRENT,subPath.c_str(),path.m_strPath.GetBuffer(MAX_PATH));
 if(result!=S_OK) result=SHGetFolderPathAndSubDirA(NULL,CSIDL_COMMON_APPDATA|flags,NULL,SHGFP_TYPE_CURRENT,subPath.c_str(),path.m_strPath.GetBuffer(MAX_PATH));
 if(result==S_OK) {
  path.m_strPath.ReleaseBuffer();
  path.AddBackslash();
  return (LPCSTR)path;
 }
 else return "";
}
}
