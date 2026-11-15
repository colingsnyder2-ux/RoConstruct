#pragma once
#include <afxext.h>
#include <boost/shared_ptr.hpp>

class ChatEnter;
namespace RBX { class DataModel; namespace Network { class Players; } }
// Inactive native layout candidate from 00411be0 and 00412800.
class CChatPrompt : public CEditView {
    DECLARE_DYNCREATE(CChatPrompt)
public:
    CWnd* hostWindow;
    boost::shared_ptr<ChatEnter> chat;
    CBrush brush;
    boost::shared_ptr<RBX::DataModel> context;
    RBX::Network::Players* players;
    void bind(RBX::DataModel*, CWnd*); // Original 00412800; final symbol pending.
    CChatPrompt();
    virtual ~CChatPrompt();
    // Message map (BEGIN_MESSAGE_MAP in CChatPromptWindow.cpp); handlers are non-virtual, so no layout change.
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    afx_msg void OnChange();
    afx_msg void OnSetFocusReflect();
    afx_msg int OnCreate(LPCREATESTRUCT cs);
    afx_msg void OnSysChar(UINT, UINT, UINT);
    afx_msg void OnChar(UINT, UINT, UINT);
    afx_msg LRESULT OnFocusMessage(WPARAM, LPARAM);
    afx_msg HBRUSH CtlColor(CDC* dc, UINT);
    DECLARE_MESSAGE_MAP()
};
