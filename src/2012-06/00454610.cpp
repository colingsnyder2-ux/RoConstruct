// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00454610 { int words[8]; };
extern void (__thiscall* str_ctor_00454610)(Str_00454610*, Str_00454610*);
struct X_00454610 {
    char pad[0xac];
    Str_00454610 value;
    Str_00454610* copy(Str_00454610* out);
};
Str_00454610* X_00454610::copy(Str_00454610* out)
{
    volatile int zero = 0;
    str_ctor_00454610(out, &value);
    return out;
}
