#pragma once
// >>> native-status (generated) -- do not edit >>>
// RenderScene2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src c7a3aaf9 | roc native-status --write
// 2008-06 native RBX::RenderBase::RenderSceneBase (inactive). Named *2008.h so it never shadows the donor
// RenderLib/RenderScene.h (a later source base whose single, non-virtual RBX::Render::RenderScene also declares the
// donor SceneManager).
//   RenderSceneBase RTTI vtable 00827424 (no bases). 6 slots: 0 ??_G 00503a30 (inlines the dtor), 1 presetLighting
//                   005039e0 (base default: throws std::exception("shouldn't be here"), string 0082743c, throw info
//                   008d997c; ret 0x114 in Render::RenderScene 00503cc0 = RCP<Sky> 4 + LightingParameters 0xf8 +
//                   2 * Color3), 2 setThrottle (_purecall; ret 0x10 in 00502d30 / 007aa770), 3 getShadingQuality
//                   (00503cb0: fld [ecx+0x24], ICF-folded with Material::Level code), 4 getMeshDetail (007b76d0: fld
//                   [ecx+0x28], ICF-folded), 5 render (_purecall; ret 8 in 00504bf0 / 007ab0a0).
//                   ctor 00504fd0 (O2, out of line; called by Render::RenderScene 00505062 and RenderNew::RenderScene
//                   007aae62): vptr, chunkArray +0x8 (+0xc / +0x10 / +0x8 zeroed), colorClearValue +0x14 = (0.5, 0.5,
//                   1, 1) (0x819bac, fld1), shadingQuality +0x24 / meshDetail +0x28 = -1.0f (0x81c3b8), renderStats
//                   +0x30 (RenderStats ctor 00501c30: 6 G3D::Stopwatch of 0x58, then 10 ints = 0x238).
//                   dtor 005039d0 (vptr, then the chunk Array dtor 00475f20 as a tail call). size 0x268 (Render::
//                   RenderScene members start at +0x268).
//                   +0x4 is not a member: MSVC pads the vfptr to the class alignment (8, from the doubles in
//                   G3D::Stopwatch), so the first member lands at +0x8 (checked by the layout probe), and +0x2c is the
//                   alignment hole before the 8-aligned RenderStats.
#include <G3D/Array.h>
#include <G3D/Color3.h>
#include <G3D/Color4.h>
#include <G3D/ReferenceCount.h>
#include <G3D/GCamera.h>
#include <GLG3D/Sky.h>
#include <GLG3D/LightingParameters.h>
#include "RenderLib/AggregateChunk2008.h"
#include "RenderLib/RenderStats.h"     // donor RenderStats (6 Stopwatch + 10 ints = 0x238; ctor 00501c30)

struct NativeRenderSceneLayout;

namespace G3D
{
	class RenderDevice;
}

namespace RBX
{
	namespace RenderBase
	{
		class SceneManager;

		class RenderSceneBase
		{
			friend class SceneManager;
			friend struct ::NativeRenderSceneLayout;

		private:
			G3D::Array<G3D::ReferenceCountedPointer<Chunk> > chunkArray;   // +0x08
		public:
			G3D::Color4 colorClearValue;                                     // +0x14
		protected:
			float shadingQuality;                                            // +0x24
			float meshDetail;                                                // +0x28
		public:
			RenderStats renderStats;                                         // +0x30

		public:
			RenderSceneBase();                                               // 00504fd0
			virtual ~RenderSceneBase()                                       // 005039d0 (??_G 00503a30)
			{
				// header-inline: Render::RenderScene 00503a60 and RenderNew::RenderScene 007aaa30 inline it (vptr
				// 00827424, then the chunk Array dtor); the out-of-line copy 005039d0 serves their EH unwind funclets
				// (007cb533, 007ed3f3).
			}

			virtual void presetLighting(G3D::ReferenceCountedPointer<G3D::Sky> sky, G3D::LightingParameters skyParameters,
			                            G3D::Color3 ambientTop, G3D::Color3 ambientBottom);   // 005039e0
			virtual void setThrottle(float shadingQuality, float meshDetail, bool shadows, float cameraDistance) = 0;
			virtual float getShadingQuality() const                          // 00503cb0 (folded)
			{
				return shadingQuality;
			}
			virtual float getMeshDetail() const                              // 007b76d0 (folded)
			{
				return meshDetail;
			}
			virtual void render(G3D::RenderDevice* rd, const G3D::GCamera& camera) = 0;
		};
	}
}
