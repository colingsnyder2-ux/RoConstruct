// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <stdexcept>
#include <new>

// INFERRED: minimal local G3D declarations; real headers not shown in the prompt.
namespace G3D {
class GWindow {
public:
    virtual void v00(); // vtable slot layout unknown; slot 0x98/4 used below via setAsCurrent
};
class Log {
public:
    static Log* common();
};
class GLCaps {
public:
    static const std::string& renderer();
};
class RenderDevice {
public:
    char data[0x8b0];
    RenderDevice();
    ~RenderDevice();
    bool init(GWindow* window, Log* log);
    void setSwapBuffersAutomatically(bool b);
    void enableAlphaWrite();
};
}

extern "C" void* fn_006a0920(int a1, int a2);
extern "C" unsigned int __stdcall glGetError(void);

extern G3D::GWindow* g_currentWindow;      // 0x96eff4
extern bool g_renderDeviceCreated;         // 0x972888

// INFERRED: window class with virtual at +0x98 (makeCurrent-like)
struct GWindowV {
    virtual void s0();
};
typedef void (__thiscall *WinFn)(void*);

// INFERRED: owner class layout from offsets a4/ac/88
struct RenderOwner {
    char pad0[0x88];
    bool alphaWrite;
    char pad1[0xa4 - 0x89];
    G3D::GWindow* window;
    char pad2[4];
    G3D::RenderDevice* renderDevice;
};

extern "C" void __fastcall fn_0045ba90(RenderOwner* self, int unusedEdx, G3D::GWindow* window)
{
    self->window = window;
    if (g_currentWindow != window) {
        (*(void (__thiscall **)(void*))(*(char**)window + 0x98))(window);
        g_currentWindow = window;
    }

    if (G3D::GLCaps::renderer() == "GDI Generic") {
        throw std::runtime_error(std::string("This computer does not have correctly installed graphics drivers and is using the default Microsoft OpenGL implementation"));
    }

    G3D::RenderDevice* dev = new G3D::RenderDevice();
    G3D::RenderDevice* old = self->renderDevice;
    if (dev != old && old) {
        delete old;
    }
    self->renderDevice = dev;

    if (!dev->init(self->window, G3D::Log::common())) {
        delete self->renderDevice;
        self->renderDevice = 0;
        throw std::runtime_error(std::string("renderDevice->init failed"));
    }

    g_renderDeviceCreated = true;
    self->renderDevice->setSwapBuffersAutomatically(false);
    if (self->alphaWrite) {
        self->renderDevice->enableAlphaWrite();
    }
    if (glGetError() != 0) {
        throw std::runtime_error(std::string("GL error creating RenderDevice"));
    }
}
