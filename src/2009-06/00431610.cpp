// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00431610 { int words[8]; };
extern void (__thiscall* str_ctor_00431610)(Str_00431610*, Str_00431610*);
struct X_00431610 {
    char pad[0xac];
    Str_00431610 value;
    Str_00431610* copy(Str_00431610* out);
};
Str_00431610* X_00431610::copy(Str_00431610* out)
{
    volatile int zero = 0;
    str_ctor_00431610(out, &value);
    return out;
}
