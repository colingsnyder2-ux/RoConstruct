// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr
// >>> native-status (generated) -- do not edit >>>
// CWorkspaceSave | 2008-06 | 2 byte-exact, inactive (not link-selected)
// 2/2 mapped addresses byte-exact | 0 unproved | no mapped strings | by EspClaude (+1) (mixed 2)
// <<< native-status | src 0ff530f8 | roc native-status --write
#include <afxwin.h>
#include <atlbase.h>
#include <fstream>
#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"
#include "v8xml/XmlElement.h"

extern HRESULT __cdecl reportWorkspaceSiteError(REFCLSID, const char*, HRESULT);
extern const CLSID workspaceSiteErrorContext;

HRESULT __stdcall CWorkspace::SaveToFile(BSTR path) {
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    try {
        std::ofstream stream;
        stream.open(CStringA(path), std::ios::out | std::ios::binary);
        RBX::DataModel::Lock lock(dataModel);
        return write(writeXmlModel().get(), stream);
    } catch (const std::exception& e) {
        return reportWorkspaceSiteError(workspaceSiteErrorContext, e.what(), 0);
    }
}

HRESULT __stdcall CWorkspace::SaveSelectionToFile(BSTR path) {
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    std::ofstream stream;
    stream.open(CStringA(path), std::ios::out | std::ios::binary);
    RBX::DataModel::Lock lock(dataModel);
    write(writeXmlSelection().get(), stream);
    return S_OK;
}
