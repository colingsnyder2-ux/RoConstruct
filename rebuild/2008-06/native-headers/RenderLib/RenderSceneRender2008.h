#pragma once
// >>> native-status (generated) -- do not edit >>>
// RenderSceneRender2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 78e36abb | roc native-status --write
// 2008-06 native RBX::Render::RenderSurface / RenderScene (the G3D render scene; inactive). Named *2008.h so it never
// shadows the donor RenderLib/RenderScene.h or RenderLib/RenderSurface.h (a later source base whose single, non-virtual
// Render::RenderScene keeps the chunk array, render stats and shading members itself).
//   RenderSurface  0x44 bytes: Array<RenderSurface> dtor 007aa980 steps by 0x44 and releases the RCP at +0x40.
//                  Implicit copy ctor 00502500 (evidence name ??0RenderSurface@Render@RBX@@QAE@ABV012@@Z): Matrix3
//                  copy ctor 00513220 on +0x0, Vector3 +0x24, float +0x30 (fld / fstp), pointer +0x34 (mov), float +0x38,
//                  pointer +0x3c, RCP +0x40 (setPointer 00598fa0). materialPtrSortProc 00505220 compares the +0x34
//                  pointers. The pointee types of +0x34 / +0x3c / +0x40 follow the donor (material / mesh levels and
//                  the full mesh); their 2008 classes are the RenderBase ones (Material2008.h, ViewNew/RenderBaseMesh.h).
//   RenderScene    RTTI vtable 00827454 -> RenderSceneBase (mdisp 0); new 0x500 (00551820 before the ctor 00505040).
//                  Slots: 0 ??_G 00503fc0 (calls the dtor 00503a60 out of line), 1 presetLighting 00503cc0 (ret 0x114),
//                  2 setThrottle 00502d30, 3 / 4 the RenderSceneBase getters, 5 render 00504bf0.
//                  ctor 00505040: RenderSceneBase() 00504fd0, vptr, then G3D::Array members zeroed at +0x268 / +0x274 /
//                  +0x280 / +0x28c / +0x298 / +0x2a4, VAR ctor 00489470 on +0x2b0, RCP +0x2d0 = NULL, RCPs +0x2e8 /
//                  +0x2ec = NULL, bool +0x2f0 = false, float +0x2f4 = G3D::inf(), Array +0x2f8, bool +0x304 = false,
//                  RCP +0x308 = NULL, LightingParameters ctor 007b6860 on +0x310 and +0x408 (0xf8 each, 8-aligned: ends
//                  at 0x500), then +0x2ec = G3D::Lighting::create() 00503960 and +0x2e8 = +0x2ec.
//                  dtor 00503a60 destroys, in reverse: RCP +0x308, Array +0x2f8 (POD, alignedFree 00507d20 inline),
//                  RCPs +0x2ec / +0x2e8, RCP +0x2d0, VAR +0x2b0 (its RCP), Array<RCP> +0x2a4 (00475f20), Array<
//                  RenderSurface> +0x298 (007aa980), POD Arrays +0x28c / +0x280 / +0x274, Array<RenderSurface> +0x268,
//                  then the inlined RenderSceneBase dtor (vptr 00827424, chunk Array 00475f20). +0x2d4..+0x2e7 (0x14) is
//                  never constructed or destroyed: it is the EffectSettings object whose update 00506dd0 is called with
//                  this = +0x2d4 by setThrottle 00502df4 / setLighting 00502ec8 (arguments: shadingQuality, meshDetail,
//                  shadows +0x2f0, cameraDistance +0x2f4, &desiredLighting +0x2e8, &desiredSkyParameters +0x310,
//                  &skyParameters +0x408; the result is stored into lighting +0x2ec).
//                  setThrottle clamps to [0, 100] (0x8163a4) before comparing; presetLighting scales the sun colour by
//                  0.9f (0x826fc8) and appends it to Lighting::shadowedLightArray (+0x4c, append 00503000).
//                  Element types of the POD arrays follow the donor (the dtor does not depend on them); the three
//                  RenderSurface* arrays are sorted with materialPtrSortProc (std::sort helpers 00505270..00505570).
#include "RenderLib/RenderScene2008.h"
#include "RenderLib/Material2008.h"
#include "RenderLib/EffectSettings.h"   // donor RBX::Render::EffectSettings: 0x14 bytes (layout probe), update 00506dd0
#include <G3D/CoordinateFrame.h>
#include <GLG3D/VAR.h>
#include <GLG3D/VARArea.h>
#include <algorithm>

