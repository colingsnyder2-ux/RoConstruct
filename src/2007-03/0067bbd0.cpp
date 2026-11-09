// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0067bbd0 { int words[8]; };
extern void (__thiscall* str_ctor_0067bbd0)(Str_0067bbd0*, Str_0067bbd0*);
struct X_0067bbd0 {
    char pad[0x30];
    Str_0067bbd0 value;
    Str_0067bbd0* copy(Str_0067bbd0* out);
};
Str_0067bbd0* X_0067bbd0::copy(Str_0067bbd0* out)
{
    volatile int zero = 0;
    str_ctor_0067bbd0(out, &value);
    return out;
}
