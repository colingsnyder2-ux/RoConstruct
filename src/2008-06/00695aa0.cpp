// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_espeon_renderqueueauthenticb965e834ae5cb4f5.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include "OgreSceneManager.h"
#include "OgreRenderQueueSortingGrouping.h"
#include "OgreTimer.h"
namespace Ogre {
class RbxSceneManager : public SceneManager { public: void f(RenderQueueGroup* group, QueuedRenderableCollection::OrganisationMode mode); };
void RbxSceneManager::f(RenderQueueGroup* group, QueuedRenderableCollection::OrganisationMode mode) {
 RenderQueueGroup::PriorityMapIterator it=group->getIterator();
 Timer timer;
 while(it.hasMoreElements()) {
  RenderPriorityGroup* p=it.getNext();
  timer.getMicroseconds(); p->sort(mCameraInProgress); timer.reset();
  timer.getMicroseconds(); renderObjects(p->getSolidsBasic(),mode,true,0); timer.reset();
  timer.getMicroseconds(); renderObjects(p->getTransparents(),QueuedRenderableCollection::OM_SORT_DESCENDING,true,0); timer.reset();
 }
}
}
