#pragma once
// >>> native-status (generated) -- do not edit >>>
// RbxSky2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 3626c050 | roc native-status --write
// Ogre::RbxSky as compiled into the June 2008 client: a MINIMAL interface for the RbxSceneManager fork (inactive native
// recovery). NO LAYOUT IS CLAIMED: the real object is 0xd4 bytes (new(0xd4) in RbxSceneManager::setSkyBox 00692a10,
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
#include <OgrePrerequisites.h>
#include <OgreRenderQueue.h>

namespace Ogre
{
	class RbxSky
	{
	public:
		virtual ~RbxSky();                                                        // 0067fb50 (??_G 0067fd40)
		void update(Camera* camera, RenderQueue* queue, RenderQueueGroupID qid);  // 0067f850
	};
}
