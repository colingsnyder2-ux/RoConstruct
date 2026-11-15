// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
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

// INFERRED names; initial values and references match original shadow settings.
// Original runtime writers still require integration.
bool nativeShadowThrottle = true; // 00962f64
int nativeShadowMode = 2;         // 00962f68
float nativeLodLowMs = 50.0f;    // 00962f6c
float nativeLodHighMs = 100.0f;  // 00962f70

namespace Ogre
{
	// INFERRED name: 0067c510 writes the non-owning FrameHistory pointer at +0x274.
	void RbxEntity::func_0067c510(FrameHistory* history)
	{
		mHistory = history;
	}

	RbxEntity::RbxEntity()
	{
		mLodBudget = 20.0f;
		mInitialised = true;
		mHistory = 0;
		mVisibilityCulling = true;
		mRecordHistory = true;
		mMinimumLod = 888;
	}

	RbxEntity::~RbxEntity()
	{
		for (int i = 0; i < (int)getNumSubEntities(); ++i)
		{
			RbxSubEntity* subEntity = dynamic_cast<RbxSubEntity*>(mSubEntityList[i]);
			if (subEntity)
				delete subEntity;
		}
		mSubEntityList.clear();
	}

	// 0067c6a0: slot 54 of vtable 0084e45c.  The name remains an address
	// placeholder; receiver, bool argument, base SubEntityList iteration and
	// virtual setVisible call are all target-derived.
	void RbxEntity::func_0067c6a0(bool visible)
	{
		for (int i = 0; i < (int)mSubEntityList.size(); ++i)
			mSubEntityList[i]->setVisible(visible);
	}

	SubEntity* RbxEntity::createSubEntity(SubMesh* subMesh, unsigned int lod)
	{
		RbxSubEntity* subEntity = new RbxSubEntity(this, subMesh, lod);
		if (subMesh->isMatInitialised())
			subEntity->setMaterialName(subMesh->getMaterialName());
		mSubEntityList.push_back(subEntity);
		return subEntity;
	}

