// CRobloxWnd window-message handlers (2008-06 native, inactive). Layout: native-headers/CRobloxView.h.
// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
#include <algorithm>
#include "CRobloxView.h"
#include "util/DxUserInput.h"
#include "OgreRbx/VisualEngine2008.h"
#include <OgreCamera.h>
#include <OgreRenderTarget.h>
#include <OgreRenderWindow.h>
#include <OgreMath.h>
#include "GLG3D/GWindow.h"
#include "GLG3D/RenderDevice.h"
#include "RenderLib/ViewBase2008.h"

#ifdef NATIVE_CROBLOXWND_GETMETRIC_PENDING
// getMetric (0045df10) stays guarded; blockers are listed at its body. Includes it needs:
#include <OgreSceneManager.h>
#include <OgreStringConverter.h>
#include <OgreEntity.h>
#include "OgreRbxNode/RbxSceneNode2008.h"
#include "OgreRbx/RbxEntity2008.h"
#include "RbxGraphics/AdornRbxGfx2008.h"   // conflicts with the donor RbxGraphics/TextureProxyBase.h this unit already sees
#include "CRenderSettings.h"
#include "reflection/enumconverter.h"
#include "util/Utilities.h"
#include <stdio.h>
extern bool nativeShadowThrottle;             // 00962f64 (defined in OgreRbxEntity.cpp)
namespace RBX { extern bool shadowsEnabled; } // 0096de64 (INFERRED name, pbb-surface-profile/RenderLib/ViewBase2008.h)
// INFERRED placeholder: 004d71b0 (`mov al, [0094065c]; ret`), the getter paired with the ViewRbxGfx setter 004d71a0
// that stores its argument into 0094065c and 009413c0; its real name/owner is not proven.
bool sub_004d71b0();
#endif

// INFERRED: a scope object of one Stopwatch pointer. 0045beb0 stores the stopwatch address in its frame, ticks it
// (G3D::Stopwatch::tick 00511cf0) and registers unwind state 0, whose funclet 007c2c00 calls this unit's out-of-line
// destructor 0045afe0 (`mov ecx, [ecx]; jmp Stopwatch::tock 00511df0`); the normal path inlines the same tock.
class StopwatchScope
{
    G3D::Stopwatch* watch;
public:
    explicit StopwatchScope(G3D::Stopwatch& watch) : watch(&watch) { watch.tick(); }
    ~StopwatchScope() { watch->tock(); }
};

// 0045b010 (INFERRED name OnSize; arguments unused by the body)
void CRobloxWnd::OnSize(UINT, int, int)
{
    if (visualEngine) {
        RECT rect;
        ::GetClientRect(m_hWnd, &rect);
        Ogre::Camera* camera = visualEngine->camera;
        Ogre::RenderTarget* target = visualEngine->renderTarget;
        // INFERRED: slot 0xc4 of the target's vtable is a RenderWindow virtual (not RenderTarget::update at 0x18).
        static_cast<Ogre::RenderWindow*>(target)->windowMovedOrResized();
        if (rect.bottom - rect.top && camera)
            camera->setAspectRatio((float)target->getWidth() / (float)target->getHeight());
        camera->yaw(Ogre::Radian(0.0f));
    }
}

// 0045b330
BOOL CRobloxWnd::PreCreateWindow(CREATESTRUCT& cs)
{
    LPCTSTR className = AfxRegisterWndClass(CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW, ::LoadCursor(NULL, IDC_ARROW));
    cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
    cs.lpszClass = className;
    cs.cx = std::max(cs.cx, 100);
    cs.cy = std::max(cs.cy, 100);
    return CWnd::PreCreateWindow(cs);
}

// 0045b5d0 (INFERRED name OnSetFocus)
void CRobloxWnd::OnSetFocus(CWnd* oldWnd)
{
    CWnd::OnSetFocus(oldWnd);
    if (userInput)
        userInput->setKeyboardWanted(true);
}

// 0045cba0 (registry name handle(int); the 0 and 1 cases are the only ones the body distinguishes)
void CRobloxWnd::handle(int code)
{
    switch (code) {
    case 0:
        sub_0045beb0();
        sub_0045c890();
        break;
    case 1:
        if (dataModelPtr && userInput) {
            userInput->updateMouse();
            Default();
            return;
        }
        break;
    }
    Default();
}

// 0045beb0 (registry placeholder; CRobloxView.h name sub_0045beb0, called by handle(0) 0045cba0): when the swap flag
// at 0x8a is set, swaps the GL buffers under RenderStats::swapBuffer (+0x58 of the view's getRenderStats(), slot 7
// [vtbl+0x1c] of the object at 0xb0; GWindow::swapGLBuffers is slot 16 [vtbl+0x40] of the adorn at 0xa4).
void CRobloxWnd::sub_0045beb0()
{
    if (flags_88_8b[2]) {
        // INFERRED: 0xb0 holds the RBX::ViewBase (CRobloxView.h types it void*; proposal for its owner).
        StopwatchScope scope(static_cast<RBX::ViewBase*>(slot_b0)->getRenderStats().swapBuffer);
        adorn->swapGLBuffers();
        flags_88_8b[2] = false;
    }
}

