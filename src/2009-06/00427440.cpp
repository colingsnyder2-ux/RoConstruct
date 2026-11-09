// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00427440 { int words[8]; };
extern void (__thiscall* str_ctor_00427440)(Str_00427440*, Str_00427440*);
struct X_00427440 {
    char pad[0x48];
    Str_00427440 value;
    Str_00427440* copy(Str_00427440* out);
};
Str_00427440* X_00427440::copy(Str_00427440* out)
{
    volatile int zero = 0;
    str_ctor_00427440(out, &value);
    return out;
}
