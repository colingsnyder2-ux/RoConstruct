// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_gamecursorexpressionedb2fa752dca4518.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise, off, push)
#include <util/UserInputBase.h>
#include <RbxGraphics/Adorn.h>
void RBX::UserInputBase::renderGameCursor(Adorn* adorn){G3D::ReferenceCountedPointer<TextureProxyBase> texture=getGameCursor(adorn);if(texture.notNull()){G3D::Rect2D rect=adorn->getTextureSize(texture);rect=(rect-rect.center())+getCursorPosition();adorn->setTexture(0,texture);adorn->rect2d(rect,G3D::Color4(1,1,1,1));adorn->setTexture(0,G3D::ReferenceCountedPointer<TextureProxyBase>());}}
