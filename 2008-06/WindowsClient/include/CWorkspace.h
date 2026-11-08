#pragma once
// >>> native-status (generated) -- do not edit >>>
// CWorkspace | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src a15cc430 | roc native-status --write
#include <atlbase.h>
#include <atlcom.h>
#include <objsafe.h>
#include <boost/shared_ptr.hpp>
#include <iosfwd>
#include <memory>
#include "util/Events.h"
#include "RobloxLib.h"

extern const IID IID_IWorkspace;
extern const IID LIBID_RobloxLib;
extern const CLSID CLSID_Workspace;

// Native RTTI and constructor 0046ab60 establish this eight-byte base.
// Safety method bodies remain separate recovery work.
template<class Derived, DWORD Supported>
class IObjectSafetyRobloxImpl : public IObjectSafety {
public:
    DWORD currentSafety;
    IObjectSafetyRobloxImpl() : currentSafety(0) {}
    HRESULT checkSite(); // 00403b60; implementation pending.
    HRESULT getSiteUrl(ATL::CComBSTR&, DWORD&); // 00403210.
    STDMETHOD(GetInterfaceSafetyOptions)(REFIID, DWORD*, DWORD*);
    STDMETHOD(SetInterfaceSafetyOptions)(REFIID, DWORD, DWORD);
};

class XmlElement;

namespace RBX {
    class ContentId;
    class DataModel;
    class RunService;
    class Selection;
    class SelectionChanged;
    class Workspace;
    class DrawChanged;
}

// Inactive candidate. Bases follow original CComObject<CWorkspace> RTTI;
// member ownership follows 0046ab60/0046a9b0/0046b5c0 and the RunService trace.
class ATL_NO_VTABLE CWorkspace :
    public ATL::IDispatchImpl<IWorkspace, &IID_IWorkspace, &LIBID_RobloxLib, 1, 2>,
    public ATL::CComObjectRootEx<ATL::CComSingleThreadModel>,
    public ATL::CComCoClass<CWorkspace, &CLSID_Workspace>,
    public ATL::ISupportErrorInfoImpl<&IID_IWorkspace>,
    public IObjectSafetyRobloxImpl<CWorkspace, 1>,
    public ATL::IObjectWithSiteImpl<CWorkspace>,
    public RBX::Listener<RBX::Selection, RBX::SelectionChanged>,
    public RBX::Listener<RBX::Workspace, RBX::DrawChanged> {
public:
    BEGIN_COM_MAP(CWorkspace)
        COM_INTERFACE_ENTRY(IWorkspace)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(ISupportErrorInfo)
    END_COM_MAP()
    DECLARE_PROTECT_FINAL_CONSTRUCT()
    HRESULT FinalConstruct();
    STDMETHOD(SaveToFile)(BSTR);
    STDMETHOD(SaveSelectionToFile)(BSTR);
    STDMETHOD(Insert)(BSTR);
    STDMETHOD(Write)(IContent**);
    STDMETHOD(WriteSelection)(IContent**);
    HRESULT execScript(const char*, VARIANT, VARIANT, VARIANT, VARIANT, SAFEARRAY**);
    STDMETHOD(ExecScript)(BSTR, VARIANT, VARIANT, VARIANT, VARIANT, SAFEARRAY**);
    STDMETHOD(ExecUrlScript)(BSTR, VARIANT, VARIANT, VARIANT, VARIANT, SAFEARRAY**);
    STDMETHOD(Close)();
    virtual void onEvent(const RBX::Selection*, RBX::SelectionChanged);
    virtual void onEvent(const RBX::Workspace*, RBX::DrawChanged);
    boost::shared_ptr<RBX::DataModel> dataModel;
    boost::shared_ptr<RBX::RunService> runService;
    CWorkspace();
    boost::shared_ptr<RBX::DataModel> getDataModel();
    RBX::Workspace* getWorkspace();
    void cleanup();
    std::auto_ptr<XmlElement> writeXmlModel();
    std::auto_ptr<XmlElement> writeXmlSelection();
    HRESULT write(XmlElement*, std::ostream&);
    void load(std::istream&); // 0046aa70; original symbol linkage pending.
    void insert(RBX::ContentId, bool);
    void insert(std::istream&, bool); // 0046b9d0; implementation pending.
};
