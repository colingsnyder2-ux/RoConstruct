// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client Rendering/RenderLib/EffectSettings.cpp

// Candidate translation unit (score above; library headers required).
#include "renderlib/EffectSettings.h"

#include <GLG3D/glcalls.h>
#include <algorithm>
#include <memory>

namespace RBX {
namespace Render {

// STUB: WEBSERVICE 0x101f7750
static bool brighter(const G3D::GLight& A, const G3D::GLight& B)
{
	return (A.color.r + A.color.g + A.color.b) / 3.0 * (1.2 - A.position.w) >
		   (B.color.r + B.color.g + B.color.b) / 3.0 * (1.2 - B.position.w);
}

// FUNCTION: WEBSERVICE 0x101f8950
G3D::ToneMap* EffectSettings::getToneMap()
{
	static std::auto_ptr<G3D::ToneMap> toneMap(new G3D::ToneMap());
	return toneMap.get();
}

// FUNCTION: WEBSERVICE 0x101f89e0
DepthBlur* EffectSettings::getDepthBlur()
{
	static std::auto_ptr<DepthBlur> depthBlur(new DepthBlur());
	return depthBlur.get();
}

// STUB: WEBSERVICE 0x101f8bc0
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
	int numShadowLights =
		desiredLighting->shadowedLightArray.size() >= 8 ? 8 : desiredLighting->shadowedLightArray.size();
	int maxLights = G3D::glGetInteger(GL_MAX_LIGHTS) - 3;
	int numNonShadowLights =
		desiredLighting->lightArray.size() >= maxLights ? maxLights : desiredLighting->lightArray.size();
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

	if (meshDetail >= 10) {
		_skyBox = true;
	}

	_groundLOD = G3D::lerp(0.0f, 1.0f, (float) (meshDetail / 100.0));

	if (meshDetail >= 30.0) {
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
