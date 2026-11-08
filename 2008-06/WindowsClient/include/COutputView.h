#pragma once
// >>> native-status (generated) -- do not edit >>>
// COutputView | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src df91f268 | roc native-status --write
#include "CSecureHtmlView.h"
#include <deque>
#include <atlbase.h>
#include <mshtml.h>
#include <boost/thread/mutex.hpp>
#include "util/standardout.h"

// Inactive layout recovery. COutputView: CRuntimeClass 00812f60 (size 0x120, no CreateObject, base
// getter 00436060 -> CSecureHtmlView::GetThisClass), RTTI of vtable 0081300c (COutputView :
// CSecureHtmlView : CHtmlView), constructor 00436a30 (CSecureHtmlView 00465a60, deque proxy at +0xf8,
// +0x108..+0x114 = 0, +0x118 = +0x11c = 0) and destructor 00436ab0 (Release +0x11c then +0x118, deque
// _Tidy 00436760 of AddRef/Release elements, ~CSecureHtmlView 00465a80). Own vtable slots: 92
// OnInitialUpdate 00436090 and 130 OnDocumentComplete 004364b0; no message map (slot 12 imports
// CHtmlView::GetMessageMap).
class COutputView : public CSecureHtmlView {
    DECLARE_DYNAMIC(COutputView)
public:
    COutputView();                                                // 00436a30
    // Implicit destructor 00436ab0 (deleting 00436b40): no vtable reset before the member releases.
    virtual void OnInitialUpdate();                               // 00436090
    virtual void OnDocumentComplete(LPCTSTR url);                 // 004364b0
protected:
    void appendElement(IHTMLElement* element);                    // 00436b60

    // IHTMLDOMNode queried with IID 3050f5da (0x812f98), pushed by 00436b60 and removed (appendChild
    // vtable +0x4c / removeChild +0x34) once more than 250 are shown.
    std::deque<CComPtr<IHTMLDOMNode> > nodes;                     // +0xf8
    CComQIPtr<IHTMLDocument2> document;                           // +0x118, IID 332c4425 (0x81056c)
    CComQIPtr<IHTMLDOMNode> output;                               // +0x11c, element "output"
};

// CStandardOutputView: CRuntimeClass 00812f7c (size 0x14c, CreateObject 00437740 = new(0x14c) +
// 004373a0), RTTI of vtables 0081324c/00813240 (COutputView +0, Listener<StandardOut,
// StandardOutMessage> +0x120), constructor 004373a0 (deque proxy +0x124, boost::mutex 00594c90 at
// +0x144, byte +0xf4 = 1, StandardOut listener registration under StandardOut::sync) and destructor
// 00436ce0 (unregistration, ~mutex 00594cb0, deque _Tidy 004366d0, ~COutputView 00436ab0).
// Message map 008134dc: ON_MESSAGE(0x465, 00437520) over CHtmlView::GetThisMessageMap.
class CStandardOutputView : public COutputView,
                            public RBX::Listener<RBX::StandardOut, RBX::StandardOutMessage> {
    DECLARE_DYNCREATE(CStandardOutputView)
public:
    CStandardOutputView();                                        // 004373a0
    virtual ~CStandardOutputView();                               // 00436ce0 (deleting 00437500)
protected:
    virtual void onEvent(const RBX::StandardOut* source, RBX::StandardOutMessage message); // 00437070
    void appendMessage(RBX::MessageType type, const char* message, __time64_t time);     // 00437150
    afx_msg LRESULT OnStandardOutMessage(WPARAM wParam, LPARAM lParam);                  // 00437520
    DECLARE_MESSAGE_MAP()

    std::deque<RBX::StandardOutMessage> messages;                 // +0x124, 0x28-byte elements
    boost::mutex messagesLock;                                    // +0x144
};
