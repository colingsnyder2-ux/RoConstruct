// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include /I{headers}/../../../tools/rbxgs/Client/RbxGraphics/include /I{headers}/../../../tools/rbxgs/Client/Network/include /I{headers}/../../../tools/rbxgs/Client/RbxView/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/zlib /I{headers}/../../../tools/rbxgs/Client/Rendering/RenderLib/include /I{headers}/../../../tools/rbxgs/Client/Rendering/AppDraw/include /I{headers}/../../../tools/rbxgs/Client/boost_1_34_1/src /I{headers}/../../../tools/rbxgs/Client/App/lua-5.1.1/src /I{headers}/../../../tools/rbxgs/Client/Rendering/SDL-1.2.6/include /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include /U_RELEASEASSERT
#include "gui/Gui.h"

namespace RBX {
    // UnifiedWidget::init() - 00573570
    // Symbol: ?init@UnifiedWidget@RBX@@AAEXXZ (private thiscall)
    // Assembly: loads globals 0x82f860 (140.0f), 0x82f85c (24.0f), stores to this+0x13c, this+0x140, sets this+0x144=0
    void UnifiedWidget::init()
    {
        setGuiSize(G3D::Vector2(140.0f, 24.0f));
        menuState = NOTHING;
    }
}