// from server: 100% by EspClaude
// roc 2007-08 004086a0  CComBSTR::operator=(LPCSTR) with inlined ATL A2WBSTR (codegen analog)
typedef wchar_t* BSTR;
typedef const char* LPCSTR;
typedef unsigned int UINT;
extern "C" __declspec(dllimport) BSTR __stdcall SysAllocStringLen(const wchar_t*, unsigned int);
extern "C" __declspec(dllimport) void __stdcall SysFreeString(BSTR);
extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int, unsigned long, const char*, int, wchar_t*, int);

namespace ATL {
__declspec(noreturn) void __stdcall AtlThrowImpl(long hr);
// codepage comes from call [0x8bab64]: a .data function pointer (initialised to 0x724e07), not an IAT import
typedef UINT (__stdcall *ATLGETTHREADACP)();
extern ATLGETTHREADACP g_pfnGetThreadACP;
inline UINT __stdcall _AtlGetConversionACP() throw() { return g_pfnGetThreadACP(); }

class CCRTAllocator;
template<class Allocator>
class CAtlSafeAllocBufferManager {
    void* m_pHead;
public:
    CAtlSafeAllocBufferManager() : m_pHead(0) {}
    ~CAtlSafeAllocBufferManager() throw();
};

__forceinline BSTR A2WBSTR(LPCSTR lp, int nLen = -1)
{
    if (lp == 0 || nLen == 0)
        return 0;
    int _convert_ex = 0; (_convert_ex);
    UINT _acp_ex = _AtlGetConversionACP(); (_acp_ex);
    CAtlSafeAllocBufferManager<CCRTAllocator> _AtlSafeAllocaManager;
    BSTR str = 0;
    int nConvertedLen = MultiByteToWideChar(_acp_ex, 0, lp, nLen, 0, 0);
    int nAllocLen = nConvertedLen;
    if (nLen == -1)
        nAllocLen -= 1;
    str = ::SysAllocStringLen(0, nAllocLen);
    if (str != 0) {
        int nResult = MultiByteToWideChar(_acp_ex, 0, lp, nLen, str, nConvertedLen);
        if (nResult != nConvertedLen) {
            SysFreeString(str);
            return 0;
        }
    }
    return str;
}

class CComBSTR {
public:
    BSTR m_str;
    CComBSTR& operator=(LPCSTR pSrc);
};

CComBSTR& CComBSTR::operator=(LPCSTR pSrc)
{
    ::SysFreeString(m_str);
    m_str = A2WBSTR(pSrc);
    if (!m_str && pSrc != 0)
        AtlThrowImpl(0x8007000e);
    return *this;
}
}
