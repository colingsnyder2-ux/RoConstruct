// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0041ade0 { int words[8]; };
extern void (__thiscall* str_ctor_0041ade0)(Str_0041ade0*, Str_0041ade0*);
struct X_0041ade0 {
    char pad[0x74];
    Str_0041ade0 value;
    Str_0041ade0* copy(Str_0041ade0* out);
};
Str_0041ade0* X_0041ade0::copy(Str_0041ade0* out)
{
    volatile int zero = 0;
    str_ctor_0041ade0(out, &value);
    return out;
}
