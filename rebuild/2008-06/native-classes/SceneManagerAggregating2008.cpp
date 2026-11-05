// 2008-06 native RBX::RenderBase::AggregatingSceneManager / Bucket (inactive): RenderBase library unit, built with the
// /Od profile of tests/record_native_render_scene.py. Rows: Bucket ctor 00540390 / dtor 00540440 / ??_G 00540410,
// AggregatingSceneManager::addModel 0053f1e0, ctor 0053f0d0 / dtor 0053f160 / ??_G 00540300 and the BucketKey ctor
// 0053f200 (these use the complete RenderBase::MaterialBase from RenderLib/Material2008.h).
#include "RenderLib/SceneManager2008.h"
#include "RenderLib/Material2008.h"   // completes RenderBase::MaterialBase (needs the Ogre 1.4.5 client headers)

namespace RBX
{
	namespace RenderBase
	{
		AggregatingSceneManager::AggregatingSceneManager(RenderSceneBase* renderScene)
			: SceneManager(renderScene)
		{
		}

		AggregatingSceneManager::~AggregatingSceneManager()
		{
		}

		AggregatingSceneManager::BucketKey::BucketKey(const G3D::ReferenceCountedPointer<Chunk>& that)
			: castsShadows(that->castsShadows()),
			  cullable(that->cullable()),
			  polygonOffset(that->polygonOffset),
			  material(that->getMaterial())
		{
		}

		AggregatingSceneManager::Bucket::Bucket()
		{
		}

		void AggregatingSceneManager::addModel(const G3D::ReferenceCountedPointer<Chunk>& chunk)
		{
			addToScene(chunk);
		}

		void AggregatingSceneManager::invalidateModel(const G3D::ReferenceCountedPointer<Chunk>& chunk, bool isSleeping)
		{
			if (isSleeping)
			{
				invalidSleepingModels.insert(chunk);
				// two empty loops follow each insert in the /Od original (xor / jne pairs 005402a5 / 005402a9 and
				// 005402e4 / 005402e8): statements compiled out in this build, kept as empty statements
				do {} while (0); do {} while (0);
			}
			else
			{
				invalidMovingModels.insert(chunk);
				do {} while (0); do {} while (0);
			}
		}

		void AggregatingSceneManager::removeModel(const G3D::ReferenceCountedPointer<Chunk>& chunk)
		{
			invalidSleepingModels.erase(chunk);
			invalidMovingModels.erase(chunk);

			G3D::ReferenceCountedPointer<AggregateChunk> aggregate = chunk->aggregate.createStrongPtr();
			if (aggregate.notNull())
			{
				deconstructAggregate(aggregate);
				removeFromScene(chunk);
			}
			else
				removeFromScene(chunk);

			dequeueSleepingChunk(chunk);
		}

		void AggregatingSceneManager::clear()
		{
			invalidSleepingModels.clear();
			invalidMovingModels.clear();

			std::map<BucketKey, G3D::ReferenceCountedPointer<Bucket> >::iterator iter = buckets.begin();
			std::map<BucketKey, G3D::ReferenceCountedPointer<Bucket> >::iterator end = buckets.end();

			while (iter != end)
			{
				iter->second->clear();
				++iter;
			}

			clearScene();
		}

		void AggregatingSceneManager::setSleeping(const G3D::ReferenceCountedPointer<Chunk>& chunk, bool sleeping)
		{
			if (sleeping)
			{
				if (invalidMovingModels.erase(chunk) == 1)
					invalidSleepingModels.insert(chunk);

				queueSleepingChunk(chunk);
			}
			else
			{
				if (invalidSleepingModels.erase(chunk) == 1)
					invalidMovingModels.insert(chunk);

				G3D::ReferenceCountedPointer<AggregateChunk> aggregate = chunk->aggregate.createStrongPtr();
				if (aggregate.notNull())
					deconstructAggregate(aggregate);

				dequeueSleepingChunk(chunk);
			}
		}
	}
}
