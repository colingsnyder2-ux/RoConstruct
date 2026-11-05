// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0042e700 { int words[8]; };
extern void (__thiscall* str_ctor_0042e700)(Str_0042e700*, Str_0042e700*);
struct X_0042e700 {
    char pad[0x44];
    Str_0042e700 value;
    Str_0042e700* copy(Str_0042e700* out);
};
Str_0042e700* X_0042e700::copy(Str_0042e700* out)
{
    volatile int zero = 0;
    str_ctor_0042e700(out, &value);
    return out;
}
