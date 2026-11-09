// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_004339c0 { int words[8]; };
extern void (__thiscall* str_ctor_004339c0)(Str_004339c0*, Str_004339c0*);
struct X_004339c0 {
    char pad[0xac];
    Str_004339c0 value;
    Str_004339c0* copy(Str_004339c0* out);
};
Str_004339c0* X_004339c0::copy(Str_004339c0* out)
{
    volatile int zero = 0;
    str_ctor_004339c0(out, &value);
    return out;
}
