// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00489970 { int words[8]; };
extern void (__thiscall* str_ctor_00489970)(Str_00489970*, Str_00489970*);
struct X_00489970 {
    char pad[0x194];
    Str_00489970 value;
    Str_00489970* copy(Str_00489970* out);
};
Str_00489970* X_00489970::copy(Str_00489970* out)
{
    volatile int zero = 0;
    str_ctor_00489970(out, &value);
    return out;
}
