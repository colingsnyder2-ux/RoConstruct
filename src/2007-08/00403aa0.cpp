// from server: 99% by EspClaude
// from server: 100% by colin
// roc 2008-06 00403210  unit: ATL::CComClassFactory  size: 505 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00403210
//
// 00403210  6aff                 push -1
// 00403212  68f8cb7b00           push 0x7bcbf8
// 00403217  64a100000000         mov eax, dword ptr fs:[0]
// 0040321d  50                   push eax
// 0040321e  64892500000000       mov dword ptr fs:[0], esp
// 00403225  83ec0c               sub esp, 0xc
// 00403228  53                   push ebx
// 00403229  33db                 xor ebx, ebx
// 0040322b  56                   push esi
// 0040322c  895c2408             mov dword ptr [esp + 8], ebx
// 00403230  895c241c             mov dword ptr [esp + 0x1c], ebx
// 00403234  3bcb                 cmp ecx, ebx
// 00403236  7405                 je 0x40323d
// 00403238  8d41f8               lea eax, [ecx - 8]
// 0040323b  eb02                 jmp 0x40323f
// 0040323d  33c0                 xor eax, eax
// 0040323f  8b4810               mov ecx, dword ptr [eax + 0x10]
// 00403242  8d542408             lea edx, [esp + 8]
// 00403246  83c010               add eax, 0x10
// 00403249  52                   push edx
// 0040324a  68a8af8000           push 0x80afa8
// 0040324f  50                   push eax
// 00403250  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00403253  ffd0                 call eax
// 00403255  8bf0                 mov esi, eax
// 00403257  3bf3                 cmp esi, ebx
// 00403259  7d2d                 jge 0x403288
// 0040325b  8b442408             mov eax, dword ptr [esp + 8]
// 0040325f  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00403267  3bc3                 cmp eax, ebx
// 00403269  7408                 je 0x403273
// 0040326b  8b08                 mov ecx, dword ptr [eax]
// 0040326d  8b5108               mov edx, dword ptr [ecx + 8]
// 00403270  50                   push eax
// 00403271  ffd2                 call edx
// 00403273  8bc6                 mov eax, esi
// 00403275  5e                   pop esi
// 00403276  5b                   pop ebx
// 00403277  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0040327b  64890d00000000       mov dword ptr fs:[0], ecx
// 00403282  83c418               add esp, 0x18
// 00403285  c20800               ret 8
// 00403288  57                   push edi
// 00403289  895c2410             mov dword ptr [esp + 0x10], ebx
// 0040328d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00403291  8b08                 mov ecx, dword ptr [eax]
// 00403293  8d542410             lea edx, [esp + 0x10]
// 00403297  52                   push edx
// 00403298  68ac018500           push 0x8501ac
// 0040329d  689c018500           push 0x85019c
// 004032a2  50                   push eax
// 004032a3  8b410c               mov eax, dword ptr [ecx + 0xc]
// 004032a6  c644243001           mov byte ptr [esp + 0x30], 1
// 004032ab  ffd0                 call eax
// 004032ad  8bf8                 mov edi, eax
// 004032af  3bfb                 cmp edi, ebx
// 004032b1  8b442410             mov eax, dword ptr [esp + 0x10]
// 004032b5  7c54                 jl 0x40330b
// 004032b7  8b742428             mov esi, dword ptr [esp + 0x28]
// 004032bb  8b08                 mov ecx, dword ptr [eax]
// 004032bd  8b5178               mov edx, dword ptr [ecx + 0x78]
// 004032c0  56                   push esi
// 004032c1  50                   push eax
// 004032c2  ffd2                 call edx
// 004032c4  85c0                 test eax, eax
// 004032c6  7c3f                 jl 0x403307
// 004032c8  895c2414             mov dword ptr [esp + 0x14], ebx
// 004032cc  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004032d0  8b08                 mov ecx, dword ptr [eax]
// 004032d2  8d542414             lea edx, [esp + 0x14]
// 004032d6  52                   push edx
// 004032d7  688c018500           push 0x85018c
// 004032dc  688c018500           push 0x85018c
// 004032e1  50                   push eax
// 004032e2  8b410c               mov eax, dword ptr [ecx + 0xc]
// 004032e5  c644243002           mov byte ptr [esp + 0x30], 2
// 004032ea  ffd0                 call eax
// 004032ec  8bf8                 mov edi, eax
// 004032ee  3bfb                 cmp edi, ebx
// 004032f0  7d57                 jge 0x403349
// 004032f2  8b442414             mov eax, dword ptr [esp + 0x14]
// 004032f6  c644242001           mov byte ptr [esp + 0x20], 1
// 004032fb  3bc3                 cmp eax, ebx
// 004032fd  7408                 je 0x403307
// 004032ff  8b08                 mov ecx, dword ptr [eax]
// 00403301  8b5108               mov edx, dword ptr [ecx + 8]
// 00403304  50                   push eax
// 00403305  ffd2                 call edx
// 00403307  8b442410             mov eax, dword ptr [esp + 0x10]
// 0040330b  885c2420             mov byte ptr [esp + 0x20], bl
// 0040330f  3bc3                 cmp eax, ebx
// 00403311  7408                 je 0x40331b
// 00403313  8b08                 mov ecx, dword ptr [eax]
// 00403315  8b5108               mov edx, dword ptr [ecx + 8]
// 00403318  50                   push eax
// 00403319  ffd2                 call edx
// 0040331b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040331f  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00403327  3bc3                 cmp eax, ebx
// 00403329  7408                 je 0x403333
// 0040332b  8b08                 mov ecx, dword ptr [eax]
// 0040332d  8b5108               mov edx, dword ptr [ecx + 8]
// 00403330  50                   push eax
// 00403331  ffd2                 call edx
// 00403333  8bc7                 mov eax, edi
// 00403335  5f                   pop edi
// 00403336  5e                   pop esi
// 00403337  5b                   pop ebx
// 00403338  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0040333c  64890d00000000       mov dword ptr fs:[0], ecx
// 00403343  83c418               add esp, 0x18
// 00403346  c20800               ret 8
// 00403349  8b06                 mov eax, dword ptr [esi]
// 0040334b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0040334f  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00403353  8b11                 mov edx, dword ptr [ecx]
// 00403355  53                   push ebx
// 00403356  56                   push esi
// 00403357  50                   push eax
// 00403358  8b4214               mov eax, dword ptr [edx + 0x14]
// 0040335b  51                   push ecx
// 0040335c  ffd0                 call eax
// 0040335e  8bf0                 mov esi, eax
// 00403360  3bf3                 cmp esi, ebx
// 00403362  8b442414             mov eax, dword ptr [esp + 0x14]
// 00403366  c644242001           mov byte ptr [esp + 0x20], 1
// 0040336b  7d4e                 jge 0x4033bb
// 0040336d  3bc3                 cmp eax, ebx
// 0040336f  7408                 je 0x403379
// 00403371  8b08                 mov ecx, dword ptr [eax]
// 00403373  8b5108               mov edx, dword ptr [ecx + 8]
// 00403376  50                   push eax
// 00403377  ffd2                 call edx
// 00403379  8b442410             mov eax, dword ptr [esp + 0x10]
// 0040337d  885c2420             mov byte ptr [esp + 0x20], bl
// 00403381  3bc3                 cmp eax, ebx
// 00403383  7408                 je 0x40338d
// 00403385  8b08                 mov ecx, dword ptr [eax]
// 00403387  8b5108               mov edx, dword ptr [ecx + 8]
// 0040338a  50                   push eax
// 0040338b  ffd2                 call edx
// 0040338d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00403391  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00403399  3bc3                 cmp eax, ebx
// 0040339b  7408                 je 0x4033a5
// 0040339d  8b08                 mov ecx, dword ptr [eax]
// 0040339f  8b5108               mov edx, dword ptr [ecx + 8]
// 004033a2  50                   push eax
// 004033a3  ffd2                 call edx
// 004033a5  5f                   pop edi
// 004033a6  8bc6                 mov eax, esi
// 004033a8  5e                   pop esi
// 004033a9  5b                   pop ebx
// 004033aa  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004033ae  64890d00000000       mov dword ptr fs:[0], ecx
// 004033b5  83c418               add esp, 0x18
// 004033b8  c20800               ret 8
// 004033bb  3bc3                 cmp eax, ebx
// 004033bd  7408                 je 0x4033c7
// 004033bf  8b08                 mov ecx, dword ptr [eax]
// 004033c1  8b5108               mov edx, dword ptr [ecx + 8]
// 004033c4  50                   push eax
// 004033c5  ffd2                 call edx
// 004033c7  8b442410             mov eax, dword ptr [esp + 0x10]
// 004033cb  885c2420             mov byte ptr [esp + 0x20], bl
// 004033cf  3bc3                 cmp eax, ebx
// 004033d1  7408                 je 0x4033db
// 004033d3  8b08                 mov ecx, dword ptr [eax]
// 004033d5  8b5108               mov edx, dword ptr [ecx + 8]
// 004033d8  50                   push eax
// 004033d9  ffd2                 call edx
// 004033db  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004033df  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 004033e7  3bc3                 cmp eax, ebx
// 004033e9  7408                 je 0x4033f3
// 004033eb  8b08                 mov ecx, dword ptr [eax]
// 004033ed  8b5108               mov edx, dword ptr [ecx + 8]
// 004033f0  50                   push eax
// 004033f1  ffd2                 call edx
// 004033f3  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004033f7  5f                   pop edi
// 004033f8  5e                   pop esi
// 004033f9  33c0                 xor eax, eax
// 004033fb  5b                   pop ebx
// 004033fc  64890d00000000       mov dword ptr fs:[0], ecx
// 00403403  83c418               add esp, 0x18
// 00403406  c20800               ret 8

