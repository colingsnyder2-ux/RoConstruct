// 2008-06 native RBX::RenderNew::RenderScene (the Ogre render scene; inactive). Its own optimized unit (document-swap
// flags, /O2, /fp:fast, Ogre 1.4.5 client headers), 007aa770 .. 007ab0a0: setThrottle 007aa770, setLighting 007aa8b0,
// presetLighting 007aacc0, ??_G 007aae20 and the ctor 007aae40 (all exact). The dtor 007aaa30 (deletes the Ogre::RbxSceneNode /
// RbxEntity forks) and render 007ab0a0 are not built. Declarations: RenderLib/RenderSceneNew2008.h.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// RenderSceneNew2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 1a212f39 | roc native-status --write
#include "RenderLib/RenderSceneNew2008.h"
#include <G3D/Vector4.h>
#include <GLG3D/ToneMap.h>
#include <memory>

// Exact target 005058f0 takes two GLight references (pointer ABI) and is
// passed directly to G3D::Array<GLight>::sort by 007afce0.
bool __cdecl compareLights(const G3D::GLight& a, const G3D::GLight& b);

bool __cdecl compareLights(const G3D::GLight& a, const G3D::GLight& b)
{
	return a.color.average() * (1.2 - a.position.w) >
	       b.color.average() * (1.2 - b.position.w);
}

namespace RBX
{
	namespace RenderNew
	{
		RenderScene::RenderScene()
			: entity(NULL),
			  shadows(false),
			  cameraDistance(G3D::inf()),
			  debugShadowVolumes(false)
		{
			desiredLighting = lighting = G3D::Lighting::create();
			rootNode = NULL;

			// The clear colour goes through the out-of-line G3D Color4(const Vector4&) (Color4.cpp; call 007ab068 ->
			// 00476550, ret 4) into a named local, then the inline operator= copies it from the stack to +0x14.
			// (A Color4 copy ctor would be inline: G3D Color4.inl.)
			G3D::Color4 clearColor(G3D::Vector4(0.5f, 0.5f, 1.0f, 1.0f));
			colorClearValue = clearColor;
		}

		void RenderScene::setThrottle(float t, float m, bool s, float c)
		{
			t = G3D::clamp(t, 0.0f, 100.0f);
			if (t != shadingQuality || m != meshDetail || s != shadows || c != cameraDistance)
			{
				shadingQuality = t;
				meshDetail = m;
				cameraDistance = c;
				shadows = s;

				lighting = effectSettings.update(t, m, s, c, desiredLighting, desiredSkyParameters, skyParameters);
			}
		}

		void RenderScene::setLighting(const G3D::ReferenceCountedPointer<G3D::Lighting>& L)
		{
			desiredLighting = L;
			lighting = effectSettings.update(shadingQuality, meshDetail, shadows, cameraDistance, desiredLighting,
			                                 desiredSkyParameters, skyParameters);
		}

		void RenderScene::presetLighting(G3D::ReferenceCountedPointer<G3D::Sky> sky, G3D::LightingParameters skyParameters,
		                                 G3D::Color3 ambientTop, G3D::Color3 ambientBottom)
		{
			desiredSkyParameters = skyParameters;

			G3D::ReferenceCountedPointer<G3D::Lighting> lighting = G3D::Lighting::create();
			lighting->ambientTop = ambientTop;
			lighting->ambientBottom = ambientBottom;

			G3D::GLight sun = G3D::GLight::directional(skyParameters.lightDirection, skyParameters.lightColor * 0.9f);
			lighting->shadowedLightArray.append(sun);

			setLighting(lighting);
		}

		G3D::ReferenceCountedPointer<G3D::Lighting> EffectSettings::update(
			float shadingDetail, float meshDetail, bool shadows, float cameraDistanceFromCharacters,
			const G3D::ReferenceCountedPointer<G3D::Lighting>& desiredLighting,
			const G3D::LightingParameters& desiredSkyParameters,
			G3D::LightingParameters& outSkyParameters)
		{
			int lightCount = desiredLighting->lightArray.size();
			int shadowLightCount = desiredLighting->shadowedLightArray.size();
			int numShadowLights = shadowLightCount >= 8 ? 8 : shadowLightCount;
			int maxLights = G3D::glGetInteger(0xd31) - 3;
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
			G3D::glGetInteger(0xd57);
			if (shadingDetail >= 10)
				_skyBox = true;
			_groundLOD = meshDetail * 0.01f;
			if (shadingDetail >= 30.0f)
				_hemisphereLighting = true;
			_LODShift = meshDetail * 0.02f - 1.0f;
			if (shadows && numShadowLights > 0)
			{
				_stencilShadows = true;
				numShadowLights = 1;
				if (numNonShadowLights == 0)
					_alphaBlendShadowLights = false;
			}
			lighting->shadowedLightArray.sort(compareLights);
			int excessShadowLights = lighting->shadowedLightArray.size() - numShadowLights;
			if (excessShadowLights > 0)
			{
				for (int i = 0; i < excessShadowLights; ++i)
					lighting->lightArray.append(lighting->shadowedLightArray[
						lighting->shadowedLightArray.size() - excessShadowLights + i]);
				lighting->shadowedLightArray.resize(lighting->shadowedLightArray.size() - excessShadowLights, true);
			}
			lighting->lightArray.sort(compareLights);
			int excessLights = lighting->lightArray.size() - numNonShadowLights;
			if (excessLights > 0)
				lighting->lightArray.resize(lighting->lightArray.size() - excessLights, true);
			_useAllLightsInUnshadowedPass = _stencilShadows == false;
			for (int i = 0; i < lighting->lightArray.size(); ++i)
				lighting->lightArray[i].color *= 1.0f;
			for (int i = 0; i < lighting->shadowedLightArray.size(); ++i)
				lighting->shadowedLightArray[i].color *= 1.0f;
			if (_toneMap)
			{
				EffectSettings::getToneMap()->setEnabled(true);
				lighting = EffectSettings::getToneMap()->prepareLighting(lighting);
				outSkyParameters = EffectSettings::getToneMap()->prepareLightingParameters(desiredSkyParameters);
			}
			else
				outSkyParameters = desiredSkyParameters;
			return lighting;
		}

		G3D::ToneMap* EffectSettings::getToneMap()
		{
			static std::auto_ptr<G3D::ToneMap> toneMap(new G3D::ToneMap);
			return toneMap.get();
		}
	}
}
