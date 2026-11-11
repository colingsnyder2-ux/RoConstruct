#pragma once
// >>> native-status (generated) -- do not edit >>>
// EventHandler2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 6396425d | roc native-status --write
// Inactive native 2008-06 EventHandler (RTTI of vtable 00810598: EventHandler : IDispatch : IUnknown), a COM
// IDispatch sink whose Invoke calls a boost::function0<bool>. Layout from the constructor 0042acb0 (new(0x30) at
// 0042c12a): vptr +0, boost::function0<bool> handler +8 (its manager vtable pointer +8, functor buffer +0x10;
// 0042afc0 is evidence-named ??R?$function0@_NV?$allocator@Vfunction_base@boost@@@std@@@boost@@QBE_NXZ and is
// called with this+8 by Invoke 0042b130), reference count +0x28.
#include <windows.h>
#include <oaidl.h>
#include <boost/function.hpp>

class EventHandler : public IDispatch
{
public:
    explicit EventHandler(boost::function0<bool> handler);   // 0042acb0

    // IUnknown / IDispatch: slots 0..6 = 0042adb0 0042ae10 0042b350 0042ae20 0042ae30 0042ae40 0042b130
    STDMETHOD(QueryInterface)(REFIID riid, void** ppvObject);
    STDMETHOD_(ULONG, AddRef)();
    STDMETHOD_(ULONG, Release)();
    STDMETHOD(GetTypeInfoCount)(UINT* pctinfo);
    STDMETHOD(GetTypeInfo)(UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo);
    STDMETHOD(GetIDsOfNames)(REFIID riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgDispId);
    STDMETHOD(Invoke)(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS* pDispParams,
                      VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr);

    // Public: CLuaHtmlView::Binder::~Binder 0042c3c0 assigns it directly (function0<bool>::operator= 0042c320 on
    // this + 8). Access does not change the layout or any mangled name.
    boost::function0<bool> handler;   // +0x08

protected:
    ULONG refCount;                   // +0x28
};
