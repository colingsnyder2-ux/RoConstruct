// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00882140 { int words[8]; };
extern void (__thiscall* str_ctor_00882140)(Str_00882140*, Str_00882140*);
struct X_00882140 {
    char pad[0x28];
    Str_00882140 value;
    Str_00882140* copy(Str_00882140* out);
};
Str_00882140* X_00882140::copy(Str_00882140* out)
{
    volatile int zero = 0;
    str_ctor_00882140(out, &value);
    return out;
}
