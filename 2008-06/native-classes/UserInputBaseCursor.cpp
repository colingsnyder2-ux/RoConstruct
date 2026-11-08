// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/slingshot-load /fp:fast
// >>> native-status (generated) -- do not edit >>>
// UserInputBaseCursor | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 2242190e | roc native-status --write
#include "util/UserInputBase.h"
#include "AppDraw/Textures.h"

namespace RBX
{
void UserInputBase::init(Adorn* adorn)
{
    setCursorId(adorn, TextureId(ContentId::fromAssets("Textures\\ArrowCursor.png")));
}

G3D::ReferenceCountedPointer<TextureProxyBase> UserInputBase::getGameCursor(Adorn* adorn)
{
    if (!currentCursor.notNull())
    {
        currentCursor = Textures::getTextureProxy(adorn, currentCursorId);
        if (!currentCursor.notNull())
            currentCursor = Textures::getTextureProxy(adorn, ContentId::fromAssets("Textures\\ArrowCursor.png"));
    }
    return currentCursor;
}

void UserInputBase::setCursorId(Adorn*, const TextureId& id)
{
    if (currentCursorId != id)
    {
        currentCursorId = id;
        currentCursor = NULL;
    }
}

#pragma float_control(precise, off, push)
void UserInputBase::renderGameCursor(Adorn* adorn)
{
    G3D::ReferenceCountedPointer<TextureProxyBase> texture = getGameCursor(adorn);
    if (texture.notNull())
    {
        G3D::Rect2D rect = adorn->getTextureSize(texture);
        rect = (rect - rect.center()) + getCursorPosition();
        adorn->setTexture(0, texture);
        adorn->rect2d(rect, G3D::Color4(1, 1, 1, 1));
        adorn->setTexture(0, G3D::ReferenceCountedPointer<TextureProxyBase>());
    }
}
#pragma float_control(pop)
}
