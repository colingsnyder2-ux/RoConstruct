// from server: 70% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/util/IRenderable.cpp

// Candidate translation unit (score above; library headers required).
#include "util/IRenderable.h"

namespace RBX {

IRenderable::~IRenderable()
{
}

// FUNCTION: WEBSERVICE 0x100a66c0
// FUNCTION: ROBLOX 0x005f5320
IRenderableBucket::~IRenderableBucket()
{
}

// FUNCTION: WEBSERVICE 0x100a6730
// FUNCTION: ROBLOX 0x005f5390
void IRenderableBucket::render2dItems(Adorn* adorn)
{
	for (int i = 0; i < renderable2ds.size(); i++) {
		renderable2ds[i]->render2d(adorn);
	}
}

// FUNCTION: WEBSERVICE 0x100a6760
// FUNCTION: ROBLOX 0x005f53c0
void IRenderableBucket::render3dAdornItems(Adorn* adorn)
{
	for (int i = 0; i < renderable3ds.size(); i++) {
		renderable3ds[i]->render3dAdorn(adorn);
	}
}

// FUNCTION: WEBSERVICE 0x100a6800
// FUNCTION: ROBLOX 0x005f5460
void IRenderableBucket::recomputeShouldRender(IRenderable* iR)
{
	if (iR->shouldRender2d()) {
		if (iR->index2d < 0) {
			renderable2ds.fastAppend(iR);
		}
	}
	else if (iR->index2d >= 0) {
		renderable2ds.fastRemove(iR);
	}

	if (iR->shouldRender3dAdorn()) {
		if (iR->index3d < 0) {
			renderable3ds.fastAppend(iR);
		}
	}
	else if (iR->index3d >= 0) {
		renderable3ds.fastRemove(iR);
	}
}

// FUNCTION: WEBSERVICE 0x100a68d0
// FUNCTION: ROBLOX 0x005f5530
void IRenderableBucket::onAdded(IRenderable* iR)
{
	iR->bucket = this;

	recomputeShouldRender(iR);
}

// FUNCTION: WEBSERVICE 0x100a68e0
// FUNCTION: ROBLOX 0x005f5540
void IRenderableBucket::onRemoving(IRenderable* iR)
{
	if (iR->index2d >= 0) {
		renderable2ds.fastRemove(iR);
	}

	if (iR->index3d >= 0) {
		renderable3ds.fastRemove(iR);
	}

	iR->bucket = NULL;
}

// FUNCTION: WEBSERVICE 0x100a6960
// FUNCTION: ROBLOX 0x005f55c0
void IRenderable::shouldRenderSetDirty()
{
	if (bucket != NULL) {
		bucket->recomputeShouldRender(this);
	}
}

} // namespace RBX
