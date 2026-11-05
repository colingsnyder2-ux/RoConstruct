// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_008b2a30 { int words[8]; };
extern void (__thiscall* str_ctor_008b2a30)(Str_008b2a30*, Str_008b2a30*);
struct X_008b2a30 {
    char pad[0x74];
    Str_008b2a30 value;
    Str_008b2a30* copy(Str_008b2a30* out);
};
Str_008b2a30* X_008b2a30::copy(Str_008b2a30* out)
{
    volatile int zero = 0;
    str_ctor_008b2a30(out, &value);
    return out;
}
