// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection { class PropertyDescriptor; }
#pragma pack(push, 1)
class Instance {
public:
    void raisePropertyChanged(const Reflection::PropertyDescriptor& d);
};
class Item : public Instance {
public:
    char pad[0xba];
    int value;
    int pad2;
    int current;
    static Reflection::PropertyDescriptor prop_Value;
    void refresh(void* p);
    void setValue(int v);
};
#pragma pack(pop)
void Item::setValue(int v)
{
    if (v != current) {
        value = v;
        refresh(0);
        raisePropertyChanged(prop_Value);
    }
}
}
