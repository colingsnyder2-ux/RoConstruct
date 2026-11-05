// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0042f1e0 { int words[8]; };
extern void (__thiscall* str_ctor_0042f1e0)(Str_0042f1e0*, Str_0042f1e0*);
struct X_0042f1e0 {
    char pad[0x48];
    Str_0042f1e0 value;
    Str_0042f1e0* copy(Str_0042f1e0* out);
};
Str_0042f1e0* X_0042f1e0::copy(Str_0042f1e0* out)
{
    volatile int zero = 0;
    str_ctor_0042f1e0(out, &value);
    return out;
}
