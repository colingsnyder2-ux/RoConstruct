#pragma once
// App COM interface and class; inactive pending complete methods and ABI proof.
#include "CWorkspace.h"

enum WindowType { NoWindowType = 0, PlayWindowType = 2 };
typedef WindowType WINDOW_TYPE;
enum ErrorReporting { DontReport = 0, Prompt = 1, Report = 2 };
typedef ErrorReporting ERROR_REPORTING;

struct __declspec(novtable) __declspec(uuid("54F58168-734E-4379-B198-64B0826A002E")) IApp : IDispatch {
    STDMETHOD(CreateGame)(WINDOW_TYPE, IWorkspace**) = 0;
    STDMETHOD(LaunchIDE)() = 0;
    STDMETHOD(get_Version)(BSTR*) = 0;
    STDMETHOD(get_ErrorReporting)(ERROR_REPORTING*) = 0;
    STDMETHOD(get_HasErrorFiles)(VARIANT_BOOL*) = 0;
    STDMETHOD(SendErrorFiles)(BSTR) = 0;
    STDMETHOD(get_IsUploadingErrorFiles)(VARIANT_BOOL*) = 0;
    STDMETHOD(DeleteErrorFiles)() = 0;
    STDMETHOD(ClearFileCache)() = 0;
    STDMETHOD(get_ID)(BSTR*) = 0;
    STDMETHOD(RobloxAuthenticate)(BSTR, BSTR) = 0;
};

extern const IID IID_IApp;
extern const CLSID CLSID_App;

class ATL_NO_VTABLE CApp :
    public ATL::CComObjectRootEx<ATL::CComSingleThreadModel>,
    public ATL::CComCoClass<CApp, &CLSID_App>,
    public ATL::ISupportErrorInfoImpl<&IID_IApp>,
    public IObjectSafetyRobloxImpl<CApp, 1>,
    public ATL::IObjectWithSiteImpl<CApp>,
    public ATL::IDispatchImpl<IApp, &IID_IApp, &LIBID_RobloxLib, 1, 2> {
public:
    DECLARE_REGISTRY_RESOURCEID(110)
    BEGIN_COM_MAP(CApp)
        COM_INTERFACE_ENTRY(IApp)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(ISupportErrorInfo)
        COM_INTERFACE_ENTRY(IObjectWithSite)
        COM_INTERFACE_ENTRY(IObjectSafety)
    END_COM_MAP()
    DECLARE_PROTECT_FINAL_CONSTRUCT()
    static void uploadErrorFiles(const char* url);
    STDMETHOD(CreateGame)(WINDOW_TYPE, IWorkspace**);
    STDMETHOD(LaunchIDE)();
    STDMETHOD(get_Version)(BSTR*);
    STDMETHOD(get_ErrorReporting)(ERROR_REPORTING*);
    STDMETHOD(get_HasErrorFiles)(VARIANT_BOOL*);
    STDMETHOD(SendErrorFiles)(BSTR);
    STDMETHOD(get_IsUploadingErrorFiles)(VARIANT_BOOL*);
    STDMETHOD(DeleteErrorFiles)();
    STDMETHOD(ClearFileCache)();
    STDMETHOD(get_ID)(BSTR*);
    STDMETHOD(RobloxAuthenticate)(BSTR, BSTR);
};
