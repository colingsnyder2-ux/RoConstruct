// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// 2008-06 native RBX::RenderNew::RenderScene (the Ogre render scene; inactive). Its own optimized unit (document-swap
// flags, /O2, /fp:fast, Ogre 1.4.5 client headers), 007aa770 .. 007ab0a0: setThrottle 007aa770, setLighting 007aa8b0,
// presetLighting 007aacc0, ??_G 007aae20 and the ctor 007aae40 (all exact), the dtor 007aaa30 and render 007ab0a0
// (7199 B, ?render@RenderScene@RenderNew@RBX@@UAEXPAVRenderDevice@G3D@@ABVGCamera@5@@Z; near miss, batch 38). render's
// shape sources: the openrbx 2007 analog tools/openrbx/Client/Rendering/RenderLibNew/RenderScene.cpp RenderScene::render
// (0052df80) and the 2008 disassembly. Declarations: RenderLib/RenderSceneNew2008.h.
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
#include <OgreMaterialManager.h>
#include <OgreMeshManager.h>
#include <OgreTextureManager.h>
#include <OgreTechnique.h>
#include <OgrePass.h>
#include <OgreTextureUnitState.h>
#include <OgreTimer.h>
#include <OgreImage.h>
#include <OgreRoot.h>
#include <OgreRenderTarget.h>
#include <OgreCamera.h>
#include <OgreSphere.h>
#include <math.h>
#include "AppUnit67C_2008/RbxSubEntity2008.h"
#include "OgreRbx/RbxSubMesh2008.h"
#include "RenderLib/TextureProxy2008.h"

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

namespace RBX
{
	namespace LDraw2Lua
	{
		// 0055c4c0 (cdecl, hidden std::string result; registry ?originalAssetFolder@LDraw2Lua@RBX@@YA?AV?$basic_string@...@XZ).
		// Body: native-classes/LDrawPath.cpp (declared ad hoc the same way in ImageContentRegistration.cpp).
		std::string originalAssetFolder();
	}
}

namespace
{
	// INFERRED access (header proposals for OgreRbx/RbxEntity2008.h, OgreRbx/RbxSubMesh2008.h and RenderLib/
	// RenderScene2008.h, not owned by this unit): render 007ab0a0 reads RbxEntity::mBounds +0x27c (007ab594 /
	// 007ac658 / 007ac6f0), writes RbxEntity +0x279 / +0x29c / +0x2a0 (007acbfb / 007acc29 / 007acc35), reads
	// RbxSubMesh::bounds +0xcc (007ac7f9) and RenderSceneBase::chunkArray +0x8 (007ab4dc), all private there.
	// These helpers inline to the same direct member accesses.
	inline Ogre::AxisAlignedBox& entityBounds(Ogre::RbxEntity* entity)
	{
		return *reinterpret_cast<Ogre::AxisAlignedBox*>(reinterpret_cast<char*>(entity) + 0x27c);
	}
	inline bool& entityCameraNotified(Ogre::RbxEntity* entity)
	{
		return *reinterpret_cast<bool*>(reinterpret_cast<char*>(entity) + 0x279);
	}
	inline Ogre::Real& entityLodBudget(Ogre::RbxEntity* entity)
	{
		return *reinterpret_cast<Ogre::Real*>(reinterpret_cast<char*>(entity) + 0x29c);
	}
	inline int& entityMinimumLod(Ogre::RbxEntity* entity)
	{
		return *reinterpret_cast<int*>(reinterpret_cast<char*>(entity) + 0x2a0);
	}
	inline const Ogre::AxisAlignedBox& subMeshBounds(const Ogre::RbxSubMesh* subMesh)
	{
		return *reinterpret_cast<const Ogre::AxisAlignedBox*>(reinterpret_cast<const char*>(subMesh) + 0xcc);
	}
	inline G3D::Array<G3D::ReferenceCountedPointer<RBX::RenderBase::Chunk> >& sceneChunks(RBX::RenderBase::RenderSceneBase* scene)
	{
		return *reinterpret_cast<G3D::Array<G3D::ReferenceCountedPointer<RBX::RenderBase::Chunk> >*>(
			reinterpret_cast<char*>(scene) + 0x8);
	}