	// 0067e2f0, from the server-exact fork analog (roc_espclaude_3a38bc51a49d03ed.cpp); RankedShadow name INFERRED.
struct RankedShadow {
    RbxSubEntity* sub;
    float priority;
    bool operator<(const RankedShadow& rhs) const {return priority<rhs.priority;}
};

void RbxEntity::collect(Camera* camera,Light* light,std::vector<ShadowCaster*>& output) {
    output.erase(output.begin(),output.end());
    bool updated=mCameraNotified;
    if(!updated) {
        func_0067daf0(camera);
        mCameraNotified=true;
    }
    const Vector3& minimum=mBounds.getMinimum();
    const Vector3* corners=mBounds.getAllCorners();
    for(int i=0;i<8;++i)
        if(camera->isVisible(corners[i])) corners[i].distance(camera->getDerivedPosition());
    float farDistance,distance;
    {
        std::vector<Plane> planes;
        planes.push_back(Plane(Vector3(1,0,0),Vector3(mBounds.getMaximum().x,0,0)));
        planes.push_back(Plane(Vector3(-1,0,0),Vector3(minimum.x,0,0)));
        planes.push_back(Plane(Vector3(0,1,0),Vector3(0,mBounds.getMaximum().y,0)));
        planes.push_back(Plane(Vector3(0,-1,0),Vector3(0,minimum.y,0)));
        planes.push_back(Plane(Vector3(0,0,1),Vector3(0,0,mBounds.getMaximum().z)));
        planes.push_back(Plane(Vector3(0,0,-1),Vector3(0,0,minimum.z)));
        const Vector3* frustum=camera->getWorldSpaceCorners();
        Ray rays[4];
        for(int i=0;i<4;++i) {
            rays[i].setOrigin(frustum[i]);
            Vector3 direction=frustum[i+4]-frustum[i];
            direction.normalise();
            rays[i].setDirection(direction);
        }
        distance=-1.0f;
        for(int i=0;i<4;++i) {
            const Ray& ray=rays[i];
            float nearest=1000000000.0f;
            for(int j=0;j<6;++j) {
                if(planes[j].getSide(ray.getOrigin())==Plane::NEGATIVE_SIDE) {
                    std::pair<bool,Real> hit=ray.intersects(planes[j]);

                    if(hit.first) nearest=std::min(nearest,hit.second);
                }
            }
            if(nearest!=1000000000.0 && nearest<10000.0f)
                distance=std::max(nearest,distance);
        }
        farDistance=camera->getNearClipDistance()+distance;
    }
    float oldFar;
    if(farDistance>0) {
        oldFar=camera->getFarClipDistance();
        camera->setFarClipDistance(farDistance);
    }
    // Native point-light branch only assigns these on its visible-volume paths.
    // The native sphere-outside-camera path leaves both variables untouched.
    bool lightVisible;
    const PlaneBoundedVolumeList* volumes;
    if(light->getType()==Light::LT_DIRECTIONAL) {
        AxisAlignedBox aabb;
        const Vector3* corners=camera->getWorldSpaceCorners();
        Vector3 min,max;
        
        const Vector3& dir=light->getDerivedDirection();
        
        Vector3 extrude=dir*-10000.0f;
        const Vector3& e=extrude;
        const Vector3& c0=corners[0];
        min=max=c0;
        const Vector3& c0b=corners[0];
        min.makeFloor(c0+extrude);
        max.makeCeil(c0+extrude);
        const Vector3& e2=extrude;
        for(size_t c=1;c<8;++c) {
            const Vector3& cc=corners[c];
            min.makeFloor(corners[c]);
            max.makeCeil(corners[c]);
            min.makeFloor(corners[c]+e);
            max.makeCeil(corners[c]+e2);
        }
        aabb.setExtents(min,max);
        lightVisible=false;
        volumes=&light->_getFrustumClipVolumes(camera);
    } else {
        Sphere sphere(light->getDerivedPosition(),light->getAttenuationRange());
        if(camera->isVisible(sphere)) {
            lightVisible=camera->isVisible(light->getDerivedPosition());
            if(!lightVisible) volumes=&light->_getFrustumClipVolumes(camera);
            else volumes=0;
        }
    }
    for(int i=0;i<(int)getNumSubEntities();++i) {
        RbxSubEntity* sub=dynamic_cast<RbxSubEntity*>(mSubEntityList[i]);
        if(!sub->getCastShadows()) continue;
        if(sub->getMaterial()->getTechnique(0)->getPass(0)->isTransparent()) continue;
        switch(nativeShadowMode) {
        case 0: if(sub->getCustomValue()<1.0f) continue; break;
        case 1: if(sub->getCustomValue()<0.5f) continue; break;
        }
        if(sub->isVisible()) output.push_back(sub);
        else {
            if(mVisibility[i]==3) continue;
            if(lightVisible && light->getType()!=Light::LT_DIRECTIONAL) continue;
            PlaneBoundedVolumeList::const_iterator it,iend;
            iend=volumes->end();
            for(it=volumes->begin();it!=iend;++it) {
                if(it->intersects(sub->getWorldBoundingBox())) {
                    output.push_back(sub);
                    break;
                }
            }
        }
    }
    if(farDistance>0) camera->setFarClipDistance(oldFar);
    if(nativeShadowThrottle && mHistory && nativeShadowMode>=1) {
        const FrameHistory::Frame& record=*mHistory->get(0);
        float previous4=record.values[0];
        float previous8=record.values[1];
        float ratio=previous8/previous4;
        int desired=(int)(output.size()*ratio);
        if((ratio<1.0f || desired>2*previous8) && output.size()+previous8>1000.0f) {
            std::vector<RankedShadow> order;
            for(int i=0;i<(int)output.size();++i) {
                RbxSubEntity* sub=static_cast<RbxSubEntity*>(output[i]);
                SubMesh* mesh=sub->getCoarsestSubMesh();
                RankedShadow item;
                item.sub=sub;
                float depth=Math::Sqrt(sub->getSquaredViewDepth(camera));
                item.priority=static_cast<float>(depth-static_cast<RbxSubMesh*>(mesh)->radius
                    -(sub->getCustomValue()==1.0f)*1000000.0-(sub->getCustomValue()==0.5f)*100);
                order.push_back(item);
            }
            std::sort(order.begin(),order.end());
            int guaranteed=0;
            for(int i=0;i<(int)order.size();++i) {
                if(!(order[i].priority>=1.0f)) break;
                ++guaranteed;
            }
            desired=std::max(desired,guaranteed);
            desired=std::min(desired,2*(int)previous8);
            if(desired+previous8<1000.0f) desired=(int)(1000.0f-previous8);
            int keep=desired;
            output.resize(keep,0);
            for(int i=0;i<keep;++i) output[i]=order[i].sub;
        }
    }
}

// 0067d010 (slot 28): Entity::_updateRenderQueue without the skeleton / vertex-animation parts (Roblox's fork has none):
// a manual LOD hands over to its LOD entity, otherwise every visible sub-entity goes to the queue.
void RbxEntity::_updateRenderQueue(RenderQueue* queue)
{
	if (!mInitialised)
		return;
	if (mMeshLodIndex > 0 && mMesh->isLodManual())
	{
		mLodEntityList[mMeshLodIndex - 1]->_updateRenderQueue(queue);
		return;
	}
	SubEntityList::iterator i, iend = mSubEntityList.end();
	for (i = mSubEntityList.begin(); i != iend; ++i)
	{
		if ((*i)->isVisible())
		{
			if (mRenderQueueIDSet)
				queue->addRenderable(*i, mRenderQueueID);
			else
				queue->addRenderable(*i);
		}
	}
}

// 0067c570 (slot 24): the per-frame camera notification runs the camera work once until something clears the flag.
void RbxEntity::_notifyCurrentCamera(Camera* camera)
{
	if (!mCameraNotified)
	{
		func_0067daf0(camera);
		mCameraNotified = true;
	}
}


}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template unsigned char * std::vector<unsigned char,class std::allocator<unsigned char> >::_Ucopy<unsigned char const *>(unsigned char const *,unsigned char const *,unsigned char *);
template unsigned char * std::vector<unsigned char,class std::allocator<unsigned char> >::_Umove<unsigned char *>(unsigned char *,unsigned char *,unsigned char *);
