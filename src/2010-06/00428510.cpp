// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00428510 { int words[8]; };
extern void (__thiscall* str_ctor_00428510)(Str_00428510*, Str_00428510*);
struct X_00428510 {
    char pad[0x44];
    Str_00428510 value;
    Str_00428510* copy(Str_00428510* out);
};
Str_00428510* X_00428510::copy(Str_00428510* out)
{
    volatile int zero = 0;
    str_ctor_00428510(out, &value);
    return out;
}
