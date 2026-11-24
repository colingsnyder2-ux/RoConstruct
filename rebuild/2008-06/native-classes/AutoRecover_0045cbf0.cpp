// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "CRobloxView.h"
#include "LogManager.h"
#include <string>
#include <stdexcept>
#include <afxwin.h>

// INFERRED: Ogre imports declared locally (VisualEngine2008.h needs OgrePrerequisites.h, not on the include path).
namespace Ogre {
    class ColourValue { public: float r, g, b, a; };   // class, not struct: Ogre exports mangle it as V (ABVColourValue)
    struct StringUtil {
        static __declspec(dllimport) bool match(const std::string& str, const std::string& pattern, bool caseSensitive);
    };
    struct Animation {
        enum InterpolationMode { IM_LINEAR };
        enum RotationInterpolationMode { RIM_LINEAR };
        static __declspec(dllimport) void setDefaultInterpolationMode(InterpolationMode m);
        static __declspec(dllimport) void setDefaultRotationInterpolationMode(RotationInterpolationMode m);
    };
    struct SceneManager { __declspec(dllimport) void setAmbientLight(const ColourValue& c); };
    struct Camera {
        __declspec(dllimport) void setPosition(float x, float y, float z);
        __declspec(dllimport) void lookAt(float x, float y, float z);
    };
}

extern "C" unsigned long fn_00678510(void);                                   // getVideoMemory
extern "C" void* __fastcall fn_006786c0(void* self, int unusedEdx);           // VisualEngine::VisualEngine
extern "C" void* fn_006a0920(int a1);                                         // operator new
extern "C" void* fn_00407be0(void* out);                                      // DebugSettings singleton
extern "C" void* __fastcall fn_005634b0(void* self, int unusedEdx, std::string* ret); // gfxcard()
extern "C" char* fn_00412d50(void);                                           // CRenderSettings singleton
extern "C" int fn_00427b60(void);                                             // G3D::assertionHook
extern "C" int __fastcall fn_00428050(void* self, int unusedEdx, int a1, int a2);
// 0067a7e0 is the native Ogre::VisualEngine::initialize(int api, HWND, int width, int height, int aa, std::string logFile)
// (thiscall ret 0x30); this fastcall declaration has the same stack layout and is aliased to it in the donor-free link.
extern "C" int __fastcall fn_0067a7e0(void* ve, int unusedEdx, int api, int hwnd, int width, int height, int aa, std::string logFile);
extern "C" void fn_004d71a0(bool value);
extern "C" int __fastcall fn_00449440(void* self, int unusedEdx);
extern "C" int fn_0045b0d0(void);
extern "C" void __fastcall fn_0045ace0(void* self, int unusedEdx);            // G3D::GWindow::Settings ctor
extern "C" void __fastcall fn_0045d4c0(CRobloxWnd* self, int unusedEdx, int width, int height);
extern "C" void __fastcall fn_0045cbf0(CRobloxWnd* self, int unusedEdx, int width, int height);

// INFERRED: G3D headers not available; local stand-in for GWindow::Settings (0x60 bytes, width/height first, string at +0x40).
struct LocalWindowSettings {
    int width;
    int height;
    char pad[0x38];
    std::string title;
    int tail;
};

// INFERRED: globals at 0x962f68 (aa tier), 0x962f64, 0x96de64
extern int g_aaTier;
extern bool g_flag962f64;
extern bool g_lowQualityFlag;

