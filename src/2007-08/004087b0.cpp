// from server: 100% by EspClaude
// roc 2007-08 004087b0  unit: VCApp::?$CComObject  size: 445 bytes
// Rewritten from target disassembly (objdump of clients/2007-08/Roblox.exe):
//   AFX_MANAGE_STATE(AfxGetStaticModuleState()) [0x62ff44, ctor 0x62ff3e, inlined dtor -> 0x62ff38]
//   0x41bd80(url) cdecl -> HRESULT; on failure CString msg (MFC80 #310) .Format("Untrusted Url: %s" @0x7851b8,
//   CString(url) [#300]) [#2322], ~CString [#578], operator PCXSTR [#876], 0x429220(&0x790290, msg, hr) cdecl.
//   Else: msi #168 MsiEnableLogA(0x1000, (LPCSTR)0x408460() [returns CString by value], 0),
//   msi #141 MsiSetInternalUI(2, 0), msi #87 MsiInstallProductA(CString(url), "REINSTALL=ALL REINSTALLMODE=vamus" @0x785194);
//   r != 0 && r != 0x669 -> 0x429220(&0x790290, "MsiInstallProduct failed" @0x785178, r).
typedef wchar_t OLECHAR;
typedef OLECHAR* BSTR;
typedef long HRESULT;
struct _GUID;

class CString;
// MFC80 #578 (CStringT destructor) reached through its IAT slot as a pointer variable, as in the
// accepted sibling 00409310 (same unit); the target never caches this import address in a register.
extern void (__thiscall *CString_Destroy)(CString*);

class CString
{
public:
    __declspec(dllimport) CString();
    __declspec(dllimport) CString(const wchar_t* psz);
    ~CString() throw() { CString_Destroy(this); }
    __declspec(dllimport) void __cdecl Format(const char* pszFormat, ...);
    __declspec(dllimport) operator const char*() const throw();
private:
    char* m_pszData;
};

// The formatted message: same MFC80 imports (#310 ctor, #2322 Format, #876, #578 dtor), but its
// destructor is a plain dllimport throw() call (no EH state reset before it in the target).
class CMessage
{
public:
    __declspec(dllimport) CMessage();
    __declspec(dllimport) ~CMessage() throw();
    __declspec(dllimport) void __cdecl Format(const char* pszFormat, ...);
    __declspec(dllimport) operator const char*() const throw();
private:
    char* m_pszData;
};

struct AFX_MODULE_STATE;
struct _AFX_THREAD_STATE { void* vtbl; AFX_MODULE_STATE* m_pModuleState; };
AFX_MODULE_STATE* __stdcall AfxGetStaticModuleState();
int __stdcall AfxDeactivateActCtx(unsigned long dwFlags, unsigned long ulCookie);

class AFX_MAINTAIN_STATE2
{
public:
    explicit AFX_MAINTAIN_STATE2(AFX_MODULE_STATE* pModuleState) throw();
    ~AFX_MAINTAIN_STATE2()
    {
        if (m_pThreadState != 0)
            m_pThreadState->m_pModuleState = m_pPrevModuleState;
        if (m_bValidActCtxCookie)
            AfxDeactivateActCtx(0, m_ulActCtxCookie);
    }
protected:
    AFX_MODULE_STATE* m_pPrevModuleState;
    _AFX_THREAD_STATE* m_pThreadState;
    unsigned long m_ulActCtxCookie;
    int m_bValidActCtxCookie;
};

extern "C" unsigned int __stdcall MsiEnableLogA(unsigned long dwLogMode, const char* szLogFile, unsigned long dwLogAttributes);
extern "C" int __stdcall MsiSetInternalUI(int dwUILevel, void** phWnd);
extern "C" unsigned int __stdcall MsiInstallProductA(const char* szPackagePath, const char* szCommandLine);

HRESULT CheckUrl(BSTR url);                                       // 0x41bd80
CMessage GetMsiLogFile();                                         // 0x408460 (returns the string by value)
HRESULT ReportError(const _GUID& iid, const char* desc, HRESULT hr); // 0x429220
extern const _GUID g_installerIID;                                // 0x790290

struct VCApp_Installer
{
    HRESULT __stdcall Install(BSTR url);
};

HRESULT __stdcall VCApp_Installer::Install(BSTR url)
{
    AFX_MAINTAIN_STATE2 _ctlState(AfxGetStaticModuleState());
    HRESULT hr = CheckUrl(url);
    if (hr != 0)
    {
        CMessage msg;
        msg.Format("Untrusted Url: %s", CString(url));
        return ReportError(g_installerIID, msg, hr);
    }
    MsiEnableLogA(0x1000, GetMsiLogFile(), 0);
    MsiSetInternalUI(2, 0);
    unsigned int r = MsiInstallProductA(CString(url), "REINSTALL=ALL REINSTALLMODE=vamus");
    if (r != 0 && r != 0x669)
        return ReportError(g_installerIID, "MsiInstallProduct failed", r);
    return 0;
}
