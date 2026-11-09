// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_0088f450 { int words[8]; };
extern void (__thiscall* str_ctor_0088f450)(Str_0088f450*, Str_0088f450*);
struct X_0088f450 {
    char pad[0xc4];
    Str_0088f450 value;
    Str_0088f450* copy(Str_0088f450* out);
};
Str_0088f450* X_0088f450::copy(Str_0088f450* out)
{
    volatile int zero = 0;
    str_ctor_0088f450(out, &value);
    return out;
}
