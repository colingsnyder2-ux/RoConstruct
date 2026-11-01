// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
namespace Reflection { struct ClassDescriptor; }
struct GuidItemX { virtual ~GuidItemX(); int g[4]; };
struct ObjectX { virtual ~ObjectX(); };
struct DescribedX { virtual ~DescribedX(); Reflection::ClassDescriptor* descriptor; };
struct DebugableX { virtual ~DebugableX(); };
struct Instance : GuidItemX, ObjectX, DescribedX, DebugableX { Instance(); virtual ~Instance(); int rest[(0x8c - 0x24) / 4]; void setName(const std::string& name); };
struct __declspec(novtable) IModelModifier { virtual ~IModelModifier(); };
struct CharacterAppearance : Instance, IModelModifier { };
template<class Base> struct NonFactoryProductX : Base { NonFactoryProductX() {} };
template<class C, class Base> struct __declspec(novtable) DescribedT : Base {
    DescribedT();
};
class BrickColor {
public:
    int number;
    BrickColor(int n) : number(n) {}
};
struct BodyColors : DescribedT<BodyColors, NonFactoryProductX<CharacterAppearance> > {
    BrickColor headColor;
    BrickColor leftArmColor;
    BrickColor rightArmColor;
    BrickColor torsoColor;
    BrickColor leftLegColor;
    BrickColor rightLegColor;
    BodyColors();
    virtual ~BodyColors();
};
BodyColors::BodyColors()
    : headColor(0xe2), leftArmColor(0xe2), rightArmColor(0xe2),
      torsoColor(0x1c), leftLegColor(0x17), rightLegColor(0x17)
{
    setName("Body Colors");
}
}
