// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-browser /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// CChatPromptWindow | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 688963c6 | roc native-status --write
#include "CChatPrompt.h"
#include <XTToolkitPro.h>
#include "Network/Players.h"
#include "v8datamodel/DataModel.h"
#include <exception>

const char* chatPromptText = "To chat click here or press the \"/\" key";

BEGIN_MESSAGE_MAP(CChatPrompt, CEditView)
    ON_CONTROL_REFLECT(EN_CHANGE, OnChange)
    ON_WM_CHAR()
    ON_WM_SYSCHAR()
    ON_MESSAGE(WM_USER + 0x68, OnFocusMessage)
    ON_CONTROL_REFLECT(EN_SETFOCUS, OnSetFocusReflect)
    ON_WM_CREATE()
    ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()

BOOL CChatPrompt::PreCreateWindow(CREATESTRUCT& cs)
{
    if (!CEditView::PreCreateWindow(cs))
        return FALSE;
    cs.style &= ~(WS_VSCROLL | WS_HSCROLL | ES_AUTOHSCROLL);
    cs.style |= WS_DISABLED;
    return TRUE;
}

void CChatPrompt::OnChange() {}

void CChatPrompt::OnSetFocusReflect()
{
    CString text;
    GetWindowText(text);
    if (text.Compare(chatPromptText) == 0)
        SetWindowText("");
}

int CChatPrompt::OnCreate(LPCREATESTRUCT cs)
{
    brush.Attach(CreateSolidBrush(0x404040));
    if (CEditView::OnCreate(cs) == -1)
        return -1;
    SetFont(XTPPaintManager()->GetRegularFont());
    SetWindowText(chatPromptText);
    return 0;
}

void CChatPrompt::OnSysChar(UINT, UINT, UINT)
{
    Default();
}

void CChatPrompt::OnChar(UINT ch, UINT, UINT)
{
    if (ch != VK_RETURN) {
        if (ch != VK_ESCAPE) {
            Default();
            return;
        }
        SetWindowText(chatPromptText);
        hostWindow->SetFocus();
        return;
    }
    CString text;
    GetWindowText(text);
    if (players && !text.IsEmpty()) {
        try {
            {
                RBX::DataModel::Lock lock(context);
                players->chat(std::string(static_cast<const char*>(text)));
            }
            SetWindowText(chatPromptText);
        } catch (const std::exception&) {
        }
    }
    hostWindow->SetFocus();
}

LRESULT CChatPrompt::OnFocusMessage(WPARAM, LPARAM)
{
    SetFocus();
    return 0;
}

HBRUSH CChatPrompt::CtlColor(CDC* dc, UINT)
{
    if (GetFocus() == this) {
        dc->SetTextColor(0);
        dc->SetBkColor(0x00fae6e6);
    } else {
        dc->SetTextColor(0x00c8ffff);
        dc->SetBkColor(0x00404040);
    }
    return brush;
}
