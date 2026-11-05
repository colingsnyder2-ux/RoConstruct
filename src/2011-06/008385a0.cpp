// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_008385a0 { int words[8]; };
extern void (__thiscall* str_ctor_008385a0)(Str_008385a0*, Str_008385a0*);
struct X_008385a0 {
    char pad[0x280];
    Str_008385a0 value;
    Str_008385a0* copy(Str_008385a0* out);
};
Str_008385a0* X_008385a0::copy(Str_008385a0* out)
{
    volatile int zero = 0;
    str_ctor_008385a0(out, &value);
    return out;
}
