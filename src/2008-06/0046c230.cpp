// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_king_originala_workspace_variant_11643d6e9fac571f.cpp

// Candidate translation unit (score above; library headers required).
#ifndef NATIVE_WORKSPACE_VARIANT_INTERFACE
#define NATIVE_WORKSPACE_VARIANT_INTERFACE
#include <windows.h>
#include <oaidl.h>
struct IContent;
// Native RobloxLib1.3 TYPELIB resource: IDispatch plus these eight APIs.
struct __declspec(uuid("0730C3C6-092D-4F45-B8B9-BDEB82DE1C7B")) IWorkspace:IDispatch {
    STDMETHOD(SaveToFile)(BSTR)=0;
    STDMETHOD(SaveSelectionToFile)(BSTR)=0;
    STDMETHOD(Insert)(BSTR)=0;
    STDMETHOD(Write)(IContent**)=0;
    STDMETHOD(WriteSelection)(IContent**)=0;
    STDMETHOD(ExecScript)(BSTR,VARIANT,VARIANT,VARIANT,VARIANT,SAFEARRAY**)=0;
    STDMETHOD(ExecUrlScript)(BSTR,VARIANT,VARIANT,VARIANT,VARIANT,SAFEARRAY**)=0;
    STDMETHOD(Close)()=0;
};
#endif

// Consumed exported DLL APIs. SDK probes establish string28/alignment4 and
// CStringA4; no private string members are accessed by this translation unit.
namespace std {
template<class C>struct char_traits;
template<class C>class allocator;
template<class C,class T,class A>class __declspec(dllimport) basic_string {
    unsigned long opaqueStorage[7];
public:
    basic_string(const C*);
    ~basic_string() throw();
    const C* c_str() const;
    unsigned int find(const C*,unsigned int,unsigned int) const;
};
typedef basic_string<char,char_traits<char>,allocator<char> > string;
}
namespace ATL {
template<class C>class ChTraitsCRT;
template<class C,bool mfc>class CSimpleStringT {
    C* m_pszData;
public:
    __declspec(dllimport) operator const C*() const throw();
};
}
template<class C,class Traits=ATL::ChTraitsCRT<C> >class StrTraitMFC_DLL;
namespace ATL {
template<class C,class Traits>class CStringT:public CSimpleStringT<C,true> {
public:
    __declspec(dllimport) CStringT(const wchar_t*);
    __declspec(dllimport) ~CStringT() throw();
};
}
typedef ATL::CStringT<char,StrTraitMFC_DLL<char> > CStringA;
class AFX_MODULE_STATE;
class _AFX_THREAD_STATE;
AFX_MODULE_STATE* __stdcall AfxGetAppModuleState();
BOOL __stdcall AfxDeactivateActCtx(DWORD,ULONG_PTR);
struct NativeAfxThreadModuleView {char prefix[4];AFX_MODULE_STATE* moduleState;};
// Supplied afxstat_.h/afxwin1.inl: complete16B guard and its normal destructor.
struct AFX_MAINTAIN_STATE2 {
    explicit AFX_MAINTAIN_STATE2(AFX_MODULE_STATE*) throw();
    ~AFX_MAINTAIN_STATE2() {
        if(m_pThreadState)
            reinterpret_cast<NativeAfxThreadModuleView*>(m_pThreadState)->moduleState=m_pPrevModuleState;
        if(m_bValidActCtxCookie)
            AfxDeactivateActCtx(0,m_ulActCtxCookie);
    }
protected:
    AFX_MODULE_STATE* m_pPrevModuleState;
    _AFX_THREAD_STATE* m_pThreadState;
    ULONG_PTR m_ulActCtxCookie;
    BOOL m_bValidActCtxCookie;
};
bool __cdecl nativeIsUrl(const std::string&);
struct VCWorkspaceView:IWorkspace {
    STDMETHOD(ExecScript)(BSTR,VARIANT,VARIANT,VARIANT,VARIANT,SAFEARRAY**);
    HRESULT executeText(const char*,VARIANT,VARIANT,VARIANT,VARIANT,SAFEARRAY**);
};
STDMETHODIMP VCWorkspaceView::ExecScript(BSTR script,VARIANT a,VARIANT b,VARIANT c,VARIANT d,SAFEARRAY** resultArray) {
    AFX_MAINTAIN_STATE2 state(AfxGetAppModuleState());
    BSTR original=script;
    std::string text(static_cast<const char*>(CStringA(original)));
    if(nativeIsUrl(text))
        return ExecUrlScript(original,a,b,c,d,resultArray);
    return executeText(text.c_str(),a,b,c,d,resultArray);
}