// from server: 99% by colin
// roc 2008-06 00403210  unit: CSiteLock<CLauncher>::GetOurUrl  size: 420 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00403210
//
// roc-lang: cpp
// roc-cl: 50727

typedef unsigned long DWORD;
typedef unsigned long ULONG;
typedef long HRESULT;
typedef wchar_t OLECHAR;
struct GUID { unsigned long a; unsigned short b, c; unsigned char d[8]; };
#define FAILED(hr) ((HRESULT)(hr) < 0)
#define S_OK 0

extern "C" const GUID IID_IServiceProvider;
extern "C" const GUID IID_IWebBrowser2;
extern "C" const GUID IID_IInternetSecurityManager;
extern "C" const GUID SID_SWebBrowserApp;
extern "C" const GUID SID_SInternetSecurityManager;

struct IUnknown {
    virtual HRESULT __stdcall QueryInterface(const GUID&, void**) = 0;
    virtual ULONG __stdcall AddRef() = 0;
    virtual ULONG __stdcall Release() = 0;
};

struct IServiceProvider : IUnknown {
    virtual HRESULT __stdcall QueryService(const GUID&, const GUID&, void**) = 0;
};

struct IWebBrowser2 : IUnknown {
    virtual void __stdcall s3() = 0; virtual void __stdcall s4() = 0; virtual void __stdcall s5() = 0;
    virtual void __stdcall s6() = 0; virtual void __stdcall s7() = 0; virtual void __stdcall s8() = 0;
    virtual void __stdcall s9() = 0; virtual void __stdcall s10() = 0; virtual void __stdcall s11() = 0;
    virtual void __stdcall s12() = 0; virtual void __stdcall s13() = 0; virtual void __stdcall s14() = 0;
    virtual void __stdcall s15() = 0; virtual void __stdcall s16() = 0; virtual void __stdcall s17() = 0;
    virtual void __stdcall s18() = 0; virtual void __stdcall s19() = 0; virtual void __stdcall s20() = 0;
    virtual void __stdcall s21() = 0; virtual void __stdcall s22() = 0; virtual void __stdcall s23() = 0;
    virtual void __stdcall s24() = 0; virtual void __stdcall s25() = 0; virtual void __stdcall s26() = 0;
    virtual void __stdcall s27() = 0; virtual void __stdcall s28() = 0; virtual void __stdcall s29() = 0;
    virtual HRESULT __stdcall get_LocationURL(OLECHAR**) = 0;
};

