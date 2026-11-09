// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0087d740 { int words[8]; };
extern void (__thiscall* str_ctor_0087d740)(Str_0087d740*, Str_0087d740*);
struct X_0087d740 {
    char pad[0x48];
    Str_0087d740 value;
    Str_0087d740* copy(Str_0087d740* out);
};
Str_0087d740* X_0087d740::copy(Str_0087d740* out)
{
    volatile int zero = 0;
    str_ctor_0087d740(out, &value);
    return out;
}
