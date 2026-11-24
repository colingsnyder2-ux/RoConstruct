// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <exception>
#include <new>
#include <string>

namespace G3D { class TextureManager; }

// INFERRED: global selecting the render factory (0 = RenderNew, 1 = Render); name guessed.
extern int g_renderFactoryType; // 0x00942ec4

// RBX::RenderNew::TextureProxy::TextureProxy(TextureManager&, const std::string&, bool)
extern "C" void* __fastcall fn_00551e30(void* self, int unusedEdx, G3D::TextureManager& tm, const std::string& name, bool flag);
// RBX::Render::TextureProxy::TextureProxy(TextureManager&, const std::string&, bool)
extern "C" void* __fastcall fn_00551b30(void* self, int unusedEdx, G3D::TextureManager& tm, const std::string& name, bool flag);

// INFERRED: target is an unnamed TextureProxy factory; returns the new proxy (base pointer).
extern "C" void* fn_00551920(G3D::TextureManager& tm, const std::string& name, bool flag)
{
    if (g_renderFactoryType == 0)
    {
        void* p = ::operator new(0x60);
        return p ? fn_00551e30(p, 0, tm, name, flag) : 0;
    }
    if (g_renderFactoryType == 1)
    {
        void* p = ::operator new(0x54);
        return p ? fn_00551b30(p, 0, tm, name, flag) : 0;
    }
    const char* msg = "Invalid factory type";
    throw std::exception(msg);
}
