// Layout probes for the inactive native Ogre::VisualEngine recovery (2008-06). Each probe compiles to `mov eax, imm32;
// ret`; tests/record_native_ogre_visual_engine.py compares the immediates with the sizes and offsets read from the original.
//   * current headers: DDSCAPS is 4 bytes (getVideoMemory 00678510 keeps the IDirectDraw2*, the free-memory DWORD and
//     the caps at esp+4 / +8 / +0xc of a 0xc-byte frame), std::vector<float> is 0x18 (the median 00679990 frees +0xc
//     and the +0x0 proxy of its local);
//   * NATIVE_OGRE_VISUAL_ENGINE_PENDING only: the generated proposal declaration (size 0x808 from new(0x808) at 0045cc9c;
//     member offsets from the constructor 006786c0, destructor 0067a130, initialiser 0067a7e0 and the readers listed in
//     the proposal header). Those probes are recorded as pending-build-only.
#include <windows.h>
#include <ddraw.h>
#include <vector>
#include <stddef.h>
#ifdef NATIVE_OGRE_VISUAL_ENGINE_PENDING
#include <OgrePrerequisites.h>
#include "OgreRbxSky/VisualEnginePending2008.h"
#endif

struct NativeOgreVisualEngineLayout
{
	static int ddsCapsSize() { return sizeof(DDSCAPS); }
	static int floatVectorSize() { return sizeof(std::vector<float>); }
#ifdef NATIVE_OGRE_VISUAL_ENGINE_PENDING
	static int engineSize() { return sizeof(Ogre::VisualEngine); }
	static int sceneManager() { return offsetof(Ogre::VisualEngine, sceneManager); }
	static int camera() { return offsetof(Ogre::VisualEngine, camera); }
	static int renderTarget() { return offsetof(Ogre::VisualEngine, renderTarget); }
	static int viewport() { return offsetof(Ogre::VisualEngine, viewport); }
	static int twoD() { return offsetof(Ogre::VisualEngine, twoD); }
	static int frameHistory() { return offsetof(Ogre::VisualEngine, frameHistory); }
	static int videoMemorySize() { return offsetof(Ogre::VisualEngine, videoMemorySize); }
	static int useLargeVertexBuffer() { return offsetof(Ogre::VisualEngine, useLargeVertexBuffer); }
	static int useLargeVertexBufferAdorn() { return offsetof(Ogre::VisualEngine, useLargeVertexBufferAdorn); }
	static int largeVertexBufferSetting() { return offsetof(Ogre::VisualEngine, largeVertexBufferSetting); }
	static int zBufferBits() { return offsetof(Ogre::VisualEngine, zBufferBits); }
	static int antialiasing() { return offsetof(Ogre::VisualEngine, antialiasing); }
	static int softwareVertexProcessing() { return offsetof(Ogre::VisualEngine, softwareVertexProcessing); }
	static int textureSquareOnly() { return offsetof(Ogre::VisualEngine, textureSquareOnly); }
	static int supportDepthBias() { return offsetof(Ogre::VisualEngine, supportDepthBias); }
	static int historySize() { return sizeof(Ogre::FrameHistory); }
	static int historyCount() { return offsetof(Ogre::FrameHistory, count); }
	static int historyFrames() { return offsetof(Ogre::FrameHistory, frames); }
	static int frameSize() { return sizeof(Ogre::FrameHistory::Frame); }
#endif
};

#define PROBE(name) int nativeOgreVisualEngine_##name() { return NativeOgreVisualEngineLayout::name(); }
PROBE(ddsCapsSize)
PROBE(floatVectorSize)
#ifdef NATIVE_OGRE_VISUAL_ENGINE_PENDING
PROBE(engineSize)
PROBE(sceneManager)
PROBE(camera)
PROBE(renderTarget)
PROBE(viewport)
PROBE(twoD)
PROBE(frameHistory)
PROBE(videoMemorySize)
PROBE(useLargeVertexBuffer)
PROBE(useLargeVertexBufferAdorn)
PROBE(largeVertexBufferSetting)
PROBE(zBufferBits)
PROBE(antialiasing)
PROBE(softwareVertexProcessing)
PROBE(textureSquareOnly)
PROBE(supportDepthBias)
PROBE(historySize)
PROBE(historyCount)
PROBE(historyFrames)
PROBE(frameSize)
#endif
