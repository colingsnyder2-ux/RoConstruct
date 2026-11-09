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
IRenderableBucket::~IRenderableBucket()
{
}

// FUNCTION: WEBSERVICE 0x100a6730
void IRenderableBucket::render2dItems(Adorn* adorn)
{
	for (int i = 0; i < renderable2ds.size(); i++) {
		renderable2ds[i]->render2d(adorn);
	}
}

// FUNCTION: WEBSERVICE 0x100a6760
void IRenderableBucket::render3dAdornItems(Adorn* adorn)
{
	for (int i = 0; i < renderable3ds.size(); i++) {
		renderable3ds[i]->render3dAdorn(adorn);
	}
}

// FUNCTION: WEBSERVICE 0x100a6800
void IRenderableBucket::recomputeShouldRender(IRenderable* renderable)
{
	if (renderable->shouldRender2d()) {
		if (renderable->index2d < 0) {
			renderable2ds.fastAppend(renderable);
		}
	}
	else if (renderable->index2d >= 0) {
		renderable2ds.fastRemove(renderable);
	}

	if (renderable->shouldRender3dAdorn()) {
		if (renderable->index3d < 0) {
			renderable3ds.fastAppend(renderable);
		}
	}
	else if (renderable->index3d >= 0) {
		renderable3ds.fastRemove(renderable);
	}
}

// FUNCTION: WEBSERVICE 0x100a68d0
void IRenderableBucket::onAdded(IRenderable* renderable)
{
	renderable->bucket = this;

	recomputeShouldRender(renderable);
}

// FUNCTION: WEBSERVICE 0x100a68e0
void IRenderableBucket::onRemoving(IRenderable* renderable)
{
	if (renderable->index2d >= 0) {
		renderable2ds.fastRemove(renderable);
	}

	if (renderable->index3d >= 0) {
		renderable3ds.fastRemove(renderable);
	}

	renderable->bucket = NULL;
}

// FUNCTION: WEBSERVICE 0x100a6960
void IRenderable::shouldRenderSetDirty()
{
	if (bucket != NULL) {
		bucket->recomputeShouldRender(this);
	}
}

} // namespace RBX
