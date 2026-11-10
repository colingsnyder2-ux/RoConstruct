#include "util/Debug.h"
#include "util/IRenderable.h"
namespace RBX {
	IRenderable::~IRenderable()
	{
		RBXASSERT(index2d == -1);
		RBXASSERT(index3d == -1);
		RBXASSERT(bucket == NULL);
	}

}
