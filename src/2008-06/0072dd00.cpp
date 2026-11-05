// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0072dd00 { int words[8]; };
extern void (__thiscall* str_ctor_0072dd00)(Str_0072dd00*, Str_0072dd00*);
struct X_0072dd00 {
    char pad[0x34];
    Str_0072dd00 value;
    Str_0072dd00* copy(Str_0072dd00* out);
};
Str_0072dd00* X_0072dd00::copy(Str_0072dd00* out)
{
    volatile int zero = 0;
    str_ctor_0072dd00(out, &value);
    return out;
}
