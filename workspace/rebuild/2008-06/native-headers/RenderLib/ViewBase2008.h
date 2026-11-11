#pragma once
// >>> native-status (generated) -- do not edit >>>
// ViewBase2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 9c8e51f8 | roc native-status --write
// 2008-06 native RBX::ViewBase (inactive). Named *2008.h so it never shadows the donor RbxViewBase/ViewBase.h (a later
// source base whose ViewBase has no members).
//   ViewBase     RTTI vtable 00826c24 (no bases); 11 slots: 0 ??_G 004d8ac0 (calls the dtor out of line), 1..10
//                _purecall (render, getShadingQuality, getMeshDetail, updateSettings, suppressSkybox, getWorkspace,
//                getRenderStats, onWorkspaceDescendentAdded, updateLighting, invalidateLighting: the order of the
//                ViewRbxGfx 00826c70 / ViewG3D 00826e04 implementations, e.g. slot 2 0064a390 = scene slot 3, slot 3
//                004d76d0 = scene slot 4, slot 4 004db660 (ret 0x10) = scene setThrottle, slot 7 004db6f0 = scene +0x30,
//                slot 8 004db7c0 ret 8 (shared_ptr by value), slot 10 004d7180 (ret 4) clears +0x44).
//                ctor 004d8a20 (thiscall, boost::shared_ptr<DataModel> by value, ret 8): vptr; +0x4 / +0x8 / +0xc /
//                +0x10 = NULL; dataModel +0x14 (px) / +0x18 (pn, use count incremented); two scoped_connections at
//                +0x1c / +0x30 (each 0x14: words +4 / +8 zeroed, bytes +0xc / +0x10 false); lightingValid +0x44 =
//                false; then releases the by-value argument.
//                dtor 004d8920 in reverse: ~scoped_connection 005954b0 (+0x30, +0x1c), the shared_ptr release (+0x14
//                / +0x18), delete +0x10 (non-virtual dtor 004d7460, operator delete), delete +0xc (inlined
//                G3D::TextureManager dtor: Table vtable 00819cd8, freeMemory 0045c680), delete +0x8 through slot 0
//                (RenderSceneBase ??_G), delete +0x4 through slot 6 (SceneManager ??_G).
//                size 0x48: ViewRbxGfx (new 0x4c at 0045b3ba) adds a bool at +0x48 (ctor 004d99fa), ViewG3D (new 0x6c
//                at 0045d86a) adds an RCP at +0x48 and a std::map at +0x4c.
//   The members' declaration order follows the destruction order of 004d8920 and the stores of 004d8a20; the derived
//   constructors fill them: renderLibScene (new 0x590 RenderNew::RenderScene 007aae40 / new 0x500 Render::RenderScene
//   00505040), textureManager (new 0x18, TextureManager(0xa00000) 0047e400), sceneManager (new 8 SimpleSceneManager /
//   new 0x68 AggregatingSceneManager), materialFactory (new 0x10, ctor 004f0920(textureManager)).
#include "RenderLib/SceneManager2008.h"
#include "RenderLib/RenderScene2008.h"
#include "RenderLib/RenderStats.h"
#include "ViewNew/MaterialFactory2008.h"
#include <GLG3D/TextureManager.h>
#include <boost/shared_ptr.hpp>
#include <boost/signals/connection.hpp>
#include <memory>

struct NativeRenderSceneLayout;

namespace RBX
{
	class Instance;
	class DataModel;

	class ViewBase
	{
		friend struct ::NativeRenderSceneLayout;
	public:
		std::auto_ptr<RenderBase::SceneManager> sceneManager;           // +0x04
		std::auto_ptr<RenderBase::RenderSceneBase> renderLibScene;      // +0x08
		std::auto_ptr<G3D::TextureManager> textureManager;              // +0x0c
		std::auto_ptr<ViewNew::MaterialFactory> materialFactory;        // +0x10 (ViewNew/MaterialFactory2008.h: dtor only)
	protected:
		boost::shared_ptr<DataModel> dataModel;                         // +0x14
		boost::signals::scoped_connection lightingChangedConnection;    // +0x1c
		boost::signals::scoped_connection workspaceDescendentAddedConnection; // +0x30
		bool lightingValid;                                             // +0x44

		ViewBase(boost::shared_ptr<DataModel> dataModel);               // 004d8a20
	public:
		virtual ~ViewBase();                                            // 004d8920 (??_G 004d8ac0)
		virtual void render(G3D::RenderDevice* rd) = 0;             // rd goes to renderLibScene slot 5 (004daf44)
		virtual float getShadingQuality() const = 0;
		virtual float getMeshDetail() const = 0;
		virtual void updateSettings(float shadingQuality, float meshDetail, bool shadows, float cameraDistance) = 0;
		virtual void suppressSkybox() = 0;
		virtual Instance* getWorkspace() = 0;
		virtual RenderStats& getRenderStats() = 0;
	private:
		virtual void onWorkspaceDescendentAdded(boost::shared_ptr<Instance> descendent) = 0;
		virtual void updateLighting() = 0;
		virtual void invalidateLighting(bool updateSkybox) = 0;
	};
}
