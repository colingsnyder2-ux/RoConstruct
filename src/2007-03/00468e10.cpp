// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00468e10 { int words[8]; };
extern void (__thiscall* str_ctor_00468e10)(Str_00468e10*, Str_00468e10*);
struct X_00468e10 {
    char pad[0x3c];
    Str_00468e10 value;
    Str_00468e10* copy(Str_00468e10* out);
};
Str_00468e10* X_00468e10::copy(Str_00468e10* out)
{
    volatile int zero = 0;
    str_ctor_00468e10(out, &value);
    return out;
}
