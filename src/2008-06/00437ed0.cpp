// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00437ed0 { int words[8]; };
extern void (__thiscall* str_ctor_00437ed0)(Str_00437ed0*, Str_00437ed0*);
struct X_00437ed0 {
    char pad[0xa4];
    Str_00437ed0 value;
    Str_00437ed0* copy(Str_00437ed0* out);
};
Str_00437ed0* X_00437ed0::copy(Str_00437ed0* out)
{
    volatile int zero = 0;
    str_ctor_00437ed0(out, &value);
    return out;
}
