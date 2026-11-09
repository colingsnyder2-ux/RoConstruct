// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_005ccee0 { int words[8]; };
extern void (__thiscall* str_ctor_005ccee0)(Str_005ccee0*, Str_005ccee0*);
struct X_005ccee0 {
    char pad[0x20];
    Str_005ccee0 value;
    Str_005ccee0* copy(Str_005ccee0* out);
};
Str_005ccee0* X_005ccee0::copy(Str_005ccee0* out)
{
    volatile int zero = 0;
    str_ctor_005ccee0(out, &value);
    return out;
}
