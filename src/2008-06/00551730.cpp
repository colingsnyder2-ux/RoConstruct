// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Factory analog for 00551730: global selector 00942ec4 picks between two
// 0x18-byte material classes (ctors 007ad960 / 007b80a0) or throws.
#include <exception>

class MaterialBase {
public:
    virtual ~MaterialBase();
};

namespace RenderNew { class Material : public MaterialBase { public: Material(); char data[0x14]; }; }
namespace Render { class Material : public MaterialBase { public: Material(); char data[0x14]; }; }

extern int materialFactoryType;

MaterialBase* createMaterial()
{
    if (materialFactoryType == 0)
        return new RenderNew::Material();
    else if (materialFactoryType == 1)
        return new Render::Material();
    else
        throw std::exception("Invalid factory type");
}
