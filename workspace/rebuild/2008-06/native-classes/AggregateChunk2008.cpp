// 2008-06 native RBX::RenderBase::AggregateChunk leaves (inactive). The RenderBase library is compiled /Od (frame
// pointer, every local spilled, no inlining), so this unit is built with the /Od profile of the recorder.
// Rows: cachesShadows 005526d0, castsShadows 00552690, cullable 005526b0, getMesh 00552720, cframe 00552760.
// ctor 00551f30, dtor 00552160, ??_G 00552780 and getMaterial 005526e0 use the complete RenderBase::MaterialBase from
// RenderLib/Material2008.h (material owner; Ogre 1.4.5 client include path).
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// AggregateChunk2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 042b7d4b | roc native-status --write
#include "RenderLib/AggregateChunk2008.h"
#include "RenderLib/Material2008.h"   // completes RenderBase::MaterialBase (needs the Ogre 1.4.5 client headers)

namespace RBX
{
	namespace RenderBase
	{
		AggregateChunk::AggregateChunk(const G3D::ReferenceCountedPointer<Chunk>& firstChunk)
			: Chunk(firstChunk->polygonOffset),
			  _castsShadows(firstChunk->castsShadows()),
			  _cullable(firstChunk->cullable())
		{
			if (!randomColors)
				material = firstChunk->getMaterial();

			RenderStats::aggregateChunkCount++;
			RenderStats::chunkCount--;

			if (randomColors)
			{
				material = createMaterial();
				material->appendLevel(NULL, (G3D::Color3::wheelRandom() + G3D::Color3::white()) / 2.0f, 0.0f, 50.0f, 0.0f, 0.0f);
			}
		}

		AggregateChunk::~AggregateChunk()
		{
			RenderStats::chunkCount++;
			RenderStats::aggregateChunkCount--;
			RenderStats::aggregatedChunkCount -= components.size();
		}

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

		G3D::ReferenceCountedPointer<MaterialBase> AggregateChunk::getMaterial()
		{
			return material;
		}

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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class G3D::ReferenceCountedPointer<G3D::VARArea>;
template class G3D::ReferenceCountedPointer<RBX::RenderBase::Chunk>;
template class G3D::ReferenceCountedPointer<RBX::RenderBase::MaterialBase>;
template class std::_Container_base_aux_alloc_real<std::allocator<G3D::ReferenceCountedPointer<RBX::RenderBase::Chunk> > >;
