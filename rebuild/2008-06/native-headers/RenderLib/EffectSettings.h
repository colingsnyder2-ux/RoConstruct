#pragma once
#include "RenderLib/DepthBlur.h"
#include <GLG3D/ToneMap.h>
#include <GLG3D/LightingParameters.h>

namespace RBX
{
	namespace Render
	{
		class EffectSettings
		{
		private:
			bool _stencilShadows;
			bool _alphaBlendShadowLights;
			bool _useAllLightsInUnshadowedPass;
			bool _skyBox;
			bool _toneMap;
			bool _hemisphereLighting;
			bool _depthBlur;
			float _farCullZ;
			float _groundLOD;
			float _LODShift;
		public:
			G3D::ReferenceCountedPointer<G3D::Lighting> update(float, float, bool, float, const G3D::ReferenceCountedPointer<G3D::Lighting>&, const G3D::LightingParameters&, G3D::LightingParameters&);

			bool stencilShadows() const
			{
				return _stencilShadows;
			}
			bool hemisphereLighting() const
			{
				return _hemisphereLighting;
			}
			bool skyBox() const
			{
				return _skyBox;
			}
			float farCullZ() const;
			bool alphaBlendShadowLights() const
			{
				return _alphaBlendShadowLights;
			}
			bool useAllLightsInUnshadowedPass() const
			{
				return _useAllLightsInUnshadowedPass;
			}
			float groundLOD() const;
			float LODShift() const;
			bool applyToneMap() const
			{
				return _toneMap;
			}
			bool applyDepthBlur() const
			{
				return _depthBlur;
			}

			static G3D::ToneMap* getToneMap();
			static DepthBlur* getDepthBlur();
		};
	}
}
// 2008-06 native header port of rbxgs Rendering/RenderLib/include/RenderLib/EffectSettings.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
