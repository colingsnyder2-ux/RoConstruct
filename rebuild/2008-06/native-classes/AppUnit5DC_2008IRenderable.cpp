// 2008-06 native RBX::IRenderable / IRenderableBucket rows of the util/IRenderable.cpp unit 005dd2c0..005dd54f inside
// the application range 005dc000..005e8000 (inactive). Declarations: the native util/IRenderable.h (read-only).
// Verified by tests/record_native_app_unit5dc_2008.py.
#undef _RELEASEASSERT
#include "util/IRenderable.h"
#include "util/Debug.h"

namespace RBX
{
	IRenderableBucket::~IRenderableBucket()                                             // 005dd2c0
	{
		RBXASSERT(renderable2ds.size() == 0);
		RBXASSERT(renderable3ds.size() == 0);
	}

	void IRenderableBucket::render2dItems(Adorn* adorn)                                 // 005dd330
	{
		for (int i = 0; i < renderable2ds.size(); ++i)
			renderable2ds[i]->render2d(adorn);
	}

	void IRenderableBucket::render3dAdornItems(Adorn* adorn)                            // 005dd360
	{
		for (int i = 0; i < renderable3ds.size(); ++i)
			renderable3ds[i]->render3dAdorn(adorn);
	}

	void IRenderableBucket::recomputeShouldRender(IRenderable* iR)                      // 005dd400
	{
		RBXASSERT(iR->bucket == this);

		if (iR->shouldRender2d())
		{
			if (iR->index2d < 0)
				renderable2ds.fastAppend(iR);
		}
		else if (iR->index2d >= 0)
		{
			renderable2ds.fastRemove(iR);
		}

		if (iR->shouldRender3dAdorn())
		{
			if (iR->index3d < 0)
				renderable3ds.fastAppend(iR);
		}
		else if (iR->index3d >= 0)
		{
			renderable3ds.fastRemove(iR);
		}
	}

	void IRenderableBucket::onAdded(IRenderable* iR)                                    // 005dd4c0
	{
		RBXASSERT(iR->index2d == -1);
		RBXASSERT(iR->index3d == -1);
		RBXASSERT(iR->bucket == NULL);

		iR->bucket = this;
		recomputeShouldRender(iR);
	}

	void IRenderableBucket::onRemoving(IRenderable* iR)                                 // 005dd4d0
	{
		RBXASSERT(iR->bucket == this);

		if (iR->index2d >= 0)
			renderable2ds.fastRemove(iR);

		if (iR->index3d >= 0)
			renderable3ds.fastRemove(iR);

		iR->bucket = NULL;

		RBXASSERT(iR->index2d == -1);
		RBXASSERT(iR->index3d == -1);
	}

	void IRenderable::shouldRenderSetDirty()                                            // 005dd540
	{
		if (bucket)
			bucket->recomputeShouldRender(this);
	}
}
