// from server: 100% by EspClaude
// from server: 99% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-render roc_espclaude_4a80d4abc73b87af.cpp

// Candidate translation unit (score above; library headers required).

#include "RenderLib/RenderScene.h"
#include <boost/noncopyable.hpp>
#include <map>
#include <set>

namespace RBX
{
	namespace Render
	{
		class AggregatingSceneManager : public SceneManager
		{
			class Bucket : public G3D::ReferenceCountedObject, public boost::noncopyable
			{
			private:
				std::vector<G3D::ReferenceCountedPointer<Chunk>> queue;
			public:
				bool dequeueSleepingChunk(const G3D::ReferenceCountedPointer<Chunk>& chunk);
				void addToQueue(const G3D::ReferenceCountedPointer<Chunk>&);
				void clear()
				{
					queue.clear();
				}
				void optimize(AggregatingSceneManager&, double);
			};

			struct BucketKey
			{
				bool castsShadows;
				bool cullable;
				float polygonOffset;
				G3D::ReferenceCountedPointer<Material> material;
				char exePad[8];

				BucketKey(const G3D::ReferenceCountedPointer<Chunk>& that)
					: castsShadows(that->castsShadows()),
					  cullable(that->cullable()),
					  polygonOffset(that->polygonOffset),
					  material(that->getMaterial())
				{
				}

				bool operator<(const BucketKey&) const;
			};

		private:
			std::map<BucketKey, G3D::ReferenceCountedPointer<Bucket>> buckets;
			std::set<G3D::WeakReferenceCountedPointer<Chunk>> invalidSleepingModels;
			std::set<G3D::WeakReferenceCountedPointer<Chunk>> invalidMovingModels;
		public:
			static size_t aggregationSize;

		public:
			AggregatingSceneManager(RenderScene*);
			virtual ~AggregatingSceneManager();

			virtual void invalidateModel(const G3D::ReferenceCountedPointer<Chunk>& chunk, bool isSleeping);
			virtual void addModel(const G3D::ReferenceCountedPointer<Chunk>& chunk);
			virtual void removeModel(const G3D::ReferenceCountedPointer<Chunk>& chunk);
			virtual void clear();
			virtual void setSleeping(const G3D::ReferenceCountedPointer<Chunk>& chunk, bool sleeping);
			virtual void prerender(double);
		private:
			void dequeueSleepingChunk(const G3D::ReferenceCountedPointer<Chunk>& chunk);
			void queueSleepingChunk(const G3D::ReferenceCountedPointer<Chunk>& chunk);
			void deconstructAggregate(G3D::ReferenceCountedPointer<AggregateChunk>);
		};
	}
}


namespace RBX
{
	namespace Render
	{
		AggregatingSceneManager::AggregatingSceneManager(RenderScene* renderScene)
			: SceneManager(renderScene)
		{
		}

		AggregatingSceneManager::~AggregatingSceneManager() {}

		void AggregatingSceneManager::addModel(const G3D::ReferenceCountedPointer<Chunk>& chunk)
		{
			addToScene(chunk);
		}

		void AggregatingSceneManager::removeModel(const G3D::ReferenceCountedPointer<Chunk>& chunk)
		{
			invalidSleepingModels.erase(chunk);
			invalidMovingModels.erase(chunk);

			G3D::ReferenceCountedPointer<AggregateChunk> aggregate = chunk->aggregate.createStrongPtr();
			if (aggregate.notNull())
				deconstructAggregate(aggregate);

			removeFromScene(chunk);
			dequeueSleepingChunk(chunk);
		}

		void AggregatingSceneManager::setSleeping(const G3D::ReferenceCountedPointer<Chunk>& chunk, bool sleeping)
		{
			if (sleeping)
			{
				bool erased = invalidMovingModels.erase(chunk) == 1;

				if (erased)
					invalidSleepingModels.insert(chunk);

				queueSleepingChunk(chunk);
			}
			else
			{
				bool erased = invalidSleepingModels.erase(chunk) == 1;

				if (erased)
					invalidMovingModels.insert(chunk);

				G3D::ReferenceCountedPointer<AggregateChunk> aggregate = chunk->aggregate.createStrongPtr();
				if (aggregate.notNull())
					deconstructAggregate(aggregate);

				dequeueSleepingChunk(chunk);
			}
		}

		void AggregatingSceneManager::invalidateModel(const G3D::ReferenceCountedPointer<Chunk>& chunk, bool isSleeping)
		{
			if (isSleeping)
				invalidSleepingModels.insert(chunk);
			else
				invalidMovingModels.insert(chunk);
		}

		void AggregatingSceneManager::dequeueSleepingChunk(const G3D::ReferenceCountedPointer<Chunk>& chunk)
		{
			std::map<BucketKey, G3D::ReferenceCountedPointer<Bucket>>::iterator iter = buckets.begin();
			std::map<BucketKey, G3D::ReferenceCountedPointer<Bucket>>::iterator end = buckets.end();

			for (; iter != end; iter++)
			{
				if (iter->second->dequeueSleepingChunk(chunk))
					break;
			}
		}

		void AggregatingSceneManager::clear()
		{
			invalidSleepingModels.clear();
			invalidMovingModels.clear();

			std::map<BucketKey, G3D::ReferenceCountedPointer<Bucket>>::iterator iter = buckets.begin();
			std::map<BucketKey, G3D::ReferenceCountedPointer<Bucket>>::iterator end = buckets.end();

			for (; iter != end; iter++)
			{
				iter->second->clear();
			}

			clearScene();
		}

		bool AggregatingSceneManager::Bucket::dequeueSleepingChunk(const G3D::ReferenceCountedPointer<Chunk>& chunk)
		{
			std::vector<G3D::ReferenceCountedPointer<Chunk>>::iterator found = std::find(queue.begin(), queue.end(), chunk);

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

		void AggregatingSceneManager::queueSleepingChunk(const G3D::ReferenceCountedPointer<Chunk>& chunk)
		{
			G3D::ReferenceCountedPointer<Bucket> queue;

			{
				BucketKey key(chunk);

				std::map<BucketKey, G3D::ReferenceCountedPointer<Bucket>>::iterator iter = buckets.find(key);

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

		bool AggregatingSceneManager::BucketKey::operator<(const AggregatingSceneManager::BucketKey& that) const
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
			else
				return false;
		}
	}
}
