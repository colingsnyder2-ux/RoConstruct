#include <afxwin.h>
#include "VersionInfo.h"

CVersionInfo::CVersionInfo()
    : m_wLangID(0), m_pVerData(NULL)
{
    Unload();
}
void CVersionInfo::Unload()
{
    m_pffi = NULL;
    if (m_pVerData) { delete[] m_pVerData; m_pVerData = NULL; }
    m_wLangID = 0;
    m_wCharset = 1252;
    m_pTranslations = NULL;
    m_nTranslations = 0;
}
CVersionInfo::~CVersionInfo() { Unload(); }
int CVersionInfo::Load(HINSTANCE module)
{
    char name[500];
    GetModuleFileName(module, name, sizeof(name));
    CString file(name);
    return Load(file);
}
int CVersionInfo::Load(const CString& fileName)
{
    m_pffi = NULL;
    if (m_pVerData) { delete[] m_pVerData; m_pVerData = NULL; }
    m_wLangID = 0;
    m_wCharset = 1252;
    m_pTranslations = NULL;
    m_nTranslations = 0;
    CString file(fileName);
    int result = 0;
    DWORD handle = 0;
    DWORD size = GetFileVersionInfoSize(file.GetBuffer(), &handle);
    if (size) {
        m_pVerData = new BYTE[size];
        if (GetFileVersionInfo(file.GetBuffer(), handle, size, m_pVerData)) {
            UINT length = 0;
            if (VerQueryValue(m_pVerData, "\\", (LPVOID*)&m_pffi, &length)) {
                if (VerQueryValue(m_pVerData, "\\VarFileInfo\\Translation", (LPVOID*)&m_pTranslations, &length) && length >= 4) {
                    m_nTranslations = length / 4;
                    m_wLangID = m_pTranslations[0].m_wLangID;
                    m_wCharset = m_pTranslations[0].m_wCodePage;
                }
                result = 1;
            }
        }
    }
    if (!result && m_pVerData) {
        delete[] m_pVerData;
        m_pVerData = NULL;
    }
    return result;
}
CString CVersionInfo::GetValue(const CString& key)
{
    CString result;
    CString query;
    query.Format("\\StringFileInfo\\%04x%04x\\%s", m_wLangID, m_wCharset, key);
    LPCTSTR value = NULL;
    UINT length = 0;
    if (VerQueryValue(m_pVerData, query.GetBuffer(), (LPVOID*)&value, &length))
        result = value;
    return result;
}
CString CVersionInfo::GetFileVersionAsString()
{
    CString key("FileVersion");
    return GetValue(key);
}

#include "CFileVersionInfo.h"

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