	// 0097f36c: the "m%d" (00874a68) Ogre material name counter (zero-initialised .bss). INFERRED name; the 2007
	// analog is openrbx RenderLibNew/RenderScene.cpp g_unk0x00958700.
	int materialCounter;
}

namespace RBX
{
	namespace RenderNew
	{
		// 007ab0a0 ?render@RenderScene@RenderNew@RBX@@UAEXPAVRenderDevice@G3D@@ABVGCamera@5@@Z (vtable 008749dc slot 5,
		// thiscall ret 8). The RenderDevice argument is the Ogre::VisualEngine (sceneManager +0x4, camera +0x8,
		// renderTarget +0xc, frameHistory +0x18, +0x7f5 / +0x806 flags), as in the 2007 analog (openrbx
		// RenderLibNew/RenderScene.cpp RenderScene::render, 0052df80), which gives the statement shapes; 2008 adds the
		// per-level pass loop, the reflect pass from level 0 and the RbxEntity LOD budget.
		// NEAR MISS (batch 38): 7345 B against 7199 B, frame 0x2fc vs 0x310; every call, vtable slot and constant
		// matches. Kept: getVertex before the scaled normal, the sphere branch first, named sphere / mesh boxes and
		// min / max corners, the lod if / else, cframe() before the quaternion, slot 54 0067c6a0 for the visibility
		// call, one throw guarded by a ternary (7406 -> 7345 B). Rejected: the same guard as a short-circuit ||
		// expression (7378 B). Remaining: register allocation (the target keeps engine in edi and this in ebp, the
		// camera reference in no register), 0x14 bytes of locals, the software-path guard materialises a bool (sete),
		// and the Sphere centre copies call the rgmain Vector3 copy constructor import (00804498) in the target.
		void RenderScene::render(G3D::RenderDevice* rd, const G3D::GCamera& camera)
		{
			Ogre::VisualEngine* engine = reinterpret_cast<Ogre::VisualEngine*>(rd);
			Ogre::GeometryBuilder* builder = reinterpret_cast<Ogre::GeometryBuilder*>(rd);
			Ogre::Camera* ogreCamera = engine->camera;
			G3D::CoordinateFrame cameraFrame = camera.getCoordinateFrame();

			if (effectSettings.stencilShadows())
			{
				engine->sceneManager->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_MODULATIVE);
				engine->sceneManager->setShadowColour(Ogre::ColourValue(shadowColor.r, shadowColor.g, shadowColor.b, 1.0f));
			}
			else
			{
				engine->sceneManager->setShadowTechnique(Ogre::SHADOWTYPE_NONE);
			}

			Ogre::Quaternion orientation(1.0f, 0.0f, 0.0f, 0.0f);
			orientation.FromRotationMatrix(reinterpret_cast<const Ogre::Matrix3&>(cameraFrame.rotation));
			ogreCamera->setOrientation(orientation);
			ogreCamera->setPosition(cameraFrame.translation.x, cameraFrame.translation.y, cameraFrame.translation.z);
			engine->camera->setNearClipDistance(-camera.getNearPlaneZ());
			engine->camera->setFarClipDistance(-camera.getFarPlaneZ());
			engine->camera->setFOVy(Ogre::Radian((float)camera.getFieldOfView()));

			Ogre::Timer timer;
			timer.reset();

			if (rootNode == NULL)
			{
				rootNode = new Ogre::RbxSceneNode(engine->sceneManager, "rbxroot");
				engine->sceneManager->getRootSceneNode()->addChild(rootNode);
			}

			updateLights(engine, effectSettings.useAllLightsInUnshadowedPass());
			bool hardwareMeshes = engine->useLargeVertexBufferAdorn;

