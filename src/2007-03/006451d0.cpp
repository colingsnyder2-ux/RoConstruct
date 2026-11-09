// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006451d0 { int words[8]; };
extern void (__thiscall* str_ctor_006451d0)(Str_006451d0*, Str_006451d0*);
struct X_006451d0 {
    char pad[0x1f4];
    Str_006451d0 value;
    Str_006451d0* copy(Str_006451d0* out);
};
Str_006451d0* X_006451d0::copy(Str_006451d0* out)
{
    volatile int zero = 0;
    str_ctor_006451d0(out, &value);
    return out;
}
