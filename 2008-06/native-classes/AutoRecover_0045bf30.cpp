// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "CRobloxView.h"
#include "CMainFrame.h"
#include "util/DxUserInput.h"
#include "v8datamodel/DataModel.h"

// INFERRED: the target is a CRobloxWnd message handler (likely OnKillFocus/OnSetFocus-style)
// taking one dword argument; it clears keyboard-wanted on the input object at +0x84,
// runs sub_0045beb0, then forwards to CWnd::Default().

namespace {
// Helper to reach the protected members (sub_0045beb0 and CWnd::Default()).
struct ProtectedAccess : public CRobloxWnd {
    void run()
    {
        // INFERRED: member at +0x84 is an RBX::DxUserInput*
        RBX::DxUserInput* input = *reinterpret_cast<RBX::DxUserInput**>(reinterpret_cast<char*>(this) + 0x84);
        if (input)
            input->setKeyboardWanted(false);

        this->sub_0045beb0();

        this->Default();
    }
};
}

extern "C" void __fastcall fn_0045bf30(CRobloxWnd* self, int unusedEdx, int arg1)
{
    static_cast<ProtectedAccess*>(self)->run();
}
