// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00631ad0 { int words[8]; };
extern void (__thiscall* str_ctor_00631ad0)(Str_00631ad0*, Str_00631ad0*);
struct X_00631ad0 {
    char pad[0xf0];
    Str_00631ad0 value;
    Str_00631ad0* copy(Str_00631ad0* out);
};
Str_00631ad0* X_00631ad0::copy(Str_00631ad0* out)
{
    volatile int zero = 0;
    str_ctor_00631ad0(out, &value);
    return out;
}
