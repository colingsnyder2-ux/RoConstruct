#pragma once
#include <afxwin.h>

// Non-polymorphic name retained from existing recovery; observed extent is 0x14.
class CFileVersionInfo {
    WORD m_wLang;
    WORD m_wCodePage;
    LPBYTE m_lpVersionData;
    LPVOID m_lpTranslation;
    UINT m_nTranslations;
    VS_FIXEDFILEINFO* m_pFixedInfo;
public:
    CFileVersionInfo();
    ~CFileVersionInfo() { Reset(); }
    void Reset();
    BOOL Create(const CString&);
    BOOL Create(HMODULE hModule);
    CString GetVersionInfo(const CString&);
    CString GetFileVersion();
};
