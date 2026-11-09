// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00438e30 { int words[8]; };
extern void (__thiscall* str_ctor_00438e30)(Str_00438e30*, Str_00438e30*);
struct X_00438e30 {
    char pad[0xa0];
    Str_00438e30 value;
    Str_00438e30* copy(Str_00438e30* out);
};
Str_00438e30* X_00438e30::copy(Str_00438e30* out)
{
    volatile int zero = 0;
    str_ctor_00438e30(out, &value);
    return out;
}
