// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_005e61c0 { int words[8]; };
extern void (__thiscall* str_ctor_005e61c0)(Str_005e61c0*, Str_005e61c0*);
struct X_005e61c0 {
    char pad[0xb8c];
    Str_005e61c0 value;
    Str_005e61c0* copy(Str_005e61c0* out);
};
Str_005e61c0* X_005e61c0::copy(Str_005e61c0* out)
{
    volatile int zero = 0;
    str_ctor_005e61c0(out, &value);
    return out;
}
