// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: xtp-11.2.2-shared-mfc roc_mfc_settings_menu_shared_0b9f15a58de06ca9.cpp

// Candidate translation unit (score above; library headers required).
// Application-side VC9 RTM reconstruction from the 00422720 body.
// The layout facts used here are byte-proven: shared MFC puts CWnd::m_hWnd at
// 0x20 and the target reads the menu handle at this+0xdc.
#include "XTToolkitPro.h"

class CEnabledCmdUI : public CCmdUI
{
public:
    CEnabledCmdUI() : m_bEnabled(FALSE) {}

    virtual void Enable(BOOL bOn)
    {
        m_bEnabled = bOn;
        m_bEnableChanged = TRUE;
    }

    virtual void SetCheck(int) {}
    virtual void SetRadio(BOOL) {}
    virtual void SetText(LPCTSTR) {}

    BOOL m_bEnabled;
};

struct MenuCommandTargetProbe;

struct MenuCommandTargetTable
{
    void* unused[5];
    BOOL (__thiscall* onCmdMsg)(MenuCommandTargetProbe*, UINT, int, void*,
        AFX_CMDHANDLERINFO*);
};

struct MenuCommandTargetProbe
{
    MenuCommandTargetTable* table;
};

class CSettingsExplorerProbe : public CWnd
{
    BYTE m_layoutToMenu[0xdc - sizeof(CWnd)];
    HMENU m_menu;

public:
    void ShowMenu(CPoint point);
};

void CSettingsExplorerProbe::ShowMenu(CPoint point)
{
    CMenu* menu = CMenu::FromHandle(::GetSubMenu(m_menu, 0));
    if (menu == NULL)
        return;

    for (UINT index = 0; index < (UINT)::GetMenuItemCount(menu->m_hMenu); ++index)
    {
        CEnabledCmdUI state;
        state.m_nID = ::GetMenuItemID(menu->m_hMenu, index);

        if (state.m_nID != 0)
        {
            if (state.m_nID == (UINT)-1)
            {
                CMenu::FromHandle(::GetSubMenu(menu->m_hMenu, index));
            }
            else
            {
                MenuCommandTargetProbe* target =
                    (MenuCommandTargetProbe*)AfxGetMainWnd();

                target->table->onCmdMsg(target, state.m_nID,
                    CN_UPDATE_COMMAND_UI, &state, NULL);
                ::EnableMenuItem(menu->m_hMenu, index,
                    MF_BYPOSITION | (state.m_bEnabled ? MF_ENABLED : MF_DISABLED));
            }
        }
    }

    if (point.x == -1 && point.y == -1)
    {
        CRect rect;
        ::GetClientRect(m_hWnd, &rect);
        point = CPoint((rect.left + rect.right) / 2,
            (rect.bottom + rect.top) / 2);
        ::ClientToScreen(m_hWnd, &point);

        CXTPCommandBars::TrackPopupMenu(menu, 0x14, point.x, point.y,
            GetParentFrame(), NULL, NULL, NULL);
    }
    else
    {
        CXTPCommandBars::TrackPopupMenu(menu, 0, point.x, point.y,
            GetParentFrame(), NULL, NULL, NULL);
    }
}
