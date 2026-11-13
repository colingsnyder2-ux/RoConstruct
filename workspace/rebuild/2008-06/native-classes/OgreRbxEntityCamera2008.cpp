// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// INFERRED: imported declarations match original 0067daf0 calls.
#include "OgreRbxEntityImports/OgreVector3.h"
// >>> native-status (generated) -- do not edit >>>
// OgreRbxEntity | 2008-06 | draft (no current byte proof)
// 0/3 mapped addresses byte-exact | 3 unproved | no mapped strings | by colin (chatgpt:gpt-6.1-sol)
// <<< native-status | src 0dcbb938 | roc native-status --write
#define NOMINMAX                 // VisualEngine2008.h pulls <windows.h>; std::max below
#include "OgreRbx/RbxEntity2008.h"
#include "AppUnit67C_2008/RbxSubEntity2008.h"
#include <OgreSubEntity.h>
#include <OgreSubMesh.h>
#include "OgreRbx/RbxSubMesh2008.h"
#include "OgreRbx/VisualEngine2008.h"
#include <OgreCamera.h>
#include <OgreLight.h>
#include "OgreRbxNode/RbxSceneNode2008.h"
#include <OgreTechnique.h>
#include <OgrePass.h>
#include <algorithm>

// INFERRED placeholder names (owner rule 2026-11-11): globals read by RbxEntity::collect 0067e2f0.
extern bool nativeShadowThrottle;
extern int nativeShadowMode;
extern float nativeLodLowMs;
extern float nativeLodHighMs;

namespace Ogre
{
struct RankedSubIndex {
    unsigned index;
    float priority;
    bool operator<(const RankedSubIndex& rhs) const {return priority<rhs.priority;}
};

void RbxEntity::func_0067daf0(Camera* camera) {
    RbxSceneNode* node=dynamic_cast<RbxSceneNode*>(getParentNode());
    std::vector<RankedSubIndex> order;
    bool adaptive=nativeShadowThrottle && mHistory;
    if(adaptive) {
        order.resize(mSubEntityList.size());
        order.erase(order.begin(),order.end());
    }
    if(mSubEntityList.size()) {
        mVisibility.resize(mSubEntityList.size(),0);
        memset(&mVisibility[0],0,mVisibility.size());
    }
    for(int i=0;i<(int)mSubEntityList.size();++i) {
        RbxSubEntity* sub=dynamic_cast<RbxSubEntity*>(mSubEntityList[i]);
        Vector3 translation=sub->mTransform.getTrans();
        bool visible=true;
        SubMesh* mesh=sub->SubEntity::getSubMesh();
        if(!mesh) mesh=sub->getSubMesh(1);
        Sphere bounds=node->getSphere(mesh);
        bounds.setCenter(bounds.getCenter()+translation);
        if(mVisibilityCulling) visible=camera->isVisible(bounds);
        sub->setVisible(visible);
        if(!visible) mVisibility[i]=2;
        else {
            mVisibility[i]=1;
            if(adaptive) {
                RankedSubIndex item;
                item.index=i;
                float depth=Math::Sqrt(sub->getSquaredViewDepth(camera));
                item.priority=static_cast<float>(depth-bounds.getRadius()
                    -(sub->getCustomValue()==1.0f)*1000000.0);
                order.push_back(item);
            }
        }
    }
    if(adaptive) {
    int selected=order.size();
    if(mHistory->getCount()>30) {
        const FrameHistory::Frame& last=*mHistory->get(0);
        float median=mHistory->median(20);
        float inverse=1.0f/median;
        float change=Math::Abs((median-last.time)*inverse);
        if(!(change<=0.2f)) {
            if(last.values[1]<last.values[0]) {
                selected=order.size();
                selected=(int)(last.values[1]<static_cast<float>(selected)?last.values[1]:static_cast<float>(selected));
            } else selected=order.size();
        } else {
            if(median>nativeLodLowMs) {
                // Native truncates this fraction before applying its budget math.
                int minimum=(int)(mLodBudget*0.01f);
                float low=nativeLodLowMs;
                float high=nativeLodHighMs;
                if(median>nativeLodHighMs) selected=(int)(minimum*last.values[1]);
                else {
                    float factor=1.0f-Math::Sin((median-low)*Math::HALF_PI/(high-low),false)*(1.0f-minimum);
                    selected=(int)(factor*last.values[1]);
                }
                if(selected<static_cast<float>(mSubEntityList.size())*minimum)
                    selected=(int)(static_cast<float>(mSubEntityList.size())*minimum);
                if(Math::Abs(last.values[1]-selected)<40.0f) selected=(int)last.values[1];
                if(selected<mMinimumLod) selected=mMinimumLod;
                if(selected>(int)order.size()) selected=order.size();
            } else {
                if(last.values[1]<last.values[0]) {
                    selected=(int)last.values[1];
                    float growth=(nativeLodLowMs-median)*inverse;
                    int grown=(int)((growth>1.2f?1.2f:growth)*selected);
                    if(grown>=selected+40) selected=grown;
                    if(selected>(int)order.size()) selected=order.size();
                } else selected=order.size();
            }
        }
    }
    if(selected<(int)order.size()) {
        std::sort(order.begin(),order.end());
        for(int i=selected;i<(int)order.size();++i) {
            RbxSubEntity* sub=dynamic_cast<RbxSubEntity*>(mSubEntityList[order[i].index]);
            sub->setVisible(false);
            mVisibility[order[i].index]=3;
        }
    }
    if(mRecordHistory) {
        FrameHistory::Frame sample;
        mHistory->push(sample);
        FrameHistory::Frame& last=*mHistory->get(0);
        last.values[0]=order.size();
        last.values[1]=selected;
    }
    }
}
}
