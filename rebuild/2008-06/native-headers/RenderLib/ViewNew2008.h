#pragma once
// >>> native-status (generated) -- do not edit >>>
// ViewNew2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src f21a0481 | roc native-status --write
// 2008-06 native RBX::ViewNew::ViewRbxGfx (inactive). Named *2008.h so it never shadows a donor header.
//   ViewRbxGfx   RTTI vtable 00826c70 -> ViewBase (mdisp 0); new 0x4c (CRobloxWnd 0045b3ba, ctor 004d9990 with the
//                DataModel shared_ptr by value); ctor: ViewBase(dataModel) 004d8a20, vptr, +0x48 = false, then new 0x590
//                RenderNew::RenderScene (007aae40), new 0x18 TextureManager(0xa00000), new 8 SimpleSceneManager (vtable
//                00826b64, renderScene +4), new 0x10 MaterialFactory (004f0920), renderLibScene->setThrottle(0, 0, false,
//                0), then the Lighting / workspace connections. dtor 004db4f0; ??_G 004db5d0.
//                Slots: 0 ??_G 004db5d0, 1 render 004daf10, 2 getShadingQuality 0064a390 (renderLibScene slot 3 as a
//                tail call; ICF-folded with CleanStage code), 3 getMeshDetail 004d76d0, 4 updateSettings 004db660,
//                5 suppressSkybox 004d9c90, 6 getWorkspace 004d7370 (dataModel->workspace +0x204), 7 getRenderStats
//                004db6f0, 8 onWorkspaceDescendentAdded 004db7c0, 9 updateLighting 0047d410 (empty; generic `ret`),
//                10 invalidateLighting 004d7180 (lightingValid +0x44 = false; if (updateSkybox) +0x48 = false).
//                Slots 3, 4, 6, 7 and 8 are shared with ViewG3D 00826e04 (identical bodies, ICF).
//   ViewG3D      RTTI vtable 00826e04 -> ViewBase (mdisp 0); new 0x6c (0045d86a); ctor 004dbbe0: ViewBase(dataModel),
//                vptr, +0x48 = NULL (an RCP: invalidateLighting 004db610 releases it through ReferenceCountedObject),
//                +0x4c std::map (ctor 00446110; 0x20 bytes, node erase 00553ca0 in the dtor 004dc270); ??_G 004dc340.
//                Not declared here: the map's key / value types are not derived yet.
#include "RenderLib/ViewBase2008.h"

struct NativeRenderSceneLayout;
namespace Ogre { class VisualEngine; }

namespace RBX
{
	namespace ViewNew
	{
		class ViewRbxGfx : public ViewBase
		{
			friend struct ::NativeRenderSceneLayout;
		private:
			bool skyValid;                                                  // +0x48 (cleared by invalidateLighting)

		public:
			// INFERRED: direct caller and 004d9e00 donor body establish method ABI.
			void updateSkybox(Ogre::VisualEngine*);
			ViewRbxGfx(boost::shared_ptr<DataModel> dataModel);             // 004d9990
			virtual ~ViewRbxGfx();                                          // 004db4f0 (??_G 004db5d0)
			virtual void render(G3D::RenderDevice* rd);                    // 004daf10
			virtual float getShadingQuality() const;                        // 0064a390 (folded)
			virtual float getMeshDetail() const;                            // 004d76d0
			virtual void updateSettings(float shadingQuality, float meshDetail, bool shadows, float cameraDistance); // 004db660
			virtual void suppressSkybox();                                  // 004d9c90
			virtual Instance* getWorkspace();                               // 004d7370
			virtual RenderStats& getRenderStats();                          // 004db6f0
		private:
			virtual void onWorkspaceDescendentAdded(boost::shared_ptr<Instance> descendent); // 004db7c0
			virtual void updateLighting();                                  // 0047d410 (folded)
			virtual void invalidateLighting(bool updateSkybox);             // 004d7180
		};
	}
}
