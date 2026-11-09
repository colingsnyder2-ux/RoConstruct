// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00470270 { int words[8]; };
extern void (__thiscall* str_ctor_00470270)(Str_00470270*, Str_00470270*);
struct X_00470270 {
    char pad[0x3c];
    Str_00470270 value;
    Str_00470270* copy(Str_00470270* out);
};
Str_00470270* X_00470270::copy(Str_00470270* out)
{
    volatile int zero = 0;
    str_ctor_00470270(out, &value);
    return out;
}
