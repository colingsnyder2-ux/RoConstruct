#include <stddef.h>
#include "COutputView.h"
// COutputView: CRuntimeClass 00812f60 size 0x120; constructor 00436a30 builds the deque proxy at +0xf8
// (map/mapsize/offset/size at +0x108..+0x114) and clears +0x118/+0x11c; destructor 00436ab0 releases
// +0x11c then +0x118 and tidies the deque. CStandardOutputView: CRuntimeClass 00812f7c size 0x14c,
// CreateObject 00437740 new(0x14c); RTTI places Listener<StandardOut,StandardOutMessage> at +0x120;
// constructor 004373a0 / destructor 00436ce0 build/tidy the deque at +0x124 and boost::mutex at +0x144;
// onEvent 00437070 copies 0x28-byte StandardOutMessage elements (00436e40).
// Protected members are checked from member function bodies of derived probes (complete class scope).
struct COutputViewProbe : COutputView {
    static void check() {
        typedef char Nodes[offsetof(COutputViewProbe, nodes) == 0xf8 ? 1 : -1];
        typedef char Document[offsetof(COutputViewProbe, document) == 0x118 ? 1 : -1];
        typedef char Output[offsetof(COutputViewProbe, output) == 0x11c ? 1 : -1];
    }
};
struct CStandardOutputViewProbe : CStandardOutputView {
    static void check() {
        typedef char Messages[offsetof(CStandardOutputViewProbe, messages) == 0x124 ? 1 : -1];
        typedef char Lock[offsetof(CStandardOutputViewProbe, messagesLock) == 0x144 ? 1 : -1];
    }
};
typedef char SecureHtmlViewSize[sizeof(CSecureHtmlView) == 0xf8 ? 1 : -1];
typedef char OutputViewSize[sizeof(COutputView) == 0x120 ? 1 : -1];
typedef char NodeDequeSize[sizeof(std::deque<CComPtr<IHTMLDOMNode> >) == 0x20 ? 1 : -1];
typedef char StandardOutputViewSize[sizeof(CStandardOutputView) == 0x14c ? 1 : -1];
typedef char StandardOutputViewListener[sizeof(COutputView) == 0x120 && sizeof(RBX::Listener<RBX::StandardOut,
    RBX::StandardOutMessage>) == 4 ? 1 : -1]; // second base directly after the COutputView part
typedef char MessageSize[sizeof(RBX::StandardOutMessage) == 0x28 ? 1 : -1];
typedef char MutexSize[sizeof(boost::mutex) == 8 ? 1 : -1];
