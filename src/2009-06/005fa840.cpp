// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_005fa840 { int words[8]; };
extern void (__thiscall* str_ctor_005fa840)(Str_005fa840*, Str_005fa840*);
struct X_005fa840 {
    char pad[0x2c0];
    Str_005fa840 value;
    Str_005fa840* copy(Str_005fa840* out);
};
Str_005fa840* X_005fa840::copy(Str_005fa840* out)
{
    volatile int zero = 0;
    str_ctor_005fa840(out, &value);
    return out;
}
