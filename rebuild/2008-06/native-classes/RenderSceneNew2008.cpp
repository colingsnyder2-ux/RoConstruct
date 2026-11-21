// 2008-06 native RBX::RenderNew::RenderScene (the Ogre render scene; inactive). Its own optimized unit (document-swap
// flags, /O2, /fp:fast, Ogre 1.4.5 client headers), 007aa770 .. 007ab0a0: setThrottle 007aa770, setLighting 007aa8b0,
// presetLighting 007aacc0, ??_G 007aae20 and the ctor 007aae40 (all exact). The dtor 007aaa30 (deletes the Ogre::RbxSceneNode /
// RbxEntity forks) and render 007ab0a0 are not built. Declarations: RenderLib/RenderSceneNew2008.h.
// render 007ab0a0 (7199 B, ?render@RenderScene@RenderNew@RBX@@UAEXPAVRenderDevice@G3D@@ABVGCamera@5@@Z) is parked: its only
// shape source is the openrbx STUB tools/openrbx/Client/Rendering/RenderLibNew/RenderScene.cpp RenderScene::render (2007
// client 0052df80, unnamed m_unk fields) plus the light helper it calls; it needs native declarations for Ogre::VisualEngine,
// RbxEntity / RbxSubEntity / RbxSceneNode helper methods (0067c520, 0067d9b0), the RenderNew Mesh / Material level fields
// and the hardware-mesh statics (00548f80, 005493e0, 007a9c40), none of which exist in native-headers yet.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
#define NOMINMAX
#include "RenderLib/RenderSceneNew2008.h"
#include "OgreRbxNode/RbxSceneNode2008.h"
#include "OgreRbx/RbxEntity2008.h"
#include <OgreSceneManager.h>
#include <G3D/Vector4.h>
#include <GLG3D/ToneMap.h>
#include <memory>
#include <algorithm>
#include "OgreRbx/VisualEngine2008.h"
#include "util/Utilities.h"
#include <OgreLight.h>
#include <OgreLogManager.h>
#include <OgreAxisAlignedBox.h>

namespace Ogre
{
	// 006784f0 (cdecl, hidden ColourValue result, one const G3D::Color4&; copies r, g, b, a). INFERRED name: the
	// registry has only func_006784f0; it sits just before VisualEngine's getVideoMemory 00678510 and the 2007
	// openrbx RenderScene stub calls the same converter (FUN_00671cd0) for its fill lights. Body: OgreColourConversion2008.cpp.
	ColourValue toColourValue(const G3D::Color4& color);
}

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

// 007aaa30: native destructor body from exact analog, with complete native fork classes.
RBX::RenderNew::RenderScene::~RenderScene()
{
    if (rootNode) {
        rootNode->getCreator()->getRootSceneNode()->removeChild(rootNode->getName());
        delete rootNode;
    }
    delete entity;
}

