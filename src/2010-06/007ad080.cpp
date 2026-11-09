// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_007ad080 { int words[8]; };
extern void (__thiscall* str_ctor_007ad080)(Str_007ad080*, Str_007ad080*);
struct X_007ad080 {
    char pad[0xf4];
    Str_007ad080 value;
    Str_007ad080* copy(Str_007ad080* out);
};
Str_007ad080* X_007ad080::copy(Str_007ad080* out)
{
    volatile int zero = 0;
    str_ctor_007ad080(out, &value);
    return out;
}
