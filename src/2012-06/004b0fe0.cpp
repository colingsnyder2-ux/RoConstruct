// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_004b0fe0 { int words[8]; };
extern void (__thiscall* str_ctor_004b0fe0)(Str_004b0fe0*, Str_004b0fe0*);
struct X_004b0fe0 {
    char pad[0xcb0];
    Str_004b0fe0 value;
    Str_004b0fe0* copy(Str_004b0fe0* out);
};
Str_004b0fe0* X_004b0fe0::copy(Str_004b0fe0* out)
{
    volatile int zero = 0;
    str_ctor_004b0fe0(out, &value);
    return out;
}
