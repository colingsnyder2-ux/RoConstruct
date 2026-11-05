// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr
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
    std::ofstream stream;
    stream.open(CStringA(path), std::ios::out | std::ios::binary);
    RBX::DataModel::Lock lock(dataModel);
    write(writeXmlModel().get(), stream);
    return S_OK;
}

HRESULT __stdcall CWorkspace::SaveSelectionToFile(BSTR path) {
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    std::ofstream stream;
    stream.open(CStringA(path), std::ios::out | std::ios::binary);
    RBX::DataModel::Lock lock(dataModel);
    write(writeXmlSelection().get(), stream);
    return S_OK;
}
