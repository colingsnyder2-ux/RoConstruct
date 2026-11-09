// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0064b070 { int words[8]; };
extern void (__thiscall* str_ctor_0064b070)(Str_0064b070*, Str_0064b070*);
struct X_0064b070 {
    char pad[0x24];
    Str_0064b070 value;
    Str_0064b070* copy(Str_0064b070* out);
};
Str_0064b070* X_0064b070::copy(Str_0064b070* out)
{
    volatile int zero = 0;
    str_ctor_0064b070(out, &value);
    return out;
}
