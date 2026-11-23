// =============================================================================
// LuaHtmlView.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/LuaHtmlView.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "AppLeaves2008/EventHandler2008.h"
#include "util/standardout.h"

EventHandler::EventHandler(boost::function0<bool> handler) : handler(handler), refCount(0)
{
}

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

template class boost::function0<bool,std::allocator<boost::function_base> >;
