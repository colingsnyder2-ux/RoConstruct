// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0049bda0 { int words[8]; };
extern void (__thiscall* str_ctor_0049bda0)(Str_0049bda0*, Str_0049bda0*);
struct X_0049bda0 {
    char pad[0x94];
    Str_0049bda0 value;
    Str_0049bda0* copy(Str_0049bda0* out);
};
Str_0049bda0* X_0049bda0::copy(Str_0049bda0* out)
{
    volatile int zero = 0;
    str_ctor_0049bda0(out, &value);
    return out;
}
