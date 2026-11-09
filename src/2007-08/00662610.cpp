// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00662610 { int words[8]; };
extern void (__thiscall* str_ctor_00662610)(Str_00662610*, Str_00662610*);
struct X_00662610 {
    char pad[0x7c];
    Str_00662610 value;
    Str_00662610* copy(Str_00662610* out);
};
Str_00662610* X_00662610::copy(Str_00662610* out)
{
    volatile int zero = 0;
    str_ctor_00662610(out, &value);
    return out;
}
