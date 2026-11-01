// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection { class PropertyDescriptor; }
class Instance {
public:
    void raisePropertyChanged(const Reflection::PropertyDescriptor&);
};
class X0063dc20 : public Instance {
    char pad[0xc0];
    int value;
public:
    void setValue(int v);
};
extern Reflection::PropertyDescriptor prop_X0063dc20;
void X0063dc20::setValue(int v)
{
    if (v != value) {
        value = v;
        raisePropertyChanged(prop_X0063dc20);
    }
}
}
