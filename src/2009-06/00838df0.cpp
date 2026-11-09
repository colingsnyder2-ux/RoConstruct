// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00838df0 { int words[8]; };
extern void (__thiscall* str_ctor_00838df0)(Str_00838df0*, Str_00838df0*);
struct X_00838df0 {
    char pad[0x4c];
    Str_00838df0 value;
    Str_00838df0* copy(Str_00838df0* out);
};
Str_00838df0* X_00838df0::copy(Str_00838df0* out)
{
    volatile int zero = 0;
    str_ctor_00838df0(out, &value);
    return out;
}
