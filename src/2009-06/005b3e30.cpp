// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /GS- /EHsc /MD
struct Base { int p; Base(); };
struct X : Base {
    int a, b;
    X(void* v);
    void assign(void* v);
};
X::X(void* v) { assign(v); a = 0; b = 0; }