// 0045bde0 (INFERRED name shutdownGraphics)
void CRobloxWnd::shutdownGraphics()
{
    if (adorn)
        adorn->makeCurrent();
    if (renderDevice) {
        renderDevice->cleanup();
        delete renderDevice;
        renderDevice = NULL;
    }
    if (adorn) {
        delete adorn;
        adorn = NULL;
    }
}

#ifdef NATIVE_CROBLOXWND_GETMETRIC_PENDING
// 0045df10 (IMetric::getMetric override; IMetric vtable 008199dc): render metrics by name for the stats display.
// PENDING (batch 23). Measured with a scratch-only access shim (not landed): 1254 candidate bytes vs 1244 target, same
// control flow, strings, calls and EH states. Remaining differences: `add eax,0x18; mov ecx,eax` vs `lea ecx,[eax+0x18]`
// before both FrameHistory::getCount calls; an extra `add ecx,0x8ac4` beside the shadow-caster size(); the GfxTime fps
// keeps an extra x87 copy (`fld st(0)` / `fstp`); the Particles dynamic_cast source register (esi in the target) and a
// 0x1e0 vs 0x1dc frame. Blockers (owners of read-only headers):
//   * Ogre::SceneManager::mShadowCasterList (+0x8acc, read as +0x8ad0/+0x8ad4) is protected: RbxSceneManager2008.h /
//     Ogre owner would need `friend class ::CRobloxWnd;` (as it already befriends ViewRbxGfx) or an accessor.
//   * RBX::AdornRbxGfx::particleCount (+0x44) is private: AdornRbxGfx2008.h owner (friend or accessor).
//   * AdornRbxGfx2008.h's TextureProxyBase2008.h redefines the donor TextureProxyBase this unit sees via DxUserInput.h.
//   * 004d71b0 has no proven name (placeholder above); CRobloxView.h types mode_5c as int (CRenderSettings::GraphicsMode).
// Verified pieces: the FRM entity count does not null-check the RbxEntity dynamic_cast; constants are float
// (100.0f, 1000.0f); GfxTime keeps 1000.0f when ms < 1.
std::string CRobloxWnd::getMetric(const std::string& name) const
{
    if (name == "graphicsMode")
        return RBX::Reflection::EnumDesc<CRenderSettings::GraphicsMode>::singleton().convertToString(
            reinterpret_cast<const CRenderSettings::GraphicsMode&>(mode_5c));
    if (name == "FRM") {
        if (!visualEngine)
            return "N/A";
        if (!nativeShadowThrottle)
            return "Off";
        if (visualEngine->frameHistory.getCount() < 30)
            return "Pending";
        std::string unused1, unused2, unused3; // three locals the target constructs and destroys unused
        Ogre::FrameHistory::Frame* frame = visualEngine->frameHistory.get(0);
        int visible = (int)frame->values[0];
        int rendered = (int)frame->values[1];
        int reduction = visible > 0 ? (int)((1.0f - (float)rendered / visible) * 100.0f) : 0;
        int subEntities = 0;
        Ogre::SceneNode* root = visualEngine->sceneManager->getRootSceneNode();
        for (int i = 0; i < root->numChildren(); ++i) {
            if (Ogre::RbxSceneNode* node = dynamic_cast<Ogre::RbxSceneNode*>(root->getChild(i)))
                subEntities += dynamic_cast<Ogre::RbxEntity*>(node->getAttachedObject(0))->getNumSubEntities();
        }
        char buffer[128];
        sprintf(buffer, "On  %2d%% r=%d v=%d w=%d", reduction, rendered, visible, subEntities);
        return buffer;
    }
    if (name == "Shadows") {
        if (!visualEngine)
            return "?";
        if (!RBX::shadowsEnabled)
            return "Off";
        return "On  #casters=" + Ogre::StringConverter::toString((int)visualEngine->sceneManager->mShadowCasterList.size());
    }
    if (name == "antiAliasing") {
        if (!visualEngine)
            return "N/A";
        std::string result;
        switch (visualEngine->antialiasing) {
        case 1: result = "On"; break;
        case 2: result = "Off"; break;
        }
        return result;
    }
    if (name == "bevels") {
        if (!visualEngine)
            return "N/A";
        return sub_004d71b0() ? "On" : "Off";
    }
    if (name == "videoMemory") {
        int memory = Ogre::getVideoMemory();
        return RBX::StringConverter<int>::convertToString(memory);
    }
    if (name == "GfxTime") {
        if (!visualEngine)
            return "?";
        float ms;
        if (nativeShadowThrottle) {
            if (visualEngine->frameHistory.getCount() == 0)
                return "??";
            ms = visualEngine->frameHistory.get(0)->time;
        } else {
            ms = (float)static_cast<RBX::ViewBase*>(slot_b0)->getRenderStats().cpuRenderTotal.elapsedTime() * 1000.0f;
        }
        float fps = 1000.0f;
        if (ms >= 1.0f)
            fps /= ms;
        char buffer[256];
        sprintf(buffer, "%.1fms (%.1ffps)", ms, fps);
        return buffer;
    }
    if (name == "Particles") {
        if (!visualEngine)
            return "N/A";
        RBX::AdornRbxGfx* adorn = dynamic_cast<RBX::AdornRbxGfx*>(static_cast<RBX::Adorn*>(slot_b4));
        if (!adorn)
            return "N/A";
        return Ogre::StringConverter::toString(adorn->particleCount);
    }
    return "";
}
#endif
