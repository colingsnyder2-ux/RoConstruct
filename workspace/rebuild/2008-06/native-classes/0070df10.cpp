// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 0070df10 (5 bytes): `jmp ?GetThisClass@CControlBar@@SGPAUCRuntimeClass@@XZ`.
// Original assembly (roc native-asm 2008-06 0070df10):
//     0070df10  jmp 0x7bc814  ; MFC ?GetThisClass@CControlBar@@SGPAUCRuntimeClass@@XZ
// This is the MFC base-getter pattern already documented for CChildFrame.h:8
// ("base getter 00412ae0 = jmp CMDIChildWnd::GetThisClass"): a GetRuntimeClass
// override whose whole body tail-jumps to the base class's static GetThisClass.
// The wrapper's destructor name (??1CControlCustomization@CXTPStatusBar@@UAE@XZ)
// is an INFERRED label and is inconsistent with a jmp to a static getter; it is
// not claimed. INFERRED: function name sub_0070df10; identity is carried by the
// jump relocation to the proven MFC target. No class/struct/union/extern is
// defined here (owner rule).
#include <afxwin.h>
#include <afxext.h>

CRuntimeClass* sub_0070df10()
{
    return CControlBar::GetThisClass();
}
