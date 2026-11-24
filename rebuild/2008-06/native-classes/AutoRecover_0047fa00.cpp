// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <stdlib.h>

namespace G3D { namespace _internal {
    // INFERRED: G3D assertion hook pointer at 0x94278c, cdecl, 6 stack dwords
    extern bool (*assertionHook)(const char* expression, const std::string& message,
                                 const char* filename, int lineNumber,
                                 bool& ignoreAlways, bool useGuiPrompt);
}}

extern "C" void fn_0050a940(void); // G3D::_internal::_releaseInputGrab_
extern "C" void fn_0050a9b0(void); // G3D::_internal::_restoreInputGrab_

// INFERRED: minimal GWindow layout; vtable slot 0x84/4 = requiresMainLoop, int at +8 = loop counter
struct GWindowLoop {
    virtual void slot00(); virtual void slot01(); virtual void slot02(); virtual void slot03();
    virtual void slot04(); virtual void slot05(); virtual void slot06(); virtual void slot07();
    virtual void slot08(); virtual void slot09(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32();
    virtual bool requiresMainLoop();
    int pad;
    int loopCount;
};

extern "C" void __fastcall fn_004896d0(GWindowLoop* self, int unusedEdx); // GWindow::executeLoopBody

extern "C" void __fastcall fn_0047fa00(GWindowLoop* self, int unusedEdx) {
    // debugAssertM(requiresMainLoop() == false, ...)
    {
        static bool ignoreAlways = false;
        if (!ignoreAlways && self->requiresMainLoop()) {
            fn_0050a940();
            bool doExit = false;
            if (G3D::_internal::assertionHook) {
                doExit = G3D::_internal::assertionHook(
                    "requiresMainLoop() == false",
                    std::string("This GWindow implementation failed to overwrite runMainLoop even though it requires a main loop."),
                    "d:\\Roblox\\Releases\\2008.06.17\\Client\\Rendering\\g3d\\include\\GLG3D/GWindow.h",
                    0x209, ignoreAlways, true);
            }
            if (doExit) {
                exit(-1);
            }
            fn_0050a9b0();
        }
    }
    while (self->loopCount > 0) {
        fn_004896d0(self, 0);
    }
}
