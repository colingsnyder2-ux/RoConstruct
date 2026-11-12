#pragma once
#include <afxext.h>
#include <boost/shared_ptr.hpp>

class ChatEnter;
namespace RBX { class DataModel; namespace Network { class Players; } }
// Inactive native layout candidate from 00411be0 and 00412800.
class CChatPrompt : public CEditView {
    DECLARE_DYNCREATE(CChatPrompt)
public:
    void* hostWindow;
    boost::shared_ptr<ChatEnter> chat;
    CBrush brush;
    boost::shared_ptr<RBX::DataModel> context;
    RBX::Network::Players* players;
    void bind(RBX::DataModel*, CWnd*); // Original 00412800; identity registry corroborates symbol.
    CChatPrompt();
    virtual ~CChatPrompt();
protected:
    virtual BOOL PreCreateWindow(CREATESTRUCT&); // 00411370, original vtable slot 27.
};
