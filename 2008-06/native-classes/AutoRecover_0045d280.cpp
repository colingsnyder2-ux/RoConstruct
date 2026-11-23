// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <afxwin.h>
#include <stdexcept>
#include <string>

// INFERRED: callee signatures follow the disassembly. Header types for G3D, RBX and CRenderSettings are not available here, so opaque pointers are used.
struct SettingsBlob { int f[0x1c]; };

extern "C" void __fastcall fn_0045ace0(SettingsBlob* self, int unusedEdx);
extern "C" void* fn_00482b30(SettingsBlob* s, HWND h);
extern "C" int __fastcall fn_0045ba90(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00449440(void* self, int unusedEdx);
extern "C" int __fastcall fn_0045cbf0(void* self, int unusedEdx, int a1, int a2);
extern "C" int fn_0045b0d0(void);
extern "C" void* fn_00412d50(void);
extern "C" void __fastcall fn_00449180(void* self, int unusedEdx, int mode);
extern "C" void* fn_00569620(void* out);
extern "C" void fn_005693a0(void* so, int type, const char* fmt, ...);
extern "C" void* fn_005690f0(void* out);
extern "C" void __fastcall fn_00568910(void* self, int unusedEdx);
extern "C" void __fastcall fn_00600660(void* sp, int unusedEdx);
extern "C" int g_930668;

extern "C" void __fastcall fn_0045d280(CWnd* self, int unusedEdx, int width, int height)
{
    char* me = (char*)self;
    std::string unusedStr;
    SettingsBlob settings;
    fn_0045ace0(&settings, 0);
    settings.f[0] = width;
    settings.f[1] = height;
    settings.f[0x14 / 4] = 0x18;
    settings.f[0x10 / 4] = *(unsigned char*)(me + 0x88) ? 8 : 0;
    settings.f[0x1c / 4 - 0] = 8;
    settings.f[0x20 / 4] = g_930668;

    CClientDC dc(self);
    RECT rc;
    GetClientRect(self->m_hWnd, &rc);
    try {
        void* win = fn_00482b30(&settings, (HWND)dc.m_hDC);
        fn_0045ba90(self, 0, (int)win);
    }
    catch (std::exception& e) {
        if (*(int*)(me + 0x60) == 0 && fn_00449440(fn_00412d50(), 0) == 1) {
            ++*(int*)(me + 0x60);
            char sp[8];
            void* so = *(void**)fn_00569620(sp);
            fn_005693a0(so, 2, "OpenGL-G3D failed: \"%s\". Trying RbxGfx.", e.what());
            fn_00600660(sp, 0);
            *(int*)(me + 0x5c) = 3;
            try {
                fn_0045cbf0(self, 0, width, height);
            }
            catch (...) {
                if (fn_00449440(fn_00412d50(), 0) == 1) {
                    fn_00449180(fn_00412d50(), 0, 3);
                    char gs[8];
                    void* g = *(void**)fn_005690f0(gs);
                    fn_00568910(g, 0);
                    fn_00600660(gs, 0);
                    AfxMessageBox("There has been an error in graphics initialization. ROBLOX has made changes to your settings.", MB_ICONEXCLAMATION, 0);
                    AfxPostQuitMessage(0);
                    fn_0045b0d0();
                    throw;
                }
                fn_0045b0d0();
                throw std::runtime_error(std::string("Graphics failed to initialize"));
            }
        } else {
            fn_0045b0d0();
            throw std::runtime_error(std::string("Graphics failed to initialize"));
        }
    }
}
