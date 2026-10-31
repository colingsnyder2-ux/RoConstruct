// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /GS- /EHsc /MD
struct S_005bacd0 { int* p; int* f(int); };
int* S_005bacd0::f(int i) { return (int*)((char*)p + i); }
