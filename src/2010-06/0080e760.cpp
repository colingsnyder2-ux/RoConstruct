// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0080e760 { int words[8]; };
extern void (__thiscall* str_ctor_0080e760)(Str_0080e760*, Str_0080e760*);
struct X_0080e760 {
    char pad[0x40];
    Str_0080e760 value;
    Str_0080e760* copy(Str_0080e760* out);
};
Str_0080e760* X_0080e760::copy(Str_0080e760* out)
{
    volatile int zero = 0;
    str_ctor_0080e760(out, &value);
    return out;
}
