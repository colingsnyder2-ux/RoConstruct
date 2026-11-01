// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_claudeC_rbxsubentitypool_2457577142b8f41d.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include "OgreSubEntity.h"
#include "OgreShadowCaster.h"
#include <vector>
namespace Ogre {
class RbxSubEntity:public SubEntity,public ShadowCaster {
 char observedTail[0x6c];
public:
 RbxSubEntity(Entity*);
 virtual ~RbxSubEntity();
 virtual bool getCastShadows()const;
 virtual EdgeData* getEdgeList();
 virtual bool hasEdgeList();
 virtual const AxisAlignedBox& getWorldBoundingBox(bool=false)const;
 virtual const AxisAlignedBox& getLightCapBounds()const;
 virtual const AxisAlignedBox& getDarkCapBounds(const Light&,Real)const;
 virtual ShadowRenderableListIterator getShadowVolumeRenderableIterator(ShadowTechnique,const Light*,HardwareIndexBufferSharedPtr*,bool,Real,unsigned long=0);
 virtual Real getPointExtrusionDistance(const Light*)const;
};
typedef char SizeAssert[sizeof(RbxSubEntity)==0x15c?1:-1];
}
struct Pool {
 char prefix[0x48];std::vector<Ogre::RbxSubEntity*> cache,active;char gap[0x20];Ogre::Entity* context;
 Ogre::RbxSubEntity* acquire();
};
Ogre::RbxSubEntity* Pool::acquire(){
 Ogre::RbxSubEntity* result;
 if(cache.size()!=0){result=cache[cache.size()-1];cache.pop_back();active.push_back(result);return result;}
 result=new Ogre::RbxSubEntity(context);
 active.push_back(result);return result;
}
