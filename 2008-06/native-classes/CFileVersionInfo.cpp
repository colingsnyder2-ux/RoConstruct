// >>> native-status (generated) -- do not edit >>>
// CFileVersionInfo | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 8e7b4c2a | roc native-status --write
#include "CFileVersionInfo.h"

// Create reuses roc_espclaude_43f0d040995d240c.cpp (0046a220).
CFileVersionInfo::CFileVersionInfo() : m_wLang(0), m_lpVersionData(NULL)
{
    Reset();
}

void CFileVersionInfo::Reset()
{
    m_pFixedInfo = NULL;
    if (m_lpVersionData) {
        delete[] m_lpVersionData;
        m_lpVersionData = NULL;
    }
    m_wLang = 0;
    m_wCodePage = 1252;
    m_lpTranslation = NULL;
    m_nTranslations = 0;
}

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

CString CFileVersionInfo::GetVersionInfo(const CString& name)
{
    CString result;
    CString path;
    path.Format("\\StringFileInfo\\%04x%04x\\%s", m_wLang, m_wCodePage, *(const char* const*)&name);
    LPVOID value = NULL;
    UINT length = 0;
    if (VerQueryValue(m_lpVersionData, path.GetBuffer(), &value, &length))
        result = static_cast<LPCTSTR>(value);
    return result;
}

CString CFileVersionInfo::GetFileVersion()
{
    CString name("FileVersion");
    return GetVersionInfo(name);
}
