// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_settingsrect_dbbc0ba479a0226d.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Rect2D.h>
struct CSettingsDialog {char pad[0x16c];void* field_16c;G3D::Rect2D method();};
G3D::Rect2D CSettingsDialog::method(){HWND window=*(HWND*)((char*)field_16c+0x20);RECT rect;GetClientRect(window,&rect);return G3D::Rect2D(G3D::Vector2((float)(rect.right-rect.left),(float)(rect.bottom-rect.top)));}
