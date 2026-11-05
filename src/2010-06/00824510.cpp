// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00824510 { int words[8]; };
extern void (__thiscall* str_ctor_00824510)(Str_00824510*, Str_00824510*);
struct X_00824510 {
    char pad[0x34];
    Str_00824510 value;
    Str_00824510* copy(Str_00824510* out);
};
Str_00824510* X_00824510::copy(Str_00824510* out)
{
    volatile int zero = 0;
    str_ctor_00824510(out, &value);
    return out;
}
