// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
struct Camera { char pad[0x30]; Camera(); };
struct S {
    int reserved;
    Camera camera;
    std::vector<void*> owners;
    S();
};
S::S() {}
