// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /fp:fast /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection { class PropertyDescriptor; }
class Instance {
public:
    void raisePropertyChanged(const Reflection::PropertyDescriptor&);
};
class X0066a980 : public Instance {
    char pad[0x1e0];
    float value;
public:
    void setValue(float v);
};
extern Reflection::PropertyDescriptor prop_X0066a980;
void X0066a980::setValue(float v)
{
    if (value != v) {
        value = v;
        raisePropertyChanged(prop_X0066a980);
    }
}
}
