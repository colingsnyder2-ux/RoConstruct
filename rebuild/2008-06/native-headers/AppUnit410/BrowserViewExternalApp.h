#pragma once
#include <guiddef.h>

extern "C" const CLSID CLSID_App;
extern "C" const IID IID_IApp;

HRESULT __cdecl reportWorkspaceSiteError(REFCLSID, const char*, HRESULT);
