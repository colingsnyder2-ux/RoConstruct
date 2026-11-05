// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Obj {
    char pad[0x120];
    std::string name;
    void setName(std::string s);
};
void Obj::setName(std::string s)
{
    name = s;
}
