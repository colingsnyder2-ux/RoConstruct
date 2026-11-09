// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_80d1ffb284fd9ea1.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <boost/shared_ptr.hpp>

template<class T>
class CStringT {
    T* m_pszData;
public:
    __declspec(noinline) CStringT() { m_pszData = 0; }
    __declspec(noinline) CStringT(const T* s) { m_pszData = (T*)s; }
    __declspec(noinline) ~CStringT() throw() { m_pszData = 0; }
    __declspec(noinline) operator const T*() const throw() { return m_pszData; }
    __declspec(noinline) int GetLength() const throw() { return 0; }
    __declspec(noinline) T* GetBuffer(int n) { return m_pszData + n; }
    __declspec(noinline) void ReleaseBuffer(int n = -1) { m_pszData += n; }
};
extern template class __declspec(dllimport) CStringT<char>;
typedef CStringT<char> CString;

extern "C" __declspec(dllimport) int __stdcall PathRemoveFileSpecA(char*);

struct CWinApp {
    unsigned char padding[0x44];
    void* m_hInstance;
};

struct AFX_MODULE_STATE {
    void* reserved;
    CWinApp* m_pCurrentWinApp;
};

AFX_MODULE_STATE* __stdcall AfxGetModuleState();
inline CWinApp* AfxGetApp() { return AfxGetModuleState()->m_pCurrentWinApp; }
void __stdcall AfxGetModuleFileName(void* hInst, CString& strFileName);
CString __cdecl operator+(const CString&, const char*);

struct Metadata {
    void load(std::string);
};

extern boost::shared_ptr<Metadata> __cdecl createMetadata();

boost::shared_ptr<Metadata> __cdecl getMetadata()
{
    static boost::shared_ptr<Metadata> cached;

    if (!cached.get()) {
        cached = createMetadata();

        CString filename;
        AfxGetModuleFileName(AfxGetApp()->m_hInstance, filename);
        CString directory((const char*)filename);
        PathRemoveFileSpecA(directory.GetBuffer(directory.GetLength()));
        directory.ReleaseBuffer();
        cached->load((const char*)(directory + "\\ReflectionMetadata.xml"));
    }

    return cached;
}
