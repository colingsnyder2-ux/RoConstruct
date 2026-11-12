#pragma once
#include <afxext.h>
#include <boost/shared_ptr.hpp>

class ChatEnter;
namespace RBX { class DataModel; namespace Network { class Players; } }
// Inactive native layout candidate from 00411be0 and 00412800.
class CChatPrompt : public CEditView {
    DECLARE_DYNCREATE(CChatPrompt)
    DECLARE_MESSAGE_MAP()
public:
    CWnd* hostWindow; // +0x88: 00411c86/00411d65 pass this receiver to CWnd::SetFocus.
    boost::shared_ptr<ChatEnter> chat;
    CBrush brush;
    boost::shared_ptr<RBX::DataModel> context;
    RBX::Network::Players* players;
    void bind(RBX::DataModel*, CWnd*); // Original 00412800; identity registry corroborates symbol.
    CChatPrompt();
    virtual ~CChatPrompt();
protected:
    virtual BOOL PreCreateWindow(CREATESTRUCT&); // 00411370, original vtable slot 27.
    // INFERRED names: original message entries at 0080e360..0080e3f0 establish signatures and bodies.
    afx_msg void OnChange();
    afx_msg void OnChar(UINT, UINT, UINT);
    afx_msg void OnSysChar(UINT, UINT, UINT);
    afx_msg LRESULT OnFocusMessage(WPARAM, LPARAM);
    afx_msg void OnSetFocusReflect();
    afx_msg int OnCreate(LPCREATESTRUCT);
    afx_msg HBRUSH CtlColor(CDC*, UINT);
};
