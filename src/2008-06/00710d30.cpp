// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00710d30 { int words[8]; };
extern void (__thiscall* str_ctor_00710d30)(Str_00710d30*, Str_00710d30*);
struct X_00710d30 {
    char pad[0xb0];
    Str_00710d30 value;
    Str_00710d30* copy(Str_00710d30* out);
};
Str_00710d30* X_00710d30::copy(Str_00710d30* out)
{
    volatile int zero = 0;
    str_ctor_00710d30(out, &value);
    return out;
}
