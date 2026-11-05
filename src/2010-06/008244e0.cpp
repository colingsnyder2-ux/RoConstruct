// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_008244e0 { int words[8]; };
extern void (__thiscall* str_ctor_008244e0)(Str_008244e0*, Str_008244e0*);
struct X_008244e0 {
    char pad[0x2c];
    Str_008244e0 value;
    Str_008244e0* copy(Str_008244e0* out);
};
Str_008244e0* X_008244e0::copy(Str_008244e0* out)
{
    volatile int zero = 0;
    str_ctor_008244e0(out, &value);
    return out;
}
