// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_007a3f80 { int words[8]; };
extern void (__thiscall* str_ctor_007a3f80)(Str_007a3f80*, Str_007a3f80*);
struct X_007a3f80 {
    char pad[0xc4];
    Str_007a3f80 value;
    Str_007a3f80* copy(Str_007a3f80* out);
};
Str_007a3f80* X_007a3f80::copy(Str_007a3f80* out)
{
    volatile int zero = 0;
    str_ctor_007a3f80(out, &value);
    return out;
}
