// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00437ea0 { int words[8]; };
extern void (__thiscall* str_ctor_00437ea0)(Str_00437ea0*, Str_00437ea0*);
struct X_00437ea0 {
    char pad[0xac];
    Str_00437ea0 value;
    Str_00437ea0* copy(Str_00437ea0* out);
};
Str_00437ea0* X_00437ea0::copy(Str_00437ea0* out)
{
    volatile int zero = 0;
    str_ctor_00437ea0(out, &value);
    return out;
}
