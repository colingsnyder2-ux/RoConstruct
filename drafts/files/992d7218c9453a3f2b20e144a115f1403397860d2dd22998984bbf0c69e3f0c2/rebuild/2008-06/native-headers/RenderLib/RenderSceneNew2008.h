#pragma once
// 2008-06 native RBX::RenderNew::EffectSettings / RenderScene (the Ogre render scene; inactive). Named *2008.h: no donor
// header has this path (the donor base has only the G3D Render::RenderScene).
//   EffectSettings 0x14 bytes (RenderScene +0x2f4 .. +0x308). update 007afce0 (this = +0x2f4, ret 0x20, same arguments
//                  as Render::EffectSettings::update) stores bytes +0x0 .. +0x6 and floats +0x8 / +0xc / +0x10, the
//                  shape of the donor Render::EffectSettings (field names from there); render 007ab0e9 / 007ab2cc
//                  reads +0x0 / +0x2.
//   RenderScene    RTTI vtable 008749dc -> RenderSceneBase (mdisp 0); 0x590 bytes (ViewRbxGfx ctor; the last member,
//                  LightingParameters 0xf8 at +0x498, ends there). Slots: 0 ??_G 007aae20 (calls the dtor 007aaa30 out
//                  of line), 1 presetLighting 007aacc0 (ret 0x114), 2 setThrottle 007aa770, 3 / 4 the RenderSceneBase
//                  getters, 5 render 007ab0a0.
//                  ctor 007aae40: RenderSceneBase() 00504fd0, vptr, +0x26c = NULL, Ogre::MaterialPtr() +0x270 and
//                  Ogre::MeshPtr() +0x27c (imports), six G3D::Arrays zeroed at +0x288 .. +0x2c4, VAR ctor 00489470 on
//                  +0x2d0, RCP +0x2f0 = NULL, RCPs +0x308 / +0x30c = NULL, bool +0x310 = false, float +0x314 =
//                  G3D::inf(), Array +0x318, bool +0x324 = false, fifteen floats +0x360 .. +0x398 = 0 (five zeroing
//                  default ctors), LightingParameters ctors 007b6860 on +0x3a0 / +0x498; body: +0x30c =
//                  G3D::Lighting::create() 00503960, +0x308 = +0x30c, +0x268 = NULL, then colorClearValue (+0x14) is
//                  assigned from a G3D::Color4 copy (out-of-line copy ctor 00476550) of (0.5, 0.5, 1, 1).
//                  +0x328 .. +0x35f is not touched by the ctor (G3D::Color4 / Color3 default ctors do not initialise).
//                  dtor 007aaa30 (not built): +0x268 is removed from its creator's root node by name and deleted
//                  (virtual), +0x26c deleted (virtual), then the members in reverse, then the inlined RenderSceneBase
//                  dtor (vptr 00827424, chunk Array 00475f20).
//                  Member types: +0x268 is new 0x248 + ctor 00674160 (RTTI .?AVRbxSceneNode@Ogre@@, built from the
//                  string "rbxroot" 0084f534 in render 007ab24f); +0x26c is new 0x2bc + ctor 0067d1f0 (Ogre::RbxEntity,
//                  render 007ab470). Both are Roblox Ogre forks owned by the Ogre fork recoveries, so they are only
//                  forward-declared here (pointer members; the dtor that deletes them is not built).
//                  +0x288 / +0x2b8 are destroyed with 007aa980 (Array<RenderSurface>: stride 0x44, RCP at +0x40, the
//                  same body as Render::RenderScene's): the element type is Render::RenderSurface, the class with that
//                  proven layout (RenderNew code never names the element otherwise). The POD arrays (+0x294 / +0x2a0
//                  / +0x2ac / +0x318) are freed with alignedFree only; their element types follow Render::RenderScene.
//                  Lighting copies (ViewRbxGfx 004dab50, dynamic_cast to .?AVRenderScene@RenderNew@RBX@@): Lighting
//                  +0x244 Color4 -> colorClearValue +0x14; +0x254..+0x260 (4 floats, ShadowColor getter 005df4a0 reads
//                  +0x254) -> +0x328; ColorShift_Top +0x270 -> +0x338; ColorShift_Bottom +0x27c -> +0x344; Brightness
//                  +0x288 -> +0x350; Ambient +0x28c -> +0x354 (getters 004d6f80 / 004d6fb0 / 004d6fe0 / 004d6ff0, names
//                  from the property descriptors 007f6b40 .. 007f6c40); Lighting +0x298 .. +0x2d0 (15 floats, no
//                  property) -> +0x360 .. +0x398. render 007ab102 reads +0x328 / +0x32c / +0x330 as a colour with alpha 1.
#include "RenderLib/RenderSceneRender2008.h"
#include <G3D/Color4.h>
#include <G3D/Vector3.h>
#include <OgreMaterial.h>
#include <OgreMesh.h>