extern "C" void __fastcall fn_0045cbf0(CRobloxWnd* self, int unusedEdx, int width, int height)
{
    char* base = (char*)self;
    char settingsBuf[sizeof(LocalWindowSettings)];
    fn_0045ace0(settingsBuf, 0);
    LocalWindowSettings& settings = *(LocalWindowSettings*)settingsBuf;
    settings.width = width;
    settings.height = height;

    CClientDC dc((CWnd*)self);
    RECT rc;
    GetClientRect(*(HWND*)(base + 0x20), &rc);

    int videoMemory = (int)fn_00678510();
    void* mem = fn_006a0920(0x808);
    void* ve = mem ? fn_006786c0(mem, 0) : 0;
    *(void**)(base + 0xb8) = ve;

    std::string gfx;
    char tmp[4];
    fn_005634b0(fn_00407be0(tmp), 0, &gfx);

    // INFERRED: tier thresholds from disassembly (100MB, 200MB, 400MB, 800MB)
    int aaFixed = *(int*)(fn_00412d50() + 0x13c);
    int tiers[3] = { 0xbebc200, 0x17d78400, 0x2faf0800 };
    int lowTiers[3] = { 0x5f5e100, 0xbebc200, 0x17d78400 };
    bool low = Ogre::StringUtil::match(gfx, "*Radeon*", false)
            || Ogre::StringUtil::match(gfx, "*ALL-IN-WONDER*", false);
    bool intel = Ogre::StringUtil::match(gfx, "*Intel*", false);
    bool useLow = low || intel;
    int* t = useLow ? lowTiers : tiers;
    bool lowFlag = false;
    if (aaFixed == 0) {
        if (videoMemory < t[0]) { lowFlag = true; g_aaTier = 0; }
        else if (videoMemory < t[1]) { lowFlag = true; g_aaTier = 1; }
        else if (videoMemory > t[2]) { lowFlag = true; g_aaTier = 2; }
    } else {
        lowFlag = aaFixed != 2;
    }
    if (lowFlag != g_lowQualityFlag) g_lowQualityFlag = lowFlag;
    if (g_lowQualityFlag) *(int*)(*(char**)(base + 0xb8) + 0x7f8) = 0;

    int aa = 0;
    switch (*(int*)(fn_00412d50() + 0x138)) {
    case 0: aa = (videoMemory >= 0xbebc200) ? 2 : 0; break;
    case 1: aa = 0; break;
    case 2: aa = 2; break;
    default:
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, "Unknown antialiasing mode");
        aa = 2;
        break;
    }

    try {
        // 00427b60 returns MainLogManager 0096d0fc; 00428050 is MainLogManager::MakeLogFileName (log_<id>gfx.txt)
        fn_0067a7e0(ve, 0, *(int*)(base + 0x5c) != 3, *(int*)(base + 0x20),
                    rc.right - rc.left, rc.bottom - rc.top, aa, MainLogManager::getMainLogManger()->MakeLogFileName("gfx"));
        g_flag962f64 = *(int*)(fn_00412d50() + 0x140) != 2;

        int hq;
        switch (*(int*)(fn_00412d50() + 0x134)) {
        case 0:
            hq = videoMemory >= 0x5f5e100 && *(char*)(*(char**)(base + 0xb8) + 0x804) != 0;
            break;
        case 1: hq = 1; break;
        default: hq = 0; break;
        }
        fn_004d71a0(hq != 0);
        Ogre::Animation::setDefaultInterpolationMode(Ogre::Animation::IM_LINEAR);
        Ogre::Animation::setDefaultRotationInterpolationMode(Ogre::Animation::RIM_LINEAR);

        Ogre::ColourValue amb = { 0.5f, 0.5f, 0.5f, 1.0f }; // INFERRED: constant at 0x819bac
        (*(Ogre::SceneManager**)(*(char**)(base + 0xb8) + 4))->setAmbientLight(amb);
        (*(Ogre::Camera**)(*(char**)(base + 0xb8) + 8))->setPosition(0.0f, 1.0f, 1.0f);
        (*(Ogre::Camera**)(*(char**)(base + 0xb8) + 8))->lookAt(0.0f, 1.0f, 0.0f);
    }
    catch (std::exception& e) {
        if (*(int*)(base + 0x60) == 0 &&
            fn_00449440(fn_00412d50(), 0) == 1) {
            ++*(int*)(base + 0x60);
            RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR,
                "Direct3D error: \"%s\". Trying OpenGL stable.", e.what());
            *(int*)(base + 0x5c) = 2;
            fn_0045d4c0(self, 0, width, height);
            return;
        }
        fn_0045b0d0();
        throw std::runtime_error(std::string("Graphics failed to initialize"));
    }
}
