#pragma once
// >>> native-status (generated) -- do not edit >>>
// CFileVersionInfo | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 50e4b987 | roc native-status --write
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
    CString GetVersionInfo(const CString&);
    CString GetFileVersion();
};
