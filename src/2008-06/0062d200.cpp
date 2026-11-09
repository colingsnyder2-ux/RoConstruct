// from server: 100% by EspClaude
// from server: 95% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espclaude_8ac19faa8bb50df6.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Color4.h>
#include <boost/shared_ptr.hpp>
namespace RBX {
class Instance { public:
    virtual void anchor();
};

struct Part;
class PartInstance : public Instance { public:
 const Part& getPart();
    unsigned char padding[804];
    float value;
};
}
using RBX::Instance; using RBX::PartInstance; using RBX::Part;
typedef boost::shared_ptr<Instance> Shared;

typedef G3D::Color4 Color;

extern const float scale;
extern const float alpha;
extern void __cdecl submit(const Part&,void*,const Color&);

void __cdecl render(Shared object, void* context, int phase)
{
    PartInstance* part = dynamic_cast<PartInstance*>(object.get());
    if (part) {
    float v = part->value;
    if (v != 0.0f) {
        float t = (phase < 15 ? phase : 30 - phase) * scale;
        Color color(t, 0.0f, 1.0f - t, alpha);
        submit(part->getPart(),context,color);
    }
    }
}

