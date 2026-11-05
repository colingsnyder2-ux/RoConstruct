// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espclaude_43f0d040995d240c.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#ifndef _AFXDLL
#define _AFXDLL
#endif
#include <new>
#include <afxwin.h>

class CFileVersionInfo
{
public:
    WORD m_wLang;
    WORD m_wCodePage;
    LPBYTE m_lpVersionData;
    LPVOID m_lpTranslation;
    UINT m_nTranslations;
    VS_FIXEDFILEINFO* m_pFixedInfo;

    CFileVersionInfo() { m_wLang = 0; m_lpVersionData = NULL; m_pFixedInfo = NULL; m_wCodePage = 1252; m_lpTranslation = NULL; m_nTranslations = 0; }
    ~CFileVersionInfo() { Reset(); }
    void Reset()
    {
        m_pFixedInfo = NULL;
        if (m_lpVersionData)
        {
            delete[] m_lpVersionData;
            m_lpVersionData = NULL;
        }
        m_wLang = 0;
        m_wCodePage = 1252;
        m_lpTranslation = NULL;
        m_nTranslations = 0;
    }
    BOOL Create(const CString& strFileName);
};

BOOL CFileVersionInfo::Create(const CString& strFileName)
{
    Reset();
    CString strPath(strFileName);
    BOOL bRet = FALSE;
    DWORD dwHandle = 0;
    DWORD dwSize = GetFileVersionInfoSize(strPath.GetBuffer(), &dwHandle);
    if (dwSize)
    {
        m_lpVersionData = new BYTE[dwSize];
        if (GetFileVersionInfo(strPath.GetBuffer(), dwHandle, dwSize, m_lpVersionData))
        {
        UINT uLen = 0;
        if (VerQueryValue(m_lpVersionData, "\\", (LPVOID*)&m_pFixedInfo, &uLen))
        {
            if (VerQueryValue(m_lpVersionData, "\\VarFileInfo\\Translation", &m_lpTranslation, &uLen) && uLen >= 4)
            {
                m_nTranslations = uLen / 4;
                m_wLang = ((WORD*)m_lpTranslation)[0];
                m_wCodePage = ((WORD*)m_lpTranslation)[1];
            }
            bRet = TRUE;
        }
        }
    }
    if (!bRet && m_lpVersionData)
    {
        delete[] m_lpVersionData;
        m_lpVersionData = NULL;
    }
    return bRet;
}
