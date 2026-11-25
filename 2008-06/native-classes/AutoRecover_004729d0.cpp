// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <windows.h>
#include <GL/gl.h>

// INFERRED: the G3D/GLCaps.h include path is not available, so only the two
// static members this function calls are declared here (no definitions emitted).
namespace G3D {
class GLCaps {
public:
    static bool hasBug_mipmapGeneration();
    static bool hasBug_redBlueMipmapSwap();
};
}

#ifndef GL_EXTENSIONS
#define GL_EXTENSIONS 0x1F03
#endif

// INFERRED: static-cached "supports generate mipmap" check; the function is unnamed, so it uses the fn_ convention.
extern "C" bool fn_004729d0()
{
    static bool initialized = false;
    static bool value;

    if (!initialized) {
        initialized = true;
        std::string ext((const char*)glGetString(GL_EXTENSIONS));
        if (ext.find("GL_SGIS_generate_mipmap") == std::string::npos
            || G3D::GLCaps::hasBug_mipmapGeneration()
            || G3D::GLCaps::hasBug_redBlueMipmapSwap()) {
            value = false;
        } else {
            value = true;
        }
    }
    return value;
}
