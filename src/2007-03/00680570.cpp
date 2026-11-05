// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00680570 { int words[8]; };
extern void (__thiscall* str_ctor_00680570)(Str_00680570*, Str_00680570*);
struct X_00680570 {
    char pad[0x14];
    Str_00680570 value;
    Str_00680570* copy(Str_00680570* out);
};
Str_00680570* X_00680570::copy(Str_00680570* out)
{
    volatile int zero = 0;
    str_ctor_00680570(out, &value);
    return out;
}
