// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob0 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espclaude_dd992e6b9a44b58d.cpp

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
#include <fstream>

class RobloxDocument {
public:
    void insertModel(std::istream& stream, bool select);
};

class CRobloxDoc : public CDocument {
public:
    char pad[0x94 - sizeof(CDocument)];
    RobloxDocument* document;
};

class CRobloxView : public CView {
public:
    CRobloxDoc* GetDocument() const { return reinterpret_cast<CRobloxDoc*>(m_pDocument); }
    void OnInsertModel(int unused);
};

void CRobloxView::OnInsertModel(int unused)
{
    CString filter;
    filter.LoadString(0xb8);
    CFileDialog dialog(TRUE, "rbxm", NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, filter, this);
    if (dialog.DoModal() == IDOK)
    {
        std::ifstream stream(dialog.GetPathName(), std::ios::in | std::ios::binary);
        CRobloxDoc* doc = static_cast<CRobloxDoc*>(m_pDocument);
        doc->document->insertModel(stream, false);
    }
}
