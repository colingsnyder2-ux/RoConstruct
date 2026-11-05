// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00454640 { int words[8]; };
extern void (__thiscall* str_ctor_00454640)(Str_00454640*, Str_00454640*);
struct X_00454640 {
    char pad[0xa4];
    Str_00454640 value;
    Str_00454640* copy(Str_00454640* out);
};
Str_00454640* X_00454640::copy(Str_00454640* out)
{
    volatile int zero = 0;
    str_ctor_00454640(out, &value);
    return out;
}
