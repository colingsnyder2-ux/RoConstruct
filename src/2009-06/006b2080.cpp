// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct S {
    char pad[8];
    int x;
    bool f();
};

bool sub_6b3b50(void*);

bool S::f() {
    return sub_6b3b50(&x);
}
