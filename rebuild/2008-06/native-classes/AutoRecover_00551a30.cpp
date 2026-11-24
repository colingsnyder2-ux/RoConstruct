// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <exception>
#include <string>

// INFERRED: opaque forward declarations; the function only forwards the two arguments.
namespace G3D { class TextureManager; }

extern "C" void* fn_006a0920(unsigned int size); // operator new
extern "C" void* __fastcall fn_007ae4b0(void* self, int unusedEdx, G3D::TextureManager& mgr, const std::string& name); // RenderNew::MegaTextureProxy::MegaTextureProxy
extern "C" void* __fastcall fn_007b8fb0(void* self, int unusedEdx, G3D::TextureManager& mgr, const std::string& name); // Render::MegaTextureProxy::MegaTextureProxy

// INFERRED: global render factory type selector at 0x942ec4 (0 = RenderNew, 1 = Render)
extern int g_renderFactoryType;

extern "C" void* fn_00551a30(G3D::TextureManager& mgr, const std::string& name)
{
    if (g_renderFactoryType == 0) {
        void* mem = fn_006a0920(0x64);
        return mem ? fn_007ae4b0(mem, 0, mgr, name) : 0;
    }
    if (g_renderFactoryType == 1) {
        void* mem = fn_006a0920(0x58);
        return mem ? fn_007b8fb0(mem, 0, mgr, name) : 0;
    }
    const char* msg = "Invalid factory type";
    throw std::exception(msg);
}
