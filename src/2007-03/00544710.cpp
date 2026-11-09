// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00544710 { int words[8]; };
extern void (__thiscall* str_ctor_00544710)(Str_00544710*, Str_00544710*);
struct X_00544710 {
    char pad[0x2c];
    Str_00544710 value;
    Str_00544710* copy(Str_00544710* out);
};
Str_00544710* X_00544710::copy(Str_00544710* out)
{
    volatile int zero = 0;
    str_ctor_00544710(out, &value);
    return out;
}
