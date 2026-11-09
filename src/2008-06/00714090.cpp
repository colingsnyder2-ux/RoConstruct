// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00714090 { int words[8]; };
extern void (__thiscall* str_ctor_00714090)(Str_00714090*, Str_00714090*);
struct X_00714090 {
    char pad[0x54];
    Str_00714090 value;
    Str_00714090* copy(Str_00714090* out);
};
Str_00714090* X_00714090::copy(Str_00714090* out)
{
    volatile int zero = 0;
    str_ctor_00714090(out, &value);
    return out;
}
