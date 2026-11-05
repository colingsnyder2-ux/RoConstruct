// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <algorithm>
namespace RBX {
namespace Reflection { class PropertyDescriptor; }
class Instance {
public:
    void raisePropertyChanged(const Reflection::PropertyDescriptor&);
};
class X681f20 : public Instance {
    char pad[0x150];
    int value;
public:
    void setValue(int v);
};
extern Reflection::PropertyDescriptor prop_X681f20;
void X681f20::setValue(int v)
{
    v = std::min(v, 5000);
    v = std::max(v, 0);
    if (v != value) {
        value = v;
        raisePropertyChanged(prop_X681f20);
    }
}
}
