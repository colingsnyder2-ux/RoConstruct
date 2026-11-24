// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// 0045b3a0: CRobloxWnd RbxGfx renderer attach (setDataModel calls it unless mode_5c == 2).
// new 0x4c ViewRbxGfx(dataModelPtr) 004d9990 -> +0xb0, new 0x144 AdornRbxGfx(visualEngine) 00674210 -> +0xb4,
// each replacing (and deleting) the previous object.
// INFERRED: name; CRobloxView.h has no declaration yet, so it keeps the fn_<address> C name setDataModel links to.
#include "CRobloxView.h"
#include "v8datamodel/DataModel.h"
#include "RenderLib/ViewNew2008.h"
#include "RbxGraphics/AdornRbxGfx2008.h"

extern "C" void __fastcall fn_0045b3a0(CRobloxWnd* self, int unusedEdx)
{
    RBX::ViewBase* view = new RBX::ViewNew::ViewRbxGfx(self->dataModelPtr);
    RBX::ViewBase* oldView = static_cast<RBX::ViewBase*>(self->slot_b0);
    if (view != oldView)
        delete oldView;
    self->slot_b0 = view;

    RBX::AdornRbxGfx* adorn = new RBX::AdornRbxGfx(self->visualEngine);
    RBX::AdornRbxGfx* oldAdorn = static_cast<RBX::AdornRbxGfx*>(self->slot_b4);
    if (adorn != oldAdorn)
        delete oldAdorn;
    self->slot_b4 = adorn;
}
