// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006763d0 { int words[8]; };
extern void (__thiscall* str_ctor_006763d0)(Str_006763d0*, Str_006763d0*);
struct X_006763d0 {
    char pad[0xf0];
    Str_006763d0 value;
    Str_006763d0* copy(Str_006763d0* out);
};
Str_006763d0* X_006763d0::copy(Str_006763d0* out)
{
    volatile int zero = 0;
    str_ctor_006763d0(out, &value);
    return out;
}
