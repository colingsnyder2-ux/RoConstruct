// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00789550 { int words[8]; };
extern void (__thiscall* str_ctor_00789550)(Str_00789550*, Str_00789550*);
struct X_00789550 {
    char pad[0xb0];
    Str_00789550 value;
    Str_00789550* copy(Str_00789550* out);
};
Str_00789550* X_00789550::copy(Str_00789550* out)
{
    volatile int zero = 0;
    str_ctor_00789550(out, &value);
    return out;
}
