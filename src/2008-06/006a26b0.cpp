// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006a26b0 { int words[8]; };
extern void (__thiscall* str_ctor_006a26b0)(Str_006a26b0*, Str_006a26b0*);
struct X_006a26b0 {
    char pad[0xf4];
    Str_006a26b0 value;
    Str_006a26b0* copy(Str_006a26b0* out);
};
Str_006a26b0* X_006a26b0::copy(Str_006a26b0* out)
{
    volatile int zero = 0;
    str_ctor_006a26b0(out, &value);
    return out;
}
