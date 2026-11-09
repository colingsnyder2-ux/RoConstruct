// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00841340 { int words[8]; };
extern void (__thiscall* str_ctor_00841340)(Str_00841340*, Str_00841340*);
struct X_00841340 {
    char pad[0x7c];
    Str_00841340 value;
    Str_00841340* copy(Str_00841340* out);
};
Str_00841340* X_00841340::copy(Str_00841340* out)
{
    volatile int zero = 0;
    str_ctor_00841340(out, &value);
    return out;
}
