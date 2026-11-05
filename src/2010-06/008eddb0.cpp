// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_008eddb0 { int words[8]; };
extern void (__thiscall* str_ctor_008eddb0)(Str_008eddb0*, Str_008eddb0*);
struct X_008eddb0 {
    char pad[0xc];
    Str_008eddb0 value;
    Str_008eddb0* copy(Str_008eddb0* out);
};
Str_008eddb0* X_008eddb0::copy(Str_008eddb0* out)
{
    volatile int zero = 0;
    str_ctor_008eddb0(out, &value);
    return out;
}
