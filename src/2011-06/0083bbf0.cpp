// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0083bbf0 { int words[8]; };
extern void (__thiscall* str_ctor_0083bbf0)(Str_0083bbf0*, Str_0083bbf0*);
struct X_0083bbf0 {
    char pad[0x24];
    Str_0083bbf0 value;
    Str_0083bbf0* copy(Str_0083bbf0* out);
};
Str_0083bbf0* X_0083bbf0::copy(Str_0083bbf0* out)
{
    volatile int zero = 0;
    str_ctor_0083bbf0(out, &value);
    return out;
}
