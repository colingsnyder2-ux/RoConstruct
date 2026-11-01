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
extern Reflection::PropertyDescriptor prop_A;
class ExeObj : public Instance {
    char pad[0xb4];
    int value;
public:
    void setValue(int v);
};
void ExeObj::setValue(int v)
{
    if (value != v) {
        value = v;
        raisePropertyChanged(prop_A);
    }
}
}
