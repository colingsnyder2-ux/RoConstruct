// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// CRobloxWnd render-quality throttle (2008-06 native, inactive). Layout: native-headers/CRobloxView.h. A separate unit
// from CRobloxWndWindow.cpp because v8datamodel/Workspace.h (donor util/UIEvent.h through gui/GuiEvent.h) cannot be
// included beside util/DxUserInput.h (util/UIEvent2008.h), which that unit needs.
#include <algorithm>
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
// takes around the pendingThrottle store. CRobloxWndThrottle.cpp defines it in an anonymous namespace; proposal there:
// give it external linkage so both bodies of the original unit share the one object.
extern ATL::CCriticalSection throttleCriticalSection;
namespace RBX { extern bool shadowsEnabled; } // 0096de64 (INFERRED name, pbb-surface-profile/RenderLib/ViewBase2008.h)

// 0045c890 (registry placeholder func_0045c890; CRobloxView.h name sub_0045c890, called by handle(0) 0045cba0 after
// sub_0045beb0 and by setDataModel 0045f7b0): consume the throttle AdjustThrottle stored (666.0, double 008199d0,
// means none pending), then under the DataModel lock scale the view's shading quality and mesh detail (ViewBase
// slots 2 / 3: 0.8f below -0.01, `x * 1.05f + 1` above 0.002), clamp them to the RenderSettings ranges (+0x144..+0x150)
// and hand them to ViewBase::updateSettings (slot 4) with the shadow flag 0096de64 and the camera-to-focus distance.
// Shadows are switched off for the OpenGL / Direct3D9 modes (3 / 4) when the Ogre render system lacks vertex programs
// (RSC_VERTEX_PROGRAM 0x200 of the capabilities at RenderSystem +0x64).
// Open (774 vs 771 bytes, parked after three shape trials): same calls, constants, EH states and x87 code. Remaining:
// (1) the target loads the view (+0xb0) into eax and tests it (`mov eax,[esi+0xb0]; test eax,eax`), this build compares
// memory (`cmp [esi+0xb0],0`); (2) the target evaluates getCameraCoordinateFrame() (temporary at esp+0x2c) before the
// focus operand of the out-of-line Vector3::operator- 0045ac40, this build evaluates the focus first; (3) an eax / edx
// swap at the updateSettings call. Rejected: a `RBX::ViewBase* view` local (776 B, kept in ebx), a named
// CoordinateFrame local (786 B, operator- inlined), a scoped_ptr bool test of +0xb0 (trial cast, no change).
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

    // INFERRED: 0xb0 holds the RBX::ViewBase (CRobloxView.h types it void*; proposal for its owner). The target
    // reloads the member before every use, so no local copy is kept.
    if (!slot_b0 || !dataModelPtr)
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
        float distance = (dataModelPtr->getWorkspace()->getCamera()->getCameraCoordinateFrame().translation
                          - dataModelPtr->getWorkspace()->getCamera()->getCameraFocus().translation).length();
        if ((mode_5c == 4 || mode_5c == 3) && Ogre::sRoot && Ogre::sRoot->getRenderSystem()
            && !Ogre::sRoot->getRenderSystem()->getCapabilities()->hasCapability(Ogre::RSC_VERTEX_PROGRAM))
            RBX::shadowsEnabled = false;
        static_cast<RBX::ViewBase*>(slot_b0)->updateSettings(shadingQuality, meshDetail, RBX::shadowsEnabled, distance);
    }
}
