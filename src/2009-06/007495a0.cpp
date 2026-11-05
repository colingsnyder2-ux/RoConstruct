// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_007495a0 { int words[8]; };
extern void (__thiscall* str_ctor_007495a0)(Str_007495a0*, Str_007495a0*);
struct X_007495a0 {
    char pad[0x280];
    Str_007495a0 value;
    Str_007495a0* copy(Str_007495a0* out);
};
Str_007495a0* X_007495a0::copy(Str_007495a0* out)
{
    volatile int zero = 0;
    str_ctor_007495a0(out, &value);
    return out;
}
