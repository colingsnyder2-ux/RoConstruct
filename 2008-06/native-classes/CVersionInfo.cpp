// Recovered against 2008-06, based on available PJ Naughter/OpenRBX implementation.
// >>> native-status (generated) -- do not edit >>>
// CVersionInfo | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by colin (chatgpt:gpt-6.1-sol)
// <<< native-status | src 68d5dac6 | roc native-status --write
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
