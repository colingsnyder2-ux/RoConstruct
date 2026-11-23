// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <stdlib.h>

// INFERRED: G3D 6.x Win32Window::setGammaRamp(const Array<uint16>&); Array layout is {data, size}.
struct GammaArray {
    unsigned short* data;
    int size;
};

struct Win32Window {
    char pad[0xA4];
    void* hdc; // 0xa4
};

namespace G3D {
class Log {
public:
    static Log* common();
    void println(const std::string& s);
};
namespace _internal {
void _releaseInputGrab_();
void _restoreInputGrab_();
}
}

// INFERRED: G3D assertion hook (debugAssertM) stored at 0x94278c
typedef bool (*AssertHook)(const char* expr, const std::string& msg,
                           const char* file, int line, bool useGuiPrompt,
                           bool* ignoreAlways);
extern AssertHook g_assertionHook;
extern bool g_ignoreAssert;

extern "C" __declspec(dllimport) int __stdcall SetDeviceGammaRamp(void* hdc, void* ramp);

extern "C" void __fastcall fn_0047fbe0(Win32Window* self, int unusedEdx, const GammaArray* gammaRamp)
{
    if (!g_ignoreAssert && gammaRamp->size < 256) {
        G3D::_internal::_releaseInputGrab_();
        if (g_assertionHook) {
            bool fail;
            {
                std::string m("Gamma ramp must have at least 256 entries");
                fail = g_assertionHook("gammaRamp.size() >= 256", m,
                                       ".\\glg3dcpp\\Win32Window.cpp", 0x304,
                                       &g_ignoreAssert != 0, &g_ignoreAssert);
            }
            if (fail) {
                exit(-1);
            }
        }
        G3D::_internal::_restoreInputGrab_();
    }

    G3D::Log* debugLog = G3D::Log::common();

    unsigned short wGammaRamp[3][256];
    for (int i = 0; i < 256; ++i) {
        unsigned short v = gammaRamp->data[i];
        wGammaRamp[2][i] = v;
        wGammaRamp[1][i] = v;
        wGammaRamp[0][i] = v;
    }

    if (!SetDeviceGammaRamp(self->hdc, wGammaRamp) && debugLog) {
        debugLog->println(std::string("Error setting gamma ramp! (Possibly LCD monitor)"));
    }
}
