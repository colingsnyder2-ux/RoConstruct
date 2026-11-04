// 2008-06 native RBX::RenderBase::Chunk (base members) and SceneManager / SimpleSceneManager (inactive).
// Rows: Chunk 004e8160 / 004e81d0 / 004e5b60 / 004e5b70, SceneManager 004d6f60 / 004d6f50 / 004d7350,
// SimpleSceneManager 004d7320 / 00458e90 (setSleeping, prerender). The chunk-array bodies (addToScene 004d7db0,
// removeFromScene 004d8320, removeModel 004d8380, clear 004d8310) need the RenderSceneBase layout, whose +0x4 member
// is not derived yet; they are declared only and bound to the original addresses by the recorder.
#include "RenderLib/SceneManager2008.h"

namespace RBX
{
	namespace RenderBase
	{
		Chunk::Chunk(float polygonOffset)
			: sortValue(0.0f),
			  polygonOffset(polygonOffset),
			  radius(G3D::inf())
		{
			RenderStats::chunkCount++;
			subEntity = NULL;
			entity = NULL;
		}

		Chunk::~Chunk()
		{
			RenderStats::chunkCount--;
			if (subEntity)
				entity->removeSubEntity(subEntity);
		}

		void Chunk::setSortValue(float value)
		{
			sortValue = value;
		}

		float Chunk::getSortValue() const
		{
			return sortValue;
		}

		SceneManager::SceneManager(RenderSceneBase* renderScene)
			: renderScene(renderScene)
		{
		}

		SceneManager::~SceneManager()
		{
		}

		SimpleSceneManager::SimpleSceneManager(RenderSceneBase* renderScene)
			: SceneManager(renderScene)
		{
		}

		void SimpleSceneManager::invalidateModel(const G3D::ReferenceCountedPointer<Chunk>& chunk, bool isSleeping)
		{
			chunk->releaseEntity();
		}

		void SimpleSceneManager::setSleeping(const G3D::ReferenceCountedPointer<Chunk>& chunk, bool sleeping)
		{
		}

		void SimpleSceneManager::prerender(double time)
		{
		}
	}
}
