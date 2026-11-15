#include <stddef.h>
#include "AppLeaves2008/DHTMLWindowService2008.h"
#include "AppLeaves2008/IDEDocManager2008.h"

// Layout probes (mov eax, imm32; ret) read by tests/record_native_app_leaves2008_services.py.

// DHTMLWindowService: Creatable<Instance>::create<DHTMLWindowService> 0041cda0 mallocs 0x130; Service is the empty
// base at mdisp 0x130 (RTTI of vtable 0080efd4).
int nativeDHTMLWindowServiceSize() { return sizeof(DHTMLWindowService); }
int nativeDHTMLWindowServiceInstanceSize() { return sizeof(RBX::Instance); }
// CIDEDocManager: InitInstance news 0x30; the constructor 00449910 stores the templates at +0x24, +0x20, +0x28, +0x2c.
struct IDEDocManagerLayout : CIDEDocManager {
    static void check();
};
void IDEDocManagerLayout::check()
{
    typedef char Base[sizeof(CDocManager) == 0x20 ? 1 : -1];
    typedef char Browser[offsetof(IDEDocManagerLayout, browserTemplate) == 0x20 ? 1 : -1];
    typedef char Play[offsetof(IDEDocManagerLayout, playTemplate) == 0x24 ? 1 : -1];
    typedef char Script[offsetof(IDEDocManagerLayout, scriptTemplate) == 0x28 ? 1 : -1];
    typedef char Objects[offsetof(IDEDocManagerLayout, objectBrowserTemplate) == 0x2c ? 1 : -1];
}
int nativeIDEDocManagerSize() { return sizeof(CIDEDocManager); }
