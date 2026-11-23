// =============================================================================
// VersionInfo.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/VersionInfo.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
