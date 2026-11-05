// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00881570 { int words[8]; };
extern void (__thiscall* str_ctor_00881570)(Str_00881570*, Str_00881570*);
struct X_00881570 {
    char pad[0x2c];
    Str_00881570 value;
    Str_00881570* copy(Str_00881570* out);
};
Str_00881570* X_00881570::copy(Str_00881570* out)
{
    volatile int zero = 0;
    str_ctor_00881570(out, &value);
    return out;
}
