// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_007505e0 { int words[8]; };
extern void (__thiscall* str_ctor_007505e0)(Str_007505e0*, Str_007505e0*);
struct X_007505e0 {
    char pad[0x74];
    Str_007505e0 value;
    Str_007505e0* copy(Str_007505e0* out);
};
Str_007505e0* X_007505e0::copy(Str_007505e0* out)
{
    volatile int zero = 0;
    str_ctor_007505e0(out, &value);
    return out;
}
