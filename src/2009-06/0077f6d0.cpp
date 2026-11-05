// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0077f6d0 { int words[8]; };
extern void (__thiscall* str_ctor_0077f6d0)(Str_0077f6d0*, Str_0077f6d0*);
struct X_0077f6d0 {
    char pad[0x30];
    Str_0077f6d0 value;
    Str_0077f6d0* copy(Str_0077f6d0* out);
};
Str_0077f6d0* X_0077f6d0::copy(Str_0077f6d0* out)
{
    volatile int zero = 0;
    str_ctor_0077f6d0(out, &value);
    return out;
}
