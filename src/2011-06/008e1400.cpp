// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_008e1400 { int words[8]; };
extern void (__thiscall* str_ctor_008e1400)(Str_008e1400*, Str_008e1400*);
struct X_008e1400 {
    char pad[0x20];
    Str_008e1400 value;
    Str_008e1400* copy(Str_008e1400* out);
};
Str_008e1400* X_008e1400::copy(Str_008e1400* out)
{
    volatile int zero = 0;
    str_ctor_008e1400(out, &value);
    return out;
}
