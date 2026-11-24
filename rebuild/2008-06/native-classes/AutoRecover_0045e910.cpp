// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <afxwin.h>

// INFERRED: CRobloxWnd layout not available; fields accessed by raw offset.
extern "C" int __fastcall fn_00575820(void* self, int unusedEdx);
extern "C" int fn_00548cb0(void);
extern "C" void __fastcall fn_0045ad50(void* self, int unusedEdx);   // GWindow::makeCurrent
extern "C" void __fastcall fn_0045beb0(void* self, int unusedEdx);   // CRobloxWnd::sub_0045beb0
extern "C" void __fastcall fn_0047ce40(void* self, int unusedEdx);   // RenderDevice::beginFrame
extern "C" void __fastcall fn_0047cea0(void* self, int unusedEdx);   // RenderDevice::endFrame
extern "C" void __fastcall fn_0045e6c0(void* self, int unusedEdx, void* arg); // CRobloxWnd::draw
extern "C" void __fastcall fn_005c3f80(void* mark, int unusedEdx, void* profiler, bool b); // Profiling::Mark ctor
extern "C" void __fastcall fn_005c42d0(void* mark, int unusedEdx);   // Profiling::Mark dtor
extern "C" char* fn_00412d50(void);                                  // GlobalSettingsItem<CRenderSettings>::singleton

// INFERRED: unknown global object with a vtable; slot 2 takes one pointer and returns bool.
struct UnkIface {
    virtual void slot0();
    virtual void slot1();
    virtual char slot2(void* arg);
};
extern "C" UnkIface* g_0096d510;
extern "C" char g_009738a1;

extern "C" bool __fastcall fn_0045e910(char* self, int unusedEdx)
{
    bool drawn = false;
    char mark[16];
    CPaintDC dc((CWnd*)self);

    if (*(void**)(self + 0xa4) && dc.m_hDC && *(void**)(self + 0x70)
        && !::IsRectEmpty(&dc.m_ps.rcPaint))
    {
        fn_0045ad50(*(void**)(self + 0xa4), 0);
        if (*(void**)(self + 0xac) == 0) {
            RECT rc;
            ::GetClientRect(*(HWND*)(self + 0x20), &rc);
            ::DrawTextA(dc.m_hDC, "Roblox can't run with your graphics driver", -1, &rc, 0x8000);
        } else {
            fn_005c3f80(mark, 0, *(void**)(self + 0x98), true);
            fn_0045beb0(self, 0);
            fn_0047ce40(*(void**)(self + 0xac), 0);
            fn_0045e6c0(self, 0, (void*)1);
            drawn = true;
            fn_0047cea0(*(void**)(self + 0xac), 0);
            self[0x8a] = 1;
            if (self[0x8b] == 0) {
                char* s = fn_00412d50();
                void* arg = s ? s + 0x14 : 0;
                if (!g_0096d510->slot2(arg) || !fn_00575820(*(void**)(self + 0x70), 0)) {
                    fn_0045beb0(self, 0);
                    self[0x8b] = 0;
                }
            } else {
                fn_0045beb0(self, 0);
                self[0x8b] = 0;
            }
            if (self[0x80]) {
                self[0x80] = 0;
                fn_00548cb0();
                g_009738a1 = 1;
            }
            fn_005c42d0(mark, 0);
        }
    }
    return drawn;
}
