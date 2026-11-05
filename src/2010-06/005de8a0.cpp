// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_005de8a0 { int words[8]; };
extern void (__thiscall* str_ctor_005de8a0)(Str_005de8a0*, Str_005de8a0*);
struct X_005de8a0 {
    char pad[0xa8];
    Str_005de8a0 value;
    Str_005de8a0* copy(Str_005de8a0* out);
};
Str_005de8a0* X_005de8a0::copy(Str_005de8a0* out)
{
    volatile int zero = 0;
    str_ctor_005de8a0(out, &value);
    return out;
}
