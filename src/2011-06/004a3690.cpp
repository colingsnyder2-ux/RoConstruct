// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_004a3690 { int words[8]; };
extern void (__thiscall* str_ctor_004a3690)(Str_004a3690*, Str_004a3690*);
struct X_004a3690 {
    char pad[0xb0];
    Str_004a3690 value;
    Str_004a3690* copy(Str_004a3690* out);
};
Str_004a3690* X_004a3690::copy(Str_004a3690* out)
{
    volatile int zero = 0;
    str_ctor_004a3690(out, &value);
    return out;
}
