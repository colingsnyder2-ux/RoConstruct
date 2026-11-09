// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_008323c0 { int words[8]; };
extern void (__thiscall* str_ctor_008323c0)(Str_008323c0*, Str_008323c0*);
struct X_008323c0 {
    char pad[0xc4];
    Str_008323c0 value;
    Str_008323c0* copy(Str_008323c0* out);
};
Str_008323c0* X_008323c0::copy(Str_008323c0* out)
{
    volatile int zero = 0;
    str_ctor_008323c0(out, &value);
    return out;
}
