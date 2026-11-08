#include <atlbase.h>
#include <atlcom.h>

typedef HRESULT (WINAPI *AtlErrorCore)(REFCLSID, LPCSTR, DWORD, LPCSTR, REFIID, HRESULT);
AtlErrorCore workspaceAtlErrorCore = static_cast<AtlErrorCore>(&ATL::AtlReportError);
