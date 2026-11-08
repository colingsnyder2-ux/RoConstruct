// >>> native-status (generated) -- do not edit >>>
// ViewVerbs | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src fcbad590 | roc native-status --write
#include "../../native-headers/CMainFrame.h"
#include "../../native-headers/ViewVerbs.h"
#include "../../native-headers/CRobloxView.h"
#include <G3D/System.h>

static CMainFrame* mainFrame() { return static_cast<CMainFrame*>(AfxGetApp()->m_pMainWnd); }

void HelpCommand::doIt(RBX::IDataState*)
{
    view->PostMessage(WM_COMMAND, 0x80fd);
}

bool ToggleFullscreenVerb::isChecked() const
{
    return mainFrame()->stateF8;
}

void ToggleFullscreenVerb::doIt(RBX::IDataState*)
{
    AfxGetApp()->m_pMainWnd->PostMessage(WM_COMMAND, 0x80f4);
}

void LockPlayModeVerb::doIt(RBX::IDataState*)
{
    AfxGetApp()->m_pMainWnd->PostMessage(WM_COMMAND, 0x80ff);
}

ToggleIDEModeVerb::ToggleIDEModeVerb(RBX::VerbContainer* c)
    : RBX::Verb(c, std::string("TogglePlayMode")), createdAt(G3D::System::getLocalTime()) {}

bool ToggleIDEModeVerb::isEnabled() const
{
    double now = G3D::System::getLocalTime();
    if (createdAt + 10.0 > now)
        return false;
    return !mainFrame()->state105;
}

bool ToggleIDEModeVerb::isChecked() const
{
    return !mainFrame()->state104;
}

void ToggleIDEModeVerb::doIt(RBX::IDataState*)
{
    if (isEnabled())
        AfxGetApp()->m_pMainWnd->PostMessage(WM_COMMAND, 0x80f5);
}
