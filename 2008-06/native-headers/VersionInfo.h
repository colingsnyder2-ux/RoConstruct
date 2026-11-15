#ifndef VERSIONINFO_H
#define VERSIONINFO_H

#include <atlstr.h>
#include <windows.h>

// PJ Naughter's CVersionInfo, www.naughter.com
// SIZE 0x14
class CVersionInfo
{
public:
	// SIZE 0x4
	struct TRANSLATION
	{
		WORD m_wLangID;
		WORD m_wCodePage;
	};

	CVersionInfo();
	~CVersionInfo();

	int Load(HINSTANCE hInst);
	int Load(const CString& fileName);
	VS_FIXEDFILEINFO* GetFixedFileInfo();
	DWORD GetFileFlagsMask();
	DWORD GetFileFlags();
	DWORD GetOS();
	DWORD GetFileType();
	DWORD GetFileSubType();
	FILETIME GetCreationTime();
	unsigned __int64 GetFileVersion();
	unsigned __int64 GetProductVersion();
	CString GetValue(const CString& sKeyName);
	CString GetComments();
	CString GetCompanyName();
	CString GetFileDescription();
	CString GetFileVersionAsString();
	CString GetInternalName();
	CString GetLegalCopyright();
	CString GetLegalTrademarks();
	CString GetOriginalFilename();
	CString GetPrivateBuild();
	CString GetProductName();
	CString GetProductVersionAsString();
	CString GetSpecialBuild();
	int GetNumberOfTranslations();
	TRANSLATION* GetTranslation(int nIndex);
	void SetTranslation(int nIndex);

protected:
	void Unload();

	WORD m_wLangID;               // 0x00
	WORD m_wCharset;              // 0x02
	void* m_pVerData;             // 0x04
	TRANSLATION* m_pTranslations; // 0x08
	int m_nTranslations;          // 0x0c
	VS_FIXEDFILEINFO* m_pffi;     // 0x10
};

#endif // VERSIONINFO_H
