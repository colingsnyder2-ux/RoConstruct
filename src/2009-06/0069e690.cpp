// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
struct T; typedef T* E;
struct S {
    std::vector<E> v;
    int n;
    S();
};
S::S() : n(0) {}
