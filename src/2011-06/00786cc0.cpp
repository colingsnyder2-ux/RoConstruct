// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00786cc0 { int words[8]; };
extern void (__thiscall* str_ctor_00786cc0)(Str_00786cc0*, Str_00786cc0*);
struct X_00786cc0 {
    char pad[0x68];
    Str_00786cc0 value;
    Str_00786cc0* copy(Str_00786cc0* out);
};
Str_00786cc0* X_00786cc0::copy(Str_00786cc0* out)
{
    volatile int zero = 0;
    str_ctor_00786cc0(out, &value);
    return out;
}
