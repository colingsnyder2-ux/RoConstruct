// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: ogre-1.4.5-dll roc_rbxscene_populate_shadow_count_989700d72290bd34.cpp

// Candidate translation unit (score above; library headers required).
#define RbxSceneManager RbxSceneManagerBase
#include "roc_fork_ea71c50b47f88007.cpp"
#undef RbxSceneManager

namespace Ogre {

class RbxSceneManager : public RbxSceneManagerBase {
public:
    virtual void _populateLightList(const Vector3& position, Real radius,
                                    LightList& destList);
};

void RbxSceneManager::_populateLightList(const Vector3& position, Real radius,
                                         LightList& destList)
{
    const LightList& candidateLights = _getLightsAffectingFrustum();

    destList.clear();
    destList.reserve(candidateLights.size());

    LightList::const_iterator it;
    for (it = candidateLights.begin(); it != candidateLights.end(); ++it)
    {
        Light* lt = *it;
        if (lt->getType() == Light::LT_DIRECTIONAL)
        {
            lt->tempSquareDist = 0.0f;
            destList.push_back(lt);
        }
        else
        {
            lt->tempSquareDist = (lt->getDerivedPosition() - position).squaredLength();
            Real range = lt->getAttenuationRange();
            Real maxDist = range + radius;
            if (lt->tempSquareDist <= Math::Sqr(maxDist))
            {
                destList.push_back(lt);
            }
        }
    }

    if (isShadowTechniqueTextureBased())
    {
        if (destList.size() > mShadowTextureConfigList.size())
        {
            LightList::iterator start = destList.begin();
            std::advance(start, mShadowTextureConfigList.size());
            std::stable_sort(start, destList.end(), lightLess());
        }
    }
    else
    {
        std::stable_sort(destList.begin(), destList.end(), lightLess());
    }
}

}
