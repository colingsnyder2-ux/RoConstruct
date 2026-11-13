#pragma once
// 2008-06 native RBX::Render::DepthBlur and RBX::Render::EffectSettings (RenderLib DepthBlur.cpp / EffectSettings.cpp;
// inactive). Declared under a non-colliding path: the donor RenderLib/DepthBlur.h (a later source base) declares an
// out-of-line ~DepthBlur that the 2008 binary does not have. A unit must not include this header together with the
// donor RenderLib/EffectSettings.h or RenderLib/DepthBlur.h.
//
//   DepthBlur       0x0c bytes: new 0xc in getDepthBlur 00506c26 before the ctor 00507740 (this +0x0 = NULL,
//                   +0x4 = NULL, +0x8 = NULL, then +0x0 = Shader::fromStrings(...) through setPointer 00598fa0).
//                   allocateTextures 005071d0 reads the +0x4 texture's width / height (+0x64 / +0x68) and assigns
//                   +0x4 ("Depth Buffer") and +0x8 ("Color Buffer"); apply 00507420 tests +0x0. The destructor is
//                   implicit: its out-of-line copy 00505b90 (releases the RCPs +0x8, +0x4, +0x0) is a COMDAT of the
//                   EffectSettings object (between the GLight sort helpers), called by the atexit destructor of
//                   getDepthBlur's static auto_ptr (007fc5d0).
//   EffectSettings  0x14 bytes (Render::RenderScene +0x2d4; render-scene layout probe). update 00506dd0 (ret 0x20)
//                   stores the bytes +0x0 .. +0x6 and the floats +0x8 (-inf), +0xc (groundLOD), +0x10 (LODShift).
//                   Field names follow the donor; the 2008 store order is +0xc, +0x10, +0x3, +0x1, +0x0, +0x2, +0x4,
//                   +0x5, +0x6, +0x8.
//                   getToneMap 00506b80: static std::auto_ptr<G3D::ToneMap> (new 0x18, ToneMap() 007b29c0, guard bit 1
//                   of 009728dc, pointer 009728d8, atexit 007fc5b0 -> implicit ~ToneMap 00505ad0).
//                   getDepthBlur 00506c00: static std::auto_ptr<DepthBlur> (new 0xc, guard 009728e4, pointer 009728e0,
//                   atexit 007fc5d0 -> ~DepthBlur 00505b90).
#include <G3D/Rect2D.h>
#include <GLG3D/RenderDevice.h>
#include <GLG3D/Shader.h>
#include <GLG3D/Texture.h>
#include <GLG3D/ToneMap.h>
#include <GLG3D/LightingParameters.h>

namespace RBX
{
	namespace Render
	{
		class DepthBlur
		{
		private:
			G3D::ReferenceCountedPointer<G3D::Shader> shader;                 // +0x0
			G3D::ReferenceCountedPointer<G3D::Texture> depth;                 // +0x4
			G3D::ReferenceCountedPointer<G3D::Texture> color;                 // +0x8
		private:
			void allocateTextures(const G3D::Rect2D& screenRect);             // 005071d0
		public:
			DepthBlur();                                                      // 00507740

			void apply(G3D::RenderDevice* rd);                                // 00507420
		};

		class EffectSettings
		{
		private:
			bool _stencilShadows;                                             // +0x0
			bool _alphaBlendShadowLights;                                     // +0x1
			bool _useAllLightsInUnshadowedPass;                               // +0x2
			bool _skyBox;                                                     // +0x3
			bool _toneMap;                                                    // +0x4
			bool _hemisphereLighting;                                         // +0x5
			bool _depthBlur;                                                  // +0x6
			float _farCullZ;                                                  // +0x8
			float _groundLOD;                                                 // +0xc
			float _LODShift;                                                  // +0x10
		public:
			G3D::ReferenceCountedPointer<G3D::Lighting> update(float shadingDetail, float meshDetail, bool shadows,
				float cameraDistanceFromCharacters, const G3D::ReferenceCountedPointer<G3D::Lighting>& desiredLighting,
				const G3D::LightingParameters& desiredSkyParameters, G3D::LightingParameters& outSkyParameters);  // 00506dd0

			static G3D::ToneMap* getToneMap();                                // 00506b80
			static DepthBlur* getDepthBlur();                                 // 00506c00
		};
	}
}
