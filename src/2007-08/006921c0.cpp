// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006921c0 { int words[8]; };
extern void (__thiscall* str_ctor_006921c0)(Str_006921c0*, Str_006921c0*);
struct X_006921c0 {
    char pad[0x30];
    Str_006921c0 value;
    Str_006921c0* copy(Str_006921c0* out);
};
Str_006921c0* X_006921c0::copy(Str_006921c0* out)
{
    volatile int zero = 0;
    str_ctor_006921c0(out, &value);
    return out;
}
