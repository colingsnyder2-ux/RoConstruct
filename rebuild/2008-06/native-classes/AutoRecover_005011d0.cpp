// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: byte flags and float constants identified by address.
extern "C" unsigned char g_0096ee88;
extern "C" unsigned char g_0096ee89;
extern "C" unsigned char g_0096ee8a;
extern "C" unsigned char g_0096ee8b;
extern "C" const float g_0081c434;
extern "C" const float g_00827298;
extern "C" const float g_00827278;

// INFERRED: callee receives a reference to a temporary string and returns bool.
extern "C" bool __cdecl fn_00471060(const std::string&);

namespace RBX { namespace Render {

float __cdecl getShaderModel()
{
    if ((g_0096ee8a && g_0096ee8b) || (g_0096ee88 && g_0096ee89))
        return g_0081c434;

    if (fn_00471060("GL_ATI_fragment_shader") ||
        fn_00471060("GL_NV_fragement_program"))
        return g_0081c434;

    if (fn_00471060("GL_ATI_texture_env_combine3") ||
        fn_00471060("GL_NV_texture_shader3"))
        return g_00827298;

    if (fn_00471060("GL_NV_register_combiners"))
        return g_00827278;

    return 1.0f;
}

} }
