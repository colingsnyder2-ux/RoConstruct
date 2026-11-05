// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Name { std::string s; int b; };
struct Key { int a; Name name; };
struct Entry { int v; };
class Registry {
public:
    bool lookup(Key k, Entry* out);
};
extern Registry g_registry;
class Handle {
    Registry* registry;
    int pad;
    Entry entry;
public:
    void init(Key k);
};
void Handle::init(Key k)
{
    registry = g_registry.lookup(k, &entry) ? &g_registry : 0;
}
