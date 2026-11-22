#include <algorithm>
#include <memory>
#include "CRobloxView.h"
#include <atlsync.h>
#include "RenderLib/ViewBase2008.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Camera.h"
#include "CRenderSettings.h"
#include <OgreRoot.h>
#include <OgreRenderSystem.h>
#include <OgreRenderSystemCapabilities.h>
#include "OgreRbx/VisualEngine2008.h"   // Ogre::sRoot 0097db48 (defined in OgreVisualEngine.cpp)

// INFERRED: the global CRITICAL_SECTION at 0096df6c (static init/term 007ef980 / 007faf20) that AdjustThrottle 0045ba60
extern ATL::CCriticalSection throttleCriticalSection;
namespace RBX { extern bool shadowsEnabled; } // 0096de64 (INFERRED name, pbb-surface-profile/RenderLib/ViewBase2008.h)

void CRobloxWnd::sub_0045c890()
{
    throttleCriticalSection.Enter();
    if (pendingThrottle == 666.0) {
        throttleCriticalSection.Leave();
        return;
    }
    double throttle = pendingThrottle;
    pendingThrottle = 666.0;
    throttleCriticalSection.Leave();

    // INFERRED: 0xb0 holds the RBX::ViewBase in a std::auto_ptr (CRobloxView.h types it void*; proposal for its owner:
    if (reinterpret_cast<std::auto_ptr<RBX::ViewBase>&>(slot_b0).get() == NULL || dataModelPtr == NULL)
        return;

    RBX::DataModel::Lock lock(dataModelPtr);
    float shadingQuality = static_cast<RBX::ViewBase*>(slot_b0)->getShadingQuality();
    float meshDetail = static_cast<RBX::ViewBase*>(slot_b0)->getMeshDetail();
    if (throttle < -0.01) {
        shadingQuality *= 0.8f;
        meshDetail *= 0.8f;
    } else if (throttle > 0.002) {
        shadingQuality = shadingQuality * 1.05f + 1.0f;
        meshDetail = meshDetail * 1.05f + 1.0f;
    }
    shadingQuality = std::min(shadingQuality, CRenderSettings::singleton().getMaxShadingQuality());
    shadingQuality = std::max(shadingQuality, CRenderSettings::singleton().getMinShadingQuality());
    meshDetail = std::min(meshDetail, CRenderSettings::singleton().getMaxMeshDetail());
    meshDetail = std::max(meshDetail, CRenderSettings::singleton().getMinMeshDetail());

    if (dataModelPtr->getWorkspace() && dataModelPtr->getWorkspace()->getCamera()) {
        const G3D::CoordinateFrame& cameraFrame = dataModelPtr->getWorkspace()->getCamera()->getCameraCoordinateFrame();
        float distance =
            (cameraFrame.translation - dataModelPtr->getWorkspace()->getCamera()->getCameraFocus().translation).length();
        if ((mode_5c == 4 || mode_5c == 3) && Ogre::sRoot && Ogre::sRoot->getRenderSystem()
            && !Ogre::sRoot->getRenderSystem()->getCapabilities()->hasCapability(Ogre::RSC_VERTEX_PROGRAM))
            RBX::shadowsEnabled = false;
        static_cast<RBX::ViewBase*>(slot_b0)->updateSettings(shadingQuality, meshDetail, RBX::shadowsEnabled, distance);
    }
}
