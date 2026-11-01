#pragma float_control(precise, off)
#include "RenderLib/EffectSettings.h"

#include <GLG3D/glcalls.h>
#include <algorithm>
#include <memory>

namespace RBX
{
	namespace Render
	{
		static bool brighter(const G3D::GLight& A, const G3D::GLight& B)
		{
			return A.color.average() * (1.2 - A.position.w) > B.color.average() * (1.2 - B.position.w);
		}

		DepthBlur::~DepthBlur()
		{
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

		G3D::ReferenceCountedPointer<G3D::Lighting> EffectSettings::update(
			float shadingDetail,
			float meshDetail,
			bool shadows,
			float cameraDistanceFromCharacters,
			const G3D::ReferenceCountedPointer<G3D::Lighting>& desiredLighting,
			const G3D::LightingParameters& desiredSkyParameters,
			G3D::LightingParameters& outSkyParameters)
		{
			int lightCount = desiredLighting->lightArray.size();
			int shadowLightCount = desiredLighting->shadowedLightArray.size();
			int numShadowLights = shadowLightCount >= 8 ? 8 : shadowLightCount;
			int maxLights = G3D::glGetInteger(GL_MAX_LIGHTS) - 3;
			int numNonShadowLights = lightCount >= maxLights ? maxLights : lightCount;
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

			_groundLOD = meshDetail * 0.01f;

			if (shadingDetail >= 30.0f)
			{
				_hemisphereLighting = true;
			}

			_LODShift = meshDetail * 0.02f - 1.0f;

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

			for (int i = 0; i < lighting->lightArray.size(); i++)
			{
				G3D::GLight& l = lighting->lightArray[i];
				l.color *= 1.0f;
			}
			for (int i = 0; i < lighting->shadowedLightArray.size(); i++)
			{
				G3D::GLight& l = lighting->shadowedLightArray[i];
				l.color *= 1.0f;
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
