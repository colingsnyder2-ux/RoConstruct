// >>> native-status (generated) -- do not edit >>>
// AtlErrorCore | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src adeac0f3 | roc native-status --write
#include <atlbase.h>
#include <atlcom.h>

typedef HRESULT (WINAPI *AtlErrorCore)(REFCLSID, LPCSTR, DWORD, LPCSTR, REFIID, HRESULT);
AtlErrorCore workspaceAtlErrorCore = static_cast<AtlErrorCore>(&ATL::AtlReportError);

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class ATL::CComPtrBase<ICreateErrorInfo>;
template class ATL::CComPtrBase<IErrorInfo>;
