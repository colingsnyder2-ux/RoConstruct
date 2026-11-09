// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0065ecd0 { int words[8]; };
extern void (__thiscall* str_ctor_0065ecd0)(Str_0065ecd0*, Str_0065ecd0*);
struct X_0065ecd0 {
    char pad[0x24];
    Str_0065ecd0 value;
    Str_0065ecd0* copy(Str_0065ecd0* out);
};
Str_0065ecd0* X_0065ecd0::copy(Str_0065ecd0* out)
{
    volatile int zero = 0;
    str_ctor_0065ecd0(out, &value);
    return out;
}
