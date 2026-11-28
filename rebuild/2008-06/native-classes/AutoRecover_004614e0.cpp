// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "stdafx.h"
// INFERRED: no -I in the fixed flags, so reach the Scintilla headers by relative path (CScriptEditor.h fails on Platform.h).
#include "../../../tools/openrbx/Client/win/ScintillaDocView.h"

namespace Scintilla
{
// INFERRED: layout of _SCINTILLA_EDIT_STATE from sibling source; strFind at 0x932fb8 = base + 8.
struct Local_00932fb0
{
    CScintillaFindReplaceDlg* pFindReplaceDlg;
    BOOL                      bFindOnly;
    CString                   strFind;
};

extern Local_00932fb0 g_00932fb0;

void CScintillaView::OnUpdateNeedFind(CCmdUI* pCmdUI)
{
    pCmdUI->Enable(GetCtrl().GetLength() != 0 && !g_00932fb0.strFind.IsEmpty());
}
}
