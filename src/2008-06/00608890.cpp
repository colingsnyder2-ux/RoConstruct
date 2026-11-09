// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espclaude_4bb330cc49725021.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Array.h>
#include <G3D/AABox.h>
#include <G3D/Color4.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/Rect2D.h>
using namespace G3D;
class Adorn {
public:
    virtual ~Adorn();
    virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5();
    virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10();
    virtual void a11(); virtual void a12(); virtual void a13();
    virtual void setObjectToWorldMatrix(const CoordinateFrame& cframe);
    virtual void a15();
    virtual void box(const AABox& box, const Color4& solid, const Color4& wire);
};
class RegionRenderer {
public:
    Array<Rect2D> regions;
    void render(Adorn* adorn);
};
void RegionRenderer::render(Adorn* adorn)
{
    adorn->setObjectToWorldMatrix(CoordinateFrame());
    for (int i = 0; i < regions.size(); ++i) {
        Vector3 lo(regions[i].x0(), 0, regions[i].y0());
        Vector3 hi(regions[i].x1(), 20, regions[i].y1());
        Color4 color(1, 0.2f, 0.2f, 0.5f);
        adorn->box(AABox(lo, hi), color, Color4::zero());
    }
}
