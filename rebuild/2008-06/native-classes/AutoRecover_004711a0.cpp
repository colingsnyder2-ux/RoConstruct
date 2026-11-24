// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: callees are declared with the fn_ convention because no headers were visible.
extern "C" const std::string* fn_004709a0(void);   // G3D::GLCaps::renderer()
extern "C" char __fastcall fn_00470600(void* table, int unusedEdx, const std::string& key); // Table<string,int>::containsKey
extern "C" bool fn_005120b0(const std::string& s, const std::string& prefix); // G3D::beginsWith

// INFERRED: unknown globals: the extension table object and a result flag byte.
extern "C" char g_009336b0[];
extern "C" bool g_0096ee76;

extern "C" void fn_004711a0(void)
{
    const std::string& renderer = *fn_004709a0();

    bool result;
    if (fn_00470600((void*)g_009336b0, 0, std::string("GL_SGIS_generate_mipmap"))) {
        result = fn_005120b0(renderer, std::string("MOBILITY RADEON 90"))
              || fn_005120b0(renderer, std::string("MOBILITY RADEON 57"))
              || fn_005120b0(renderer, std::string("Intel 845G"))
              || fn_005120b0(renderer, std::string("Intel 854G"));
    } else {
        result = false;
    }
    g_0096ee76 = result;
}
