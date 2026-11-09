// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00552f90 { int words[8]; };
extern void (__thiscall* str_ctor_00552f90)(Str_00552f90*, Str_00552f90*);
struct X_00552f90 {
    char pad[0x104];
    Str_00552f90 value;
    Str_00552f90* copy(Str_00552f90* out);
};
Str_00552f90* X_00552f90::copy(Str_00552f90* out)
{
    volatile int zero = 0;
    str_ctor_00552f90(out, &value);
    return out;
}
