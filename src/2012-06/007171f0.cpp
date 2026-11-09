// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-atl90-dll roc_filesystem_nested_78e80a56ef829311.cpp

// Candidate translation unit (score above; library headers required).
#include <atlpath.h>
#include "util/FileSystem.h"

namespace RBX
{
	VistaAPIs::~VistaAPIs()
	{
		if (gShell32DLLInst)
			FreeLibrary(gShell32DLLInst);
	}

	HRESULT VistaAPIs::GetIntegrity(PUCHAR pVal)
	{
		*pVal = 0;

		OSVERSIONINFOA osvi;
		ZeroMemory((char*)&osvi + sizeof(DWORD), sizeof(OSVERSIONINFOA) - sizeof(DWORD));
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
}


namespace RBX {
VistaAPIs::VistaAPIs() : getKnownFolderPath(NULL) {
 gShell32DLLInst = LoadLibraryA("Shell32.dll");
 if(gShell32DLLInst) getKnownFolderPath = (GetKnownFolderPathPtr)GetProcAddress(gShell32DLLInst,"SHGetKnownFolderPath");
}
HRESULT VistaAPIs::SHGetKnownFolderPath(REFKNOWNFOLDERID folder, DWORD flags, HANDLE token, PWSTR* path) {
 if(getKnownFolderPath==NULL) return E_NOTIMPL;
 return getKnownFolderPath(folder,flags,token,path);
}
std::string FileSystem::getCacheDirectory(bool create) {
 VistaAPIs apis;
 UCHAR integrity;
 apis.GetIntegrity(&integrity);
 if(integrity == 1) {
  GUID internetCache;
  CLSIDFromString(L"{352481E8-33BE-4251-BA85-6007CAEDCF9D",&internetCache);
  PWSTR knownPath = NULL;
  if(apis.SHGetKnownFolderPath(internetCache,0x8000,NULL,&knownPath)!=E_NOTIMPL) {
   ATL::CStringA path(knownPath);
   CoTaskMemFree(knownPath);
   path += "\\Roblox\\";
   if(create && !CreateDirectoryA(path,NULL) && GetLastError()!=ERROR_ALREADY_EXISTS) return "";
   ATL::CPath cache(path);
   cache.AddBackslash();
   return (LPCSTR)cache;
  }
 }
 char path[MAX_PATH];
 HRESULT result=SHGetFolderPathAndSubDirA(NULL,CSIDL_COMMON_APPDATA | (create ? CSIDL_FLAG_CREATE : 0),NULL,SHGFP_TYPE_CURRENT,"Roblox\\Cache",path);
 if(result==S_OK) return path;
 else return "";
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
