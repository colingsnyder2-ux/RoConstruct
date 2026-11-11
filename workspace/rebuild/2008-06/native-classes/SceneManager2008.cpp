// 2008-06 native RBX::RenderBase::Chunk (base members) and SceneManager / SimpleSceneManager (inactive).
// Rows: Chunk 004e8160 / 004e81d0 / 004e5b60 / 004e5b70, SceneManager 004d6f60 / 004d6f50 / 004d7350,
// SimpleSceneManager 004d7320 / 00458e90 (setSleeping, prerender). The chunk-array bodies (addToScene / addModel
// 004d7db0, removeFromScene 004d8320, removeModel 004d8380, clear 004d8310) use the RenderSceneBase chunkArray +0x8
// (RenderLib/RenderScene2008.h).
// >>> native-status (generated) -- do not edit >>>
// SceneManager2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 76ae9185 | roc native-status --write
#include "RenderLib/SceneManager2008.h"
#include "RenderLib/RenderScene2008.h"

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

		void SceneManager::clearScene()
		{
			renderScene->chunkArray.clear();
		}

		void SceneManager::addToScene(const G3D::ReferenceCountedPointer<Chunk>& chunk)
		{
			renderScene->chunkArray.push_back(chunk);
		}

		void SceneManager::removeFromScene(const G3D::ReferenceCountedPointer<Chunk>& chunk)
		{
			renderScene->chunkArray.fastRemove(renderScene->chunkArray.findIndex(chunk));
		}

		SimpleSceneManager::SimpleSceneManager(RenderSceneBase* renderScene)
			: SceneManager(renderScene)
		{
		}

		void SimpleSceneManager::invalidateModel(const G3D::ReferenceCountedPointer<Chunk>& chunk, bool isSleeping)
		{
			chunk->releaseEntity();
		}

		void SimpleSceneManager::addModel(const G3D::ReferenceCountedPointer<Chunk>& chunk)
		{
			addToScene(chunk);
		}

		void SimpleSceneManager::removeModel(const G3D::ReferenceCountedPointer<Chunk>& chunk)
		{
			removeFromScene(chunk);
		}

		void SimpleSceneManager::clear()
		{
			clearScene();
		}

		void SimpleSceneManager::setSleeping(const G3D::ReferenceCountedPointer<Chunk>& chunk, bool sleeping)
		{
		}

		void SimpleSceneManager::prerender(double time)
		{
		}
	}
}
