// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006a63e0 { int words[8]; };
extern void (__thiscall* str_ctor_006a63e0)(Str_006a63e0*, Str_006a63e0*);
struct X_006a63e0 {
    char pad[0xc4];
    Str_006a63e0 value;
    Str_006a63e0* copy(Str_006a63e0* out);
};
Str_006a63e0* X_006a63e0::copy(Str_006a63e0* out)
{
    volatile int zero = 0;
    str_ctor_006a63e0(out, &value);
    return out;
}
