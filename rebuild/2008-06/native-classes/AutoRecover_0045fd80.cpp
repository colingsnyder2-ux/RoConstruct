// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "CRobloxView.h"

extern "C" void __fastcall fn_006a107c(CRobloxWnd* self, int unusedEdx);

// INFERRED: protected members exposed through a derived accessor so the free function can call them
struct CRobloxWndAccess : CRobloxWnd {
    using CRobloxWnd::sub_0045beb0;
    using CRobloxWnd::shutdownGraphics;
};

// INFERRED: objects at +0xb4/+0xb8 have a virtual deleting destructor (vtable slot 0, push 1)
struct Fn45fd80Owned {
    virtual ~Fn45fd80Owned() {}
};

extern "C" void __fastcall fn_0045fd80(CRobloxWnd* self, int unusedEdx)
{
    char* p = (char*)self;
    CRobloxWndAccess* acc = static_cast<CRobloxWndAccess*>(self);
    acc->sub_0045beb0();
    self->setDataModel(0);
    if (*(int*)(p + 0x5c) == 2) {
        acc->shutdownGraphics();
        fn_006a107c(self, 0);
        return;
    }
    if (*(int*)(p + 0xb8) != 0) {
        Fn45fd80Owned* a = *(Fn45fd80Owned**)(p + 0xb4);
        if (a)
            delete a;
        *(int*)(p + 0xb4) = 0;
        Fn45fd80Owned* b = *(Fn45fd80Owned**)(p + 0xb8);
        if (b)
            delete b;
    }
    fn_006a107c(self, 0);
}
