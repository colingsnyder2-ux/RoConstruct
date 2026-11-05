// 2008-06 native RBX::ViewNew::ViewRbxGfx leaves (inactive; document-swap flags, /O2). Rows: getMeshDetail 004d76d0,
// updateSettings 004db660, getRenderStats 004db6f0 (all three shared with ViewG3D by ICF), invalidateLighting 004d7180;
// getShadingQuality 0064a390 and updateLighting 0047d410 are ICF-folded with unrelated code and recorded as folded.
// The ctor / dtor (Lighting and workspace connections, mesh-cache flushes) and render / suppressSkybox / getWorkspace /
// onWorkspaceDescendentAdded need DataModel / Workspace / Lighting declarations owned elsewhere and are not built.
#include "RenderLib/ViewNew2008.h"

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
