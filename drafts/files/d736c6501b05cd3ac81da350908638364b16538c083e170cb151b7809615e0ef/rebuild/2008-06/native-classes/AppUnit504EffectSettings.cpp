// 2008-06 native RBX::Render::EffectSettings (RenderLib EffectSettings.cpp; inactive). Declarations:
// native-headers/AppUnit504/RenderEffects.h. Verified by tests/record_native_app_unit504.py.
#include "AppUnit504/RenderEffects.h"

#include <GLG3D/glcalls.h>
#include <algorithm>
#include <memory>

namespace RBX
{
	namespace Render
	{
		// 005058f0: the std::sort predicate (its address is pushed by update 00506f5d / 00506fd5)
		static bool brighter(const G3D::GLight& A, const G3D::GLight& B)
		{
			return A.color.average() * (1.2 - A.position.w) > B.color.average() * (1.2 - B.position.w);
		}

		G3D::ToneMap* EffectSettings::getToneMap()
		{
			static std::auto_ptr<G3D::ToneMap> toneMap(new G3D::ToneMap());
			return toneMap.get();
		}

		DepthBlur* EffectSettings::getDepthBlur()
		{
			static std::auto_ptr<DepthBlur> depthBlur(new DepthBlur());
			return depthBlur.get();
		}

		G3D::ReferenceCountedPointer<G3D::Lighting> EffectSettings::update(float shadingDetail, float meshDetail,
			bool shadows, float cameraDistanceFromCharacters,
			const G3D::ReferenceCountedPointer<G3D::Lighting>& desiredLighting,
			const G3D::LightingParameters& desiredSkyParameters, G3D::LightingParameters& outSkyParameters)
		{
			int numLights = desiredLighting->lightArray.size();
			int numShadowLights = G3D::iMin(desiredLighting->shadowedLightArray.size(), 8);
			int maxLights = G3D::glGetInteger(GL_MAX_LIGHTS) - 3;
			int numNonShadowLights = numLights >= maxLights ? maxLights : numLights;
			numNonShadowLights = numNonShadowLights > 0 ? numNonShadowLights : 0;

			_groundLOD = 1.0f;
			_LODShift = 0.0f;
			_skyBox = false;
			_alphaBlendShadowLights = true;
			_stencilShadows = false;
			_useAllLightsInUnshadowedPass = false;
			_toneMap = false;
			_hemisphereLighting = false;
			_depthBlur = false;
			_farCullZ = -G3D::inf();

			G3D::ReferenceCountedPointer<G3D::Lighting> lighting = G3D::Lighting::create();
			*lighting = *desiredLighting;

			G3D::glGetInteger(GL_STENCIL_BITS);

			if (shadingDetail >= 10)
			{
				_skyBox = true;
			}

			_groundLOD = meshDetail / 100.0f;

			if (shadingDetail >= 30.0f)
			{
				_hemisphereLighting = true;
			}

			_LODShift = meshDetail / 50.0f - 1.0f;

			if (shadows && numShadowLights > 0)
			{
				_stencilShadows = true;
				numShadowLights = 1;

				if (numNonShadowLights == 0)
				{
					_alphaBlendShadowLights = false;
				}
			}

			lighting->shadowedLightArray.sort(brighter);

			int excessShadowLights = lighting->shadowedLightArray.size() - numShadowLights;

			if (excessShadowLights > 0)
			{
				for (int i = 0; i < excessShadowLights; i++)
				{
					lighting->lightArray.append(
						lighting->shadowedLightArray[lighting->shadowedLightArray.size() - excessShadowLights + i]);
				}

				lighting->shadowedLightArray.resize(lighting->shadowedLightArray.size() - excessShadowLights, true);
			}

			lighting->lightArray.sort(brighter);

			int excessLights = lighting->lightArray.size() - numNonShadowLights;

			if (excessLights > 0)
			{
				lighting->lightArray.resize(lighting->lightArray.size() - excessLights, true);
			}

			_useAllLightsInUnshadowedPass = _stencilShadows == false;

			// Both loops survive in the target only as counters (00507013..0050703f: the Lighting pointer is reloaded each
			// iteration and the element offset steps by 0x50 with no access): a body that stores the element back
			// unchanged. The `color *= 1.0f` body is a codegen analog of that store, not the original statement.
			for (int i = 0; i < lighting->lightArray.size(); ++i)
			{
				lighting->lightArray[i].color *= 1.0f;
			}
			for (int i = 0; i < lighting->shadowedLightArray.size(); ++i)
			{
				lighting->shadowedLightArray[i].color *= 1.0f;
			}

			if (_toneMap)
			{
				getToneMap()->setEnabled(true);
				lighting = getToneMap()->prepareLighting(lighting);
				outSkyParameters = getToneMap()->prepareLightingParameters(desiredSkyParameters);
			}
			else
			{
				outSkyParameters = desiredSkyParameters;
			}

			return lighting;
		}
	}
}
