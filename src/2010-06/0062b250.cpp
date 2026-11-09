// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0062b250 { int words[8]; };
extern void (__thiscall* str_ctor_0062b250)(Str_0062b250*, Str_0062b250*);
struct X_0062b250 {
    char pad[0xbc];
    Str_0062b250 value;
    Str_0062b250* copy(Str_0062b250* out);
};
Str_0062b250* X_0062b250::copy(Str_0062b250* out)
{
    volatile int zero = 0;
    str_ctor_0062b250(out, &value);
    return out;
}
