// from server: 100% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espclaude_135b8f6b171fe827.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Rect2D.h>
struct CSettingsDialog {char pad[0x164];void* field_164;G3D::Rect2D method();};
G3D::Rect2D CSettingsDialog::method(){HWND window=*(HWND*)((char*)field_164+0x20);RECT rect;GetClientRect(window,&rect);return G3D::Rect2D(G3D::Vector2((float)(rect.right-rect.left),(float)(rect.bottom-rect.top)));}

