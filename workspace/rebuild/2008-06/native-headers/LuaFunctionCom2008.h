#pragma once
// Inactive native 2008-06 recovery: CLuaHtmlView::Binder and CLuaHtmlView::Binder::PropBinding, the two-way binding
// between an HTML <input> element and the string value of one or more Instance properties (CLuaHtmlView unit,
// 0042ac20..0042ced0, together with EventHandler).
//
// Names of the methods are provisional (the binary has no symbol names for them); the classes, their nesting and the
// bases come from RTTI: .?AVBinder@CLuaHtmlView@@ (vtable 00810654: Binder, enable_shared_from_this<Binder> at +4,
// noncopyable at +0xc), sp_counted_impl_p<CLuaHtmlView::Binder::PropBinding> (vtable 00810524) and
// sp_counted_impl_p<CLuaHtmlView::Binder> (vtable 00810538); the bind_t RTTI names in .rdata give the bound
// callables: bind_t<bool, mf0<bool, Binder>, list1<value<Binder*>>> (onchange handler),
// bind_t<void, mf0<void, Binder>, list1<value<shared_ptr<Binder>>>> (the posted update) and
// bind_t<void, void(*)(const PropertyDescriptor*, const PropertyDescriptor&, Binder*),
//        list3<arg<1>, reference_wrapper<const PropertyDescriptor>, value<Binder*>>> (the property-changed slot).
#include "AppLeaves2008/Marshaller2008.h"     // first: MFC/ATL before anything that includes windows.h
#include "AppLeaves2008/EventHandler2008.h"
#include <afxext.h>
#include <afxhtml.h>
#include <atlbase.h>
#include <atlcom.h>
#include <mshtml.h>
#include <list>
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/noncopyable.hpp>
#include <boost/signals/connection.hpp>
#include "v8tree/Instance.h"
#include "script/ThreadRef.h"
#include "security/SecurityContext.h"

namespace RBX { class DataModel; }

struct __declspec(uuid("D5AB3A9C-C462-48BA-A430-34B227340E42")) __declspec(novtable) ILuaFunction : public IDispatch
{
    virtual HRESULT STDMETHODCALLTYPE Call(VARIANT arg1, VARIANT arg2, VARIANT arg3, VARIANT arg4, VARIANT* result) = 0;
};

extern const CLSID CLSID_LuaFunction;

extern const IID IID_ILuaFunction; extern const IID LIBID_RobloxLib;
class ATL_NO_VTABLE CLuaFunction : public ATL::ISupportErrorInfoImpl<&IID_ILuaFunction>, public ATL::IDispatchImpl<ILuaFunction, &IID_ILuaFunction, &LIBID_RobloxLib, 1, 0>, public ATL::CComObjectRootEx<ATL::CComSingleThreadModel>
{
public:
    BEGIN_COM_MAP(CLuaFunction)
 COM_INTERFACE_ENTRY(ILuaFunction)
 COM_INTERFACE_ENTRY(IDispatch)
 COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
    DECLARE_PROTECT_FINAL_CONSTRUCT() // INFERRED: the original keeps the InternalFinalConstructAddRef/Release refcount pair
    CLuaFunction();
    STDMETHOD(Call)(VARIANT arg1, VARIANT arg2, VARIANT arg3, VARIANT arg4, VARIANT* result);
    boost::shared_ptr<RBX::DataModel> dataModel;
    RBX::Lua::FunctionRef function;
    RBX::Security::Identities identity;
};


