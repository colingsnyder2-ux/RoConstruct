// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_004350b0 { int words[8]; };
extern void (__thiscall* str_ctor_004350b0)(Str_004350b0*, Str_004350b0*);
struct X_004350b0 {
    char pad[0x44];
    Str_004350b0 value;
    Str_004350b0* copy(Str_004350b0* out);
};
Str_004350b0* X_004350b0::copy(Str_004350b0* out)
{
    volatile int zero = 0;
    str_ctor_004350b0(out, &value);
    return out;
}
