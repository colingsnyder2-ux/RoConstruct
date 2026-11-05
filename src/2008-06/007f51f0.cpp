// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Base {
    Base();
    virtual ~Base();
    char pad[0x1c];
};
struct Derived : Base {
    Derived() { value = 0xc2; }
    virtual ~Derived();
    int value;
};
Derived g_object;
