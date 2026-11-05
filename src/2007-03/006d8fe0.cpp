// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006d8fe0 { int words[8]; };
extern void (__thiscall* str_ctor_006d8fe0)(Str_006d8fe0*, Str_006d8fe0*);
struct X_006d8fe0 {
    char pad[0x20];
    Str_006d8fe0 value;
    Str_006d8fe0* copy(Str_006d8fe0* out);
};
Str_006d8fe0* X_006d8fe0::copy(Str_006d8fe0* out)
{
    volatile int zero = 0;
    str_ctor_006d8fe0(out, &value);
    return out;
}
