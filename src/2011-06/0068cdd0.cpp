// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0068cdd0 { int words[8]; };
extern void (__thiscall* str_ctor_0068cdd0)(Str_0068cdd0*, Str_0068cdd0*);
struct X_0068cdd0 {
    char pad[0x4];
    Str_0068cdd0 value;
    Str_0068cdd0* copy(Str_0068cdd0* out);
};
Str_0068cdd0* X_0068cdd0::copy(Str_0068cdd0* out)
{
    volatile int zero = 0;
    str_ctor_0068cdd0(out, &value);
    return out;
}
