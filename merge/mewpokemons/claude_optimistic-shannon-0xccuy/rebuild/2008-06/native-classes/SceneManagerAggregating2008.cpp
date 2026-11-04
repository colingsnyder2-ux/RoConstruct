// 2008-06 native RBX::RenderBase::AggregatingSceneManager / Bucket (inactive): RenderBase library unit, built with the
// /Od profile of tests/record_native_render_scene.py. Rows: Bucket ctor 00540390 / dtor 00540440 / ??_G 00540410,
// AggregatingSceneManager::addModel 0053f1e0. The manager's ctor 0053f0d0 / dtor 0053f160 / ??_G 00540300 and the
// BucketKey bodies need the RenderBase material class (map<BucketKey, ...> node destruction) and are not built.
#include "RenderLib/SceneManager2008.h"

namespace RBX
{
	namespace RenderBase
	{
		AggregatingSceneManager::Bucket::Bucket()
		{
		}

		void AggregatingSceneManager::addModel(const G3D::ReferenceCountedPointer<Chunk>& chunk)
		{
			addToScene(chunk);
		}
	}
}
