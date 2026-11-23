// =============================================================================
// UserInputBase.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/util/UserInputBase.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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

namespace RBX
{
bool MovementKeys::any() const
{
    return up || down || left || right || w || s || a || d || space;
}
void UserInputBase::getMovementKeys(MovementKeys& keys) const
{
    keys.up = keyDown(SDLK_UP);
    keys.down = keyDown(SDLK_DOWN);
    keys.left = keyDown(SDLK_LEFT);
    keys.right = keyDown(SDLK_RIGHT);
    keys.w = keyDown(SDLK_w);
    keys.s = keyDown(SDLK_s);
    keys.a = keyDown(SDLK_a);
    keys.d = keyDown(SDLK_d);
    keys.space = keyDown(SDLK_SPACE);
}
}
