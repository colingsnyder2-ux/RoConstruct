// from server: 100% by EspClaude
// from server: 81% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: ogre-1.4.5-dll roc_espclaude_3a38bc51a49d03ed.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
#include <string.h>

struct ShadowHistoryRecord { float value[5]; };
class ShadowHistoryView {
public:
    ShadowHistoryRecord& previous(int);
    int count() const;
    float median(int) const;
    void append(const ShadowHistoryRecord&);
};
extern bool nativeShadowThrottle;
extern int nativeShadowMode;

namespace Ogre {
class RbxSceneNode : public SceneNode {
public:
    RbxSceneNode(SceneManager*, const String&);
    ~RbxSceneNode();
    virtual void setTransform(unsigned long, const Matrix4&);
    virtual const Matrix4& getTransform(unsigned long) const;
    virtual bool hasTransform(unsigned long) const;
    virtual void setSphere(unsigned long, const Sphere&);
    virtual const Sphere& getSphere(unsigned long) const;
};
class RbxSubEntity : public SubEntity, public ShadowCaster {
public:
    virtual ~RbxSubEntity();
    virtual void setFloat138(float);
    virtual float getFloat138() const;
    SubMesh* activeMesh();
    SubMesh* getLodMesh(unsigned int);
    Matrix4 mLocalTransform;
};
class RbxEntity : public Entity {
public:
    void* field274;
    bool field278, field279, field27a;
    AxisAlignedBox field27c;
    float field29c;
    int field2a0;
    std::vector<unsigned char> field2a4;
    RbxEntity();
    virtual ~RbxEntity();
    virtual void method67daf0(Camera*);
    virtual void setSubEntitiesVisible(bool);
    void collect(Camera*, Light*, std::vector<ShadowCaster*>&);
    ShadowHistoryView* history() { return static_cast<ShadowHistoryView*>(field274); }
};
}
using namespace Ogre;

struct RankedShadow {
    RbxSubEntity* sub;
    float priority;
    bool operator<(const RankedShadow& rhs) const {return priority<rhs.priority;}
};

void RbxEntity::collect(Camera* camera,Light* light,std::vector<ShadowCaster*>& output) {
    output.erase(output.begin(),output.end());
    bool updated=field279;
    if(!updated) {
        method67daf0(camera);
        field279=true;
    }
    const Vector3& minimum=field27c.getMinimum();
    const Vector3* corners=field27c.getAllCorners();
    for(int i=0;i<8;++i)
        if(camera->isVisible(corners[i])) corners[i].distance(camera->getDerivedPosition());
    float farDistance,distance;
    {
        std::vector<Plane> planes;
        planes.push_back(Plane(Vector3(1,0,0),Vector3(field27c.getMaximum().x,0,0)));
        planes.push_back(Plane(Vector3(-1,0,0),Vector3(minimum.x,0,0)));
        planes.push_back(Plane(Vector3(0,1,0),Vector3(0,field27c.getMaximum().y,0)));
        planes.push_back(Plane(Vector3(0,-1,0),Vector3(0,minimum.y,0)));
        planes.push_back(Plane(Vector3(0,0,1),Vector3(0,0,field27c.getMaximum().z)));
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
        case 0: if(sub->getFloat138()<1.0f) continue; break;
        case 1: if(sub->getFloat138()<0.5f) continue; break;
        }
        if(sub->isVisible()) output.push_back(sub);
        else {
            if(field2a4[i]==3) continue;
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
    if(nativeShadowThrottle && field274 && nativeShadowMode>=1) {
        const ShadowHistoryRecord& record=static_cast<ShadowHistoryView*>(field274)->previous(0);
        float previous4=record.value[1];
        float previous8=record.value[2];
        float ratio=previous8/previous4;
        int desired=(int)(output.size()*ratio);
        if((ratio<1.0f || desired>2*previous8) && output.size()+previous8>1000.0f) {
            std::vector<RankedShadow> order;
            for(int i=0;i<(int)output.size();++i) {
                RbxSubEntity* sub=static_cast<RbxSubEntity*>(output[i]);
                SubMesh* mesh=sub->activeMesh();
                RankedShadow item;
                item.sub=sub;
                float depth=Math::Sqrt(sub->getSquaredViewDepth(camera));
                item.priority=static_cast<float>(depth-*reinterpret_cast<float*>(reinterpret_cast<char*>(mesh)+0xec)
                    -(sub->getFloat138()==1.0f)*1000000.0-(sub->getFloat138()==0.5f)*100);
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



