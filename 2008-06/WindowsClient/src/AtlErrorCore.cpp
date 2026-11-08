// >>> native-status (generated) -- do not edit >>>
// AtlErrorCore | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src 903436c0 | roc native-status --write
#include <atlbase.h>
#include <atlcom.h>

typedef HRESULT (WINAPI *AtlErrorCore)(REFCLSID, LPCSTR, DWORD, LPCSTR, REFIID, HRESULT);
AtlErrorCore workspaceAtlErrorCore = static_cast<AtlErrorCore>(&ATL::AtlReportError);
