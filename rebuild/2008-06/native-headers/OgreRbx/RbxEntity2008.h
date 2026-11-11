#pragma once
// >>> native-status (generated) -- do not edit >>>
// RbxEntity2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 9497cc93 | roc native-status --write
// Ogre::RbxEntity, June 2008 executable-local Entity extension.
// Target proof: 0067d1f0 constructs Entity then writes derived state through
// +0x274..+0x2b8; allocation is 0x2bc. 0067d420 destroys AxisAlignedBox at
// +0x27c and the debug std::vector ABI at +0x2a4. 0067daf0 writes byte
// elements through +0x2b0; 007acbfb writes the +0x279 byte flag.
#include <OgreEntity.h>
#include <OgreAxisAlignedBox.h>
#include <vector>

namespace Ogre
{
	class RbxEntity : public Entity
	{
		void* mHistory;                         // +0x274, non-owning opaque receiver
		bool mVisibilityCulling;                // +0x278
		bool mCameraNotified;                   // +0x279
		bool mRecordHistory;                    // +0x27a
		AxisAlignedBox mBounds;                 // +0x27c
		Real mLodBudget;                        // +0x29c
		int mMinimumLod;                        // +0x2a0
		std::vector<unsigned char> mVisibility; // +0x2a4, byte element accesses proven

	public:
		RbxEntity();                            // 0067d1f0
		virtual ~RbxEntity();                   // 0067d420
		virtual void _notifyCurrentCamera(Camera* camera); // slot 24, 0067c570
		virtual void _updateRenderQueue(RenderQueue* queue); // slot 28, 0067d010
		virtual void func_0067daf0(Camera* camera); // slot 53; name not recovered
		virtual void func_0067c6a0(bool visible);  // slot 54; name not recovered
		SubEntity* createSubEntity(SubMesh* subMesh, unsigned int lod); // 0067d9b0
		// Direct call 00696269 -> 0067e2f0 proves this exact non-virtual ABI.
		// Its body remains unrecovered; declaration enables its proven SceneManager caller.
		void collect(const Camera* camera, const Light* light, std::vector<ShadowCaster*>& output); // 0067e2f0
	};

	typedef char RbxEntity2008Size[(sizeof(RbxEntity) == 0x2bc) ? 1 : -1];
}
