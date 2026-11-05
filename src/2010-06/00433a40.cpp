// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00433a40 { int words[8]; };
extern void (__thiscall* str_ctor_00433a40)(Str_00433a40*, Str_00433a40*);
struct X_00433a40 {
    char pad[0xa4];
    Str_00433a40 value;
    Str_00433a40* copy(Str_00433a40* out);
};
Str_00433a40* X_00433a40::copy(Str_00433a40* out)
{
    volatile int zero = 0;
    str_ctor_00433a40(out, &value);
    return out;
}
