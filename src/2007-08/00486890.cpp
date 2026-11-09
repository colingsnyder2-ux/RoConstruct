// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00486890 { int words[8]; };
extern void (__thiscall* str_ctor_00486890)(Str_00486890*, Str_00486890*);
struct X_00486890 {
    char pad[0x13c];
    Str_00486890 value;
    Str_00486890* copy(Str_00486890* out);
};
Str_00486890* X_00486890::copy(Str_00486890* out)
{
    volatile int zero = 0;
    str_ctor_00486890(out, &value);
    return out;
}
