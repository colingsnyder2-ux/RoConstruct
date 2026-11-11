#pragma once
// Native copy of rbxgs IRenderable.h with indexFunc2d/indexFunc3d made public
// to work around VS2008 template friend access limitation:
//   IndexArray<IRenderable, &IRenderable::indexFunc2d> in IRenderableBucket
// requires access to the private member function pointer, which VS2008 rejects
// even though IRenderableBucket is a friend. Native-only glue fix.
#include "RbxGraphics/Adorn.h"
#include "AppDraw/SelectState.h"
#include "util/IndexArray.h"

namespace RBX 
{
	class IRenderableBucket;

	class __declspec(novtable) IRenderable
	{
		friend class IRenderableBucket;

	public:  // was private - native glue fix for VS2008 friend/template access
		int& indexFunc2d()
		{
			return index2d;
		}

		int& indexFunc3d()
		{
			return index3d;
		}

	private:
		int index2d;
		int index3d;
		IRenderableBucket* bucket;

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
