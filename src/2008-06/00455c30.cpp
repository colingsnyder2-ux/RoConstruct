// from server: 100% by EspClaude
// from server: 59% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob0 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espclaude_8da179552268be3c.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#ifndef _AFXDLL
#define _AFXDLL
#endif
#include <new>
#include <afxwin.h>
#include <afxdlgs.h>
#include <string>

class CRobloxView : public CDocument {
public:
    int loadFile(std::string path);
    void OnInsertModel();
};

void CRobloxView::OnInsertModel()
{
    CString filter;
    filter.LoadString(0xd0);
    CFileDialog dialog(TRUE, "lua", NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, filter);
    if (dialog.DoModal() == IDOK)
        loadFile((const char*)dialog.GetPathName());
}
