// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0086bef0 { int words[8]; };
extern void (__thiscall* str_ctor_0086bef0)(Str_0086bef0*, Str_0086bef0*);
struct X_0086bef0 {
    char pad[0x40];
    Str_0086bef0 value;
    Str_0086bef0* copy(Str_0086bef0* out);
};
Str_0086bef0* X_0086bef0::copy(Str_0086bef0* out)
{
    volatile int zero = 0;
    str_ctor_0086bef0(out, &value);
    return out;
}
