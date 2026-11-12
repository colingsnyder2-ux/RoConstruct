// from server: 100% by EspClaude
// roc 2007-08 00408970  unit: VCApp::?$CComObject  size: 241 bytes
// Shape (read from target): AFX_MANAGE_STATE(AfxGetStaticModuleState()) [0x62ff44 -> ctor 0x62ff3e],
// AfxGetModuleState() [0x62ff02] ->m_pCurrentWinApp (+4), std::string at app+0xf0, c_str via MSVCP80 IAT,
// CComBSTR(LPCSTR) -> A2WBSTR(lp,-1) [0x401180], AtlThrow(E_OUTOFMEMORY) [0x401000],
// CComBSTR::CopyTo, ~CComBSTR (SysFreeString #6), ~AFX_MAINTAIN_STATE2 inlined (AfxDeactivateActCtx #6754).
// std::string::c_str is called through the MSVCP80 IAT (not inlined in the target), so declare it
// as an out-of-line dllimport member of the exported basic_string<char> instantiation.
namespace std {
template<class _Elem> struct char_traits;
template<class _Ty> class allocator;
template<class _Elem, class _Traits, class _Ax> class basic_string
{
public:
    __declspec(dllimport) const _Elem* c_str() const;
};
typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

typedef unsigned short OLECHAR;
typedef OLECHAR* BSTR;
typedef long HRESULT;

extern "C" __declspec(dllimport) BSTR __stdcall SysAllocStringByteLen(const char* psz, unsigned int len);
extern "C" __declspec(dllimport) void __stdcall SysFreeString(BSTR bstr);
extern "C" __declspec(dllimport) unsigned int __stdcall SysStringByteLen(BSTR bstr);

BSTR A2WBSTR(const char* lp, int nLen = -1);
__declspec(noreturn) void __stdcall AtlThrowImpl(HRESULT hr);

struct AFX_MODULE_STATE;
struct _AFX_THREAD_STATE { void* vtbl; // m_pModuleState at +4 (mov [eax+4],ecx)
    AFX_MODULE_STATE* m_pModuleState; };
struct CWinApp;
struct AFX_MODULE_STATE { void* vtbl; CWinApp* m_pCurrentWinApp; };

AFX_MODULE_STATE* __stdcall AfxGetStaticModuleState();
AFX_MODULE_STATE* __stdcall AfxGetModuleState();
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

class CComBSTR
{
public:
    BSTR m_str;
    CComBSTR(const char* pSrc)
    {
        if (pSrc != 0)
        {
            m_str = A2WBSTR(pSrc);
            if (m_str == 0)
                AtlThrowImpl((HRESULT)0x8007000e);
        }
        else
            m_str = 0;
    }
    ~CComBSTR() throw() { ::SysFreeString(m_str); }
    BSTR Copy() const throw()
    {
        if (m_str == 0)
            return 0;
        return ::SysAllocStringByteLen((char*)m_str, ::SysStringByteLen(m_str));
    }
    HRESULT CopyTo(BSTR* pbstr) const throw()
    {
        if (pbstr == 0)
            return (HRESULT)0x80004003;
        *pbstr = Copy();
        if ((*pbstr == 0) && (m_str != 0))
            return (HRESULT)0x8007000e;
        return 0;
    }
};

struct CRobloxApp
{
    char pad[0xf0];
    std::string m_string;   // app+0xf0 (read from lea ecx,[eax+0xf0])
    const std::string& getString() const { return m_string; }
};

struct VCApp_Object
{
    HRESULT __stdcall get_String(BSTR* pVal);
};

HRESULT __stdcall VCApp_Object::get_String(BSTR* pVal)
{
    AFX_MAINTAIN_STATE2 _ctlState(AfxGetStaticModuleState());
    CComBSTR s(((CRobloxApp*)AfxGetModuleState()->m_pCurrentWinApp)->getString().c_str());
    return s.CopyTo(pVal);
}
