#pragma once
// >>> native-status (generated) -- do not edit >>>
// RobloxLib | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 283a8a8c | roc native-status --write
#include <oaidl.h>

// Original embedded TYPELIB, read through its dual (vtable) interfaces.
// Evidence: shared-layouts/original-typelib.json. HRESULT/retval parameters
// must not be taken from the transformed IDispatch metadata view.
struct __declspec(novtable) __declspec(uuid("D63F927A-1170-4239-9C1D-06E8A658F300")) IContent : IDispatch {
    STDMETHOD(Upload)(BSTR url) = 0;
};

struct __declspec(novtable) __declspec(uuid("0730C3C6-092D-4F45-B8B9-BDEB82DE1C7B")) IWorkspace : IDispatch {
    STDMETHOD(SaveToFile)(BSTR pathName) = 0;
    STDMETHOD(SaveSelectionToFile)(BSTR pathName) = 0;
    STDMETHOD(Insert)(BSTR url) = 0;
    STDMETHOD(Write)(IContent** result) = 0;
    STDMETHOD(WriteSelection)(IContent** result) = 0;
    STDMETHOD(ExecScript)(BSTR script, VARIANT arg1, VARIANT arg2, VARIANT arg3, VARIANT arg4, SAFEARRAY** result) = 0;
    STDMETHOD(ExecUrlScript)(BSTR url, VARIANT arg1, VARIANT arg2, VARIANT arg3, VARIANT arg4, SAFEARRAY** result) = 0;
    STDMETHOD(Close)() = 0;
};
