// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0044cfd0 { int words[8]; };
extern void (__thiscall* str_ctor_0044cfd0)(Str_0044cfd0*, Str_0044cfd0*);
struct X_0044cfd0 {
    char pad[0xe8];
    Str_0044cfd0 value;
    Str_0044cfd0* copy(Str_0044cfd0* out);
};
Str_0044cfd0* X_0044cfd0::copy(Str_0044cfd0* out)
{
    volatile int zero = 0;
    str_ctor_0044cfd0(out, &value);
    return out;
}