struct NativeRenderSceneLayout;

namespace RBX
{
	namespace Render
	{
		class RenderSurface
		{
		public:
			G3D::CoordinateFrame cframe;                                      // +0x00
			float z;                                                          // +0x30
			const RenderBase::MaterialBase::Level* material;                  // +0x34
			float polygonOffset;                                              // +0x38
			const RenderBase::Mesh::Level* mesh;                              // +0x3c
			G3D::ReferenceCountedPointer<RenderBase::Mesh> fullMesh;          // +0x40
		};

		bool depthPtrSortProc(RenderSurface* const& A, RenderSurface* const& B);           // 00505240
		bool materialDepthPtrSortProc(RenderSurface* const& A, RenderSurface* const& B);   // 005051e0
		bool materialPtrSortProc(RenderSurface* const& A, RenderSurface* const& B);        // 00505220

		// std::sort with the procs above (std::_Sort 00505780 and its helpers 00505270..00505730)
		void sortByDepth(G3D::Array<RenderSurface*>& array);                               // 005058c0
		void sortByMaterial(G3D::Array<RenderSurface*>& array);                            // 00505890
		void sortByMaterialAndDepth(G3D::Array<RenderSurface*>& array);                    // 00505860 (render 00504ba5)

		class RenderScene : public RenderBase::RenderSceneBase
		{
			friend struct ::NativeRenderSceneLayout;
		private:
			G3D::Array<RenderSurface> proxyArray;                                     // +0x268
			G3D::Array<RenderSurface*> diffuseProxyArray;                             // +0x274
			G3D::Array<RenderSurface*> reflectProxyArray;                             // +0x280
			G3D::Array<RenderSurface*> transparentProxyArray;                         // +0x28c
			G3D::Array<RenderSurface> shadowProxyArray;                               // +0x298
			G3D::Array<G3D::ReferenceCountedPointer<RenderBase::Chunk> > shadowCachingChunkArray; // +0x2a4
			G3D::VAR shadowVAR;                                                       // +0x2b0
			G3D::ReferenceCountedPointer<G3D::VARArea> shadowVARArea;                 // +0x2d0
			EffectSettings effectSettings;                                            // +0x2d4
			G3D::ReferenceCountedPointer<G3D::Lighting> desiredLighting;              // +0x2e8
			G3D::ReferenceCountedPointer<G3D::Lighting> lighting;                     // +0x2ec
			bool shadows;                                                             // +0x2f0
			float cameraDistance;                                                     // +0x2f4
			G3D::Array<unsigned int> shadowIndexArray;                                // +0x2f8
		public:
			bool debugShadowVolumes;                                                  // +0x304
			G3D::ReferenceCountedPointer<G3D::Sky> sky;                               // +0x308
			G3D::LightingParameters desiredSkyParameters;                             // +0x310
			G3D::LightingParameters skyParameters;                                    // +0x408

		public:
			RenderScene();                                                            // 00505040
			virtual ~RenderScene();                                                   // 00503a60 (??_G 00503fc0)

			virtual void presetLighting(G3D::ReferenceCountedPointer<G3D::Sky> sky, G3D::LightingParameters skyParameters,
			                            G3D::Color3 ambientTop, G3D::Color3 ambientBottom);   // 00503cc0
			void setLighting(const G3D::ReferenceCountedPointer<G3D::Lighting>& L);    // 00502e70
			virtual void setThrottle(float t, float m, bool s, float c);              // 00502d30
			virtual void render(G3D::RenderDevice* rd, const G3D::GCamera& camera);    // 00504bf0 (not built)
		};
	}
}
