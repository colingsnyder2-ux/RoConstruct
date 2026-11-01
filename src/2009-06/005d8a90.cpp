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
class X005d8a90 : public Instance {
    char pad[0x8c];
    int value;
public:
    void setValue(int v);
};
extern Reflection::PropertyDescriptor prop_X005d8a90;
void X005d8a90::setValue(int v)
{
    if (value != v) {
        value = v;
        raisePropertyChanged(prop_X005d8a90);
    }
}
}
