// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006bdba0 { int words[8]; };
extern void (__thiscall* str_ctor_006bdba0)(Str_006bdba0*, Str_006bdba0*);
struct X_006bdba0 {
    char pad[0x74];
    Str_006bdba0 value;
    Str_006bdba0* copy(Str_006bdba0* out);
};
Str_006bdba0* X_006bdba0::copy(Str_006bdba0* out)
{
    volatile int zero = 0;
    str_ctor_006bdba0(out, &value);
    return out;
}
