// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_rbxscene_apply_animations_a7ba41ac8adad042.cpp

// Candidate translation unit (score above; library headers required).
#define RbxSceneManager RbxSceneManagerBase
#include "roc_fork_ea71c50b47f88007.cpp"
#undef RbxSceneManager

namespace Ogre {

class RbxSceneManager : public RbxSceneManagerBase {
public:
    virtual void _applySceneAnimations(void);
};

void RbxSceneManager::_applySceneAnimations(void)
{
    OGRE_LOCK_MUTEX(mAnimationStates.OGRE_AUTO_MUTEX_NAME)

    ConstEnabledAnimationStateIterator stateIt =
        mAnimationStates.getEnabledAnimationStateIterator();

    while (stateIt.hasMoreElements())
    {
        const AnimationState* state = stateIt.getNext();
        Animation* animation = getAnimation(state->getAnimationName());

        Animation::NodeTrackIterator nodeTrackIt = animation->getNodeTrackIterator();
        while (nodeTrackIt.hasMoreElements())
        {
            Node* node = nodeTrackIt.getNext()->getAssociatedNode();
            node->resetToInitialState();
        }

        Animation::NumericTrackIterator numericTrackIt =
            animation->getNumericTrackIterator();
        while (numericTrackIt.hasMoreElements())
        {
            const AnimableValuePtr& value =
                numericTrackIt.getNext()->getAssociatedAnimable();
            value->resetToBaseValue();
        }

        animation->apply(state->getTimePosition(), state->getWeight());
    }
}

}
