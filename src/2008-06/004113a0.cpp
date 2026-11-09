// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0-shared-rtm roc_campaign_color_f35d68de5c521b95.cpp

// Candidate translation unit (score above; library headers required).
#define NDEBUG 1
#include <afxwin.h>
#include <afxext.h>
class CChatPrompt : public CEditView {
    // Constructor 00411be0 initializes three words at 0x88,0x8c,0x90.
    unsigned long observed[3];
    CBrush brush;
public:
    HBRUSH CtlColor(CDC* dc, UINT type);
};
HBRUSH CChatPrompt::CtlColor(CDC* dc, UINT type) {
    if (GetFocus() == this) {
        dc->SetTextColor(0);
        dc->SetBkColor(0x00fae6e6);
    } else {
        dc->SetTextColor(0x00c8ffff);
        dc->SetBkColor(0x00404040);
    }
    return brush;
}
