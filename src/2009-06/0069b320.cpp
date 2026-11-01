// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection { class PropertyDescriptor; }
class Instance {
public:
    void raisePropertyChanged(const Reflection::PropertyDescriptor& d);
};
class Thing : public Instance {
public:
    char pad[0x1a0];
    struct C{int c;} value;
    static Reflection::PropertyDescriptor prop_Value;
    void setValue(C v);
};
void Thing::setValue(C v)
{
    value = v;
    raisePropertyChanged(prop_Value);
}
}
