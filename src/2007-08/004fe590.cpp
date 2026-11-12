// from server: 100% by EspClaude
// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-lib: openrbx-client Rendering/RenderLib/EffectSettings.cpp

// Candidate translation unit (score above; library headers required).
#include "renderlib/EffectSettings.h"

#include <GLG3D/glcalls.h>
#include <algorithm>
#include <memory>

namespace RBX {
namespace Render {

// FUNCTION: WEBSERVICE 0x101f7750
// FUNCTION: ROBLOX 0x00536d60
inline static bool brighter(const G3D::GLight& A, const G3D::GLight& B)
{
	return A.color.average() * (1.2 - A.position.w) > B.color.average() * (1.2 - B.position.w);
}

// FUNCTION: WEBSERVICE 0x101f8950
// FUNCTION: ROBLOX 0x004a3e80
G3D::ToneMap* EffectSettings::getToneMap()
{
	static std::auto_ptr<G3D::ToneMap> toneMap(new G3D::ToneMap());
	return toneMap.get();
}

// FUNCTION: WEBSERVICE 0x101f89e0
// FUNCTION: ROBLOX 0x004a3f10
DepthBlur* EffectSettings::getDepthBlur()
{
	static std::auto_ptr<DepthBlur> depthBlur(new DepthBlur());
	return depthBlur.get();
}

// STUB: WEBSERVICE 0x101f8bc0
// STUB: ROBLOX 0x004a40f0
G3D::ReferenceCountedPointer<G3D::Lighting> EffectSettings::update(
	float shadingDetail,
	float meshDetail,
	bool shadows,
	float cameraDistanceFromCharacters,
	const G3D::ReferenceCountedPointer<G3D::Lighting>& desiredLighting,
	const G3D::LightingParameters& desiredSkyParameters,
	G3D::LightingParameters& outSkyParameters
)
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

	static const float SKY_BOX = 10.0f;
	if (shadingDetail >= SKY_BOX) {
		_skyBox = true;
	}

	_groundLOD = G3D::lerp(0.0f, 1.0f, (float) (meshDetail / 100.0));

	if (shadingDetail >= 30.0) {
		_hemisphereLighting = true;
	}

	_LODShift = G3D::lerp(-1.0f, 1.0f, (float) (meshDetail / 100.0));

	if (shadows && numShadowLights > 0) {
		_stencilShadows = true;
		numShadowLights = 1;

		if (numNonShadowLights == 0) {
			_alphaBlendShadowLights = false;
		}
	}

	std::sort(lighting->shadowedLightArray.begin(), lighting->shadowedLightArray.end(), brighter);

	int excessShadowLights = lighting->shadowedLightArray.size() - numShadowLights;

	if (excessShadowLights > 0) {
		for (int i = 0; i < excessShadowLights; i++) {
			lighting->lightArray.append(
				lighting->shadowedLightArray[lighting->shadowedLightArray.size() - excessShadowLights + i]
			);
		}

		lighting->shadowedLightArray.resize(lighting->shadowedLightArray.size() - excessShadowLights, true);
	}

	std::sort(lighting->lightArray.begin(), lighting->lightArray.end(), brighter);

	int excessLights = lighting->lightArray.size() - numNonShadowLights;

	if (excessLights > 0) {
		lighting->lightArray.resize(lighting->lightArray.size() - excessLights, true);
	}

	_useAllLightsInUnshadowedPass = _stencilShadows == false;

	for (int i = 0; i < lighting->lightArray.size(); i++) {
	}

	for (int i = 0; i < lighting->shadowedLightArray.size(); i++) {
	}

	if (_toneMap) {
		getToneMap()->setEnabled(true);
		lighting = getToneMap()->prepareLighting(lighting);
		outSkyParameters = getToneMap()->prepareLightingParameters(desiredSkyParameters);
	}
	else {
		outSkyParameters = desiredSkyParameters;
	}

	return lighting;
}

} // namespace Render
} // namespace RBX
