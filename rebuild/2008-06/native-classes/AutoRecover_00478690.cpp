// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <stdlib.h>

// INFERRED: this is G3D RenderDevice::setDrawBuffer(Buffer b); RenderDevice layout is not
// available, so members are accessed by raw offset.
class RenderDevice;

namespace G3D {
namespace _internal {
void _releaseInputGrab_();
void _restoreInputGrab_();
}
}

extern "C" void __stdcall glDrawBuffer(unsigned int mode);

// INFERRED: G3D assertion hook (function pointer at 0x94278c), 6 cdecl args
extern "C" bool (*G3D_assertionHook)(const char* expr, const std::string& msg,
                                     const char* file, int line,
                                     bool& ignoreAlways, bool useGuiPrompt);

// INFERRED: per-assertion "ignore always" flags (0x96f055 / 0x96f054)
static bool s_ignoreNoFb = false;
static bool s_ignoreFb = false;

static inline int& intAt(RenderDevice* self, int off)
{
    return *(int*)((char*)self + off);
}

extern "C" void __fastcall fn_00478690(RenderDevice* self, int unusedEdx, int b)
{
    intAt(self, 0x78)++;

    if (b == 10)
        return;

    if (intAt(self, 0x3e8) == 0) {
        if (!s_ignoreNoFb && (b < 0 || b > 10)) {
            G3D::_internal::_releaseInputGrab_();
            bool doExit = false;
            if (G3D_assertionHook) {
                std::string msg("Drawing to a color buffer is only supported by application-created framebuffers!");
                doExit = G3D_assertionHook("(b >= BUFFER_NONE) && (b <= BUFFER_CURRENT)", msg,
                                           ".\\glg3dcpp\\RenderDevice.cpp", 0x4a1,
                                           s_ignoreNoFb, true);
            }
            if (doExit)
                exit(-1);
            G3D::_internal::_restoreInputGrab_();
        }
    } else {
        if (!s_ignoreFb && (b < 10 || b > 0x1a)) {
            G3D::_internal::_releaseInputGrab_();
            bool doExit = false;
            if (G3D_assertionHook) {
                std::string msg("Visible buffers cannot be specified for application-created framebuffers!");
                doExit = G3D_assertionHook("(b >= BUFFER_CURRENT) && (b <= BUFFER_COLOR15)", msg,
                                           ".\\glg3dcpp\\RenderDevice.cpp", 0x4a4,
                                           s_ignoreFb, true);
            }
            if (doExit)
                exit(-1);
            G3D::_internal::_restoreInputGrab_();
        }
    }

    if (b != intAt(self, 0x3e4)) {
        intAt(self, 0x70)++;
        intAt(self, 0x3e4) = b;
        glDrawBuffer((unsigned int)intAt(self, 0x80 + b * 4));
    }
}
