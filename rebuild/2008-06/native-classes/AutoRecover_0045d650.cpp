// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "CRobloxView.h"
#include <string>

// INFERRED: no G3D header was reachable, so the G3D types the target uses are
// declared locally. Only the signatures needed for the mangled names to match
// are given.
namespace G3D {

class Rect2D {
public:
    float x0, y0, x1, y1;
    static Rect2D xywh(float x, float y, float w, float h);
};

class RenderDevice {
public:
    void notifyResize(int w, int h);
    int height() const;
    int width() const;
    void setViewport(const Rect2D& r);
};

class GLCaps {
public:
    static const std::string& renderer();
};

bool beginsWith(const std::string& test, const std::string& pattern);

}

// INFERRED: global holding the currently-activated object (0x96eff4).
extern void* g_currentActive;

// INFERRED: CRobloxWnd members are reached by raw offsets because no class
// header excerpt was available.
#define WND_FIELD(self, off, T) (*(T*)((char*)(self) + (off)))

extern "C" void __fastcall fn_0045d650(CRobloxWnd* self, int unusedEdx, int arg1, int width, int height)
{
    void* engine = WND_FIELD(self, 0xa4, void*);
    G3D::RenderDevice* rd = WND_FIELD(self, 0xac, G3D::RenderDevice*);
    if (engine == 0 || rd == 0)
        return;

    std::string renderer(G3D::GLCaps::renderer());
    bool isRadeon7500 = G3D::beginsWith(renderer, std::string("MOBILITY RADEON 7500"));

    if (isRadeon7500) {
        self->releaseRenderer();
        self->createRenderer(width, height);

        void* eng = WND_FIELD(self, 0xa4, void*);
        if (g_currentActive != eng) {
            // INFERRED: virtual slot 0x98/4 is an "activate" style method
            typedef void (__thiscall *VFn)(void*);
            VFn fn = (VFn)(*(void***)eng)[0x98 / 4];
            fn(eng);
            g_currentActive = eng;
        }
    } else {
        WND_FIELD(self, 0xac, G3D::RenderDevice*)->notifyResize(width, height);
        G3D::RenderDevice* dev = WND_FIELD(self, 0xac, G3D::RenderDevice*);
        float h = (float)dev->height();
        float w = (float)dev->width();
        G3D::Rect2D r = G3D::Rect2D::xywh(0.0f, 0.0f, w, h);
        WND_FIELD(self, 0xac, G3D::RenderDevice*)->setViewport(r);
    }

    WND_FIELD(self, 0x8b, unsigned char) = 1;
}
