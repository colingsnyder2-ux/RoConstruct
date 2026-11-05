// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0061ff40 { int words[8]; };
extern void (__thiscall* str_ctor_0061ff40)(Str_0061ff40*, Str_0061ff40*);
struct X_0061ff40 {
    char pad[0x54];
    Str_0061ff40 value;
    Str_0061ff40* copy(Str_0061ff40* out);
};
Str_0061ff40* X_0061ff40::copy(Str_0061ff40* out)
{
    volatile int zero = 0;
    str_ctor_0061ff40(out, &value);
    return out;
}
