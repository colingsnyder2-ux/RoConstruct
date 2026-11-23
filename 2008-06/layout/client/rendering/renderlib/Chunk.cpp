// =============================================================================
// Chunk.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/renderlib/Chunk.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "RenderLib/SceneManager2008.h"
#include "OgreRbx/RbxEntity2008.h"
#include "RenderLib/RenderScene2008.h"

namespace RBX
{
	namespace RenderBase
	{
		inline void Chunk::releaseEntity()
		{
			if (subEntity)
				entity->removeSubEntity(subEntity);
			subEntity = NULL;
			entity = NULL;
		}

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

#ifndef NATIVE_SCENE_MANAGER_EXTERNAL_CONSTRUCTORS
		SceneManager::SceneManager(RenderSceneBase* renderScene)
			: renderScene(renderScene)
		{
		}
#endif

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

#ifndef NATIVE_SCENE_MANAGER_EXTERNAL_CONSTRUCTORS
		SimpleSceneManager::SimpleSceneManager(RenderSceneBase* renderScene)
			: SceneManager(renderScene)
		{
		}
#endif

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
