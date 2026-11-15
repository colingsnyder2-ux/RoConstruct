// 2008-06 native RBX::ViewNew::ViewRbxGfx leaves (inactive; document-swap flags, /O2). Rows: getMeshDetail 004d76d0,
// updateSettings 004db660, getRenderStats 004db6f0 (all three shared with ViewG3D by ICF), invalidateLighting 004d7180;
// getWorkspace 004d7370 (shared with ViewG3D by ICF; dataModel->workspace +0x204 through the committed native
// DataModel.h / Workspace.h). getShadingQuality 0064a390 and updateLighting 0047d410 are ICF-folded with unrelated
// code and recorded as folded. The ctor / dtor (Lighting and workspace connections, mesh-cache flushes), render (its
// 004dab50 lighting helper), suppressSkybox and onWorkspaceDescendentAdded need declarations owned elsewhere and are
// not built.
#include "RenderLib/ViewNew2008.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"

namespace RBX
{
	namespace ViewNew
	{
		float ViewRbxGfx::getShadingQuality() const
		{
			return renderLibScene->getShadingQuality();
		}

		float ViewRbxGfx::getMeshDetail() const
		{
			return renderLibScene->getMeshDetail();
		}

		void ViewRbxGfx::updateSettings(float shadingQuality, float meshDetail, bool shadows, float cameraDistance)
		{
			renderLibScene->setThrottle(shadingQuality, meshDetail, shadows, cameraDistance);
		}

		Instance* ViewRbxGfx::getWorkspace()
		{
			return dataModel->getWorkspace();
		}

		RenderStats& ViewRbxGfx::getRenderStats()
		{
			return renderLibScene->renderStats;
		}

		void ViewRbxGfx::updateLighting()
		{
		}

		void ViewRbxGfx::invalidateLighting(bool updateSkybox)
		{
			lightingValid = false;
			if (updateSkybox)
				skyValid = false;
		}
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::auto_ptr<RBX::RenderBase::RenderSceneBase>;
template class std::deque<G3D::Token,std::allocator<G3D::Token> >;
