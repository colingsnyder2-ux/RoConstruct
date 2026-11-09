// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00455d00 { int words[8]; };
extern void (__thiscall* str_ctor_00455d00)(Str_00455d00*, Str_00455d00*);
struct X_00455d00 {
    char pad[0x98];
    Str_00455d00 value;
    Str_00455d00* copy(Str_00455d00* out);
};
Str_00455d00* X_00455d00::copy(Str_00455d00* out)
{
    volatile int zero = 0;
    str_ctor_00455d00(out, &value);
    return out;
}
