// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class Desc {};
extern Desc desc_a4c3e0;
extern bool g_allowed;
class C {
public:
    static bool value;
    void raisePropertyChanged(const Desc& d);
    void setValue(bool v);
};
void C::setValue(bool v)
{
    bool b = !g_allowed ? true : v;
    if (b != value) {
        value = b;
        raisePropertyChanged(desc_a4c3e0);
    }
}
