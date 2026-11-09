// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_007140c0 { int words[8]; };
extern void (__thiscall* str_ctor_007140c0)(Str_007140c0*, Str_007140c0*);
struct X_007140c0 {
    char pad[0xb4];
    Str_007140c0 value;
    Str_007140c0* copy(Str_007140c0* out);
};
Str_007140c0* X_007140c0::copy(Str_007140c0* out)
{
    volatile int zero = 0;
    str_ctor_007140c0(out, &value);
    return out;
}
