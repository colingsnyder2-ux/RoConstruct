// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "network/Players.h"
#include "network/Player.h"
#include "gui/Gui.h"
#include "RbxGraphics/Adorn.h"

extern "C" int __fastcall fn_0045de20(void* self, int unusedEdx);
extern "C" int __fastcall fn_005a38f0(void* self, int unusedEdx, int a1);

namespace RBX {

// INFERRED: renderPass2d body follows 0057a1b0 disassembly and the 2007 analog.
void DataModel::renderPass2d(Adorn* adorn, IMetric* metric)
{
    if (!renderEnabled)
        return;
    if (!adorn || !metric)
        return;

    tempMetric = metric;

    workspace->render2d(adorn);
    GuiRoot::render2dItem(adorn,
        Network::Players::findLocalPlayer(this)
            ? static_cast<GuiItem*>(localBackpack.get())
            : static_cast<GuiItem*>(starterPackService.get()));
    guiRoot->render2d(adorn);

    Network::Players* players = create<Network::Players>();
    Network::Player* player = players->localPlayer.get();
    if (player) {
        for (unsigned i = 0; i < player->numChildren(); i++) {
            IRenderable* renderable = dynamic_cast<IRenderable*>(player->getChild(i));
            if (renderable)
                renderable->render2d(adorn);
        }
    }

    std::string text;
    if (uiMessage == "[[[progress]]]") {
        std::string joints("numJoints");
        std::string primitives("numPrimitives");
        text = "Bricks: " + evaluate(primitives) + " Connectors: " + evaluate(joints);
    } else {
        text = uiMessage;
    }

    if (text.size() > 0) {
        G3D::Rect2D viewport = adorn->getViewport();
        G3D::Vector2 center = viewport.center();
        int w = (int)viewport.width();
        int fontSize = (int)(w * 0.02f);
        float halfW = viewport.width() * 0.3f;
        G3D::Vector2 halfSize(halfW, halfW * 0.3f);

        G3D::Vector2 lo = center - halfSize;
        G3D::Vector2 hi = center + halfSize;
        adorn->rect2d(G3D::Rect2D::xyxy(lo, hi), GuiItem::translucentBackdrop());

        const G3D::Vector3& m = G3D::Vector3::minFinite();
        adorn->outlineRect2d(G3D::Rect2D::xyxy(lo, hi), 2.0f,
                             G3D::Color4(G3D::Color3(m.x, m.y, m.z), 1.0f));

        adorn->drawFont2D(text, center, (double)fontSize,
                          G3D::Color4(G3D::Color3::white(), 1.0f),
                          G3D::Color4::zero(),
                          Adorn::XALIGN_CENTER, Adorn::YALIGN_CENTER,
                          Adorn::PROPORTIONAL_SPACING);
    }

    UserInputBase* input = (UserInputBase*)(((int*)fn_0045de20(this, 0))[0x130 / 4]);
    if (input) {
        if (forceArrowCursor)
            input->setCursorId(adorn, ContentId::fromAssets("Textures\\ArrowCursor.png"));
        else
            fn_005a38f0(workspace.get(), 0, (int)adorn);
        input->renderGameCursor(adorn);
    }

    tempMetric = 0;
}

}
