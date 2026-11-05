// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0064e3e0 { int words[8]; };
extern void (__thiscall* str_ctor_0064e3e0)(Str_0064e3e0*, Str_0064e3e0*);
struct X_0064e3e0 {
    char pad[0x7c];
    Str_0064e3e0 value;
    Str_0064e3e0* copy(Str_0064e3e0* out);
};
Str_0064e3e0* X_0064e3e0::copy(Str_0064e3e0* out)
{
    volatile int zero = 0;
    str_ctor_0064e3e0(out, &value);
    return out;
}
