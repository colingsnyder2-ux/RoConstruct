#include <stddef.h>
#include "AppLeaves2008/DHTMLWindow2008.h"

// Layout probes (mov eax, imm32; ret) read by tests/record_native_app_leaves2008_dhtml.py.

// DHTMLWindow: members right after Instance (sizeof 0x130). Every worker (00417a10..004185c0) locks the
// recursive_mutex at this + 0x130 and reads the CLuaHtmlView* at this + 0x13c.
struct DHTMLWindowLayout
{
    static int instanceSize() { return sizeof(RBX::Instance); }
    static int viewLock() { return offsetof(DHTMLWindow, viewLock); }
    static int view() { return offsetof(DHTMLWindow, view); }
    static int lockSize() { return sizeof(boost::recursive_mutex); }
};
int nativeDHTMLWindowInstanceSize() { return DHTMLWindowLayout::instanceSize(); }
int nativeDHTMLWindowViewLockOffset() { return DHTMLWindowLayout::viewLock(); }
int nativeDHTMLWindowViewOffset() { return DHTMLWindowLayout::view(); }
int nativeDHTMLWindowLockSize() { return DHTMLWindowLayout::lockSize(); }
// Member pointers to DHTMLWindow are 8 bytes (function + this adjustment): every BoundFuncDesc initializer pushes
// the function address and a 0 adjustment, and execute 0041c450 calls [desc + 0x38] with this + [desc + 0x3c].
int nativeDHTMLWindowMemberPointerSize() { return sizeof(&DHTMLWindow::show); }
