// Layout probes for the inactive native Ogre::RbxSceneManager (2008-06).
// Each probe compiles to `mov eax, imm32; ret`; tests/record_native_ogre_scene_manager.py compares the immediates with
// the size and offsets read from the original (operator new(0x8c04) in createInstance 0068fde0, constructor 0068e7c0,
// destructor 0069e220, _renderScene 00698cc0 / renderSingleObject 0069bc50; see native-headers/OgreRbx/
// RbxSceneManager2008.h). nativeNewOgreRbxSceneManagerFactory instantiates the header-inline factory constructor so that
// this object carries the RbxSceneManagerFactory vtable and its ??_G.
#include "OgreRbx/RbxSceneManager2008.h"
#include <stddef.h>

struct NativeOgreRbxSceneManagerLayout
{
	typedef Ogre::RbxSceneManager M;
	static int size() { return sizeof(M); }
	static int baseSize() { return sizeof(Ogre::SceneManager); }
	static int passLightingEnabled() { return offsetof(M, mPassLightingEnabled); }
	static int lightsLightingEnabled() { return offsetof(M, mLightsLightingEnabled); }
	static int rbxSkyName() { return offsetof(M, mRbxSkyName); }
	static int rbxSky() { return offsetof(M, mRbxSky); }
	static int rbxSkyNode() { return offsetof(M, mRbxSkyNode); }
	static int shadowCasterQueryListener() { return offsetof(M, mShadowCasterQueryListener); }
	static int activeQueuedRenderableVisitor() { return offsetof(M, mActiveQueuedRenderableVisitor); }
	static int defaultQueuedRenderableVisitor() { return offsetof(M, mDefaultQueuedRenderableVisitor); }
	static int visitorSize() { return sizeof(M::SceneMgrQueuedRenderableVisitor); }
	static int visitorTransparent() { return offsetof(M::SceneMgrQueuedRenderableVisitor, transparentShadowCastersMode); }
	static int listenerSize() { return sizeof(M::ShadowCasterSceneQueryListener); }
	static int skySharedPtrSize() { return sizeof(Ogre::SharedPtr<Ogre::RbxSky>); }
	static int factorySize() { return sizeof(Ogre::RbxSceneManagerFactory); }
};

#define PROBE(name) int nativeOgreRbxSceneManager_##name() { return NativeOgreRbxSceneManagerLayout::name(); }
PROBE(size) PROBE(baseSize) PROBE(passLightingEnabled) PROBE(lightsLightingEnabled) PROBE(rbxSkyName) PROBE(rbxSky)
PROBE(rbxSkyNode) PROBE(shadowCasterQueryListener) PROBE(activeQueuedRenderableVisitor)
PROBE(defaultQueuedRenderableVisitor) PROBE(visitorSize) PROBE(visitorTransparent) PROBE(listenerSize)
PROBE(skySharedPtrSize) PROBE(factorySize)

Ogre::SceneManagerFactory* nativeNewOgreRbxSceneManagerFactory()
{
	return new Ogre::RbxSceneManagerFactory();
}
