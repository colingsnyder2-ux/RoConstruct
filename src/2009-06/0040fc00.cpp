// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0040fc00 { int words[8]; };
extern void (__thiscall* str_ctor_0040fc00)(Str_0040fc00*, Str_0040fc00*);
struct X_0040fc00 {
    char pad[0x54];
    Str_0040fc00 value;
    Str_0040fc00* copy(Str_0040fc00* out);
};
Str_0040fc00* X_0040fc00::copy(Str_0040fc00* out)
{
    volatile int zero = 0;
    str_ctor_0040fc00(out, &value);
    return out;
}
