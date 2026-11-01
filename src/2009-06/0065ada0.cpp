// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct PropDesc { int x; };
extern PropDesc prop_X;
class Instance {
public:
    void raisePropertyChanged(const PropDesc& d);
};
class C : public Instance {
public:
    char pad[0x13c];
    int value;
    void setValue(int v);
};
void C::setValue(int v)
{
    if (value != v) {
        value = v;
        raisePropertyChanged(prop_X);
    }
}
