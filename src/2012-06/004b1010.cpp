// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_004b1010 { int words[8]; };
extern void (__thiscall* str_ctor_004b1010)(Str_004b1010*, Str_004b1010*);
struct X_004b1010 {
    char pad[0x84];
    Str_004b1010 value;
    Str_004b1010* copy(Str_004b1010* out);
};
Str_004b1010* X_004b1010::copy(Str_004b1010* out)
{
    volatile int zero = 0;
    str_ctor_004b1010(out, &value);
    return out;
}
