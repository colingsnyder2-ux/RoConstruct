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
class X00660630 : public Instance {
    char pad[0x124-0];
    int value;
public:
    void setValue(int v);
};
extern Reflection::PropertyDescriptor prop_X00660630;
void X00660630::setValue(int v)
{
    if (v != value) {
        value = v;
        raisePropertyChanged(prop_X00660630);
    }
}
}
