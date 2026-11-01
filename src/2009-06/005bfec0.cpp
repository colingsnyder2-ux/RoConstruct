// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#pragma optimize("", off)
struct S {
    void* pointer;
    bool f();
};

bool S::f() {
    return pointer == 0;
}