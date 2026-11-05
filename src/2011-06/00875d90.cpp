// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00875d90 { int words[8]; };
extern void (__thiscall* str_ctor_00875d90)(Str_00875d90*, Str_00875d90*);
struct X_00875d90 {
    char pad[0xb4];
    Str_00875d90 value;
    Str_00875d90* copy(Str_00875d90* out);
};
Str_00875d90* X_00875d90::copy(Str_00875d90* out)
{
    volatile int zero = 0;
    str_ctor_00875d90(out, &value);
    return out;
}
