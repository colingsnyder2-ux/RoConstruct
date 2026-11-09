// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_try_3de506635a8ad8a6.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
using namespace Ogre;
#include <set>
namespace Ogre {
class RbxSceneNode : public SceneNode {
public:
    RbxSceneNode();
    std::set<unsigned int> mSet;
    bool has(unsigned int key);
};
bool RbxSceneNode::has(unsigned int key)
{
    std::set<unsigned int>::iterator it = mSet.find(key);
    return it != mSet.end();
}
}
