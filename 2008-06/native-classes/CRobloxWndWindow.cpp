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
