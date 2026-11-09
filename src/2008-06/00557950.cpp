// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
#include <string>
struct Instance {
    char padding[0x110];
    std::string name;
};
struct Ptr {
    Instance *px;
    void *pn;
};
struct S {
    char padding[0x108];
    std::vector<Ptr> *children;
    Instance *f(const std::string &name);
};
Instance *S::f(const std::string &name)
{
    std::vector<Ptr> *p = children;
    if (!p)
        return 0;
    for (size_t i = 0; i < p->size(); ++i) {
        const std::string &childName = (*p)[i].px->name;
        if (childName == name)
            return (*p)[i].px;
    }
    return 0;
}
