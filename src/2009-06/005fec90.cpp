// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <utility>
namespace RBX {
struct Item { int x; };
struct Val { std::string t; Val(const std::string& s) : t(s) {} }; struct Key { int id; Val name; Key(int i, const std::string& n) : id(i), name(n) {} };
class Registry {
public:
    bool find(Key key, Item* out);
};
extern Registry registry;
class S {
public:
    Registry* reg;
    int pad;
    Item item;
    void f(int a, std::string s);
};
void S::f(int a, std::string s) { reg = registry.find(Key(a, s), &item) ? &registry : 0; }
}
