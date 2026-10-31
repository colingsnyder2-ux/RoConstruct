// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Base { virtual void a(); virtual void b(); virtual char* c(); };
struct S : Base {
    char* f();
};

char* S::f() {
    return c() + 0x98;
}
