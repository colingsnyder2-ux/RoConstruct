// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_007b3bf0 { int words[8]; };
extern void (__thiscall* str_ctor_007b3bf0)(Str_007b3bf0*, Str_007b3bf0*);
struct X_007b3bf0 {
    char pad[0x54];
    Str_007b3bf0 value;
    Str_007b3bf0* copy(Str_007b3bf0* out);
};
Str_007b3bf0* X_007b3bf0::copy(Str_007b3bf0* out)
{
    volatile int zero = 0;
    str_ctor_007b3bf0(out, &value);
    return out;
}
