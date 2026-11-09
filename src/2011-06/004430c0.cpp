// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_004430c0 { int words[8]; };
extern void (__thiscall* str_ctor_004430c0)(Str_004430c0*, Str_004430c0*);
struct X_004430c0 {
    char pad[0xac];
    Str_004430c0 value;
    Str_004430c0* copy(Str_004430c0* out);
};
Str_004430c0* X_004430c0::copy(Str_004430c0* out)
{
    volatile int zero = 0;
    str_ctor_004430c0(out, &value);
    return out;
}
