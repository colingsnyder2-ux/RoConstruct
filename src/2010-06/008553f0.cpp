// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_008553f0 { int words[8]; };
extern void (__thiscall* str_ctor_008553f0)(Str_008553f0*, Str_008553f0*);
struct X_008553f0 {
    char pad[0x7c];
    Str_008553f0 value;
    Str_008553f0* copy(Str_008553f0* out);
};
Str_008553f0* X_008553f0::copy(Str_008553f0* out)
{
    volatile int zero = 0;
    str_ctor_008553f0(out, &value);
    return out;
}
