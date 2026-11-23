// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <stdlib.h>

namespace G3D {
namespace _internal {
void _releaseInputGrab_();
void _restoreInputGrab_();
}

// INFERRED: local declaration of the GLCaps static bug checks; real header not available.
class GLCaps {
public:
    static void checkBug_cubeMapBugs();
    static void checkBug_redBlueMipmapSwap();
    static void checkBug_slowVBO();
};
}

extern "C" int fn_004711a0(void);

// INFERRED: 0x94278c is the G3D assertion hook function pointer; 0x96ee64 is GLCaps::_loadedExtensions;
// 0x96ef41 is the static ignoreAlways flag of the alwaysAssertM; 0x96ee66 is the checkAllBugs "initialized" flag.
extern "C" bool (*fn_var_assertionHook)(const char* expression, const std::string& message,
                                        const char* filename, int line, bool* ignoreAlways,
                                        bool useGuiPrompt);
extern "C" bool fn_var_loadedExtensions;
extern "C" bool fn_var_ignoreAlways;
extern "C" bool fn_var_bugsInitialized;

extern "C" void fn_00471590(void) {
    if (fn_var_bugsInitialized) {
        return;
    }
    fn_var_bugsInitialized = true;

    if (!fn_var_ignoreAlways && !fn_var_loadedExtensions) {
        G3D::_internal::_releaseInputGrab_();
        if (fn_var_assertionHook) {
            if (fn_var_assertionHook("_loadedExtensions",
                                     std::string("Cannot check for OpenGL bugs before extensions are loaded."),
                                     ".\\glg3dcpp\\GLCaps.cpp", 0x21c, &fn_var_ignoreAlways, true)) {
                exit(-1);
            }
        }
        G3D::_internal::_restoreInputGrab_();
    }

    G3D::GLCaps::checkBug_cubeMapBugs();
    G3D::GLCaps::checkBug_redBlueMipmapSwap();
    fn_004711a0();
    G3D::GLCaps::checkBug_slowVBO();
}
