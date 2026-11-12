// Layout probes for the inactive native Ogre::RbxSky recovery (2008-06). Each probe compiles to `mov eax, imm32; ret`;
// tests/record_native_ogre_rbx_sky.py compares the immediates with the sizes and offsets read from the original.
//   * library types the RbxSky bodies use, from the current (Ogre 1.4.5 client / G3D) headers: ManualObject is 0x1d4
//     (operator new(0x1d4) at 00680ede before the ManualObject constructor import), TexturePtr / MaterialPtr are 0xc
//     (members 0xc apart in the constructor 0067fd60 / destructor 0067fb50), std::vector is 0x18 (+0x88 / +0xa0, the
//     destructor frees +0x0 and +0xc of each), Ogre::Vector3 is 0xc (0x2aaaaaab / 12 in resize 0067fc70), G3D
//     LightingParameters is 0xf8 (by value: ret 0x114 in Render::RenderScene 00503cc0 = 4 + 0xf8 + 2 * Color3, and
//     the LightingParameters ctor 007b6860 on +0x310 / +0x408 in Render::RenderScene), and the LightingParameters members read by 0067f7f0 / 0067f230 / 0067f550 (skyAmbient +0xc, emissiveScale +0x0,
//     physicallyCorrect +0x4c, trueSunPosition +0x50, sunPosition +0x5c, trueMoonPosition +0x68, moonPosition +0x74);
//   * NATIVE_OGRE_RBX_SKY_PENDING only: the generated proposal declaration of RbxSky (size 0xd4 from new(0xd4) in
//     setSkyBox 00692a10) and the VisualEngine prefix. Those probes are recorded as pending-build-only.
#include <vector>
#include <stddef.h>
#include <OgreManualObject.h>
#include <OgreTexture.h>
#include <OgreMaterial.h>
#include <OgreVector3.h>
#include <GLG3D/LightingParameters.h>
#ifdef NATIVE_OGRE_RBX_SKY_PENDING
#include "OgreRbxSky/RbxSkyPending2008.h"
#endif

struct NativeOgreRbxSkyLayout
{
	static int manualObjectSize() { return sizeof(Ogre::ManualObject); }
	static int texturePtrSize() { return sizeof(Ogre::TexturePtr); }
	static int materialPtrSize() { return sizeof(Ogre::MaterialPtr); }
	static int vector3VectorSize() { return sizeof(std::vector<Ogre::Vector3>); }
	static int floatVectorSize() { return sizeof(std::vector<float>); }
	static int vector3Size() { return sizeof(Ogre::Vector3); }
	static int lightingSize() { return sizeof(G3D::LightingParameters); }
	static int lightingEmissiveScale() { return offsetof(G3D::LightingParameters, emissiveScale); }
	static int lightingSkyAmbient() { return offsetof(G3D::LightingParameters, skyAmbient); }
	static int lightingPhysicallyCorrect() { return offsetof(G3D::LightingParameters, physicallyCorrect); }
	static int lightingTrueSunPosition() { return offsetof(G3D::LightingParameters, trueSunPosition); }
	static int lightingSunPosition() { return offsetof(G3D::LightingParameters, sunPosition); }
	static int lightingTrueMoonPosition() { return offsetof(G3D::LightingParameters, trueMoonPosition); }
	static int lightingMoonPosition() { return offsetof(G3D::LightingParameters, moonPosition); }
#ifdef NATIVE_OGRE_RBX_SKY_PENDING
	static int skySize() { return sizeof(Ogre::RbxSky); }
	static int visualEngineViewport() { return offsetof(Ogre::VisualEngine, viewport); }
	static int visualEngineTwoD() { return offsetof(Ogre::VisualEngine, twoD); }
#endif
};

#define PROBE(name) int nativeOgreRbxSky_##name() { return NativeOgreRbxSkyLayout::name(); }
PROBE(manualObjectSize)
PROBE(texturePtrSize)
PROBE(materialPtrSize)
PROBE(vector3VectorSize)
PROBE(floatVectorSize)
PROBE(vector3Size)
PROBE(lightingSize)
PROBE(lightingEmissiveScale)
PROBE(lightingSkyAmbient)
PROBE(lightingPhysicallyCorrect)
PROBE(lightingTrueSunPosition)
PROBE(lightingSunPosition)
PROBE(lightingTrueMoonPosition)
PROBE(lightingMoonPosition)
#ifdef NATIVE_OGRE_RBX_SKY_PENDING
PROBE(skySize)
PROBE(visualEngineViewport)
PROBE(visualEngineTwoD)
#endif
