// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_004430f0 { int words[8]; };
extern void (__thiscall* str_ctor_004430f0)(Str_004430f0*, Str_004430f0*);
struct X_004430f0 {
    char pad[0xa4];
    Str_004430f0 value;
    Str_004430f0* copy(Str_004430f0* out);
};
Str_004430f0* X_004430f0::copy(Str_004430f0* out)
{
    volatile int zero = 0;
    str_ctor_004430f0(out, &value);
    return out;
}
