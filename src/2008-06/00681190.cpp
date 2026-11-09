// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.4.5 roc_observed_3db354efc99e4c09.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>

namespace Ogre {
// Codegen analog on the genuine vendor layout. The two stack arguments are
// proven by ret 8; the target ignores them and copies the local transform.
class RbxSceneNode : public SceneNode {
public:
    void _update(bool, bool);
};
void RbxSceneNode::_update(bool, bool) {
    mDerivedOrientation.w = mOrientation.w;
    mDerivedOrientation.x = mOrientation.x;
    mDerivedOrientation.y = mOrientation.y;
    mDerivedOrientation.z = mOrientation.z;
    mDerivedPosition.x = mPosition.x;
    mDerivedPosition.y = mPosition.y;
    mDerivedPosition.z = mPosition.z;
    mDerivedScale.x = mScale.x;
    mDerivedScale.y = mScale.y;
    mDerivedScale.z = mScale.z;
    mWorldAABB.setExtents(-10000.0f, -10000.0f, -10000.0f,
                        10000.0f, 10000.0f, 10000.0f);
}
}
