// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
#include <algorithm>
struct E { void* px; void* pn; };
typedef std::vector<E> Holder;
bool isPart(E e);
struct Inst {
    char pad[0x4c];
    Holder* children;
    int countParts() const;
};
int Inst::countParts() const
{
    if (children)
        return std::count_if(children->begin(), children->end(), isPart);
    return 0;
}
