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