struct NativeRenderSceneLayout;

namespace Ogre
{
	class RbxSceneNode;
	class RbxEntity;
}

namespace RBX
{
	namespace RenderNew
	{
		class EffectSettings
		{
			friend struct ::NativeRenderSceneLayout;
		private:
			bool _stencilShadows;                                                     // +0x0
			bool _alphaBlendShadowLights;                                             // +0x1
			bool _useAllLightsInUnshadowedPass;                                       // +0x2
			bool _skyBox;                                                             // +0x3
			bool _toneMap;                                                            // +0x4
			bool _hemisphereLighting;                                                 // +0x5
			bool _depthBlur;                                                          // +0x6
			float _farCullZ;                                                          // +0x8
			float _groundLOD;                                                         // +0xc
			float _LODShift;                                                          // +0x10
		public:
			G3D::ReferenceCountedPointer<G3D::Lighting> update(float, float, bool, float,
			                                                   const G3D::ReferenceCountedPointer<G3D::Lighting>&,
			                                                   const G3D::LightingParameters&,
			                                                   G3D::LightingParameters&);   // 007afce0 (not built)
		};

		class RenderScene : public RenderBase::RenderSceneBase
		{
			friend struct ::NativeRenderSceneLayout;
		private:
			Ogre::RbxSceneNode* rootNode;                                             // +0x268
			Ogre::RbxEntity* entity;                                                  // +0x26c
			Ogre::MaterialPtr material;                                               // +0x270
			Ogre::MeshPtr mesh;                                                       // +0x27c
			G3D::Array<Render::RenderSurface> proxyArray;                             // +0x288
			G3D::Array<Render::RenderSurface*> diffuseProxyArray;                     // +0x294
			G3D::Array<Render::RenderSurface*> reflectProxyArray;                     // +0x2a0
			G3D::Array<Render::RenderSurface*> transparentProxyArray;                 // +0x2ac
			G3D::Array<Render::RenderSurface> shadowProxyArray;                       // +0x2b8
			G3D::Array<G3D::ReferenceCountedPointer<RenderBase::Chunk> > shadowCachingChunkArray; // +0x2c4
			G3D::VAR shadowVAR;                                                       // +0x2d0
			G3D::ReferenceCountedPointer<G3D::VARArea> shadowVARArea;                 // +0x2f0
			EffectSettings effectSettings;                                            // +0x2f4
			G3D::ReferenceCountedPointer<G3D::Lighting> desiredLighting;              // +0x308
			G3D::ReferenceCountedPointer<G3D::Lighting> lighting;                     // +0x30c
			bool shadows;                                                             // +0x310
			float cameraDistance;                                                     // +0x314
			G3D::Array<unsigned int> shadowIndexArray;                                // +0x318
		public:
			bool debugShadowVolumes;                                                  // +0x324
			G3D::Color4 shadowColor;                                                  // +0x328
			G3D::Color3 colorShiftTop;                                                // +0x338
			G3D::Color3 colorShiftBottom;                                             // +0x344
			float brightness;                                                         // +0x350
			G3D::Color3 ambient;                                                      // +0x354
			// Lighting +0x298 .. +0x2d0 (no reflected property; semantic names unknown), zeroed by the ctor
			G3D::Vector3 lightingTerm0;                                               // +0x360
			G3D::Vector3 lightingTerm1;                                               // +0x36c
			G3D::Vector3 lightingTerm2;                                               // +0x378
			G3D::Vector3 lightingTerm3;                                               // +0x384
			G3D::Vector3 lightingTerm4;                                               // +0x390
			G3D::LightingParameters desiredSkyParameters;                             // +0x3a0
			G3D::LightingParameters skyParameters;                                    // +0x498

		public:
			RenderScene();                                                            // 007aae40
			virtual ~RenderScene();                                                   // 007aaa30 (not built; ??_G 007aae20)

			virtual void presetLighting(G3D::ReferenceCountedPointer<G3D::Sky> sky, G3D::LightingParameters skyParameters,
			                            G3D::Color3 ambientTop, G3D::Color3 ambientBottom);   // 007aacc0
			void setLighting(const G3D::ReferenceCountedPointer<G3D::Lighting>& L);    // 007aa8b0
			virtual void setThrottle(float t, float m, bool s, float c);              // 007aa770
			virtual void render(G3D::RenderDevice* rd, const G3D::GCamera& camera);    // 007ab0a0 (not built)
		};
	}
}
