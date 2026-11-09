// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0076d780 { int words[8]; };
extern void (__thiscall* str_ctor_0076d780)(Str_0076d780*, Str_0076d780*);
struct X_0076d780 {
    char pad[0xf0];
    Str_0076d780 value;
    Str_0076d780* copy(Str_0076d780* out);
};
Str_0076d780* X_0076d780::copy(Str_0076d780* out)
{
    volatile int zero = 0;
    str_ctor_0076d780(out, &value);
    return out;
}
