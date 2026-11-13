// Inactive native 2008-06 EventHandler (native-headers/AppLeaves2008/EventHandler2008.h).
// >>> native-status (generated) -- do not edit >>>
// AppLeaves2008EventHandler | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by auto
// <<< native-status | src 508ac20f | roc native-status --write
#include "AppLeaves2008/EventHandler2008.h"
#include "util/standardout.h"

EventHandler::EventHandler(boost::function0<bool> handler) : handler(handler), refCount(0)
{
}

// 0042adb0: IID_IUnknown then IID_IDispatch through the out-of-line guiddef.h IsEqualGUID (0042ad40).
STDMETHODIMP EventHandler::QueryInterface(REFIID riid, void** ppvObject)
{
    HRESULT hr = S_OK;
    *ppvObject = NULL;
    if (IsEqualGUID(riid, IID_IUnknown))
        *ppvObject = this;
    else if (IsEqualGUID(riid, IID_IDispatch))
        *ppvObject = this;
    else
        hr = E_NOINTERFACE;
    if (SUCCEEDED(hr))
        AddRef();
    return hr;
}

STDMETHODIMP_(ULONG) EventHandler::AddRef()
{
    return ++refCount;
}

STDMETHODIMP_(ULONG) EventHandler::Release()
{
    if (--refCount == 0)
    {
        delete this;
        return 0;
    }
    return refCount;
}

STDMETHODIMP EventHandler::GetTypeInfoCount(UINT* pctinfo)
{
    *pctinfo = 0;
    return S_OK;
}

STDMETHODIMP EventHandler::GetTypeInfo(UINT, LCID, ITypeInfo**)
{
    return DISP_E_BADINDEX;
}

STDMETHODIMP EventHandler::GetIDsOfNames(REFIID, LPOLESTR*, UINT, LCID, DISPID*)
{
    return DISP_E_UNKNOWNNAME;
}

// 0042b130 (+ catch funclet 0042b191): VT_BOOL result 1/0 (setne), returns 1 (S_FALSE) on success and E_FAIL after
// reporting a std::exception as MESSAGE_WARNING.
STDMETHODIMP EventHandler::Invoke(DISPID, REFIID, LCID, WORD, DISPPARAMS*, VARIANT* pVarResult, EXCEPINFO*, UINT*)
{
    pVarResult->vt = VT_BOOL;
    try
    {
        pVarResult->boolVal = handler() ? 1 : 0;
        return S_FALSE;
    }
    catch (std::exception& e)
    {
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_WARNING, e);
        return E_FAIL;
    }
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::function0<bool,std::allocator<boost::function_base> >;
