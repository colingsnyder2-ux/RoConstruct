// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
struct S {
    char padding[0x13c];
    std::vector<int*> items;
    int *f();
};
int *S::f()
{
    if (items.size() > 0) return items.front();
    return 0;
}
