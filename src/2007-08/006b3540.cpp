// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006b3540 { int words[8]; };
extern void (__thiscall* str_ctor_006b3540)(Str_006b3540*, Str_006b3540*);
struct X_006b3540 {
    char pad[0x2c];
    Str_006b3540 value;
    Str_006b3540* copy(Str_006b3540* out);
};
Str_006b3540* X_006b3540::copy(Str_006b3540* out)
{
    volatile int zero = 0;
    str_ctor_006b3540(out, &value);
    return out;
}
