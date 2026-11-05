// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00653dd0 { int words[8]; };
extern void (__thiscall* str_ctor_00653dd0)(Str_00653dd0*, Str_00653dd0*);
struct X_00653dd0 {
    char pad[0xb8];
    Str_00653dd0 value;
    Str_00653dd0* copy(Str_00653dd0* out);
};
Str_00653dd0* X_00653dd0::copy(Str_00653dd0* out)
{
    volatile int zero = 0;
    str_ctor_00653dd0(out, &value);
    return out;
}
