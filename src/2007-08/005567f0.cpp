// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_005567f0 { int words[8]; };
extern void (__thiscall* str_ctor_005567f0)(Str_005567f0*, Str_005567f0*);
struct X_005567f0 {
    char pad[0xfc];
    Str_005567f0 value;
    Str_005567f0* copy(Str_005567f0* out);
};
Str_005567f0* X_005567f0::copy(Str_005567f0* out)
{
    volatile int zero = 0;
    str_ctor_005567f0(out, &value);
    return out;
}
