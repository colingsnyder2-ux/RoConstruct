// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00608610 { int words[8]; };
extern void (__thiscall* str_ctor_00608610)(Str_00608610*, Str_00608610*);
struct X_00608610 {
    char pad[0xa0];
    Str_00608610 value;
    Str_00608610* copy(Str_00608610* out);
};
Str_00608610* X_00608610::copy(Str_00608610* out)
{
    volatile int zero = 0;
    str_ctor_00608610(out, &value);
    return out;
}
