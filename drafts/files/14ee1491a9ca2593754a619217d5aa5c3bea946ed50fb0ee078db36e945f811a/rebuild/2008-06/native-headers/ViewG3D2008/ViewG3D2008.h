#pragma once
// 2008-06 native RBX::ViewNew::ViewG3D (inactive). A new path (ViewG3D2008/ViewG3D2008.h) that shadows no donor header.
//   ViewG3D      RTTI vtable 00826e04 -> ViewBase (mdisp 0); new 0x6c at 0045d86a before the ctor 004dbbe0 (thiscall,
//                boost::shared_ptr<DataModel> by value, ret 8). ctor: ViewBase(dataModel) 004d8a20, vptr 00826e04,
//                +0x48 = NULL, +0x4c map ctor (_Tree(const less&, const allocator&) 00446110), then new 0x500
//                Render::RenderScene 00505040, new 0x18 TextureManager(0xa00000), new 0x68 AggregatingSceneManager
//                (0053f0d0, renderLibScene), new 0x10 MaterialFactory 004f0920, renderLibScene->setThrottle(0, 0, false,
//                0), then the Lighting-changed / workspace descendant-added connections.
//                dtor 004dc270: vptr, sceneManager->clear() (slot 3), the dataModel / mesh-cache calls shared with
//                ~ViewRbxGfx, then ~map (_Tree dtor 00553d80 -> erase 00553ca0), ~sky, ~ViewBase 004d8920. ??_G 004dc340.
//                11 slots: 0 ??_G 004dc340, 1 render 004db690, 2 getShadingQuality 0064a390, 3 getMeshDetail 004d76d0,
//                4 updateSettings 004db660, 5 suppressSkybox 004dbf00, 6 getWorkspace 004d7370, 7 getRenderStats
//                004db6f0, 8 onWorkspaceDescendentAdded 004db7c0, 9 updateLighting 004dc040, 10 invalidateLighting
//                004db610. Slots 2, 3, 4, 6, 7 and 8 hold the same (ICF) bodies as ViewRbxGfx 00826c70 (RenderLib/
//                ViewNew2008.h); they are declared here as overrides because the vtable is ViewG3D's own.
//   +0x48 sky    G3D::ReferenceCountedPointer<G3D::Sky>: released through ReferenceCountedObject (InterlockedDecrement,
//                zeroWeakPointers 0045ad90, slot 0 delete) in invalidateLighting 004db610 / suppressSkybox 004dbf00 /
//                the dtor; set from the Sky factory 005ebbb0 through RCP setPointer 00598fa0 in updateLighting 004dc0fc
//                and passed by value (4 bytes) as the first presetLighting argument (004dc219).
//   +0x4c        a std::map of 0x20 bytes (VS2008 _Tree: proxy +0x0, head +0x18, size +0x1c). Its head node is 0x18 bytes
//                (_Buynode 0056d3d0; isnil at node +0x15), so value_type is 8 bytes, 4-aligned, and trivially destructible
//                (the erase 00553ca0 destroys no value). No 2008-06 code inserts, finds or iterates it: the ctor and dtor
//                are its only users. Its key / mapped types are NOT derived, so it is not declared here (as in
//                RenderLib/ViewNew2008.h): the class below is declared only through +0x4b, so sizeof(ViewG3D) is 0x4c, not
//                the original 0x6c. Nothing here allocates or constructs a ViewG3D (the ctor / dtor are not built).
#include "RenderLib/ViewBase2008.h"
#include <G3D/ReferenceCount.h>
#include <GLG3D/Sky.h>

struct NativeViewG3D2008Layout;

namespace RBX
{
	namespace ViewNew
	{
		class ViewG3D : public ViewBase
		{
			friend struct ::NativeViewG3D2008Layout;
		private:
			G3D::ReferenceCountedPointer<G3D::Sky> sky;                     // +0x48
			// +0x4c std::map (0x20 bytes): key / mapped types not derived; not declared

		public:
			ViewG3D(boost::shared_ptr<DataModel> dataModel);                // 004dbbe0
			virtual ~ViewG3D();                                             // 004dc270 (??_G 004dc340)
			virtual void render(G3D::RenderDevice* rd);                    // 004db690
			virtual float getShadingQuality() const;                        // 0064a390 (ICF, ViewRbxGfx)
			virtual float getMeshDetail() const;                            // 004d76d0 (ICF, ViewRbxGfx)
			virtual void updateSettings(float shadingQuality, float meshDetail, bool shadows, float cameraDistance); // 004db660 (ICF)
			virtual void suppressSkybox();                                  // 004dbf00
			virtual Instance* getWorkspace();                               // 004d7370 (ICF, ViewRbxGfx)
			virtual RenderStats& getRenderStats();                          // 004db6f0 (ICF, ViewRbxGfx)
		private:
			virtual void onWorkspaceDescendentAdded(boost::shared_ptr<Instance> descendent); // 004db7c0 (ICF)
			virtual void updateLighting();                                  // 004dc040
			virtual void invalidateLighting(bool updateSkybox);             // 004db610
		};
	}
}
