// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/util/UserInputBase.cpp

// Candidate translation unit (score above; library headers required).
#include "util/UserInputBase.h"

#include "appdraw/Textures.h"
#include "rbxgraphics/Adorn.h"
#include "rbxgraphics/TextureProxyBase.h"
#include "util/ContentProvider.h"
#include "util/TextureId.h"

namespace RBX {

// FUNCTION: WEBSERVICE 0x100d0ec0
// FUNCTION: ROBLOX 0x005d8b60
void UserInputBase::getNavKeys(NavKeys& navKeys) const
{
	navKeys.forward_arrow = keyDown(SDLK_UP);
	navKeys.backward_arrow = keyDown(SDLK_DOWN);
	navKeys.left_arrow = keyDown(SDLK_LEFT);
	navKeys.right_arrow = keyDown(SDLK_RIGHT);
	navKeys.forward_asdw = keyDown(SDLK_w);
	navKeys.backward_asdw = keyDown(SDLK_s);
	navKeys.left_asdw = keyDown(SDLK_a);
	navKeys.right_asdw = keyDown(SDLK_d);
	navKeys.space = keyDown(SDLK_SPACE);
}

// FUNCTION: ROBLOX 0x005d8c00
void UserInputBase::init(Adorn* adorn)
{
	setCursorId(adorn, ContentId::fromAssets("Textures\\ArrowCursor.png"));
}

// FUNCTION: ROBLOX 0x005d8ce0
UserInputBase::UserInputBase() : currentCursor(NULL)
{
}

// FUNCTION: ROBLOX 0x005d8d40
G3D::ReferenceCountedPointer<TextureProxyBase> UserInputBase::getGameCursor(Adorn* adorn)
{
	return currentCursor;
}

// FUNCTION: ROBLOX 0x005d8d70
void UserInputBase::setCursorId(Adorn* adorn, const TextureId& cursorId)
{
	if (currentCursorId != cursorId) {
		currentCursorId = cursorId;
		currentCursor = Textures::getTextureProxy(adorn, cursorId);

		if (currentCursor.isNull()) {
			currentCursor = Textures::getTextureProxy(adorn, ContentId::fromAssets("Textures\\ArrowCursor.png"));
		}
	}
}

// FUNCTION: ROBLOX 0x005d8ee0
void UserInputBase::renderGameCursor(Adorn* adorn)
{
	G3D::ReferenceCountedPointer<TextureProxyBase> cursor = getGameCursor(adorn);
	if (cursor.notNull()) {
		G3D::Rect2D rect = adorn->getTextureSize(cursor);
		rect = (rect - rect.center()) + getCursorPosition();

		adorn->setTexture(0, cursor);
		adorn->rect2d(rect, G3D::Color4(1.0f, 1.0f, 1.0f, 1.0f));
		adorn->setTexture(0, NULL);
	}
}

} // namespace RBX
