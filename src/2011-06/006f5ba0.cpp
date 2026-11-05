// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_006f5ba0 { int words[8]; };
extern void (__thiscall* str_ctor_006f5ba0)(Str_006f5ba0*, Str_006f5ba0*);
struct X_006f5ba0 {
    char pad[0x90];
    Str_006f5ba0 value;
    Str_006f5ba0* copy(Str_006f5ba0* out);
};
Str_006f5ba0* X_006f5ba0::copy(Str_006f5ba0* out)
{
    volatile int zero = 0;
    str_ctor_006f5ba0(out, &value);
    return out;
}
