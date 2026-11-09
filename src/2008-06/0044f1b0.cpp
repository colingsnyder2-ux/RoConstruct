// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0044f1b0 { int words[8]; };
extern void (__thiscall* str_ctor_0044f1b0)(Str_0044f1b0*, Str_0044f1b0*);
struct X_0044f1b0 {
    char pad[0x130];
    Str_0044f1b0 value;
    Str_0044f1b0* copy(Str_0044f1b0* out);
};
Str_0044f1b0* X_0044f1b0::copy(Str_0044f1b0* out)
{
    volatile int zero = 0;
    str_ctor_0044f1b0(out, &value);
    return out;
}
