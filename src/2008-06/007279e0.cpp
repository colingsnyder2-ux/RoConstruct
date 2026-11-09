// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_007279e0 { int words[8]; };
extern void (__thiscall* str_ctor_007279e0)(Str_007279e0*, Str_007279e0*);
struct X_007279e0 {
    char pad[0x28];
    Str_007279e0 value;
    Str_007279e0* copy(Str_007279e0* out);
};
Str_007279e0* X_007279e0::copy(Str_007279e0* out)
{
    volatile int zero = 0;
    str_ctor_007279e0(out, &value);
    return out;
}