struct IInternetSecurityManager : IUnknown {
    virtual void __stdcall s3() = 0;
    virtual void __stdcall s4() = 0;
    virtual HRESULT __stdcall MapUrlToZone(const OLECHAR*, DWORD*, DWORD) = 0;
};

struct IObjectWithSite : IUnknown {
    virtual HRESULT __stdcall SetSite(IUnknown*) = 0;
    virtual HRESULT __stdcall GetSite(const GUID&, void**) = 0;
};

struct CComBSTR {
    OLECHAR* m_str;
    OLECHAR** operator&() { return &m_str; }
    operator OLECHAR*() const { return m_str; }
};

template <class T>
struct CComPtr {
    T* p;
    CComPtr() : p(0) {}
    ~CComPtr() { if (p) p->Release(); }
    T* operator->() const { return p; }
    T** operator&() { return &p; }
};

template <class T>
class CSiteLock {
public:
    virtual void lock0();
    void* reserved;
    HRESULT GetOurUrl(CComBSTR& bstrURL, DWORD& dwZone)
    {
        HRESULT hr = S_OK;
        CComPtr<IServiceProvider> spSrvProv;

        T* pT = static_cast<T*>(this);
        hr = pT->GetSite(IID_IServiceProvider, (void**)&spSrvProv);
        if (FAILED(hr))
            return hr;

        CComPtr<IWebBrowser2> spWebBrowser;
        hr = spSrvProv->QueryService(SID_SWebBrowserApp, IID_IWebBrowser2, (void**)&spWebBrowser);
        if (FAILED(hr))
            return hr;

        if (FAILED(spWebBrowser->get_LocationURL(&bstrURL)))
            return hr;

        CComPtr<IInternetSecurityManager> spInetSecMgr;
        hr = spSrvProv->QueryService(SID_SInternetSecurityManager, IID_IInternetSecurityManager, (void**)&spInetSecMgr);
        if (FAILED(hr))
            return hr;

        hr = spInetSecMgr->MapUrlToZone(bstrURL, &dwZone, 0);
        if (FAILED(hr))
            return hr;
        return S_OK;
    }
};

struct Root {
    virtual void root0();
    long m_dwRef;
};

class CLauncher : public Root, public CSiteLock<CLauncher>, public IObjectWithSite {
public:
    HRESULT __stdcall QueryInterface(const GUID&, void**);
    ULONG __stdcall AddRef();
    ULONG __stdcall Release();
    HRESULT __stdcall SetSite(IUnknown*);
    HRESULT __stdcall GetSite(const GUID&, void**);
};

template class CSiteLock<CLauncher>;
