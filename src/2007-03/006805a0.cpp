// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006805a0 { int words[8]; };
extern void (__thiscall* str_ctor_006805a0)(Str_006805a0*, Str_006805a0*);
struct X_006805a0 {
    char pad[0x10];
    Str_006805a0 value;
    Str_006805a0* copy(Str_006805a0* out);
};
Str_006805a0* X_006805a0::copy(Str_006805a0* out)
{
    volatile int zero = 0;
    str_ctor_006805a0(out, &value);
    return out;
}
