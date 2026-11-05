// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00848ad0 { int words[8]; };
extern void (__thiscall* str_ctor_00848ad0)(Str_00848ad0*, Str_00848ad0*);
struct X_00848ad0 {
    char pad[0x98];
    Str_00848ad0 value;
    Str_00848ad0* copy(Str_00848ad0* out);
};
Str_00848ad0* X_00848ad0::copy(Str_00848ad0* out)
{
    volatile int zero = 0;
    str_ctor_00848ad0(out, &value);
    return out;
}
