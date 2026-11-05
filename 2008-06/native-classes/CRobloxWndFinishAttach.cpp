#include <afxwin.h>
#include "util/NativeContentProvider.h"
#include "CRobloxView.h"
#include "v8datamodel/DataModel.h"
#include <GLG3D/GWindow.h>

namespace RBX { extern ContentProvider* guiContentProvider; }

void CRobloxWnd::finishAttach()
{
    gWindow->makeCurrent();
    RBX::guiContentProvider = RBX::ServiceProvider::create<RBX::ContentProvider>(
        static_cast<const RBX::ServiceProvider*>(dataModel.get()));
    dataModel->buildGui(adorn.get());
    RBX::guiContentProvider = NULL;
}
