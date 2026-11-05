// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
struct ExeBaseA { virtual ~ExeBaseA(); };
struct ExeBaseB { virtual ~ExeBaseB(); };
class BrickColor { int n; };
class Appearance : public ExeBaseA, public ExeBaseB {
public:
    char pad[0x94 - 8];
    BrickColor value;
    void setValue(BrickColor);
};
namespace Reflection {
template<class C, class V>
class PropDescriptor {
public:
    template<class Getter, class Setter>
    PropDescriptor(const char* name, const char* category, Getter getter, Setter setter, int f);
    ~PropDescriptor();
private:
    char data[0x50];
};
}
static Reflection::PropDescriptor<Appearance, BrickColor> desc_LeftArmColor("LeftArmColor", "Appearance", &Appearance::value, &Appearance::setValue, 7);
}
