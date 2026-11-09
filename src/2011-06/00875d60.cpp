// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_00875d60 { int words[8]; };
extern void (__thiscall* str_ctor_00875d60)(Str_00875d60*, Str_00875d60*);
struct X_00875d60 {
    char pad[0xb0];
    Str_00875d60 value;
    Str_00875d60* copy(Str_00875d60* out);
};
Str_00875d60* X_00875d60::copy(Str_00875d60* out)
{
    volatile int zero = 0;
    str_ctor_00875d60(out, &value);
    return out;
}
