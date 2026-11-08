// >>> native-status (generated) -- do not edit >>>
// AtlErrorCore | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 903436c0 | roc native-status --write
#include <atlbase.h>
#include <atlcom.h>

typedef HRESULT (WINAPI *AtlErrorCore)(REFCLSID, LPCSTR, DWORD, LPCSTR, REFIID, HRESULT);
AtlErrorCore workspaceAtlErrorCore = static_cast<AtlErrorCore>(&ATL::AtlReportError);
