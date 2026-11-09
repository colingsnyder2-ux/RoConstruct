// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006f4270 { int words[8]; };
extern void (__thiscall* str_ctor_006f4270)(Str_006f4270*, Str_006f4270*);
struct X_006f4270 {
    char pad[0x98];
    Str_006f4270 value;
    Str_006f4270* copy(Str_006f4270* out);
};
Str_006f4270* X_006f4270::copy(Str_006f4270* out)
{
    volatile int zero = 0;
    str_ctor_006f4270(out, &value);
    return out;
}
