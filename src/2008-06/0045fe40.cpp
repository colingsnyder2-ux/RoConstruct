// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /Zp4
// roc-lang: cpp
// afxver_.h sets _AFX_PACKING=4; afxdhtml.h applies that SDK ABI. The fixed
// packing option preserves its genuine declarations without source pragmas.
// Consumed WinSDK declarations; all COM payloads are passed by pointer/ref.
typedef long HRESULT;typedef unsigned long ULONG;typedef unsigned int UINT;
typedef ULONG LCID;typedef long DISPID;typedef wchar_t OLECHAR;
typedef unsigned short WORD;typedef const char*LPCTSTR;
struct _GUID;typedef const _GUID&REFIID;
struct ITypeInfo;struct tagDISPPARAMS;typedef tagDISPPARAMS DISPPARAMS;
struct tagVARIANT;typedef tagVARIANT VARIANT;
struct tagEXCEPINFO;typedef tagEXCEPINFO EXCEPINFO;
#define NULL 0
// Genuine consumed MFC90 RTM afxdhtml.h declarations. Both empty bases are
// explicitly present in that SDK to give the event member-pointer its real
// multiple-inheritance representation; no placeholder virtual methods.
enum DHtmlEventMapEntryType {DHTMLEVENTMAPENTRY_NAME,DHTMLEVENTMAPENTRY_CLASS,
 DHTMLEVENTMAPENTRY_TAG,DHTMLEVENTMAPENTRY_ELEMENT,DHTMLEVENTMAPENTRY_CONTROL,DHTMLEVENTMAPENTRY_END};
struct DHtmlEventMapEntry;
class CDHtmlSinkHandlerBase1 {};
class CDHtmlSinkHandlerBase2 {};
class CDHtmlSinkHandler:public CDHtmlSinkHandlerBase1,public CDHtmlSinkHandlerBase2 {
public:
 virtual __declspec(nothrow) HRESULT __stdcall CDHtmlSinkHandlerQueryInterface(REFIID riid,void**ppvObject)=0;
 virtual ULONG __stdcall AddRef(void)=0;
 virtual ULONG __stdcall Release(void)=0;
 virtual __declspec(nothrow) HRESULT __stdcall GetTypeInfoCount(UINT*pctinfo)=0;
 virtual __declspec(nothrow) HRESULT __stdcall GetTypeInfo(UINT iTInfo,LCID lcid,ITypeInfo**ppTInfo)=0;
 virtual __declspec(nothrow) HRESULT __stdcall GetIDsOfNames(REFIID riid,OLECHAR**rgszNames,UINT cNames,LCID lcid,DISPID*rgDispId)=0;
 virtual __declspec(nothrow) HRESULT __stdcall Invoke(DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS*pDispParams,VARIANT*pVarResult,EXCEPINFO*pExcepInfo,UINT*puArgErr)=0;
 virtual const DHtmlEventMapEntry*GetDHtmlEventMap()=0;
};
struct DHtmlEventMapEntry {
 DHtmlEventMapEntryType nType;
 DISPID dispId;
 LPCTSTR szName;
 void(__stdcall CDHtmlSinkHandler::*pfnEventFunc)();
};
typedef void(__stdcall CDHtmlSinkHandler::*DHEVTFUNCCONTROL)();
// Only the borrowed event-sink interface is needed by this stateless getter.
// The complete containing dialog is neither allocated nor represented.
class EmptyDHtmlEventMap:public CDHtmlSinkHandler {
protected:virtual const DHtmlEventMapEntry*GetDHtmlEventMap();
};
const DHtmlEventMapEntry*EmptyDHtmlEventMap::GetDHtmlEventMap() {
 static const DHtmlEventMapEntry _dhtmlEventEntries[]={
  {DHTMLEVENTMAPENTRY_END,0,NULL,(DHEVTFUNCCONTROL)NULL}
 };
 return _dhtmlEventEntries;
}
typedef char NativeEventEntrySize[sizeof(DHtmlEventMapEntry)==20?1:-1];
typedef char NativeEventMemberSize[sizeof(DHEVTFUNCCONTROL)==8?1:-1];
