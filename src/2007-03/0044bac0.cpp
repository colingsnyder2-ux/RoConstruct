// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0044bac0 { int words[8]; };
extern void (__thiscall* str_ctor_0044bac0)(Str_0044bac0*, Str_0044bac0*);
struct X_0044bac0 {
    char pad[0xf0];
    Str_0044bac0 value;
    Str_0044bac0* copy(Str_0044bac0* out);
};
Str_0044bac0* X_0044bac0::copy(Str_0044bac0* out)
{
    volatile int zero = 0;
    str_ctor_0044bac0(out, &value);
    return out;
}
