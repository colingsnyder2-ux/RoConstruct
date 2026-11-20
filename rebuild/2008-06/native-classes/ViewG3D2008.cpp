// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// 2008-06 native RBX::ViewNew::ViewG3D (inactive; document-swap flags, /O2, /fp:fast). Rows: invalidateLighting
// 004db610, render 004db690 and suppressSkybox 004dbf00 (Lighting2008.h getters; the clear colour through getClearColor()
// by value, all four loads before the stores, needs /fp:fast). The ctor 004dbbe0 / dtor 004dc270 / ??_G 004dc340 and updateLighting 004dc040 need declarations owned elsewhere (ViewNew::MaterialFactory, the Lighting service, the
// ViewNew mesh-cache flushes, the Lighting / descendant-added signal descriptors) and are not built here.
#include "ViewG3D2008/ViewG3D2008.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Lighting2008.h"
#include "v8tree/Service.h"
#include "RenderLib/RenderScene2008.h"

namespace RBX
{
	namespace ViewNew
	{
		// 004dbf00: presetLighting slot 1 with a NULL sky (004dbfbe), sky = NULL after it, then the clear colour copy.
		void ViewG3D::suppressSkybox()
		{
			Lighting* lighting = ServiceProvider::create<Lighting>(static_cast<ServiceProvider*>(dataModel.get()));
			renderLibScene->presetLighting(NULL, lighting->getSkyParameters(),
			                               lighting->getAmbientTop(), lighting->getAmbientBottom());
			sky = NULL;
			renderLibScene->colorClearValue = lighting->getClearColor();
		}

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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class G3D::ReferenceCountedPointer<G3D::Sky>;
