// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_005fe2a0 { int words[8]; };
extern void (__thiscall* str_ctor_005fe2a0)(Str_005fe2a0*, Str_005fe2a0*);
struct X_005fe2a0 {
    char pad[0x28];
    Str_005fe2a0 value;
    Str_005fe2a0* copy(Str_005fe2a0* out);
};
Str_005fe2a0* X_005fe2a0::copy(Str_005fe2a0* out)
{
    volatile int zero = 0;
    str_ctor_005fe2a0(out, &value);
    return out;
}
