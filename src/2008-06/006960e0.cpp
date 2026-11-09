// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_rbx_scenemgr_shadowcasters_44af38d731495640.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>

namespace Ogre {

class RbxEntity : public Entity {
public:
    void collect(const Camera* camera, const Light* light,
                 std::vector<ShadowCaster*>& casters);
};

class RbxSceneManager : public SceneManager {
public:
    const ShadowCasterList& findShadowCastersForLight(const Light* light, const Camera* camera);
};



bool findingShadowCasters = false;

const SceneManager::ShadowCasterList& RbxSceneManager::findShadowCastersForLight(
    const Light* light, const Camera* camera)
{
    if (findingShadowCasters == true)
        throw std::exception("findShadowCastersForLight call repeated");
    findingShadowCasters = true;

    mShadowCasterList.clear();

    SceneNode* root = dynamic_cast<SceneNode*>(mSceneRoot->getChild("rbxroot"));
    if (!root)
    {
        LogManager::getSingleton().logMessage("RBX Missing or duplicate world node", LML_NORMAL);
    }
    else
    {
        if (root->getAttachedObjectIterator().hasMoreElements())
        {
            RbxEntity* entity = dynamic_cast<RbxEntity*>(root->getAttachedObject(0));
            entity->collect(camera, light, mShadowCasterList);
        }
    }
    return mShadowCasterList;
}

}

