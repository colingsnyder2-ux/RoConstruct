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
	}
}
