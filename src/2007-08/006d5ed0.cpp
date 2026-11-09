// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006d5ed0 { int words[8]; };
extern void (__thiscall* str_ctor_006d5ed0)(Str_006d5ed0*, Str_006d5ed0*);
struct X_006d5ed0 {
    char pad[0x70];
    Str_006d5ed0 value;
    Str_006d5ed0* copy(Str_006d5ed0* out);
};
Str_006d5ed0* X_006d5ed0::copy(Str_006d5ed0* out)
{
    volatile int zero = 0;
    str_ctor_006d5ed0(out, &value);
    return out;
}
