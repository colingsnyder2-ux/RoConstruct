// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0072dcd0 { int words[8]; };
extern void (__thiscall* str_ctor_0072dcd0)(Str_0072dcd0*, Str_0072dcd0*);
struct X_0072dcd0 {
    char pad[0x2c];
    Str_0072dcd0 value;
    Str_0072dcd0* copy(Str_0072dcd0* out);
};
Str_0072dcd0* X_0072dcd0::copy(Str_0072dcd0* out)
{
    volatile int zero = 0;
    str_ctor_0072dcd0(out, &value);
    return out;
}
