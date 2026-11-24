// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "CRobloxView.h"
#include <GL/gl.h>

extern "C" void* __fastcall fn_0041eea0(void* serviceProvider, int unusedEdx);
extern "C" void __fastcall fn_0045bc80(CRobloxWnd* self, int unusedEdx, int arg);
extern "C" void __fastcall fn_0045e3f0(CRobloxWnd* self, int unusedEdx, int arg);
extern "C" void __fastcall fn_005555e0(void* runService, int unusedEdx, void* runView);

// INFERRED: global ContentProvider pointer at 0x974d74, set only for the duration of the draw
extern void* g_contentProvider_00974d74;

namespace {
// INFERRED: scope guard that restores the re-entrancy flag at 0x89 (saved at [esp+0xc], restored on exit)
struct FlagGuard {
    bool* p;
    bool saved;
    explicit FlagGuard(bool* f) : p(f), saved(*f) { *f = true; }
    ~FlagGuard() { *p = saved; }
};
}

// INFERRED: CRobloxWnd::draw is not declared in CRobloxView.h, so the target is defined
// under the fn_ convention (public members only) until the header gains `void draw(void*);`.
extern "C" void __fastcall fn_0045e6c0(CRobloxWnd* self, int unusedEdx, void* arg)
{
    if (self->flags_88_8b[1])
        return;
    FlagGuard guard(&self->flags_88_8b[1]);

    if (!self->dataModelPtr.get()) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(0x4100);
    } else if (!self->slot_b0) {
        if (self->slot_78)
            fn_005555e0(self->slot_78, 0, static_cast<RBX::IRunView*>(self));
    } else {
        g_contentProvider_00974d74 = fn_0041eea0(self->dataModelPtr.get(), 0);
        if (self->mode_5c == 2)
            fn_0045bc80(self, 0, (int)arg);
        else
            fn_0045e3f0(self, 0, (int)arg);
        g_contentProvider_00974d74 = 0;
    }
}
