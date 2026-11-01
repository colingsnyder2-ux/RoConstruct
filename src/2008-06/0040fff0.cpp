// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_king_originala_browser_dispatch_4935761f6beb402b.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#ifndef _AFXDLL
#define _AFXDLL
#endif
#include <afxwin.h>
#include <atlbase.h>
#include <atlcom.h>
MIDL_INTERFACE("E2ECE10D-9997-414B-B40B-0928B8F3CADB") IBrowserViewExternal:IDispatch {
 STDMETHOD(get_IsRobloxIDE)(VARIANT_BOOL*)=0;
 STDMETHOD(GetApp)(IDispatch**)=0;
};
struct __declspec(uuid("DD754D30-321A-45A2-A40C-75783AFABFAB")) _IBrowserViewExternalEvents;
extern const CLSID CLSID_BrowserViewExternal;
extern const IID IID_IBrowserViewExternal;
extern const GUID LIBID_RobloxLib;
template<class T>class CProxy_IBrowserViewExternalEvents:
 public ATL::IConnectionPointImpl<T,&__uuidof(_IBrowserViewExternalEvents),ATL::CComDynamicUnkArray> {};
class ATL_NO_VTABLE CBrowserViewExternal:
 public ATL::CComObjectRootEx<ATL::CComSingleThreadModel>,
 public ATL::CComCoClass<CBrowserViewExternal,&CLSID_BrowserViewExternal>,
 public ATL::ISupportErrorInfoImpl<&IID_IBrowserViewExternal>,
 public ATL::IConnectionPointContainerImpl<CBrowserViewExternal>,
 public CProxy_IBrowserViewExternalEvents<CBrowserViewExternal>,
 public ATL::IDispatchImpl<IBrowserViewExternal,&IID_IBrowserViewExternal,&LIBID_RobloxLib,1,0> {
public:
 VARIANT_BOOL isIDE;
 CBrowserViewExternal():isIDE(VARIANT_FALSE){}
 STDMETHOD(get_IsRobloxIDE)(VARIANT_BOOL*);
 STDMETHOD(GetApp)(IDispatch**);
 BEGIN_COM_MAP(CBrowserViewExternal)
  COM_INTERFACE_ENTRY(IBrowserViewExternal)
  COM_INTERFACE_ENTRY(ISupportErrorInfo)
  COM_INTERFACE_ENTRY(IConnectionPointContainer)
 END_COM_MAP()
 BEGIN_CONNECTION_POINT_MAP(CBrowserViewExternal)
  CONNECTION_POINT_ENTRY(__uuidof(_IBrowserViewExternalEvents))
 END_CONNECTION_POINT_MAP()
};
extern char CBrowserView_typeDescriptor[];
extern char CIDEBrowserView_typeDescriptor[];
// Native helper second word is unused; preserve its observed cdecl ABI.
HRESULT __cdecl nativeCreateBrowserExternal(CBrowserViewExternal** result,BOOL) {
 HRESULT status=E_OUTOFMEMORY;
 ATL::CComObjectNoLock<CBrowserViewExternal>* object=0;
 try {object=new ATL::CComObjectNoLock<CBrowserViewExternal>();}
 catch(CException* exception){exception->Delete();}
 if(object) {
  object->SetVoid(NULL);
  object->InternalFinalConstructAddRef();
  status=object->_AtlInitialConstruct();
  if(SUCCEEDED(status))status=object->FinalConstruct();
  object->InternalFinalConstructRelease();
  if(status!=S_OK){delete object;object=0;}
 }
 *result=object;
 return status;
}
struct BrowserDispatchView {
 char prefix[0x2c4];
 ATL::CComPtr<IDispatch> browser;
 HRESULT getExternal(IDispatch**);
};
HRESULT BrowserDispatchView::getExternal(IDispatch** result) {
 if(!browser) {
  CBrowserViewExternal* object;
  HRESULT status=nativeCreateBrowserExternal(&object,FALSE);
  if(status)return status;
  object->isIDE=__RTDynamicCast(this,0,CBrowserView_typeDescriptor,CIDEBrowserView_typeDescriptor,0)?VARIANT_TRUE:VARIANT_FALSE;
  browser=static_cast<IBrowserViewExternal*>(object);
 }
 return browser.CopyTo(result);
}
