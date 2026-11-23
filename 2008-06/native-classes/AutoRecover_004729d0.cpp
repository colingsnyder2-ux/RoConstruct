// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>
#include <GL/gl.h>
#include <string>

namespace G3D {
// INFERRED: local declaration of the G3D::GLCaps statics (no header was provided).
class GLCaps {
public:
    static bool hasBug_mipmapGeneration();
    static bool hasBug_redBlueMipmapSwap();
};
}

static bool s_initialized;   // 0x96ef49
static bool s_value;         // 0x96ef48

// INFERRED: lazily-initialised capability query; found-extension => false, as the disassembly shows.
extern "C" bool fn_004729d0()
{
    if (!s_initialized) {
        s_initialized = true;
        std::string ext((const char*)glGetString(GL_EXTENSIONS));
        if (ext.find("GL_SGIS_generate_mipmap", 0, 23) == std::string::npos &&
            !G3D::GLCaps::hasBug_mipmapGeneration()) {
            bool bug = G3D::GLCaps::hasBug_redBlueMipmapSwap();
            s_value = true;
            if (bug) {
                s_value = false;
            }
        } else {
            s_value = false;
        }
    }
    return s_value;
}
