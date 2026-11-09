// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_skyrendernativeb9ff7f3686536bca.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/Ogre.h"
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreRenderQueueSortingGrouping.h"
using namespace Ogre;
class SkyRenderRecovery {
public:
 template<class T> T& field(unsigned offset) {return *reinterpret_cast<T*>(reinterpret_cast<char*>(this)+offset);}
 void render(Camera*,RenderQueue*,bool);
};
void SkyRenderRecovery::render(Camera* camera,RenderQueue* queue,bool) {
 Vector3 position=camera->getDerivedPosition();
 field<SceneNode*>(0x44)->setPosition(field<Vector3>(0xc8)+position);
 field<SceneNode*>(0x40)->setPosition(field<Vector3>(0xbc)+position);
 field<SceneNode*>(0x48)->setPosition(position);
 queue->getQueueGroup(10)->setShadowsEnabled(false);
 queue->getQueueGroup(20)->setShadowsEnabled(false);
 field<BillboardSet*>(0x38)->setRenderQueueGroup(10);
 field<BillboardSet*>(0x38)->_notifyCurrentCamera(camera);
 field<BillboardSet*>(0x38)->_updateRenderQueue(queue);
 field<BillboardSet*>(0x34)->setRenderQueueGroup(20);
 field<BillboardSet*>(0x34)->_notifyCurrentCamera(camera);
 field<BillboardSet*>(0x34)->_updateRenderQueue(queue);
 if(field<bool>(0x84)) {
  field<BillboardSet*>(0x3c)->setRenderQueueGroup(20);
  field<BillboardSet*>(0x3c)->_notifyCurrentCamera(camera);
  field<BillboardSet*>(0x3c)->_updateRenderQueue(queue);
 }
 if(field<bool>(0x85)) {
  SceneNode::ObjectIterator i=field<SceneNode*>(0x48)->getAttachedObjectIterator();
  while(i.hasMoreElements()) {
   ManualObject* object=dynamic_cast<ManualObject*>(i.getNext());
   object->setRenderQueueGroup(10);
   object->_notifyCurrentCamera(camera);
   object->_updateRenderQueue(queue);
  }
 }
}
