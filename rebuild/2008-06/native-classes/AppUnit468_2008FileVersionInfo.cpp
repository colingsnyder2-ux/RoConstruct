// Inactive 2008-06 native unit: CFileVersionInfo, the version-resource reader unit 0046a200..0046a57f of the
// application range 00468000..00474000 (verified by tests/record_native_app_unit468_2008.py).
// The class is declared by the native CFileVersionInfo.h (read-only here); its layout (0x14) is proven by the bodies:
// ctor 0046a200 / Reset 0046a4b0 store m_wLang +0, m_wCodePage +2 (1252 = 0x4e4), m_lpVersionData +4 (delete[] 006a094a),
// m_lpTranslation +8, m_nTranslations +0xc and m_pFixedInfo +0x10.
// Create(HMODULE) 0046a4f0 (GetModuleFileName into a 500-char buffer, then Create(CString)) is not declared by
// CFileVersionInfo.h: it is built only with NATIVE_APPUNIT468_PENDING against a generated header copy (proposal).
// A codegen analog: names follow the native header, not the original source.
// >>> native-status (generated) -- do not edit >>>
// AppUnit468_2008FileVersionInfo | 2008-06 | draft (no current byte proof)
// 0/5 mapped addresses byte-exact | 5 unproved | no mapped strings | by EspClaude (+2) (mixed 2)
// <<< native-status | src 280785ad | roc native-status --write
#include "CFileVersionInfo.h"

// @0046a200 ??0CFileVersionInfo@@QAE@XZ
CFileVersionInfo::CFileVersionInfo() : m_wLang(0), m_lpVersionData(NULL)
{
    Reset();
}

// @0046a4b0 ?Reset@CFileVersionInfo@@QAEXXZ
void CFileVersionInfo::Reset()
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

// @0046a220 ?Create@CFileVersionInfo@@QAEHABV
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

// @0046a370 ?GetVersionInfo@CFileVersionInfo@@QAE
CString CFileVersionInfo::GetVersionInfo(const CString& name)
{
    CString result;
    CString path;
    path.Format("\\StringFileInfo\\%04x%04x\\%s", m_wLang, m_wCodePage, name);
    LPVOID value = NULL;
    UINT length = 0;
    if (VerQueryValue(m_lpVersionData, path.GetBuffer(), &value, &length))
        result = static_cast<LPCTSTR>(value);
    return result;
}

// @0046a440 ?GetFileVersion@CFileVersionInfo@@QAE
CString CFileVersionInfo::GetFileVersion()
{
    CString name("FileVersion");
    return GetVersionInfo(name);
}

#ifdef NATIVE_APPUNIT468_PENDING
// @0046a4f0 ?Create@CFileVersionInfo@@QAEHPAUHINSTANCE__@@@Z
BOOL CFileVersionInfo::Create(HMODULE hModule)
{
    TCHAR szPath[500];
    GetModuleFileName(hModule, szPath, 500);
    CString strPath(szPath);
    return Create(strPath);
}
#endif
