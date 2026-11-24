// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL /D_DLL /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// 2008-06 native verbs created by CRobloxView's initializer (0045a4a0), original unit 00458fd0..00459169 (inactive).
// Classes in native-headers/ViewVerbs.h. Flags copied from the byte-exact sibling shards Conv2008_*Verb_*.cpp.
// CMainFrame.h (XTP) needs the windows min/max macros, which later headers remove: include it first.
#include "../native-headers/CMainFrame.h"
#include "../native-headers/ViewVerbs.h"
#include "../native-headers/CRobloxView.h"
#include <G3D/System.h>

// The CMainFrame state readers below need native-headers/CMainFrame.h. Batch 49: core util/MarshaledListener.h
// compiles again, and with CMainFrame.h included first the unit builds (isEnabled 00459040 / isChecked 00459080 exact).
#define VIEWVERBS_MAINFRAME_HEADER_COMPILES
#ifdef VIEWVERBS_MAINFRAME_HEADER_COMPILES
static CMainFrame* mainFrame() { return static_cast<CMainFrame*>(AfxGetApp()->m_pMainWnd); }
#endif

// HelpCommand::doIt 00459150 and ToggleFullscreenVerb::doIt 00459120 / isChecked 00459100 are already exact in the
// shards Conv2008_HelpCommand_doIt_00459150.cpp, Conv2008_ToggleFullscreenVerb_doIt_00459120.cpp and
// Conv2008_ToggleFullscreenVerb_isChecked_00459100.cpp (not this batch's files). Define VIEWVERBS_OWNS_SHARD_BODIES
// when those shards are retired so this unit holds them again without duplicate credit.
#ifdef VIEWVERBS_OWNS_SHARD_BODIES
// 00459150
void HelpCommand::doIt(RBX::IDataState*)
{
    view->PostMessage(WM_COMMAND, 0x80fd);
}

#ifdef VIEWVERBS_MAINFRAME_HEADER_COMPILES
// 00459100
bool ToggleFullscreenVerb::isChecked() const
{
    return mainFrame()->stateF8;
}
#endif

// 00459120
void ToggleFullscreenVerb::doIt(RBX::IDataState*)
{
    AfxGetApp()->m_pMainWnd->PostMessage(WM_COMMAND, 0x80f4);
}
#endif

// 004590d0 ?doIt@LockPlayModeVerb@@UAEXPAVIDataState@RBX@@@Z
void LockPlayModeVerb::doIt(RBX::IDataState*)
{
    AfxGetApp()->m_pMainWnd->PostMessage(WM_COMMAND, 0x80ff);
}

// 00458fd0 ??0ToggleIDEModeVerb@@QAE@PAVVerbContainer@RBX@@@Z: Verb::Verb 005833e0 with a std::string temporary
// "TogglePlayMode" (0x8190d8), vftable 008190c4, then fstp of 005083d0 = G3D::System::getTick (identity registry)
// into +0x10. The earlier getLocalTime (00508410) draft was rejected.
ToggleIDEModeVerb::ToggleIDEModeVerb(RBX::VerbContainer* c)
    : RBX::Verb(c, std::string("TogglePlayMode")), createdAt(G3D::System::getTick()) {}

#ifdef VIEWVERBS_MAINFRAME_HEADER_COMPILES
// 00459040: getTick, createdAt + 10.0 (0x8190b8) > now -> false; else main frame +0x105 == 0.
bool ToggleIDEModeVerb::isEnabled() const
{
    double now = G3D::System::getTick();
    if (createdAt + 10.0 > now)
        return false;
    return !mainFrame()->state105;
}

// 00459080: main frame +0x104 == 0.
bool ToggleIDEModeVerb::isChecked() const
{
    return !mainFrame()->state104;
}
#endif

// 004590a0 ?doIt@ToggleIDEModeVerb@@UAEXPAVIDataState@RBX@@@Z: virtual isEnabled (vftable +8), then PostMessage
// WM_COMMAND 0x80f5 to the main frame. Moved here from Conv2008_LockPlayModeVerb_doIt_004590a0.cpp, which defined
// this body under the LockPlayModeVerb name (registry: 004590a0 is ToggleIDEModeVerb::doIt, 004590d0 is LockPlayModeVerb).
void ToggleIDEModeVerb::doIt(RBX::IDataState*)
{
    if (isEnabled())
        AfxGetApp()->m_pMainWnd->PostMessage(WM_COMMAND, 0x80f5);
}
