// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0062b2c0 { int words[8]; };
extern void (__thiscall* str_ctor_0062b2c0)(Str_0062b2c0*, Str_0062b2c0*);
struct X_0062b2c0 {
    char pad[0xec];
    Str_0062b2c0 value;
    Str_0062b2c0* copy(Str_0062b2c0* out);
};
Str_0062b2c0* X_0062b2c0::copy(Str_0062b2c0* out)
{
    volatile int zero = 0;
    str_ctor_0062b2c0(out, &value);
    return out;
}
