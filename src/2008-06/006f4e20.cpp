// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006f4e20 { int words[8]; };
extern void (__thiscall* str_ctor_006f4e20)(Str_006f4e20*, Str_006f4e20*);
struct X_006f4e20 {
    char pad[0xf0];
    Str_006f4e20 value;
    Str_006f4e20* copy(Str_006f4e20* out);
};
Str_006f4e20* X_006f4e20::copy(Str_006f4e20* out)
{
    volatile int zero = 0;
    str_ctor_006f4e20(out, &value);
    return out;
}
