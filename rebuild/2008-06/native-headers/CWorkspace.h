#pragma once
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
    STDMETHOD(GetInterfaceSafetyOptions)(REFIID, DWORD*, DWORD*);
    STDMETHOD(SetInterfaceSafetyOptions)(REFIID, DWORD, DWORD);
};

class XmlElement;

namespace RBX {
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
    boost::shared_ptr<RBX::DataModel> dataModel;
    boost::shared_ptr<RBX::RunService> runService;
    CWorkspace();
    boost::shared_ptr<RBX::DataModel> getDataModel();
    void cleanup();
    std::auto_ptr<XmlElement> writeXmlModel();
    void load(std::istream&); // 0046aa70; original symbol linkage pending.
    void insert(std::istream&, bool); // 0046b9d0; implementation pending.
};
