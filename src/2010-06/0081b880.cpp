// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0081b880 { int words[8]; };
extern void (__thiscall* str_ctor_0081b880)(Str_0081b880*, Str_0081b880*);
struct X_0081b880 {
    char pad[0xb4];
    Str_0081b880 value;
    Str_0081b880* copy(Str_0081b880* out);
};
Str_0081b880* X_0081b880::copy(Str_0081b880* out)
{
    volatile int zero = 0;
    str_ctor_0081b880(out, &value);
    return out;
}
