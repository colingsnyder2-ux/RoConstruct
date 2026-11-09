// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_007ce130 { int words[8]; };
extern void (__thiscall* str_ctor_007ce130)(Str_007ce130*, Str_007ce130*);
struct X_007ce130 {
    char pad[0x24];
    Str_007ce130 value;
    Str_007ce130* copy(Str_007ce130* out);
};
Str_007ce130* X_007ce130::copy(Str_007ce130* out)
{
    volatile int zero = 0;
    str_ctor_007ce130(out, &value);
    return out;
}
