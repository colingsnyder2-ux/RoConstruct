#pragma once
// >>> native-status (generated) -- do not edit >>>
// VisualEngine2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 9c5033d4 | roc native-status --write
// 2008-06 native Ogre::VisualEngine (Roblox exe-local owner of the Ogre Root / scene manager / camera / render window).
// Layout derived from the original exe (evidence per member below; derivation: commit e816da27a6,
// tests/record_native_ogre_visual_engine.py). Size 0x808 (new(0x808) at CRobloxView 0045cc9c).
// One member is INFERRED, not derived: FrameHistory +0x4 (VisualEngine +0x1c), which no instruction reads, writes,
// constructs or destroys. Owner approved (2026-11-11) declaring an inferred field where the original source plausibly
// had one; its type and name are not evidence.
#include <windows.h>
#include <map>
#include <boost/thread/once.hpp>
#include <OgrePrerequisites.h>
#include <OgreString.h>
#include <OgreStringVector.h>
namespace Ogre
{
	class TwoDManager;
	class SubMesh;
	// History of the last 100 frames (ring buffer), VisualEngine +0x18, size 0x7d8. RbxEntity keeps a pointer to it
	// (RbxEntity +0x274, set by 0067c510 from AdornRbxGfx 00674579 and 007acbf0).
	class FrameHistory
	{
	public:
		struct Frame                            // 0x14: stride of push 006785f0 / get 00678630
		{
			float time;                         // +0x0 the value median 00679990 sorts
			float values[4];                    // +0x4.. (+0x4 / +0x8 read as floats by CRobloxView 0045e014 / 0045e01c)
			Frame() { time = -1.0f; for (int i = 0; i < 4; ++i) values[i] = -1.0f; }   // all -1.0f (006785b0)
		};
		FrameHistory();                         // 006785b0
		void push(const Frame& frame);          // 006785f0 (RbxEntity 0067e26a)
		Frame* get(int ago);                    // 00678630
		float median(int n);                    // 00679990 (RbxEntity 0067de8c, n = 20)
		int count;                              // +0x0 frames pushed so far (also read through the folded getter 0071f210)
		int inferred4;                          // +0x4 INFERRED (owner-approved): 4 bytes never accessed; type/name unknown
		Frame frames[100];                      // +0x8
	};
	class VisualEngine
	{
	public:
		VisualEngine();                         // 006786c0 (new(0x808) at 0045cc9c)
		virtual ~VisualEngine();                // 0067a130, vtable 0084df2c, ??_G 0067c4b0
		SceneManager* sceneManager;             // +0x04 dynamic_cast<RbxSceneManager*> 0067ba33, Root::destroySceneManager
		Camera* camera;                         // +0x08 sceneManager->createCamera("Camera") 0067ba68
		RenderTarget* renderTarget;             // +0x0c Root::createRenderWindow 0067b279, Root::detachRenderTarget 0067a17e
		Viewport* viewport;                     // +0x10 renderTarget->addViewport 0067bad3, RbxSky::setLighting 0067f80e
		TwoDManager* twoD;                      // +0x14 new(0x58) TwoDManager 0067bb22, deleted 0067a191
		FrameHistory frameHistory;              // +0x18 (ctor 006786dd)
		size_t videoMemorySize;                 // +0x7f0 getVideoMemory 0067ac3b, "RBX vidMemSize=" (unsigned), memory budget
		bool useLargeVertexBuffer;              // +0x7f4 "RBX useLargeVertexBuffer=" 0067b87e / 0067b8c3, RenderScene 0054acfa
		bool useLargeVertexBufferAdorn;         // +0x7f5 written with +0x7f4 (0067b877 / 0067b8bc), Adorn 007ab2ea
		int largeVertexBufferSetting;           // +0x7f8 ctor -1; CRobloxView 0045cecb; 0 / 1 force +0x7f4 / +0x7f5
		int zBufferBits;                        // +0x7fc 16 / 15 / 32 / 24 / -1 (0067b302..0067b3a1), "RBX zbuffer bits "
		int antialiasing;                       // +0x800 1 on / 2 off (0067b1e8 / 0067b22e) or the setting, CRobloxView 0045e1fb
		bool softwareVertexProcessing;          // +0x804 "RBX softwareVertexProcessing=" 0067b4ff, CRobloxView 0045d0e4
		bool textureSquareOnly;                 // +0x805 "RBX textureSquareOnly=" 0067b56f, "RBX Savage lies" 0067b983
		bool supportDepthBias;                  // +0x806 "RBX supportDepthBias=" 0067b5d9, Adorn 007ab8aa
	};
	extern Root* sRoot;                         // 0097db48
	DWORD getVideoMemory();                     // 00678510
	void releaseUnusedResources(ResourceManager& manager, const String& type, const StringVector& keepPatterns);  // 006792b0
	void dumpResources(ResourceManager& manager, const String& type);                                             // 00678e20
	// Not VisualEngine's (owner not derived; used by the SubMesh helpers 0067c130): the SubMesh name map 0097db44
	// (map<SubMesh*, String>: node key +0xc, String +0x10, size +0x1c read by the destructor), its once flag 00973984
	// and initialiser 0054ab60 (boost::call_once 00557330 at 0067a34e).
	typedef std::map<SubMesh*, String> SubMeshNames;
	extern SubMeshNames* subMeshNames;
	extern boost::once_flag subMeshNamesOnce;
	void initializeSubMeshNames();
}

// Layout checks (offsets derived from the exe).
typedef char VisualEngine_size_is_0x808[sizeof(Ogre::VisualEngine) == 0x808 ? 1 : -1];
