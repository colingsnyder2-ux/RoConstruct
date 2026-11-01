// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Desc { int x; };
extern Desc desc;
class C {
public:
    char pad[0xa8];
    std::string value;
    void raisePropertyChanged(const Desc& d);
    void setValue(const std::string& v);
};
void C::setValue(const std::string& v)
{
    if (v != value) {
        value = v;
        raisePropertyChanged(desc);
    }
}
