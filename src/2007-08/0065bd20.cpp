// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0065bd20 { int words[8]; };
extern void (__thiscall* str_ctor_0065bd20)(Str_0065bd20*, Str_0065bd20*);
struct X_0065bd20 {
    char pad[0x1fc];
    Str_0065bd20 value;
    Str_0065bd20* copy(Str_0065bd20* out);
};
Str_0065bd20* X_0065bd20::copy(Str_0065bd20* out)
{
    volatile int zero = 0;
    str_ctor_0065bd20(out, &value);
    return out;
}