namespace RBX
{
	namespace RenderNew
	{
		// 007a9d30 (thiscall, ret 8; called once from render 007ab2de as (engine, effectSettings +0x2f6)).
		// INFERRED name: the registry has only func_007a9d30; the 2007 client's same helper is openrbx
		// RenderLibNew/RenderScene.cpp RenderScene::FUN_0052c9b0(Ogre::VisualEngine*, bool) (shape source).
		// 2008 evidence: scene manager = engine +0x4; setAmbientLight(ambient +0x354, alpha 1); colour-shift
		// averages * 0.3333f (008749d4) of +0x344 (bottom) / +0x338 (top); brightness +0x350 clamped to
		// [0.05, 5]; per shadowed light (Lighting +0x4c / +0x50, GLight stride 0x50, colour +0x40) "rbxlight"
		// 008749c8 + StringConverter<int> 005bdef0, hasLight / getLight / createLight (SceneManager slots +0x8c /
		// +0x88 / +0x84), the log strings 008749b0 / 00874990, setCastShadows inline (+0xa4), RbxEntity bounds
		// (+0x27c, extent +0x294) radius * 0.8585f * 1.3f, setType(LT_POINT), setDiffuseColour / setPosition /
		// setSpecularColour; stale "rbxlight<n>" destroyed (slot +0x90); with one shadowed light the "rbxfl"
		// 00874980 fill light (0.4f 00832a18, 2000.0f 00874988, converter 006784f0); the trailing ambient average
		// (Color3::operator/ 00514c40) and the first light's position.xyz() (00514890) results are unused.
		// The second argument (EffectSettings::_useAllLightsInUnshadowedPass) is not read.
		// NEAR MISS (batch 30: 2446 B -> 2633 B against 2616 B). Kept: the address-compare specular block, the
		// create-first hasLight branch, the named specularScale copy. Rejected: r+g+b sum spelling (no change, /fp:fast
		// reorders), a named diffuseScale copy before the diffuse product (2585 B), `specular = specular * (0.5f/peak)`
		// (no change). Remaining: frame 0x118 vs 0x130 (the target has 0x18 more bytes of locals), the destroy loop is
		// rotated/duplicated in ours, setCastShadows is `cmp [+0x2f4],0; setne` (a non-bool source) and the colour-shift
		// sums load b, g, r.
		// Batch 36: 2620 B against 2616 B (frame 0x124 vs 0x130). Kept: the compared Color3 is a block-scope local in the
		// light loop and the ambient average a separate end-of-function local (2633 -> 2620 B, frame 0x118 -> 0x124); the
		// ambient average sums ambientTop + ambientBottom (the target adds bottom.g+top.g, bottom.b+top.b, top.r+bottom.r,
		// which the 2007 bottom + top spelling mirrors; that block now matches). Rejected: dropping /fp:fast from the unit
		// (motivated by the target's two separate fmul 0.8585f / 1.3f, ours folds them into one constant): 3143 B and nine
		// exact siblings lost. Remaining: the radius constant product is folded in ours, setCastShadows `cmp/setne`, the
		// colour-shift sums' operand order, and the stack-slot assignment (0xc bytes of locals still missing).
		void RenderScene::updateLights(Ogre::VisualEngine* engine, bool useAllLights)
		{
			Ogre::SceneManager* sceneManager = engine->sceneManager;
			float radius = 1000.0f;
			Ogre::Vector3 center(0.0f, 0.0f, 0.0f);

			sceneManager->setAmbientLight(Ogre::ColourValue(ambient.r, ambient.g, ambient.b));

			float bottomAverage = (colorShiftBottom.b + colorShiftBottom.g + colorShiftBottom.r) * 0.3333f;
			G3D::Color3 bottomShift(colorShiftBottom.r - bottomAverage, colorShiftBottom.g - bottomAverage,
			                        colorShiftBottom.b - bottomAverage);
			float topAverage = (colorShiftTop.b + colorShiftTop.g + colorShiftTop.r) * 0.3333f;
			G3D::Color3 topShift(colorShiftTop.r - topAverage, colorShiftTop.g - topAverage, colorShiftTop.b - topAverage);

			float lightBrightness = brightness;
			if (lightBrightness > 5.0f)
				lightBrightness = 5.0f;
			else if (lightBrightness < 0.05f)
				lightBrightness = 0.05f;

			int i;
			for (i = 0; i < lighting->shadowedLightArray.size(); i++)
			{
				const G3D::GLight& source = lighting->shadowedLightArray[i];
				std::string name = std::string("rbxlight") + StringConverter<int>::convertToString(i);

				Ogre::Light* light;
				if (!sceneManager->hasLight(name))
				{
					light = sceneManager->createLight(name);
					if (light)
						Ogre::LogManager::getSingleton().logMessage(std::string("RbxGfx: created light") + name);
					else
						Ogre::LogManager::getSingleton().logMessage(std::string("RbxGfx : FAILED to create light") + name);
				}
				else
				{
					light = sceneManager->getLight(name);
				}
				light->setCastShadows(effectSettings.stencilShadows());

				if (entity)
				{
					// INFERRED access: RbxEntity::mBounds (+0x27c) is private in OgreRbx/RbxEntity2008.h (read-only
					// here); the target reads it directly (lea ecx, [entity+0x27c]). Header proposal: a public
					// const AxisAlignedBox& getBounds() const accessor.
					const Ogre::AxisAlignedBox& box =
						*reinterpret_cast<const Ogre::AxisAlignedBox*>(reinterpret_cast<const char*>(entity) + 0x27c);
					if (!box.isNull())
					{
						Ogre::Vector3 size = box.getSize();
						float extent = size.x > size.y ? size.x : size.y;
						extent = size.z > extent ? size.z : extent;
						radius = extent * 0.8585f * 1.3f;
						Ogre::Vector3 boxCenter = box.getCenter();
						center.x = boxCenter.x;
						center.z = boxCenter.z;
						center.y = box.getMinimum().y;
					}
				}

				light->setType(Ogre::Light::LT_POINT);

				G3D::Color3 diffuse = source.color * lightBrightness * G3D::Color3(lightingTerm0);
				diffuse = diffuse + topShift * diffuse.length();
				light->setDiffuseColour(diffuse.r, diffuse.g, diffuse.b);
				light->setPosition(source.position.x * radius + center.x, source.position.y * radius + center.y,
				                   source.position.z * radius + center.z);
				// 007aa19b..007aa22d: the target compares &lightingTerm1 (+0x36c) with the address of a stack Color3
				// (esp+0x118, the slot the trailing ambient average is written to after the loops); equal -> normalise the colour so its
				// largest component (std::max by reference) is at least 0.5, else scale by Color3(lightingTerm1).
				G3D::Color3 specular = source.color;
				// INFERRED (batch 36): a never-written loop-scope Color3 whose address is compared below; the target's
				// compared slot (esp+0x118) is only written after the loops (by the trailing ambient average), which fits
				// a block-scope object sharing its slot with that later local. Function-scope spelling: 2633 B, this: 2620 B.
				G3D::Color3 specularTag;
				if (static_cast<const void*>(&lightingTerm1) == static_cast<const void*>(&specularTag))
				{
					float peak = std::max(specular.r, std::max(specular.g, specular.b));
					if (peak < 0.5f)
						specular *= 0.5f / peak;
				}
				else
				{
					G3D::Color3 specularScale(lightingTerm1);
					specular = specular * specularScale;
				}
				light->setSpecularColour(specular.r, specular.g, specular.b);
			}

			for (;; i++)
			{
				std::string name = std::string("rbxlight") + StringConverter<int>::convertToString(i);
				if (!sceneManager->hasLight(name))
					break;
				sceneManager->destroyLight(sceneManager->getLight(name));
			}

			if (lighting->shadowedLightArray.size() == 1)
			{
				const G3D::GLight& source = lighting->shadowedLightArray[0];
				int index = 0;
				std::string name = std::string("rbxlight") + StringConverter<int>::convertToString(index);
				Ogre::Light* light = sceneManager->getLight(name);

				Ogre::Vector3 position;
				if (light->getType() == Ogre::Light::LT_DIRECTIONAL)
					position = -light->getDirection() * 2000.0f;
				else
					position = light->getPosition();

				std::string fillName("rbxfl");
				Ogre::Light* fill;
				if (sceneManager->hasLight(fillName))
				{
					fill = sceneManager->getLight(fillName);
				}
				else
				{
					fill = sceneManager->createLight(fillName);
					fill->setCastShadows(false);
					fill->setType(Ogre::Light::LT_POINT);
				}
				fill->setPosition(center * 2.0f - position);

				G3D::Color3 fillColor = source.color * lightBrightness * 0.4f * G3D::Color3(lightingTerm2) *
				                        G3D::Color3(lightingTerm4);
				fillColor = fillColor + bottomShift * fillColor.length();
				fill->setDiffuseColour(Ogre::toColourValue(G3D::Color4(fillColor, 1.0f)));
				G3D::Color3 fillSpecular = fillColor * G3D::Color3(lightingTerm3);
				fill->setSpecularColour(fillSpecular.r, fillSpecular.g, fillSpecular.b);
			}

			G3D::Color3 ambientAverage = (lighting->ambientTop + lighting->ambientBottom) / 2.0f;
			if (lighting->shadowedLightArray.size() > 0)
			{
				G3D::Vector3 direction = lighting->shadowedLightArray[0].position.xyz();
			}
		}
	}
}
