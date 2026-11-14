// >>> native-status (generated) -- do not edit >>>
// ViewVerbs | 2008-06 | draft (no current byte proof)
// 0/8 mapped addresses byte-exact | 8 unproved | no mapped strings | by colin (+3) (mixed 3)
// <<< native-status | src 5c93d29a | roc native-status --write
#include "../native-headers/CMainFrame.h"
#include "../native-headers/ViewVerbs.h"
#include "../native-headers/CRobloxView.h"
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
    : RBX::Verb(c, std::string("TogglePlayMode")), createdAt(G3D::System::getTick()) {}
// 00458fd0 ctor and 00459040 isEnabled both call 005083d0 = G3D::System::getTick
// (identity registry); the earlier getLocalTime (00508410) draft was rejected.

// 00459040
bool ToggleIDEModeVerb::isEnabled() const
{
    double now = G3D::System::getTick();
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
