// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_007358b0 { int words[8]; };
extern void (__thiscall* str_ctor_007358b0)(Str_007358b0*, Str_007358b0*);
struct X_007358b0 {
    char pad[0xc4];
    Str_007358b0 value;
    Str_007358b0* copy(Str_007358b0* out);
};
Str_007358b0* X_007358b0::copy(Str_007358b0* out)
{
    volatile int zero = 0;
    str_ctor_007358b0(out, &value);
    return out;
}
