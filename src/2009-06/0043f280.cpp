// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct B_0043f280 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[0x8c - 0x24];
    B_0043f280();
};
struct X_0043f280 : B_0043f280 {
    void* f_8c;
    X_0043f280();
};
X_0043f280::X_0043f280()
{
    f_0 = (void*)0x8b5fa4;
    f_14 = (void*)0x8b5f98;
    f_18 = (void*)0x8b5f90;
    f_20 = (void*)0x8b5f88;
    f_8c = 0;
}
