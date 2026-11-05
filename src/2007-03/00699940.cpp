// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00699940 { int words[8]; };
extern void (__thiscall* str_ctor_00699940)(Str_00699940*, Str_00699940*);
struct X_00699940 {
    char pad[0x84];
    Str_00699940 value;
    Str_00699940* copy(Str_00699940* out);
};
Str_00699940* X_00699940::copy(Str_00699940* out)
{
    volatile int zero = 0;
    str_ctor_00699940(out, &value);
    return out;
}
