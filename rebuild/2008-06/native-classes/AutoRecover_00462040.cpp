// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0081a8c8[];   // INFERRED: unnamed global at 0x0081a8c8 in the original
#include "stdafx.h"

// INFERRED: CScriptEditor.h includes Platform.h, which is not on the fixed include path.
// To avoid that header, the member is defined as an extern "C" function with a
// local CView-derived helper, using the fn_<address> convention.

// INFERRED: 0x932fb0 is _scintillaEditState.pFindReplaceDlg; only its CWnd base is used here.
extern "C" CWnd* g_00932fb0;

// INFERRED: CRuntimeClass of CScintillaView at ((int)&g_0081a8c8)
#define Local_00462040_RTC ((CRuntimeClass*)((int)&g_0081a8c8))

struct Local_00462040 : public CView
{
    void DoDestroy();
};

void Local_00462040::DoDestroy()
{
    if (g_00932fb0)
    {
        CWinApp* pApp = AfxGetApp();
        int nScintillaViews = 0;

        if (pApp->m_pDocManager)
        {
            POSITION pos = pApp->m_pDocManager->GetFirstDocTemplatePosition();
            while (pos && (nScintillaViews == 0))
            {
                CDocTemplate* pTemplate = pApp->m_pDocManager->GetNextDocTemplate(pos);
                POSITION pos2 = pTemplate->GetFirstDocPosition();
                while (pos2 && (nScintillaViews == 0))
                {
                    CDocument* pDoc = pTemplate->GetNextDoc(pos2);
                    POSITION pos3 = pDoc->GetFirstViewPosition();
                    while (pos3 && (nScintillaViews == 0))
                    {
                        CView* pView = pDoc->GetNextView(pos3);
                        if (pView->IsKindOf(Local_00462040_RTC) && (pView != this) && ::IsWindow(pView->GetSafeHwnd()))
                            ++nScintillaViews;
                    }
                }
            }
        }

        if (nScintillaViews == 0)
        {
            if (::IsWindow(g_00932fb0->m_hWnd))
                g_00932fb0->SendMessage(WM_CLOSE);
            g_00932fb0 = NULL;
        }
    }

    CWnd::OnDestroy();
}

extern "C" void __fastcall fn_00462040(CView* self, int unusedEdx)
{
    static_cast<Local_00462040*>(self)->DoDestroy();
}
