// Mew fork 5fe2214e131d: inactive original 2008 render loops.
#undef _RELEASEASSERT
#include "util/IRenderable.h"

namespace RBX
{
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

}
