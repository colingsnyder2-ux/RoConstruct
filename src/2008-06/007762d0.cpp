// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_007762d0 { int words[8]; };
extern void (__thiscall* str_ctor_007762d0)(Str_007762d0*, Str_007762d0*);
struct X_007762d0 {
    char pad[0x20];
    Str_007762d0 value;
    Str_007762d0* copy(Str_007762d0* out);
};
Str_007762d0* X_007762d0::copy(Str_007762d0* out)
{
    volatile int zero = 0;
    str_ctor_007762d0(out, &value);
    return out;
}
