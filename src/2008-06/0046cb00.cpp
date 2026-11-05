// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0046cb00 { int words[8]; };
extern void (__thiscall* str_ctor_0046cb00)(Str_0046cb00*, Str_0046cb00*);
struct X_0046cb00 {
    char pad[0x3c];
    Str_0046cb00 value;
    Str_0046cb00* copy(Str_0046cb00* out);
};
Str_0046cb00* X_0046cb00::copy(Str_0046cb00* out)
{
    volatile int zero = 0;
    str_ctor_0046cb00(out, &value);
    return out;
}
