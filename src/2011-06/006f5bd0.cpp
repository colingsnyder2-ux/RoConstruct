// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006f5bd0 { int words[8]; };
extern void (__thiscall* str_ctor_006f5bd0)(Str_006f5bd0*, Str_006f5bd0*);
struct X_006f5bd0 {
    char pad[0xac];
    Str_006f5bd0 value;
    Str_006f5bd0* copy(Str_006f5bd0* out);
};
Str_006f5bd0* X_006f5bd0::copy(Str_006f5bd0* out)
{
    volatile int zero = 0;
    str_ctor_006f5bd0(out, &value);
    return out;
}
