// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
struct Str { std::string s; Str(const std::string& x) : s(x) {} };
class Item {
public:
    int id;
    Str name;
    Item(int id, int unused, std::string name);
};
Item::Item(int id, int, std::string name) : id(id), name(name) {}
}
