#pragma once
#include <guiddef.h>

// 2008-06 native declarations used only by the CBrowserViewExternal unit (inactive; app range 00410000..00414000).
// CBrowserViewExternal::GetApp 00410fe0 passes these two GUIDs to CoCreateInstance (CLSCTX_ALL):
//   * 00816508 = {EEC6B245-01BE-4A51-92BA-2AFDAF97581B}: the "App Class" coclass of REGISTRY resource 110
//     (ProgID Roblox.App), a TKIND_COCLASS entry of the embedded TYPELIB;
//   * 0080b468 = {54F58168-734E-4379-B198-64B0826A002E}: the dispatch interface that follows that coclass in the
//     TYPELIB. The names follow the MIDL CLSID_<coclass> / IID_I<coclass> convention (codegen analog names).
extern "C" const CLSID CLSID_App;
extern "C" const IID IID_IApp;

// 00429330 (bound by workspace-save-trial / workspace-site-trust-working): reports an error for a COM class and
// returns the HRESULT. Declared ad hoc the same way by the committed CContentUpload.cpp / CWorkspaceExecScriptHelper.cpp.
HRESULT __cdecl reportWorkspaceSiteError(REFCLSID, const char*, HRESULT);
