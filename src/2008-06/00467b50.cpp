// from server: 100% by EspClaude
// from server: 97% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_874bc7282ca22812.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include <G3D/Vector2.h>
#include <G3D/Rect2D.h>
G3D::Vector2 nudge(const G3D::Vector2& v, int amount);
struct Window { char padding[0x20]; HWND handle; };
struct DxUserInput {
    char padding0[0x34];
    CRITICAL_SECTION criticalSection; char pad[0x2c-sizeof(CRITICAL_SECTION)];
    G3D::Vector2 offset;
    char input[0x104];
    Window* window;
    G3D::Rect2D getWindowRect() { RECT rect; GetClientRect(window->handle, &rect); return G3D::Rect2D(G3D::Vector2((float)(rect.right-rect.left),(float)(rect.bottom-rect.top))); }
    G3D::Vector2 f();
};
G3D::Vector2 DxUserInput::f()
{
    EnterCriticalSection(&criticalSection);
    G3D::Vector2 result = nudge(offset, 10) + getWindowRect().center();
    LeaveCriticalSection(&criticalSection);
    return result;
}
