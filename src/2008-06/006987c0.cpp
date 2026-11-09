// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: ogre-1.4.5 roc_rbxscene_destroyall_stock_7a06ef240f3628d2.cpp

// Candidate translation unit (score above; library headers required).
#include "roc_rbxscene_ctor_0606b79b7c96ed1a.cpp"

namespace Ogre {

void RbxSceneManager::destroyAllCameras(void)
{
    CameraList::iterator i = mCameras.begin();
    for (; i != mCameras.end(); ++i)
    {
        mDestRenderSystem->_notifyCameraRemoved(i->second);
        delete i->second;
    }
    mCameras.clear();
}

}
