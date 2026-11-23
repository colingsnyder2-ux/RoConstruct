// =============================================================================
// IRenderable.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/IRenderable.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "RbxGraphics/Adorn.h"
#include "AppDraw/SelectState.h"
#include "util/IndexArray.h"

namespace RBX
{
	class IRenderableBucket;

	class __declspec(novtable) IRenderable
	{
		friend class IRenderableBucket;

	private:
		int index2d;
		int index3d;
		IRenderableBucket* bucket;

		public:
		int& indexFunc2d()
		{
			return index2d;
		}

		int& indexFunc3d()
		{
			return index3d;
		}

	protected:
		virtual bool shouldRender2d() const
		{
			return false;
		}

		virtual bool shouldRender3dAdorn() const
		{
			return false;
		}

	public:
		IRenderable() : index2d(-1), index3d(-1), bucket(NULL)
		{
		}

		~IRenderable();

		void shouldRenderSetDirty();

		virtual void render2d(Adorn* adorn)
		{
			return;
		}

		virtual void render3dAdorn(Adorn* adorn)
		{
			return;
		}

		virtual void render3dSelect(Adorn* adorn, SelectState selectState)
		{
			return;
		}
	};

	class IRenderableBucket
	{
		friend class IRenderable;

	private:
		IndexArray<IRenderable, &IRenderable::indexFunc2d> renderable2ds;
		IndexArray<IRenderable, &IRenderable::indexFunc3d> renderable3ds;

	protected:
		void onAdded(IRenderable* iR);
		void onRemoving(IRenderable* iR);
		void recomputeShouldRender(IRenderable* iR);

	public:
		~IRenderableBucket();

		void render2dItems(Adorn* adorn);
		void render3dAdornItems(Adorn* adorn);
	};
}
