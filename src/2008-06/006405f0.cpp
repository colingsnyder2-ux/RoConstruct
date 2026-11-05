// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006405f0 { int words[8]; };
extern void (__thiscall* str_ctor_006405f0)(Str_006405f0*, Str_006405f0*);
struct X_006405f0 {
    char pad[0x24];
    Str_006405f0 value;
    Str_006405f0* copy(Str_006405f0* out);
};
Str_006405f0* X_006405f0::copy(Str_006405f0* out)
{
    volatile int zero = 0;
    str_ctor_006405f0(out, &value);
    return out;
}
