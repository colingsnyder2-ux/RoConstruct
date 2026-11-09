// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00749c40 { int words[8]; };
extern void (__thiscall* str_ctor_00749c40)(Str_00749c40*, Str_00749c40*);
struct X_00749c40 {
    char pad[0x1c];
    Str_00749c40 value;
    Str_00749c40* copy(Str_00749c40* out);
};
Str_00749c40* X_00749c40::copy(Str_00749c40* out)
{
    volatile int zero = 0;
    str_ctor_00749c40(out, &value);
    return out;
}
