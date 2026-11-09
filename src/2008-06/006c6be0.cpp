// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006c6be0 { int words[8]; };
extern void (__thiscall* str_ctor_006c6be0)(Str_006c6be0*, Str_006c6be0*);
struct X_006c6be0 {
    char pad[0x24];
    Str_006c6be0 value;
    Str_006c6be0* copy(Str_006c6be0* out);
};
Str_006c6be0* X_006c6be0::copy(Str_006c6be0* out)
{
    volatile int zero = 0;
    str_ctor_006c6be0(out, &value);
    return out;
}
