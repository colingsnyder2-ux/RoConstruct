// >>> native-status (generated) -- do not edit >>>
// CPropGridMap | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src c140b965 | roc native-status --write
#include "CPropGrid.h"

BEGIN_MESSAGE_MAP(CPropGrid, CXTPPropertyGrid)
    ON_WM_CREATE()
    ON_MESSAGE(WM_USER + 101, OnUpdate)
END_MESSAGE_MAP()

int CPropGrid::OnCreate(LPCREATESTRUCT)
{
    if (Default() == -1) return -1;
    SetTheme((XTPPropertyGridPaintTheme)6);
    XTPImageManager()->InternalAddRef();
    SetImageManager(XTPImageManager());
    return 0;
}
