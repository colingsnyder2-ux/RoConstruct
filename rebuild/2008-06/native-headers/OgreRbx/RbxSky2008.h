#pragma once
// >>> native-status (generated) -- do not edit >>>
// RbxSky2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src fdf86ae6 | roc native-status --write
// Ogre::RbxSky as compiled into the June 2008 client: full declaration (inactive native recovery). Layout from tests/record_native_ogre_rbx_sky.py (commit
// 5650640db1) with the one INFERRED member at +0x50: the real object is 0xd4 bytes (new(0xd4) in RbxSceneManager::setSkyBox 00692a10,
// constructor 0067fd60), but no member is declared here; one 4-byte member at +0x50 is not derived (no instruction of
// the client touches it), see tests/record_native_ogre_rbx_sky.py and its generated proposal header. Do not allocate,
// construct or take sizeof of this class from this declaration.
//
// Non-colliding name: there is no donor RbxSky header.
//
// Evidence (original Roblox.exe):
//   * RTTI: vtable 0084e56c .?AVRbxSky@Ogre@@, no base classes, one slot: ??_G 0067fd40 (calls the destructor
//     0067fb50). The virtual destructor is declared because SharedPtr<RbxSky>::destroy (slot 1 of the SharedPtr<RbxSky>
//     vtable 0084ec3c, ICF-folded at 004d73a0) deletes pRep through vtable slot 0 with flag 1.
//   * update(Camera*, RenderQueue*, RenderQueueGroupID) 0067f850 (non-virtual __thiscall, ret 0xc): called by
//     RbxSceneManager::_queueSkiesForRendering 0068d7d0 for the sky-box queue group.
#include <vector>
#include <OgrePrerequisites.h>
#include <OgreTexture.h>
#include <OgreMaterial.h>
#include <OgreVector3.h>
#include <OgreRenderQueue.h>
namespace G3D { class LightingParameters; }

namespace Ogre
{
	class VisualEngine;     // OgreRbx/VisualEngine2008.h

	class RbxSky
	{
	public:
		RbxSky(SceneManager* sceneManager, const String& path, bool enabled);   // 0067fd60
		virtual ~RbxSky();                                                      // 0067fb50 (??_G 0067fd40)
		void update(Camera* camera, RenderQueue* queue, RenderQueueGroupID qid);   // 0067f850
		void setLighting(VisualEngine* engine, const G3D::LightingParameters& lighting);   // 0067f7f0 (004daef2)
	protected:
		void updateMoonAndStars(VisualEngine* engine, const G3D::LightingParameters& lighting);   // 0067f230
		void updateSun(VisualEngine* engine, const G3D::LightingParameters& lighting);            // 0067f550

		TexturePtr mSunTexture;                 // +0x04
		TexturePtr mMoonTexture;                // +0x10
		TexturePtr mSpareTexture;               // +0x1c (constructed / destroyed only)
		TexturePtr mSunRaysTexture;             // +0x28
		BillboardSet* mSun;                     // +0x34
		BillboardSet* mMoon;                    // +0x38
		BillboardSet* mSunRays;                 // +0x3c
		SceneNode* mSunNode;                    // +0x40
		SceneNode* mMoonNode;                   // +0x44
		SceneNode* mStarsNode;                  // +0x48
		SceneNode* mSkyNode;                    // +0x4c
		void* mUnderived50;                     // +0x50 INFERRED (owner rule 2026-11-11): 4 bytes never accessed; type/name unknown
		MaterialPtr mSunMaterial;               // +0x54
		MaterialPtr mSunRaysMaterial;           // +0x60
		MaterialPtr mMoonMaterial;              // +0x6c
		MaterialPtr mStarsMaterial;             // +0x78
		bool mSunRaysVisible;                   // +0x84
		bool mStarsVisible;                     // +0x85
		std::vector<Vector3> mStarPositions;    // +0x88
		std::vector<float> mStarIntensities;    // +0xa0
		bool mEnabled;                          // +0xb8
		Vector3 mSunPosition;                   // +0xbc
		Vector3 mMoonPosition;                  // +0xc8
	};
	typedef char RbxSky2008Size[(sizeof(RbxSky) == 0xd4) ? 1 : -1];
}
