#include <afxwin.h>
#include <afxdlgs.h>
#include "CRobloxDoc.h"

void CRobloxDoc::handle_455c30()
{
    CString filter;
    filter.LoadString(0xd0);
    CFileDialog dialog(TRUE, "lua", NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, filter);
    if (dialog.DoModal() == IDOK)
        loadFile((const char*)dialog.GetPathName());
}
