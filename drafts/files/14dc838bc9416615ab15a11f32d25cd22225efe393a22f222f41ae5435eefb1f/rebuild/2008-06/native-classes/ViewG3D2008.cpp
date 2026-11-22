// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/viewrbx-ctor-profile /I{headers}/partchunk-profile /I{headers}/g3d-image-2008 /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// 2008-06 native RBX::ViewNew::ViewG3D (inactive; document-swap flags, /O2, /fp:fast). Rows: invalidateLighting
// 004db610, render 004db690 and suppressSkybox 004dbf00 (Lighting2008.h getters; the clear colour through getClearColor()
// by value, all four loads before the stores, needs /fp:fast). The ctor 004dbbe0 (batch 42) needs the
// viewrbx-ctor-profile MaterialFactory(TextureManager*) and the partchunk-profile TextureProxyBase forwarder; dtor 004dc270 /
// ??_G 004dc340 and updateLighting 004dc040 follow.
#include "ViewG3D2008/ViewG3D2008.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Lighting2008.h"
#include "v8tree/Service.h"
#include "RenderLib/RenderScene2008.h"
#include "v8datamodel/Sky.h"
#include "util/StandardOut.h"
#include <G3D/GImage.h>
#include "ViewNew/CylinderMesh.h"
#include "ViewNew/SphereMesh.h"
#include "ViewNew/PBBMesh.h"
#include "ViewNew/BrickMesh.h"
#include "ViewNew/WedgeMesh.h"
#include "ViewNew/HeadMesh.h"
#include "ViewNew/TorsoMesh.h"
#include "RenderLib/RenderSceneRender2008.h"
#include "RenderLib/SceneManager2008.h"
#include <GLG3D/TextureManager.h>
#include <boost/bind.hpp>

namespace RBX
{
	namespace ViewNew
	{
		// 004dbbe0 (new 0x6c at 0045d86a). The ViewRbxGfx ctor 004d9990 shape (ViewRbxGfxConstructor2008.cpp) with the old
		// renderer: new 0x500 Render::RenderScene 00505040, new 0x18 TextureManager(0xa00000) 0047e400, new 0x68
		// AggregatingSceneManager 0053f0d0, new 0x10 MaterialFactory 004f0920, setThrottle (slot 2), the
		// Lighting-changed (0097a88c) and Workspace descendant-added (00973e40) connections.
		ViewG3D::ViewG3D(boost::shared_ptr<DataModel> dataModel)
			: ViewBase(dataModel)
		{
			renderLibScene.reset(new Render::RenderScene);
			textureManager.reset(new G3D::TextureManager(0xa00000));
			sceneManager.reset(new RenderBase::AggregatingSceneManager(renderLibScene.get()));
			materialFactory.reset(new MaterialFactory(textureManager.get()));
			renderLibScene->setThrottle(0.f, 0.f, false, 0.f);
			Lighting* lighting = ServiceProvider::create<Lighting>(static_cast<ServiceProvider*>(dataModel.get())); // 004b3870
			lightingChangedConnection = Lighting::event_LightingChanged.connect(lighting, boost::bind(&ViewG3D::invalidateLighting, this, _1), 10);
			dataModel->getWorkspace()->visitDescendents(boost::bind(&ViewG3D::onWorkspaceDescendentAdded, this, _1));
			workspaceDescendentAddedConnection = Instance::event_descendentAdded.connect(dataModel->getWorkspace(), boost::bind(&ViewG3D::onWorkspaceDescendentAdded, this, _1), 10);
		}

		// 004dc270 (??_G 004dc340, vtable 00826e04 slot 0). Same shape as ~ViewRbxGfx 004db4f0 (ViewRbxGfxLifecycle2008.cpp):
		// sceneManager->clear() (slot 3), the Lighting lookup 004b3380 behind the dataModel +0x14 null test, the seven
		// mesh-cache flushes 004db130 / 004db040 / 004daf50 / 004e5670 / 004db310 / 004db220 / 004db400, then the
		// implicit ~map (_Tree dtor 00553d80), ~sky (+0x48 release) and ~ViewBase 004d8920. Unlike ~ViewRbxGfx it does
		// not reset the ViewBase auto_ptrs itself.
		ViewG3D::~ViewG3D()
		{
			sceneManager->clear();
			ServiceProvider::find<Lighting>(dataModel.get());
			CylinderAlongXMesh::flushCache();
			SphereMesh::flushCache();
			PBBMesh::flushCache();
			BrickMesh::flushCache();
			WedgeMesh::flushCache();
			HeadMesh::flushCache();
			TorsoMesh::flushCache();
		}

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

		// 004dc040 (vtable 00826e04 slot 9). The static Sky factory 005ebbb0 (cdecl, hidden RCP result, one Sky*
		// argument: `push [lighting+0x2d4]; push &tmp; call; add esp, 8`) is declared in v8datamodel/Sky.h. Donor name and signature:
		// tools/rbxgs App/include/v8datamodel/Sky.h `static G3D::ReferenceCountedPointer<G3D::Sky> getG3DSky(Sky*);`
		// (openrbx: ?getG3DSky@Sky@RBX@@SA?AV?$ReferenceCountedPointer@VSky@G3D@@@G3D@@PAV12@@Z). Shape: openrbx
		// Client/RbxView/View.cpp View::updateLighting; 2008 evidence: lightingValid +0x44, dataModel +0x14 null test
		// before 004b3870 (as in suppressSkybox 004dbf00), hasSky +0x240 == 0 releases sky +0x48, otherwise a null sky
		// is reloaded in a try block (RCP setPointer 00598fa0 / zeroPointer 00502a70) with catch (G3D::GImage::Error& e)
		// -> StandardOut::singleton 00569620 ->print(MESSAGE_ERROR 3, 00826dc4, e.reason.c_str() (+0x28)) and
		// catch (...) -> print(3, 00826dac); then presetLighting (slot 1) with LightingParameters copy 004d7020, the
		// clear colour (all four loads before the stores) and lightingValid = true.
		// NEAR MISS (561 B vs 560 B; only the entry differs: `xor ebx,ebx; mov [ebp-0x1c],ebx`). Rejected in batch 30:
		// a named RCP local for the getG3DSky result (562 B); `sky = G3D::ReferenceCountedPointer<G3D::Sky>()` in the
		// !hasSky branch (532 B: it does create the zeroed -0x1c temporary and the ebx zero register, but setPointer
		// stays out of line). Parked after 3 hypotheses.
		void ViewG3D::updateLighting()
		{
			if (!lightingValid)
			{
				Lighting* lighting = ServiceProvider::create<Lighting>(static_cast<ServiceProvider*>(dataModel.get()));

				if (!lighting->hasSky)
				{
					sky = NULL;
				}
				else if (sky.isNull())
				{
					try
					{
						sky = Sky::getG3DSky(lighting->sky.get());
					}
					catch (const G3D::GImage::Error& e)
					{
						StandardOut::singleton()->print(MESSAGE_ERROR, "Failed to load sky box. %s", e.reason.c_str());
					}
					catch (...)
					{
						StandardOut::singleton()->print(MESSAGE_ERROR, "Failed to load sky box");
					}
				}

				renderLibScene->presetLighting(sky, lighting->getSkyParameters(), lighting->getAmbientTop(),
				                               lighting->getAmbientBottom());
				renderLibScene->colorClearValue = lighting->getClearColor();

				lightingValid = true;
			}
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
