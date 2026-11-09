// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_007b76f0 { int words[8]; };
extern void (__thiscall* str_ctor_007b76f0)(Str_007b76f0*, Str_007b76f0*);
struct X_007b76f0 {
    char pad[0x98];
    Str_007b76f0 value;
    Str_007b76f0* copy(Str_007b76f0* out);
};
Str_007b76f0* X_007b76f0::copy(Str_007b76f0* out)
{
    volatile int zero = 0;
    str_ctor_007b76f0(out, &value);
    return out;
}
