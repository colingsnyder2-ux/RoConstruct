// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <afxwin.h>
#include "util/NativeContentProvider.h"
#include "CRobloxView.h"
#include "RenderContentProvider.h"
#include "v8datamodel/DataModel.h"
#include <GLG3D/GWindow.h>

RBX::ContentProvider* provider = 0;

void CRobloxWnd::finishAttach()
{
    gWindow->makeCurrent();
    provider = dataModel ? dataModel->create<RBX::ContentProvider>() : 0;
    dataModel->buildGui(adorn.get());
    provider = 0;
}
