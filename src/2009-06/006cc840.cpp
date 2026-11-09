// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006cc840 { int words[8]; };
extern void (__thiscall* str_ctor_006cc840)(Str_006cc840*, Str_006cc840*);
struct X_006cc840 {
    char pad[0x1c];
    Str_006cc840 value;
    Str_006cc840* copy(Str_006cc840* out);
};
Str_006cc840* X_006cc840::copy(Str_006cc840* out)
{
    volatile int zero = 0;
    str_ctor_006cc840(out, &value);
    return out;
}