			if (material.isNull())
				material = Ogre::MaterialManager::getSingleton().getByName("BaseWhite");

			if (mesh.isNull())
				mesh = Ogre::MeshManager::getSingleton().createOrRetrieve("rbxdummymesh", "General").first;

			G3D::Array<G3D::ReferenceCountedPointer<RenderBase::Chunk> >& chunkArray = sceneChunks(this);

			if (entity == NULL && chunkArray.size() != 0)
			{
				entity = new Ogre::RbxEntity();
				rootNode->attachObject(entity);
				entity->setMesh(mesh);
			}

			for (int i = 0; i < chunkArray.size(); i++)
			{
				RenderBase::Chunk* chunk = chunkArray[i].getPointer();
				if (chunk)
					chunk->getMesh();
			}

			if (RenderBase::Mesh::varDirty && chunkArray.size() != 0 && hardwareMeshes)
			{
				RenderBase::Mesh::updateGeometry(builder);
				entity->setMesh(RenderBase::Mesh::sharedMesh);
				if (entityBounds(entity).isNull())
					entity->sub_007a9c40(RenderBase::Mesh::sharedMesh->getBounds());
			}

			G3D::CoordinateFrame viewFrame;
			camera.getCoordinateFrame(viewFrame);

			for (int i = 0; i < chunkArray.size(); i++)
			{
				RenderBase::Chunk* chunk = chunkArray[i].getPointer();
				if (chunk == NULL)
					continue;

				bool hasMesh = chunk->getMesh().notNull();
				bool hasMaterial = chunk->getMaterial().notNull();
				if (!hasMesh || !hasMaterial)
					continue;

				if (chunk->getMaterial()->detailLevel(0.0f) == NULL)
					continue;

				G3D::ReferenceCountedPointer<RenderBase::Mesh> chunkMesh = chunk->getMesh();
				if (effectSettings.stencilShadows() && chunkMesh->subMesh == NULL)
					chunkMesh->makeShadowSubMesh(builder);

				int lod = 0;
				if (chunkMesh->levels.size() == 2)
				{
					G3D::Vector3 local = viewFrame.pointToObjectSpace(chunk->cframe().translation);
					// 007ab823 / 007ab867: lod = 0 is stored again before the compare, and the compare is the negated
					// `<` (test ah, 5; jnp), i.e. an if / else on -z < 80.
					if (-local.z < 80.0f)
						lod = 0;
					else
						lod = 1;
				}

				RenderBase::Mesh::LevelRef meshLevel = chunkMesh->detailLevel((float)lod);
				bool rebuilt = false;

				if (chunkMesh->meshKind == 4 && !engine->supportDepthBias && meshLevel->dirty)
				{
					RenderBase::Mesh::LevelRef base = chunkMesh->detailLevel(0.0f);
					if (base->primitive == G3D::RenderDevice::QUADS && base->indexArray.size() == 4)
					{
						const G3D::Vector3& normal = chunkMesh->getNormal(base->indexArray[0]);
						for (int j = 0; j < 4; j++)
						{
							// The 2007 analog's getVertex returns a writable reference; the native header declares it const.
							// The target calls getVertex 007a9c90 before scaling the normal (007ab911 / 007ab916).
							G3D::Vector3& vertex = const_cast<G3D::Vector3&>(chunkMesh->getVertex(base->indexArray[j]));
							vertex += normal * 0.06f;
						}
					}
				}

				if (!hardwareMeshes)
				{
					if (meshLevel->dirty)
					{
						Ogre::AxisAlignedBox box;
						meshLevel->makeSWSubMesh(engine, box);
						float radius = box.getHalfSize().length();
						Ogre::Sphere sphere(box.getCenter(), radius);
						rootNode->setSphere(meshLevel->subMesh, sphere);
						rebuilt = true;
					}
				}
				else if (meshLevel->dirty)
				{
					Ogre::AxisAlignedBox box;
					meshLevel->makeHWSubMesh(builder, box);
					float radius = box.getHalfSize().length();
					Ogre::Sphere sphere(box.getCenter(), radius);
					rootNode->setSphere(!meshLevel->dirty && meshLevel->vertexStart >= 0
					                        ? RenderBase::Mesh::sharedMesh->getSubMesh(meshLevel->vertexStart)
					                        : NULL,
					                    sphere);
					rebuilt = true;
				}

				bool updateMaterial = false;
				Material::Level* level = dynamic_cast<Material::Level*>(&chunk->getMaterial()->getLevel(0));
				if (level && level->ogreMaterial.isNull())
				{
					char name[8];
					_snprintf(name, 8, "m%d", materialCounter++);
					level->ogreMaterial = Ogre::MaterialManager::getSingleton().create(name, "General");

					for (int j = 0; j < (int)chunk->getMaterial()->levelCount(); j++)
					{
						Material::Level* levelJ = dynamic_cast<Material::Level*>(&chunk->getMaterial()->getLevel(j));
						if (levelJ == NULL)
							continue;

						levelJ->baseTexture(rd);

						Ogre::Pass* pass;
						if (j == 0)
							pass = level->ogreMaterial->getTechnique(0)->getPass(0);
						else
							pass = level->ogreMaterial->getTechnique(0)->createPass();

						const G3D::Color3& color = levelJ->color();
						pass->setDiffuse(color.r, color.g, color.b, 1.0f - levelJ->transparent());
						pass->setAmbient(color.r, color.g, color.b);

						if (chunkMesh->meshKind == 1 || chunkMesh->meshKind == 2 || chunkMesh->meshKind == 3)
						{
							pass->setSpecular(levelJ->specular(), levelJ->specular(), levelJ->specular(), 1.0f);
							pass->setShininess(chunkMesh->meshKind == 2 ? 40.0f : 18.0f);
						}
						else
						{
							pass->setSpecular(0.75f, 0.75f, 0.75f, 1.0f);
							pass->setShininess(10.0f);
						}

						pass->setDepthBias(chunk->polygonOffset * -16.0f, 0.0f);

						if (levelJ->transparent() > 0.0f || chunkMesh->meshKind == 4)
						{
							pass->setSceneBlending(Ogre::SBF_SOURCE_ALPHA, Ogre::SBF_ONE_MINUS_SOURCE_ALPHA);
							pass->setDepthWriteEnabled(false);
						}

						if (levelJ->baseTexture().notNull())
						{
							Ogre::TexturePtr texture =
								dynamic_cast<TextureProxy*>(levelJ->baseTexture().getPointer())->ogreTexture;
							if (!texture.isNull())
							{
								Ogre::TextureUnitState* unit = pass->createTextureUnitState();
								unit->setColourOperation(Ogre::LBO_MODULATE);
								unit->setTextureFiltering(Ogre::FO_LINEAR, Ogre::FO_LINEAR, Ogre::FO_LINEAR);
								unit->setTextureAddressingMode(Ogre::TextureUnitState::TAM_WRAP,
								                               Ogre::TextureUnitState::TAM_WRAP,
								                               Ogre::TextureUnitState::TAM_WRAP);
								unit->setTextureBorderColour(
									Ogre::ColourValue(levelJ->color().r, levelJ->color().g, levelJ->color().b, 1.0f));
								unit->setTextureName(texture->getName(), Ogre::TEX_TYPE_2D);
							}

							bool hasAlpha = !texture.isNull() && texture->hasAlpha();
							if (!(levelJ->transparent() > 0.0f) && hasAlpha &&
							    meshLevel->primitive == G3D::RenderDevice::TRIANGLES)
							{
								pass->setSceneBlending(Ogre::SBT_REPLACE);
								pass->setDepthWriteEnabled(true);
								pass->setAlphaRejectSettings(Ogre::CMPF_GREATER_EQUAL, 1);
							}
						}
					}

					if (level->reflect() > 0.0f)
					{
						Ogre::TexturePtr sky = Ogre::TextureManager::getSingleton().getByName("skysphmap");
						if (sky.isNull())
						{
							sky = Ogre::TextureManager::getSingleton().create("skysphmap", "General");
							Ogre::Image image;
							std::string path = LDraw2Lua::originalAssetFolder() + "Sky\\" + "skyspheremap.jpg";
							image.load(path, "General");
							sky->loadImage(image);
						}

						Ogre::Pass* reflection = level->ogreMaterial->getTechnique(0)->createPass();
						float reflect = level->reflect();
						reflection->setDiffuse(reflect, reflect, reflect, reflect * 0.8f);
						reflection->setAmbient(reflect, reflect, reflect);
						reflection->setSceneBlending(Ogre::SBF_ONE, Ogre::SBF_ONE_MINUS_SOURCE_ALPHA);
						Ogre::TextureUnitState* unit = reflection->createTextureUnitState();
						unit->setTextureName(sky->getName(), Ogre::TEX_TYPE_2D);
						unit->setEnvironmentMap(true, Ogre::TextureUnitState::ENV_CURVED);
					}

					updateMaterial = true;
				}

				if (chunk->subEntity == NULL)
				{
					Ogre::SubMesh* subMesh;
					Ogre::RbxSubEntity* subEntity;
					// One shared throw site (007acb93) for both the hardware and the software checks.
					if (hardwareMeshes ? (meshLevel->dirty || meshLevel->vertexStart < 0 ||
					                      !RenderBase::Mesh::sharedMesh->getSubMesh(meshLevel->vertexStart))
					                   : meshLevel->subMesh == NULL)
						throw std::exception("Please restart ROBLOX, if you changed your settings but have not restarted");
					if (hardwareMeshes)
					{
						subMesh = !meshLevel->dirty && meshLevel->vertexStart >= 0
						              ? RenderBase::Mesh::sharedMesh->getSubMesh(meshLevel->vertexStart)
						              : NULL;
						subEntity = static_cast<Ogre::RbxSubEntity*>(entity->createSubEntity(subMesh, lod));
						subEntity->mCastShadows = false;
					}
					else
					{
						subMesh = meshLevel->subMesh;
						subEntity = static_cast<Ogre::RbxSubEntity*>(entity->createSubEntity(subMesh, lod));
					}

					subEntity->setCustomValue(chunk->getSortValue());
					subEntity->mShadowSubMesh = chunkMesh->subMesh;
					if (chunkMesh->subMesh == NULL && chunkMesh->meshKind == 1)
						subEntity->mCastShadows = false;
					if (chunkMesh->meshKind == 4)
						subEntity->mCastShadows = false;

					chunk->subEntity = subEntity;
					chunk->entity = entity;

					const G3D::Vector3& translation = chunk->cframe().translation;
					Ogre::AxisAlignedBox bounds(entityBounds(entity));
					if (fabs(translation.x) < 10000.0f && fabs(translation.y) < 10000.0f && fabs(translation.z) < 10000.0f)
					{
						// 007ac6b7: the sphere branch is laid out first (je to the mesh-bounds branch 007ac7f6).
						if (subMesh != meshLevel->subMesh)
						{
							const Ogre::Sphere& sphere = rootNode->getSphere(subMesh);
							float radius = sphere.getRadius();
							const G3D::Vector3& position = chunk->cframe().translation;
							Ogre::AxisAlignedBox merged(entityBounds(entity));
							// The sphere box (007ac788, esp+0x188) is destroyed after the 007a9c40 call: a named local.
							// The minimum corner is computed and stored first (007ac703..007ac74f), then the maximum.
							Ogre::Vector3 minimum(sphere.getCenter().x + position.x - radius, sphere.getCenter().y + position.y - radius,
							                      sphere.getCenter().z + position.z - radius);
							Ogre::Vector3 maximum(position.x + sphere.getCenter().x + radius, position.y + sphere.getCenter().y + radius,
							                      position.z + sphere.getCenter().z + radius);
							Ogre::AxisAlignedBox sphereBox(minimum, maximum);
							merged.merge(sphereBox);
							entity->sub_007a9c40(merged);
						}
						else
						{
							const Ogre::AxisAlignedBox& meshBounds = subMeshBounds(meshLevel->subMesh);
							// The offset box (007ac872, esp+0x78) is destroyed after the 007a9c40 call: a named local.
							Ogre::AxisAlignedBox meshBox(
								Ogre::Vector3(meshBounds.getMinimum().x + translation.x, meshBounds.getMinimum().y + translation.y,
								              meshBounds.getMinimum().z + translation.z),
								Ogre::Vector3(meshBounds.getMaximum().x + translation.x, meshBounds.getMaximum().y + translation.y,
								              meshBounds.getMaximum().z + translation.z));
							bounds.merge(meshBox);
							entity->sub_007a9c40(bounds);
						}
					}
				}
				else if (rebuilt || !chunk->subEntity->getSubMesh(lod))
				{
					if (hardwareMeshes)
					{
						if (!meshLevel->dirty && meshLevel->vertexStart >= 0 &&
						    RenderBase::Mesh::sharedMesh->getSubMesh(meshLevel->vertexStart))
							chunk->subEntity->setSubMesh(lod, !meshLevel->dirty && meshLevel->vertexStart >= 0
							                                      ? RenderBase::Mesh::sharedMesh->getSubMesh(meshLevel->vertexStart)
							                                      : NULL);
					}
					else if (meshLevel->subMesh)
					{
						chunk->subEntity->setSubMesh(lod, meshLevel->subMesh);
					}
				}

				chunk->subEntity->setLod(lod);
				chunk->subEntity->setCustomValue(chunk->getSortValue());

				Ogre::RbxSubEntity* subEntity = chunk->subEntity;
				if (level && (updateMaterial || subEntity->getMaterial() == material))
				{
					if (!level->ogreMaterial.isNull())
						subEntity->setMaterialName(level->ogreMaterial->getName());
				}

				// cframe() is called before the quaternion is initialised (007ac9c5).
				const G3D::Matrix3& rotationMatrix = chunk->cframe().rotation;
				Ogre::Quaternion rotation(1.0f, 0.0f, 0.0f, 0.0f);
				rotation.FromRotationMatrix(reinterpret_cast<const Ogre::Matrix3&>(rotationMatrix));
				const G3D::Vector3& position = chunk->cframe().translation;
				Ogre::Matrix4 transform;
				transform.makeTransform(Ogre::Vector3(position.x, position.y, position.z), Ogre::Vector3(1.0f, 1.0f, 1.0f),
				                        rotation);
				chunk->subEntity->mTransform = transform;
			}

			if (hardwareMeshes && RenderBase::Mesh::varDirty)
			{
				RenderBase::Mesh::updateGeometry(builder);
				if (entity)
					entity->setMesh(RenderBase::Mesh::sharedMesh);
			}

			timer.getMicroseconds();
			timer.reset();

			if (entity)
			{
				entity->func_0067c510(&engine->frameHistory);
				entityCameraNotified(entity) = false;
				// vtable +0xd8 (007acc0a): RbxEntity slot 54 0067c6a0, not MovableObject::setVisible (+0x74).
				entity->func_0067c6a0(true);
				if (effectSettings.stencilShadows())
				{
					entityLodBudget(entity) = 15.0f;
					entityMinimumLod(entity) = 600;
				}
				else
				{
					entityLodBudget(entity) = 20.0f;
					entityMinimumLod(entity) = 650;
				}
			}

			if (Ogre::sRoot->_fireFrameStarted())
			{
				engine->renderTarget->update();
				Ogre::sRoot->_fireFrameEnded();
				timer.getMicroseconds();
			}
		}
	}
}
