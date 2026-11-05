// 2008-06 native RBX::ViewNew::ViewG3D (inactive; document-swap flags, /O2, /fp:fast). Rows: invalidateLighting
// 004db610 and render 004db690. The ctor 004dbbe0 / dtor 004dc270 / ??_G 004dc340, suppressSkybox 004dbf00 and
// updateLighting 004dc040 need declarations owned elsewhere (ViewNew::MaterialFactory, the Lighting service, the
// ViewNew mesh-cache flushes, the Lighting / descendant-added signal descriptors) and are not built here.
#include "ViewG3D2008/ViewG3D2008.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"

namespace RBX
{
	namespace ViewNew
	{
		void ViewG3D::render(G3D::RenderDevice* rd)
		{
			updateLighting();
			sceneManager->prerender(0.1f);
			Workspace* workspace = dataModel->getWorkspace();
			RenderBase::RenderSceneBase* scene = renderLibScene.get();
			scene->render(rd, workspace->getGCamera());
		}

		void ViewG3D::invalidateLighting(bool updateSkybox)
		{
			lightingValid = false;
			if (updateSkybox)
				sky = NULL;
		}
	}
}
