// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0077f730 { int words[8]; };
extern void (__thiscall* str_ctor_0077f730)(Str_0077f730*, Str_0077f730*);
struct X_0077f730 {
    char pad[0x40];
    Str_0077f730 value;
    Str_0077f730* copy(Str_0077f730* out);
};
Str_0077f730* X_0077f730::copy(Str_0077f730* out)
{
    volatile int zero = 0;
    str_ctor_0077f730(out, &value);
    return out;
}
