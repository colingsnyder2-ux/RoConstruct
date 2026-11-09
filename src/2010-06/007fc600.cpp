// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_007fc600 { int words[8]; };
extern void (__thiscall* str_ctor_007fc600)(Str_007fc600*, Str_007fc600*);
struct X_007fc600 {
    char pad[0xf0];
    Str_007fc600 value;
    Str_007fc600* copy(Str_007fc600* out);
};
Str_007fc600* X_007fc600::copy(Str_007fc600* out)
{
    volatile int zero = 0;
    str_ctor_007fc600(out, &value);
    return out;
}
