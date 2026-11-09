// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006df3a0 { int words[8]; };
extern void (__thiscall* str_ctor_006df3a0)(Str_006df3a0*, Str_006df3a0*);
struct X_006df3a0 {
    char pad[0x4];
    Str_006df3a0 value;
    Str_006df3a0* copy(Str_006df3a0* out);
};
Str_006df3a0* X_006df3a0::copy(Str_006df3a0* out)
{
    volatile int zero = 0;
    str_ctor_006df3a0(out, &value);
    return out;
}
