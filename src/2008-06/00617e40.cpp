// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00617e40 { int words[8]; };
extern void (__thiscall* str_ctor_00617e40)(Str_00617e40*, Str_00617e40*);
struct X_00617e40 {
    char pad[0x1c];
    Str_00617e40 value;
    Str_00617e40* copy(Str_00617e40* out);
};
Str_00617e40* X_00617e40::copy(Str_00617e40* out)
{
    volatile int zero = 0;
    str_ctor_00617e40(out, &value);
    return out;
}
