// 2008-06 native RBX::RenderBase::AggregatingSceneManager members (inactive), the RenderBase AggregatingSceneManager.cpp
// unit 0053f0d0..005473ff. Built by tests/record_native_app_unit540_2008.py with the RenderBase library profile of
// tests/record_native_render_scene.py (/Od /Ob0 /GS plus the Ogre 1.4.5 client headers) against the read-only
// native RenderLib/SceneManager2008.h. native-classes/SceneManagerAggregating2008.cpp (render-scene owner) holds the
// ctor / dtor / addModel / invalidateModel / removeModel / clear / setSleeping and the Bucket ctor; this file holds
// the members that file does not define:
//   BucketKey::operator<            0053f280 (material, castsShadows, polygonOffset, cullable; donor order, but a
//                                             final `return false` after the last if: the donor's else costs a
//                                             second jmp, 190 vs 188 B)
//   queueSleepingChunk              0053f340 (new 0x24 Bucket at 0053f3b9; map find 005409e0 / operator[] 00540830)
//   dequeueSleepingChunk            0053f470 (a while loop with prefix ++ 00540eb0 at its end: the call at 0053f4d3
//                                             pushes no int argument; the donor for loop is 114 vs 112 B)
//   Bucket::dequeueSleepingChunk    0053f4e0 (std::find 00545d40, vector::erase 00540710)
//   deconstructAggregate            005400f0 (components +0xf0 begin / end once, aggregate weak pointer reset through a
//                                             NULL RCP temporary 004e6030 / 00540530, aggregatedChunkCount 00972890 -=
//                                             1 per component, addToScene 004d7db0, setSleeping slot 4 (+0x10) with
//                                             true, then removeFromScene(RCP<Chunk>(aggregate)) 00545e30 / 004d8320
//                                             and components.clear() 00540780)
//   Bucket::clear                   005404b0 (queue.clear() 00540780)
// >>> native-status (generated) -- do not edit >>>
// AppUnit540_2008AggregatingSceneManager | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src c7fe7f19 | roc native-status --write
#include "RenderLib/SceneManager2008.h"
#include "RenderLib/Material2008.h"   // completes RenderBase::MaterialBase (needs the Ogre 1.4.5 client headers)
#include <algorithm>

namespace RBX
{
	namespace RenderBase
	{
		bool AggregatingSceneManager::BucketKey::operator<(const BucketKey& that) const
		{
			if (this->material < that.material)
				return true;
			if (this->material > that.material)
				return false;

			if (this->castsShadows < that.castsShadows)
				return true;
			if (this->castsShadows > that.castsShadows)
				return false;

			if (this->polygonOffset < that.polygonOffset)
				return true;
			if (this->polygonOffset > that.polygonOffset)
				return false;

			if (this->cullable < that.cullable)
				return true;

			return false;
		}

		void AggregatingSceneManager::queueSleepingChunk(const G3D::ReferenceCountedPointer<Chunk>& chunk)
		{
			G3D::ReferenceCountedPointer<Bucket> queue;

			{
				BucketKey key(chunk);

				std::map<BucketKey, G3D::ReferenceCountedPointer<Bucket> >::iterator iter = buckets.find(key);

				if (iter == buckets.end())
				{
					queue = new Bucket;
					buckets[key] = queue;
				}
				else
				{
					queue = iter->second;
				}
			}

			queue->addToQueue(chunk);
		}

		void AggregatingSceneManager::dequeueSleepingChunk(const G3D::ReferenceCountedPointer<Chunk>& chunk)
		{
			std::map<BucketKey, G3D::ReferenceCountedPointer<Bucket> >::iterator iter = buckets.begin();
			std::map<BucketKey, G3D::ReferenceCountedPointer<Bucket> >::iterator end = buckets.end();

			while (iter != end)
			{
				if (iter->second->dequeueSleepingChunk(chunk))
					break;
				++iter;
			}
		}

		bool AggregatingSceneManager::Bucket::dequeueSleepingChunk(const G3D::ReferenceCountedPointer<Chunk>& chunk)
		{
			std::vector<G3D::ReferenceCountedPointer<Chunk> >::iterator found = std::find(queue.begin(), queue.end(), chunk);

			if (found != queue.end())
			{
				queue.erase(found);
				return true;
			}
			else
			{
				return false;
			}
		}

		void AggregatingSceneManager::deconstructAggregate(G3D::ReferenceCountedPointer<AggregateChunk> aggregate)
		{
			std::vector<G3D::ReferenceCountedPointer<Chunk> >::iterator iter = aggregate->components.begin();
			std::vector<G3D::ReferenceCountedPointer<Chunk> >::iterator end = aggregate->components.end();

			while (iter != end)
			{
				const G3D::ReferenceCountedPointer<Chunk>& chunk = *iter;
				chunk->aggregate = NULL;
				RenderStats::aggregatedChunkCount--;
				addToScene(chunk);
				setSleeping(chunk, true);
				++iter;
			}

			removeFromScene(aggregate);
			aggregate->components.clear();
		}

		void AggregatingSceneManager::Bucket::clear()
		{
			queue.clear();
		}
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Tmap_traits<RBX::RenderBase::AggregatingSceneManager::BucketKey,G3D::ReferenceCountedPointer<RBX::RenderBase::AggregatingSceneManager::Bucket>,std::less<RBX::RenderBase::AggregatingSceneManager::BucketKey>,std::allocator<std::pair<RBX::RenderBase::AggregatingSceneManager::BucketKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::AggregatingSceneManager::Bucket> > >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::RenderBase::AggregatingSceneManager::BucketKey,G3D::ReferenceCountedPointer<RBX::RenderBase::AggregatingSceneManager::Bucket>,std::less<RBX::RenderBase::AggregatingSceneManager::BucketKey>,std::allocator<std::pair<RBX::RenderBase::AggregatingSceneManager::BucketKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::AggregatingSceneManager::Bucket> > >,0> >;
template class std::_Vector_const_iterator<G3D::ReferenceCountedPointer<RBX::RenderBase::Chunk>,std::allocator<G3D::ReferenceCountedPointer<RBX::RenderBase::Chunk> > >;
template class std::_Vector_iterator<G3D::ReferenceCountedPointer<RBX::RenderBase::Chunk>,std::allocator<G3D::ReferenceCountedPointer<RBX::RenderBase::Chunk> > >;
template class std::allocator<G3D::ReferenceCountedPointer<RBX::RenderBase::Chunk> >;
template class std::allocator<std::pair<RBX::RenderBase::AggregatingSceneManager::BucketKey const ,G3D::ReferenceCountedPointer<RBX::RenderBase::AggregatingSceneManager::Bucket> > >;
template class std::vector<G3D::ReferenceCountedPointer<RBX::RenderBase::Chunk>,std::allocator<G3D::ReferenceCountedPointer<RBX::RenderBase::Chunk> > >;
