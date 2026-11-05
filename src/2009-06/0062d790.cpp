// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <map>
struct Primitive;
struct Other { void g(Primitive* p); };
struct Workspace {
    char pad[0x1fc];
    std::map<Primitive*, int> mech;
    Other* other;
    void onX(Primitive* p);
};
void Workspace::onX(Primitive* p)
{
    size_t n = mech.erase(p);
    if (other && !n)
        other->g(p);
}
