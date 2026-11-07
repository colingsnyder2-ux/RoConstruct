#pragma once
// >>> native-status (generated) -- do not edit >>>
// CChatPrompt | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src b0520e93 | roc native-status --write
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
    void bind(RBX::DataModel*, CWnd*); // Original 00412800; final symbol pending.
    CChatPrompt();
    virtual ~CChatPrompt();
};
