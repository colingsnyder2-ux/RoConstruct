// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_005e6420 { int words[8]; };
extern void (__thiscall* str_ctor_005e6420)(Str_005e6420*, Str_005e6420*);
struct X_005e6420 {
    char pad[0xc84];
    Str_005e6420 value;
    Str_005e6420* copy(Str_005e6420* out);
};
Str_005e6420* X_005e6420::copy(Str_005e6420* out)
{
    volatile int zero = 0;
    str_ctor_005e6420(out, &value);
    return out;
}
