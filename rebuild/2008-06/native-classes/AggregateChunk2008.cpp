// 2008-06 native RBX::RenderBase::AggregateChunk leaves (inactive). The RenderBase library is compiled /Od (frame
// pointer, every local spilled, no inlining), so this unit is built with the /Od profile of the recorder.
// Rows: cachesShadows 005526d0, castsShadows 00552690, cullable 005526b0, getMesh 00552720, cframe 00552760.
// ??_G 00552780 and the ctor / dtor are not built (they come with the vtable). getMaterial 005526e0 needs the complete RenderBase::MaterialBase
// (material owner) and is built only with NATIVE_AGGREGATECHUNK_PENDING.
#include "RenderLib/AggregateChunk2008.h"

namespace RBX
{
	namespace RenderBase
	{
		bool AggregateChunk::cachesShadows() const
		{
			return true;
		}

		bool AggregateChunk::castsShadows() const
		{
			return _castsShadows;
		}

		bool AggregateChunk::cullable() const
		{
			return _cullable;
		}

#ifdef NATIVE_AGGREGATECHUNK_PENDING
		G3D::ReferenceCountedPointer<MaterialBase> AggregateChunk::getMaterial()
		{
			return material;
		}
#endif

		G3D::ReferenceCountedPointer<Mesh> AggregateChunk::getMesh()
		{
			return mesh;
		}

		const G3D::CoordinateFrame& AggregateChunk::cframe()
		{
			return _cframe;
		}
	}
}
