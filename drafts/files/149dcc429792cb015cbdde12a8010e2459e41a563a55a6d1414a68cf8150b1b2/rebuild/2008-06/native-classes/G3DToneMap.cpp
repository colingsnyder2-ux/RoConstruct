// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <GLG3D/ToneMap.h>

namespace G3D
{
	ToneMap::Profile ToneMap::profile = ToneMap::UNINITIALIZED;

	ToneMap::ToneMap()
		: mEnabled(true)
	{
		if (profile == UNINITIALIZED)
		{
			profile = NO_TONE;
			if (GLCaps::supports_GL_ARB_texture_non_power_of_two())
			{
				if (Shader::supportsPixelShaders())
				{
					profile = PS20;
				}
				else if (GLCaps::supports("GL_ARB_texture_env_crossbar") &&
				         GLCaps::supports("GL_ARB_texture_env_combine") &&
				         GLCaps::supports("GL_EXT_texture_env_add") &&
				         GLCaps::supports("GL_NV_texture_shader") &&
				         (GLCaps::numTextureUnits() >= 4))
				{
					profile = PS14NVIDIA;
					profile = NO_TONE;
				}
				else if (GLCaps::supports("GL_ATI_fragment_shader") &&
				         (GLCaps::numTextureUnits() >= 4))
				{
					profile = NO_TONE;
				}
			}
		}
		if (profile != NO_TONE)
		{
			makeGammaCorrectionTextures();
			if (profile == PS20)
				makeShadersPS20();
			else if (profile == PS14ATI)
				makeShadersPS14ATI();
		}
	}

	void ToneMap::setEnabled(bool e)
	{
		if (e == mEnabled)
			return;
		mEnabled = e;
	}

	LightingParameters ToneMap::prepareLightingParameters(const LightingParameters& L) const
	{
		bool on = mEnabled && (profile != NO_TONE);
		double lightScale = on ? 0.75 : 1.0;
		LightingParameters params = L;
		params.emissiveScale *= lightScale;
		params.skyAmbient *= on ? 0.5 : 1.0;
		params.diffuseAmbient *= lightScale;
		params.lightColor *= lightScale;
		params.ambient *= lightScale;
		return params;
	}

	LightingRef ToneMap::prepareLighting(const LightingRef& L) const
	{
		double lightScale = (mEnabled && (profile != NO_TONE)) ? 0.75 : 1.0;
		LightingRef lighting = Lighting::create();
		*lighting = *L;
		lighting->environmentMapColor *= lightScale;
		lighting->emissiveScale *= lightScale;
		lighting->ambientTop *= lightScale;
		lighting->ambientBottom *= lightScale;
		for (int i = 0; i < lighting->lightArray.size(); ++i)
			lighting->lightArray[i].color *= lightScale;
		for (int i = 0; i < lighting->shadowedLightArray.size(); ++i)
			lighting->shadowedLightArray[i].color *= lightScale;
		return lighting;
	}
}
