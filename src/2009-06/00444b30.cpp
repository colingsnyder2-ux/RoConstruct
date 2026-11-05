// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct PropertyDescriptor { int x; };
extern PropertyDescriptor prop_Setting;
#pragma pack(push, 2)
class Item {
public:
    char pad[0xb6];
    int requested;
    int pad2;
    int current;
    void apply(int force);
    void raisePropertyChanged(const PropertyDescriptor& d);
    void setValue(int v);
};
#pragma pack(pop)
void Item::setValue(int v)
{
    if (v != current) {
        requested = v;
        apply(0);
        raisePropertyChanged(prop_Setting);
    }
}
