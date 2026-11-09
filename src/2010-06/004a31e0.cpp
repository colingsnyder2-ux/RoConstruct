// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_004a31e0 { int words[8]; };
extern void (__thiscall* str_ctor_004a31e0)(Str_004a31e0*, Str_004a31e0*);
struct X_004a31e0 {
    char pad[0xc0];
    Str_004a31e0 value;
    Str_004a31e0* copy(Str_004a31e0* out);
};
Str_004a31e0* X_004a31e0::copy(Str_004a31e0* out)
{
    volatile int zero = 0;
    str_ctor_004a31e0(out, &value);
    return out;
}
